#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

// Formato R - Operações entre registradores
// Formato I - Operações entre registradores e valores Imediatos
// Formato J - Instruções de salto incondicional

// Banco de registradores
// Identificar instrução (R, I ,J), registradores ($s0, $t0...) e operandos (+ | - | / | *)

// RS, RT, RD

int bancoRegistradores(char instrucao[4], long int *PC){

  char rs[5], rd[5], rt[5];
  long int label_end;
  int inst, opcode, funct;

  if(strcmp(instrucao, "add") == 0){
    inst = 1;   funct = 32;
  }   
  if(strcmp(instrucao, "sub") == 0){
    inst = 2;   funct = 34;
  }   
  if(strcmp(instrucao, "mult") == 0){
    inst = 3;   funct = 24;
  } 
  if(strcmp(instrucao, "div") == 0){
    inst = 4;   funct = 26;
  }   
  if(strcmp(instrucao, "and") == 0){
    inst = 5;   funct = 36;
  }  
  if(strcmp(instrucao, "or") == 0){
    inst = 6;   funct = 37;
  }

  if(strcmp(instrucao, "beq") == 0){
    inst = 7;   opcode = 4;
  }
  if(strcmp(instrucao, "bne") == 0){
    inst = 8;   opcode = 5;
  }

  if(strcmp(instrucao, "lw") == 0){
    inst = 9;   opcode = 35;
  }  
  if(strcmp(instrucao, "sw") == 0){
    inst = 10;  opcode = 43;
  }    

  if(strcmp(instrucao, "j") == 0){
    inst = 11;  opcode = 2;
  }

  if(inst > 0 && inst < 7){
    opcode = 0;
    printf("Informe RS: ");
    scanf(" %s", &rs);
    printf("Informe RT: ");
    scanf(" %s", &rt);
    printf("Informe RD: ");
    scanf(" %s", &rd);
    ULA(0, opcode, funct, rs, rt, rd, label_end, &PC);
  }

  if(inst == 7 || inst == 8){
    printf("Informe RS: ");
    scanf(" %s", &rs);
    printf("Informe RT: ");
    scanf(" %s", &rt);
    printf("Informe o valor da label: ");
    scanf("%li", &label_end);
    ULA(-1, opcode, funct, rs, rt, rd, label_end, &PC);
  }

  if(inst == 9 || inst == 10){
    printf("Informe RS: ");
    scanf(" %s", &rs);
    printf("Informe RT: ");
    scanf(" %s", &rt);
    ULA(8, opcode, funct, rs, rt, rd, label_end, &PC);
  }

  if(inst == 11){
    printf("Informe o valor da label: ");
    scanf("%li", &label_end);
    ULA(2, opcode, funct, rs, rt, rd, label_end, &PC);
  }

}

