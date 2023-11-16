#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

// Formato R - Operações entre registradores
// Formato I - Operações entre registradores e valores Imediatos
// Formato J - Instruções de salto incondicional

void main(){

  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();

  SetConsoleOutputCP(CPAGE_UTF8);

  char instrucao[5];

  while(instrucao[0] != '0'){
    
    printf("Digite a instrução: ");
    scanf("%s", &instrucao);

  }
  
  
}