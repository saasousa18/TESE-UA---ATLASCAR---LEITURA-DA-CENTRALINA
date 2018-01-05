#include <stdio.h>
#include <stdlib.h>

int main(void){
int l=1;
int c=11;

char MID[c][l];

///ID's das mensagens///
MID[0][0]=0x2;MID[0][1]=0x0;MID[0][2]=0x9;//pedal do travao
//MID[1][0]=0x231;//sensor do travao
//MID[2][0]=0x412;//velocidade e distancia percorrida
//MID[3][0]=0x236;//sensor do volante

MID[0][3]=MID[0][8]=MID[0][10]=0x00;
MID[0][4]=MID[0][9]=0x20;
MID[0][7]=0xC0;
MID[0][5]=0xff;
MID[0][6]=0xBB;



for (int i=0;i<l;i++){
for(int j=0;j<c;j++){
if(j<3){
printf("%x",MID[i][j]);
}
else{
printf(" %02x",MID[i][j]);
}}
printf("\n");
}
}