int ULA(int type, int opcode, int funct, char rs[5], char rt[5], char rd[5], long int label_end, long int **PC){

  // Identificar os registradores RS, RT e RD na ordem

  int Drs, Drt, Drd;

  if(strcmp(rs, "$t0") == 0)  Drs = 8;
  if(strcmp(rs, "$t1") == 0)  Drs = 9;
  if(strcmp(rs, "$t2") == 0)  Drs = 10;
  if(strcmp(rs, "$t3") == 0)  Drs = 11;
  if(strcmp(rs, "$t4") == 0)  Drs = 12;
  if(strcmp(rs, "$t5") == 0)  Drs = 13;
  if(strcmp(rs, "$t6") == 0)  Drs = 14;
  if(strcmp(rs, "$t7") == 0)  Drs = 15;

  if(strcmp(rs, "$s0") == 0)  Drs = 16;
  if(strcmp(rs, "$s1") == 0)  Drs = 17;
  if(strcmp(rs, "$s2") == 0)  Drs = 18;
  if(strcmp(rs, "$s3") == 0)  Drs = 19;
  if(strcmp(rs, "$s4") == 0)  Drs = 20;
  if(strcmp(rs, "$s5") == 0)  Drs = 21;
  if(strcmp(rs, "$s6") == 0)  Drs = 22;
  if(strcmp(rs, "$s7") == 0)  Drs = 23;

  if(strcmp(rs, "$t8") == 0)  Drs = 24;
  if(strcmp(rs, "$t9") == 0)  Drs = 25;

  // ------------------------------------

  if(strcmp(rt, "$t0") == 0)  Drt = 8;
  if(strcmp(rt, "$t1") == 0)  Drt = 9;
  if(strcmp(rt, "$t2") == 0)  Drt = 10;
  if(strcmp(rt, "$t3") == 0)  Drt = 11;
  if(strcmp(rt, "$t4") == 0)  Drt = 12;
  if(strcmp(rt, "$t5") == 0)  Drt = 13;
  if(strcmp(rt, "$t6") == 0)  Drt = 14;
  if(strcmp(rt, "$t7") == 0)  Drt = 15;
  
  if(strcmp(rt, "$s0") == 0)  Drt = 16;
  if(strcmp(rt, "$s1") == 0)  Drt = 17;
  if(strcmp(rt, "$s2") == 0)  Drt = 18;
  if(strcmp(rt, "$s3") == 0)  Drt = 19;
  if(strcmp(rt, "$s4") == 0)  Drt = 20;
  if(strcmp(rt, "$s5") == 0)  Drt = 21;
  if(strcmp(rt, "$s6") == 0)  Drt = 22;
  if(strcmp(rt, "$s7") == 0)  Drt = 23;

  if(strcmp(rt, "$t8") == 0)  Drt = 24;
  if(strcmp(rt, "$t9") == 0)  Drt = 25;

  // ------------------------------------

  if(strcmp(rd, "$t0") == 0)  Drd = 8;
  if(strcmp(rd, "$t1") == 0)  Drd = 9;
  if(strcmp(rd, "$t2") == 0)  Drd = 10;
  if(strcmp(rd, "$t3") == 0)  Drd = 11;
  if(strcmp(rd, "$t4") == 0)  Drd = 12;
  if(strcmp(rd, "$t5") == 0)  Drd = 13;
  if(strcmp(rd, "$t6") == 0)  Drd = 14;
  if(strcmp(rd, "$t7") == 0)  Drd = 15;
  
  if(strcmp(rd, "$s0") == 0)  Drd = 16;
  if(strcmp(rd, "$s1") == 0)  Drd = 17;
  if(strcmp(rd, "$s2") == 0)  Drd = 18;
  if(strcmp(rd, "$s3") == 0)  Drd = 19;
  if(strcmp(rd, "$s4") == 0)  Drd = 20;
  if(strcmp(rd, "$s5") == 0)  Drd = 21;
  if(strcmp(rd, "$s6") == 0)  Drd = 22;
  if(strcmp(rd, "$s7") == 0)  Drd = 23;

  if(strcmp(rd, "$t8") == 0)  Drd = 24;
  if(strcmp(rd, "$t9") == 0)  Drd = 25;

  printf("Estrutura do código:\n");
  switch(type){
    case -1:
    printf("Opcode = [%d] | RS = [%d] | RT = [%d] | End Label = [%li]\n", opcode, Drs, Drt, label_end);
    if(opcode == 4){
      printf("beq %s, %s = [%s == %s] branch to label\n", rs, rt, rs, rt);
    }
    if(opcode == 5){
      printf("beq %s, %s = [%s != %s] branch to label\n", rs, rt, rs, rt);
    }
    **PC += label_end;
    printf("Resultado [PC] caso for verdadeira a condição = [%li]\n", **PC);
    break;

    case 0:
    printf("Opcode = [%d] | RS = [%d] | RT = [%d] | RD = [%d] | Schamt = [0] | Funct = [%d]\n", opcode, Drs, Drt, Drd, funct);
    switch(funct){
      case 24: printf("%s = %s * %s\n", rs, rt, rd); break;
      case 26: printf("%s = %s / %s\n", rs, rt, rd); break;
      case 32: printf("%s = %s + %s\n", rs, rt, rd); break;
      case 34: printf("%s = %s - %s\n", rs, rt, rd); break;
      case 36: printf("%s = %s & %s\n", rs, rt, rd); break;
      case 37: printf("%s = %s | %s\n", rs, rt, rd); break;
    }
    break;

    case 2:
    printf("Opcode = [%d] | End Label = [%li]\n", opcode, label_end);
    **PC += label_end;
    printf("Código irá pular para o endereço | PC = [%li]\n", **PC);
    break;

    case 8:
    printf("Opcode = [%d] | RS = [%d] | RT = [%d]\n", opcode, Drs, Drt);
    if(opcode == 35){
      printf("carrega a word que está no endereço dado pelo %s, para o %s\n", rt, rs);
    }
    if(opcode == 43){
      printf("copia a word que está no endereço dado pelo %s, para o %s\n", rt, rs);
    }
    break;
  }

}

void main(){

  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();

  SetConsoleOutputCP(CPAGE_UTF8);

  char instrucao[4];
  long int PC = 0;

  while(instrucao[0] != '0'){
    
    printf("Digite a instrução: ");
    scanf("%s", &instrucao);

    if(strcmp(instrucao, "0") != 0){
      PC += 4;
      bancoRegistradores(instrucao, &PC);
    }

  }

  printf("valor do PC no final do simulador = [%li]\n", PC);
  
  
}