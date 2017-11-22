//programa: a funçao main aceita argumentos de entrada e representa-os

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[ ]){
int cont;
printf("O nome do programa é: %s\n",argv[0]); // o argv[0] é onde está guardado o nome do ficheiro 
for(cont=1;cont<argc;cont++){
printf("%d Parametro %s\n", cont, argv[cont]);
}
return 0;
}
