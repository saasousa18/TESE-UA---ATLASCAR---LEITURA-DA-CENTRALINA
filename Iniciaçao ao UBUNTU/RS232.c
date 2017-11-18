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

//FUNCAO DE ESCRITA 
int OpenPort( char *port_name, char* text)
{
    int fd;
    fd=open(port_name, O_RDWR | O_NDELAY );
    if(fd == -1) { printf("Error. Could not open port\n"); return -1; }
    if (text) //Se text for NULL e não faz a parte de baixo 
    	write( fd, text, strlen(text) );
    return fd;
}

//FUNCAO DE LEITURA
int ReadPortUntilChar(int fd)
{
    char ch;
    do
    {
        int n=read( fd, &ch, 1); //O 1 indica o numero de bytes que está a pretender ler.
        if( n == -1 ) continue;   //perror("Err:") metemos para continuar porque as vezes a porta pode nao estar pronta;
        if(n>0) { printf("%c", ch); fflush(stdout);}
    } 
    while( ch != 'Q');

    return 0;
}

int main()
{
	//escreve ola na porta ttyUSB0
	int fd=OpenPort( "/dev/ttyUSB0", "ola\n");
	if( fd != -1) 

		
	//Lê o que vem da porta ttYUBO
	ReadPortUntilChar(fd);

	return 0;
}
