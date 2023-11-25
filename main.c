#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <math.h>

void printTitle(){
  borda(100); vazio(); seletoresInicio(35);
  printf("SIMULADOR PROCESSADOR MIPS                                   ██\n");
  vazio();borda(100); 
}

void printEstrutura(){
  vazio(); seletoresInicio(42);
  printf("ESTRUTURA                                             ██\n");
  vazio();borda(100); 
}

void borda(int n){
  for(int i = 0; i < n + 1; i++){
    printf("█");
  }
  printf("\n");
}

void seletoresInicio(int n){
  printf("██");
  for(int i = 0; i < n + 1; i++){
    printf(" ");
  }
}

void vazio(){
  printf("██");
  for(int i = 0; i < 97; i++){
    printf(" ");
  }
  printf("██\n");
}

void buscaIntrucao(char instrucao[], int registradores[], int *PC, int memoria[]){

  long int label;
  int valor, offset, tipoInst, opcode, funct;
  char rs[6], rd[6], rt[6];

  system("cls"); printTitle();

  if(strcmp(instrucao, "add") == 0){
    tipoInst = 1;   funct = 32;
  }
  if(strcmp(instrucao, "move") == 0){
    tipoInst = 1;   funct = 33;
  }
  if(strcmp(instrucao, "sub") == 0){
    tipoInst = 1;   funct = 34;
  }   
  if(strcmp(instrucao, "mult") == 0){
    tipoInst = 1;   funct = 24;
  } 
  if(strcmp(instrucao, "div") == 0){
    tipoInst = 1;   funct = 26;
  }   
  if(strcmp(instrucao, "and") == 0){
    tipoInst = 1;   funct = 36;
  }  
  if(strcmp(instrucao, "or") == 0){
    tipoInst = 1;   funct = 37;
  }


  if(strcmp(instrucao, "beq") == 0){
    tipoInst = 2;   opcode = 4;
  }
  if(strcmp(instrucao, "bne") == 0){
    tipoInst = 2;   opcode = 5;
  }


  if(strcmp(instrucao, "lw") == 0){
    tipoInst = 3;   opcode = 35;
  }  
  if(strcmp(instrucao, "sw") == 0){
    tipoInst = 3;  opcode = 43;
  }


  if(strcmp(instrucao, "j") == 0){
    tipoInst = 4;  opcode = 2;
  }

  if(strcmp(instrucao, "li") == 0){
    tipoInst = 5;  opcode = 9;
  }

  if(tipoInst == 1){
    opcode = 0;
    if(funct == 33){
      printf("\n        Informe RS: ");
      scanf(" %s", &rs);
      printf("        Informe RT: ");
      scanf(" %s", &rt);
    } else {
      printf("\n        Informe RS: ");
      scanf(" %s", &rs);
      printf("        Informe RT: ");
      scanf(" %s", &rt);
      printf("        Informe RD: ");
      scanf(" %s", &rd);
    }
  } else if(tipoInst == 2){
    printf("\n        Informe RS: ");
    scanf(" %s", &rs);
    printf("        Informe RT: ");
    scanf(" %s", &rt);
    printf("        Informe o valor da label: ");
    scanf("%li", &label);
  } else if(tipoInst == 3){
    printf("\n        Informe RS: ");
    scanf(" %s", &rs);
    printf("        Informe o posição da RAM (vetor): ");
    scanf("%d", &valor);
  } else if(tipoInst == 4){
    printf("\n        Informe o valor da label: ");
    scanf("%li", &label);
  } else if(tipoInst == 5){
    printf("\n        Informe RS: ");
    scanf(" %s", &rs);
    printf("        Informe o valor: ");
    scanf("%d", &valor);
  }

  bancoRegistradores(registradores, opcode, rs, rd, rt, funct, label, &PC, tipoInst, valor, offset, memoria);

}

