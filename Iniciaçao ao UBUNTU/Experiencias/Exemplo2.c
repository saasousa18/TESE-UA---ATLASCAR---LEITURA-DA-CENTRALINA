///fecha o programa se a soma for 4
#include <stdio.h>
#include <stdlib.h>

int main()
{
int a, b;
scanf("%d %d",&a, &b);
int c;
c=a+b;
printf("%d \n",c);
if(c==4){
exit(0);
}
printf("ola mundo\n");
return(0);
}
