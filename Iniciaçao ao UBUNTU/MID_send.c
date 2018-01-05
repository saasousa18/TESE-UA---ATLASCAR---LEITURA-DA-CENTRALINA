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
int escrever_serial(char *nome_porta, unsigned char data,int fd){
	//int fd=open(nome_porta, O_WRONLY | O_NDELAY);
	if(fd == -1) { printf("Error. Could not open port\n"); return -1; }
        

int l=1;
int c=11;

char MID_PT[c][l];
char MID_ST[c][l];
char MID_VEL_DIST[c][l];
char MID_SV[c][l];
///ID's das mensagens///
MID_PT[0][0]=0x2;MID_PT[0][1]=0x0;MID_PT[0][2]=0x8;//pedal do travao
MID_ST[0][0]=0x2;MID_ST[0][1]=0x3;MID_ST[0][2]=0x1;//sensor do travao
MID_VEL_DIST[0][0]=0x4;MID_VEL_DIST[0][1]=0x1;MID_VEL_DIST[0][2]=0x2;//velocidade e distancia percorrida
MID_SV[0][0]=0x2;MID_SV[0][1]=0x3;MID_SV[0][2]=0x6; //sensor do volante

//Corpo das mensagens////
MID_PT[0][3]=MID_PT[0][8]=MID_PT[0][10]=0x00;
MID_PT[0][4]=MID_PT[0][9]=0x20;
MID_PT[0][7]=0xC0;
MID_PT[0][5]=0xff;
MID_PT[0][6]=0xBB;

MID_ST[0][3]=MID_ST[0][4]=MID_ST[0][5]=MID_ST[0][6]=MID_ST[0][8]=MID_ST[0][9]=MID_ST[0][10]=0x00;
MID_ST[0][7]=0x11;

MID_VEL_DIST[0][8]=0x00;
MID_VEL_DIST[0][3]=0x7F;
MID_VEL_DIST[0][9]=0x21;
MID_VEL_DIST[0][10]=0x06;
MID_VEL_DIST[0][4]=MID_VEL_DIST[0][5]=MID_VEL_DIST[0][6]=MID_VEL_DIST[0][7]=0xDD;

MID_SV[0][8]=MID_SV[0][9]=0x00;
MID_SV[0][3]=MID_SV[0][4]=MID_SV[0][10]=0xFF;
MID_SV[0][5]=MID_SV[0][6]=MID_SV[0][7]=0xAA;
////
    	//write( fd, &MID_PT,11 );
    	//write( fd, &MID_ST,11 );
    	//write( fd, &MID_VEL_DIST,11 );
    	write( fd, &MID_SV,11 );

    return fd;
}

//Funçao para ler de uma porta
int ler_serial(char *nome_porta, int fd){
	unsigned char dados_recebidos[11];

	   while(1)
    {
        int n=read( fd, &dados_recebidos,11); //O 1 indica o numero de bytes que está a pretender ler.
       if( n == -1 ) continue;   //perror("Err:") metemos para continuar porque as vezes a porta pode nao estar pronta;

       if(n>0) {

        for(int ss=0;ss<11;ss++){
        printf("%x ", dados_recebidos[ss]);}
        printf("\n");
        fflush(stdout);}
   
    }
 
    
    return 0;
} 

///////Funçao para mudar a Baud Rate///////////
int ChangeBaudRate( int fd, int new_baud)
{  
    int oldS;
    struct termios options;

    tcgetattr(fd, &options);
    oldS=cfgetispeed(&options);   //Permite saber a ultima velocidade.

    cfsetispeed(&options, new_baud);
    cfsetospeed(&options, new_baud);

    options.c_cflag |= (CLOCAL | CREAD);
    tcsetattr(fd, TCSANOW, &options);
    
    return oldS;
}

///////////////////////////////////////////////////////////////////

int main(int argc, char *argv[ ])
{  



    int num;
	num=atoi(argv[1]);	
	//printf("%d",num);
	if(argc==2){ // é 2 dois porque o nome do ficheiro ocupa logo a primeira 		posiçao
		if(num==0){
		           int fd=open("/dev/ttyUSB0", O_WRONLY | O_NDELAY);
		           
		           ChangeBaudRate(fd,B921600);
		           
		            unsigned char data=0xAA;
					escrever_serial( "/dev/ttyUSB0", data, fd);//abre a porta USB0 e escreve ola
					//if( port0 != -1);				
				  }
		if(num==1){
		    int fd=open("/dev/ttyUSB1", O_RDONLY | O_NDELAY);
		    ChangeBaudRate(fd,B921600);
			ler_serial("/dev/ttyUSB1",fd);
		}
	}
	else{
		printf("excesso de parametros de entrada\n");
		exit(0);
	}


	return 0;
}


