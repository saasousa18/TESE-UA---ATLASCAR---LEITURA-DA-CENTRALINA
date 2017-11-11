

#include "myfunx.h"



int OpenPort( char *port_name, char* text)
{
    int fd;
    fd=open(port_name, O_RDWR | O_NDELAY ); /*O_RDONLY, O_WRONLY*/
    if(fd == -1) { printf("Error. Could not open port\n"); return -1; }
    if (text) //Se text for NULL e não faz a parte de baixo 
    	write( fd, text, strlen(text) );
    return fd;
}

//Esta função vai ler o que vem no cutecom e envia para a consola (fecha o programa se for escrito 'a')
int ReadPortUntilChar(int fd)
{
    char ch;
    do
    {
        int n=read( fd, &ch, 1); //O 1 indica o numero de bytes que está a pretender ler.
        if( n == -1 ) continue;   //perror("Err:") metemos para continuar porque as vezes a porta pode nao estar pronta;
        if(n>0) { printf("%c", ch); fflush(stdout);}
    } 
    while( ch != 'a');

    return 0;
}

/*função para mudar o baud rate de uma porta série. Aceita um inteiro que é o file descriptor da porta e outro que é o Baud rate.
Retorna -1 em caso de erro e o baud rate antigo se não houver error.*/

int ChangeBaudRate( int fd, int new_baud)
{
    /*... código...*/
    int oldS;
    struct termios options;

    /** Get the current options for the port...  */
    tcgetattr(fd, &options);
    oldS=cfgetispeed(&options);   //Permite saber a ultima velocidade.

    /** Set the baud rates to newBaud for example B19200...  */
    cfsetispeed(&options, new_baud);
    cfsetospeed(&options, new_baud);

    /** Enable the receiver and set local mode...  */
    options.c_cflag |= (CLOCAL | CREAD);

    /** Set the new options for the port...  */
    tcsetattr(fd, TCSANOW, &options);
    
    return oldS;
}

//Cutecom permite ver o terminal da cutecom para as comunicações Rs232:
//Dar permissoes para mexer no cutecom e comunicar em Rs232:
//sudo adduser $USER dialout
//sudo su $USER
//No device usar: /dev/ttyUSB0 para receber com um jumper.

//NOTA: Por cada consola de Rs232 que criamos temos que cria um novo user com "sudo su $USER"


