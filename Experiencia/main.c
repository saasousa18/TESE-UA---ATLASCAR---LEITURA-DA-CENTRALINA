/**
 *  @file   main.c
 *  @brief  Descrição resumida do ficheiro
 *
 *  @author    danielcosta@ua.pt
 *  @date      Qua Out 15 09:52:22 WEST 2014
 *  @version   1
 */

#define _MAIN_C_
#include "myfunx.h"




int main(int argc, char *argv[])
{

#if 0
//Ex1:
	int pid = fork();
	int s_id;
	if(pid == -1) { printf("Could not fork(). Exiting\n"); return -1; }

	if(pid == 0)		/* The child */
	{
		MessageFromChild("I am the child\n");
		ChildMain3();
		MessageFromChild("CHILD ended\n");
	}
	else/* The parent */
	{
		MessageFromParent("I am the parent\n");
		s_id = ParentMain3();	/*Get s_id from return value to know the id to destroy the shared mem */
		if(s_id > 0) shmctl(s_id, IPC_RMID, NULL);	/*Allow elimination of shared memory */
		//if you comment the previous line the shared memory is not cleared from system!

		MessageFromParent("PARENT ended\n");
	}

	return 0;

#endif

#if 0
//Ex b
	int fd=OpenPort( "/dev/ttyUSB0", "Ola");
	if( fd != -1) 
		close(fd);
	return 0;
#endif

#if 1
//Ex c
	int fd=OpenPort("/dev/ttyUSB0", NULL);
	if(fd == -1) 
	{ 
		printf("Error. Could not open port\n"); 
		return 0; 
	}
		
	ChangeBaudRate(fd,B115200);
	char *str="Hello at high speed \n";
	write( fd, str, strlen(str) );
	
	//ReadPortUntilChar(fd);
	
	close(fd);
	return 0;
#endif

#if 0
    GtkWidget *window;

/* Initialize GTK+ and all of its supporting libraries. */
    gtk_init(&argc, &argv);

/* Create a new window, give it a title and display it to the user. */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Hello World");
    gtk_widget_show(window);

/* Hand control over to the main loop. */
    gtk_main();
    return 0;
    
#endif
}




