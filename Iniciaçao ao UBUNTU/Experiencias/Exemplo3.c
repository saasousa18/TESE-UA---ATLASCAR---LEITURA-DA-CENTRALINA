//fecha o programa se o ESC for precionado como terceiro caracterer
#include <stdio.h>
#include <stdlib.h>


int main()
{
int a, b;
char d;
scanf("%d %d %c",&a, &b, &d);
int c;
c=a+b;
printf("%d \n",c);
//d=getch();
if(d==27){//27 é o valor decimal da tecla ESC na tabela ASCII
exit(0);
}
printf("ola mundo\n");
return(0);
}