void bancoRegistradores(int registradores[], int opcode, char rs[6], char rd[6], char rt[6], int funct, long int label, int **PC, int tipoInst, int valor, int offset, int memoria[]){

  int x, y, z;
  
  if(strcmp(rs, "$zero") == 0){ x = 0; }  if(strcmp(rs, "$t0") == 0)  { x = 8; }  if(strcmp(rs, "$t1") == 0)  { x = 9; }  if(strcmp(rs, "$t2") == 0)  { x = 10; }
  if(strcmp(rs, "$t3") == 0)  { x = 11; } if(strcmp(rs, "$t4") == 0)  { x = 12; } if(strcmp(rs, "$t5") == 0)  { x = 13; } if(strcmp(rs, "$t6") == 0)  { x = 14; }
  if(strcmp(rs, "$t7") == 0)  { x = 15; }

  if(strcmp(rs, "$s0") == 0)  { x = 16; } if(strcmp(rs, "$s1") == 0)  { x = 17; } if(strcmp(rs, "$s2") == 0)  { x = 18; } if(strcmp(rs, "$s3") == 0)  { x = 19; } 
  if(strcmp(rs, "$s4") == 0)  { x = 20; } if(strcmp(rs, "$s5") == 0)  { x = 21; } if(strcmp(rs, "$s6") == 0)  { x = 22; } if(strcmp(rs, "$s7") == 0)  { x = 23; } 

  if(strcmp(rs, "$t8") == 0)  { x = 24; } if(strcmp(rs, "$t9") == 0)  { x = 25; }
  
  // -------------------------------------------------- //

  if(strcmp(rt, "$zero") == 0){ y = 0; }  if(strcmp(rt, "$t0") == 0)  { y = 8; }  if(strcmp(rt, "$t1") == 0)  { y = 9; }  if(strcmp(rt, "$t2") == 0)  { y = 10; }
  if(strcmp(rt, "$t3") == 0)  { y = 11; } if(strcmp(rt, "$t4") == 0)  { y = 12; } if(strcmp(rt, "$t5") == 0)  { y = 13; } if(strcmp(rt, "$t6") == 0)  { y = 14; }
  if(strcmp(rt, "$t7") == 0)  { y = 15; }

  if(strcmp(rt, "$s0") == 0)  { y = 16; } if(strcmp(rt, "$s1") == 0)  { y = 17; } if(strcmp(rt, "$s2") == 0)  { y = 18; } if(strcmp(rt, "$s3") == 0)  { y = 19; } 
  if(strcmp(rt, "$s4") == 0)  { y = 20; } if(strcmp(rt, "$s5") == 0)  { y = 21; } if(strcmp(rt, "$s6") == 0)  { y = 22; } if(strcmp(rt, "$s7") == 0)  { y = 23; } 

  if(strcmp(rt, "$t8") == 0)  { y = 24; } if(strcmp(rt, "$t9") == 0)  { y = 25; }
  
  // -------------------------------------------------- //

  if(strcmp(rd, "$zero") == 0){ x = 0; }  if(strcmp(rd, "$t0") == 0)  { z = 8; }  if(strcmp(rd, "$t1") == 0)  { z = 9; }  if(strcmp(rd, "$t2") == 0)  { z = 10; }
  if(strcmp(rd, "$t3") == 0)  { z = 11; } if(strcmp(rd, "$t4") == 0)  { z = 12; } if(strcmp(rd, "$t5") == 0)  { z = 13; } if(strcmp(rd, "$t6") == 0)  { z = 14; }
  if(strcmp(rd, "$t7") == 0)  { z = 15; }

  if(strcmp(rd, "$s0") == 0)  { z = 16; } if(strcmp(rd, "$s1") == 0)  { z = 17; } if(strcmp(rd, "$s2") == 0)  { z = 18; } if(strcmp(rd, "$s3") == 0)  { z = 19; }
  if(strcmp(rd, "$s4") == 0)  { z = 20; } if(strcmp(rd, "$s5") == 0)  { z = 21; } if(strcmp(rd, "$s6") == 0)  { z = 22; } if(strcmp(rd, "$s7") == 0)  { z = 23; } 

  if(strcmp(rd, "$t8") == 0)  { z = 24; } if(strcmp(rd, "$t9") == 0)  { z = 25; }
  
  ULA(registradores, opcode, rs, rd, rt, funct, label, &PC, x, y, z, tipoInst, valor, memoria);

}

int conversao(int decimal, int binario[], int n){

  if(decimal > 0){
    binario[n] = decimal % 2;
    return conversao(decimal / 2, binario, n - 1);
  }

}

int binarioParaDecimal(int binario[], int tamanho) {
    if (tamanho == 0) {
        return 0;
    }

    int resultado = binarioParaDecimal(binario, tamanho - 1);

    int bit = binario[tamanho - 1];
    resultado += bit * pow(2, (16 - tamanho));

    return resultado;
}

