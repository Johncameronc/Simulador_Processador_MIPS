#include <stdio.h>
#include <string.h>

int bancoInstrucoes(char instrucao[5]){

  if(strcmp(instrucao, "add") == 0) return 10;

  return -1;

}

void main(){

  char instrucoes[5];
  int i, inst;

  printf("Instrucao: ");
  scanf("%s", &instrucoes);
  inst = bancoInstrucoes(instrucoes);

  switch(inst){
    case 10: printf("soma\n"); break;
    case -1: printf("inválido\n"); break;
  }

}