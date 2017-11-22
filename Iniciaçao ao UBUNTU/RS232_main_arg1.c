#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
//includes para a função OPEN
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//includes para a função WRITE
#include <unistd.h>
//include para a função READ
#include <unistd.h>

#include <string.h>
#include <termios.h>
#include <unistd.h>
       


//Funçao para escrever numa porta
int escrever_serial(char *nome_porta,char*dados){
	int fd=open(nome_porta, O_WRONLY | O_NDELAY);
	if(fd == -1) { printf("Error. Could not open port\n"); return -1; }
    if (dados) //Se text for NULL e não faz a parte de baixo 
    	write( fd, dados, strlen(dados) );
    return fd;
}

//Funçao para ler de uma porta
int ler_serial(char *nome_porta){
	char dados_recebidos;
	int fd=open(nome_porta, O_RDONLY | O_NDELAY);
	do
    {
        int n=read( fd, &dados_recebidos, 1); //O 1 indica o numero de bytes que está a pretender ler.
        if( n == -1 ) continue;   //perror("Err:") metemos para continuar porque as vezes a porta pode nao estar pronta;
        if(n>0) { printf("%c", dados_recebidos); fflush(stdout);}
    } 
    while( dados_recebidos!= 'Q');

    return 0;
}

///////////////////////////////////////////////////////////////////

int main(int argc, char *argv[ ])
{  
    int num;
	num=atoi(argv[1]);	
	//printf("%d",num);
	if(argc==2){ // é 2 dois porque o nome do ficheiro ocupa logo a primeira 		posiçao
		if(num==0){
					escrever_serial( "/dev/ttyUSB0","ola");//abre a porta USB0 e escreve ola
					//if( port0 != -1);				
				  }
		if(num==1){
			ler_serial("/dev/ttyUSB1");
		}
	}
	else{
		printf("excesso de parametros de entrada\n");
		exit(0);
	}


	return 0;
}
