 //verifica se os parametros de entrada é só 1

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[ ]){
if(argc==2){ // é dois porque o nome do ficheiro ocupa logo a primeira posiçao
//printf("ta fixe\n");
}
else{
printf("excesso de parametros de entrada\n");
exit(0);
}
return 0;
}