void ULA(int registradores[], int opcode, char rs[6], char rd[6], char rt[6], int funct, long int label, int ***PC, int x, int y, int z, int tipoInst, int valor, int memoria[]){

  system("cls"); printTitle(); printEstrutura();

  int binario1[16] = {0}, binario2[16] = {0}, binario3[16] = {0}, i;

  switch(tipoInst){

    case 1:
    if(funct == 33){
      printf("\n        Opcode = [%d] | RS = [%d] | RT = [%d] | Schamt = [0] | Funct = [%d]\n", opcode, x, y, funct);
      vazio(); borda(100);
      printf("[%s] = [%s]\n", rs, rt); registradores[x] = registradores[y]; system("pause"); break;
      printf("\n        1. (IF) Busca da Instrução\n");
      printf("        2. (ID) Decodificação\n");
      printf("        3. (EX) Execução das Operações Aritméticas / Lógicas ou desvios condicionais\n");
      printf("        4. (WB) Escrita dos Resultados \n");
    }
    printf("\n        Opcode = [%d] | RS = [%d] | RT = [%d] | RD = [%d] | Schamt = [0] | Funct = [%d]\n", opcode, x, y, z, funct);
    switch(funct){
      case 24: printf("\n        [%s] = [%s] * [%s]\n", rs, rt, rd); printf("        [%d] = [%d] * [%d]\n", registradores[x], registradores[y], registradores[z]); registradores[x] = registradores[y] * registradores[z]; printf("        Resultado = [%d]\n", registradores[x]); break;
      case 26: printf("\n        [%s] = [%s] / [%s]\n", rs, rt, rd); printf("        [%d] = [%d] / [%d]\n", registradores[x], registradores[y], registradores[z]); registradores[x] = registradores[y] / registradores[z]; printf("        Resultado = [%d]\n", registradores[x]); break;
      case 32: printf("\n        [%s] = [%s] + [%s]\n", rs, rt, rd); printf("        [%d] = [%d] + [%d]\n", registradores[x], registradores[y], registradores[z]); registradores[x] = registradores[y] + registradores[z]; printf("        Resultado = [%d]\n", registradores[x]); break;
      case 34: printf("\n        [%s] = [%s] - [%s]\n", rs, rt, rd); printf("        [%d] = [%d] - [%d]\n", registradores[x], registradores[y], registradores[z]); registradores[x] = registradores[y] - registradores[z]; printf("        Resultado = [%d]\n", registradores[x]); break;
      // Função AND
      case 36: printf("\n        [%s] = [%s] & [%s]\n", rs, rt, rd); printf("        [%d] = [%d] & [%d]\n", registradores[x], registradores[y], registradores[z]); 
      conversao(registradores[y], binario1, 15); conversao(registradores[z], binario2, 15);
      for(i = 15; i > -1; i--){
        if(binario1[i] == 1 && binario2[i] == 1){
          binario3[i] = 1;
        } else {
          binario3[i] = 0;
        }
      }
      registradores[x] = binarioParaDecimal(binario3, 16);
      printf("        Resultado = [%d]\n", registradores[x]);
      printf("\n        1. (IF) Busca da Instrução\n");
      printf("        2. (ID) Decodificação\n");
      printf("        3. (EX) Execução das Operações Aritméticas / Lógicas ou desvios condicionais\n");
      printf("        4. (WB) Escrita dos Resultados \n");
      break;
      // Função OR
      case 37: printf("\n        [%s] = [%s] | [%s]\n", rs, rt, rd); printf("        [%d] = [%d] | [%d]\n", registradores[x], registradores[y], registradores[z]); 
      conversao(registradores[y], binario1, 15); conversao(registradores[z], binario2, 15);
      for(i = 15; i > -1; i--){
        if(binario1[i] == 0 && binario2[i] == 0){
          binario3[i] = 0;
        } else {
          binario3[i] = 1;
        }
      }
      registradores[x] = binarioParaDecimal(binario3, 16);
      printf("        Resultado = [%d]\n", registradores[x]);
      printf("\n        1. (IF) Busca da Instrução\n");
      printf("        2. (ID) Decodificação\n");
      printf("        3. (EX) Execução das Operações Aritméticas / Lógicas ou desvios condicionais\n");
      printf("        4. (WB) Escrita dos Resultados \n");
      break;
    }
    break;

    case 2:
    printf("\n        Opcode = [%d] | RS = [%d] | RT = [%d] | End Label = [%li]\n", opcode, x, y, label);
    if(opcode == 4){
      printf("\n        beq %s, %s = [%s == %s] branch to label\n", rs, rt, rs, rt);
      if(registradores[x] == registradores[y]){
        ***PC += label;
        printf("        [%d] e [%d] são iguais\n", registradores[x], registradores[y]);
      } else {
        printf("        [%d] e [%d] não são iguais\n", registradores[x], registradores[y]);
      }
    }
    if(opcode == 5){
      printf("\n        bne %s, %s = [%s != %s] branch to label\n", rs, rt, rs, rt);
      if(registradores[x] != registradores[y]){
        ***PC += label;
        printf("        [%d] e [%d] são diferentes\n", registradores[x], registradores[y]);
      } else {
        printf("        [%d] e [%d] não são diferentes\n", registradores[x], registradores[y]);
      }
    }
    printf("        Resultado = [%d]\n", ***PC);
    printf("\n        1. (IF) Busca da Instrução\n");
    printf("        2. (ID) Decodificação\n");
    printf("        3. (EX) Execução das Operações Aritméticas / Lógicas ou desvios condicionais\n");
    printf("        4. (WB) Escrita dos Resultados \n");
    break;

    case 3:
    printf("\n        Opcode = [%d] | RS = [%d] | Immediate = [%d]\n", opcode, x, valor);
    if(opcode == 35){
      registradores[x] = memoria[valor];
      printf("\n        [%s] = memória[%d]\n", rs, valor);
    }
    if(opcode == 43){
      memoria[valor] = registradores[x];
      printf("\n        memória[%d] = [%s]\n", valor, rs);
    }
    printf("\n        1. (IF) Busca da Instrução\n");
    printf("        2. (ID) Decodificação\n");
    printf("        3. (EX) Execução das Operações Aritméticas / Lógicas ou desvios condicionais\n");
    printf("        4. (MEM) Acesso à memória\n");
    printf("        5. (WB) Escrita dos Resultados \n");
    break;

    case 4:
    printf("\n        Opcode = [%d] | End Label = [%li]\n", opcode, label);
    ***PC += label;
    printf("\n        Código irá pular para o endereço | PC = [%li]\n", ***PC);
    printf("\n        1. (IF) Busca da Instrução\n");
    printf("        2. (ID) Decodificação\n");
    printf("        3. (EX) Execução das Operações Aritméticas / Lógicas ou desvios condicionais\n");
    printf("        4. Desvio incondicional, atualização do PC\n");
    break;

    case 5:
    printf("\n        Opcode = [%d] | RS = [0] | RT = [%d] | Immediate = [%d]\n", opcode, x, valor);
    printf("\n        [%s] = [0] + [%d]\n", rs, valor);
    registradores[x] = valor;
    printf("        Resultado = [%d]\n", registradores[x]);
    printf("\n        1. (IF) Busca da Instrução\n");
    printf("        2. (ID) Decodificação\n");
    printf("        3. (EX) Execução das Operações Aritméticas / Lógicas ou desvios condicionais\n");
    printf("        4. (WB) Escrita dos Resultados \n");
    break;
  }

  printf("\n        PC fim da instrução = [%d]\n", ***PC);
  system("pause");
  registradores[0] = 0;

}

