#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/timeb.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <errno.h>
#include <unistd.h>

int timer=0;
int initTimer(void (*func) (int))
{
	// Timers decrement from it_value to zero, generate a signal, and reset to it_interval.
	// A timer which is set to zero (it_value is zero or the timer expires and it_interval is zero) stops.

	const struct itimerval vValue = { {1, 0},	// it_interval: next value (sec,usecs) - interval of repetition (1 sec) 
	                                  {1, 0}     };	// it_value: initial value (sec,usecs) - initial delay (1 second here)
	int a = setitimer(ITIMER_REAL, &vValue, NULL);
	if (a)
	{
		perror("Setting timer:");
		return 0;
	}

	signal(SIGALRM, func);
	return 1;
	
}

 int SetTimerOff(void)
{
	const struct itimerval vValue = { {0, 0},
	                                  {0, 0}};

	int a = setitimer(ITIMER_REAL, &vValue, NULL);
	if (a)
	{
		perror("Setting timer off:");
		return 0;
	}

	return 1;
}

void RespondAlarm(int signum)
{
	static long int count = 0;
	count++;

	if (count == 5)
	{
		SetTimerOff();
		//printf("5 segundos\n");
		timer=1; //flag de estouro do timer
		count=0;
	}
}




int main()
{

char c=0;
int temp=0;

    while(1){
   int tempo=0;
   temp=temp+1;
   initTimer(RespondAlarm);
   while (timer!=1);
   if(temp==1){
         tempo=temp*5;
         printf("passou %dseg\n%d\n",tempo,temp);
         timer=0; //limpa a flag
              }
   if(temp==2){
         tempo=temp*5;
         printf("passou %dseg\n%d\n",tempo,temp);
         timer=0; //limpa a flag
         //temp=0;
              }
    }
    
	return 0;


}