void main(){

  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();

  SetConsoleOutputCP(CPAGE_UTF8);

  char instrucao[4];
  int registradores[26] = {0}, memoria[500] = {0};
  long int PC = 0;
  int menu = 1;

  while((strcmp(instrucao, "sair") != 0)){
    
    system("cls");
    printTitle();
    
    printf("\n        Digite sair para encerrar o programa\n");
    printf("        Digite a instrução: ");
    scanf(" %s", &instrucao);

    if(strcmp(instrucao, "sair") != 0){
      PC += 4;
      buscaIntrucao(instrucao, &registradores, &PC, &memoria);
    }

  }

  system("cls"); printTitle();
  printf("\n$zero = [%d]\n",registradores[0]);
  printf("$st0 =  [%d]\n", registradores[8]);
  printf("$st1 =  [%d]\n", registradores[9]);
  printf("$st2 =  [%d]\n", registradores[10]);
  printf("$st3 =  [%d]\n", registradores[11]);
  printf("$st4 =  [%d]\n", registradores[12]);
  printf("$st5 =  [%d]\n", registradores[13]);
  printf("$st6 =  [%d]\n", registradores[14]);
  printf("$st7 =  [%d]\n", registradores[15]);

  printf("$s0 =   [%d]\n", registradores[16]);
  printf("$s1 =   [%d]\n", registradores[17]);
  printf("$s2 =   [%d]\n", registradores[18]);
  printf("$s3 =   [%d]\n", registradores[19]);
  printf("$s4 =   [%d]\n", registradores[20]);
  printf("$s5 =   [%d]\n", registradores[21]);
  printf("$s6 =   [%d]\n", registradores[22]);
  printf("$s7 =   [%d]\n", registradores[23]);

  printf("$st8 =  [%d]\n", registradores[24]);
  printf("$st9 =  [%d]\n", registradores[25]);
  printf("PC   =  [%li]\n", PC);

}