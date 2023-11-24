#include <stdio.h>
#include <string.h>
#include <windows.h>

void buscaIntrucao(char instrucao[], int registradores[], int *PC){

  long int label;
  int valor, tipoInst, opcode, funct;
  char rs[5], rd[5], rt[5];

  if(strcmp(instrucao, "add") == 0){
    tipoInst = 1;   funct = 32;
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

  if(tipoInst == 1){
    opcode = 0;
    printf("Informe RS: ");
    scanf(" %s", &rs);
    printf("Informe RT: ");
    scanf(" %s", &rt);
    printf("Informe RD: ");
    scanf(" %s", &rd);
  } else if(tipoInst == 2){
    printf("Informe RS: ");
    scanf(" %s", &rs);
    printf("Informe RT: ");
    scanf(" %s", &rt);
    printf("Informe o valor da label: ");
    scanf("%li", &label);
  } else if(tipoInst == 3){
    printf("Informe RS: ");
    scanf(" %[^\n]", &rs);
    printf("Informe valor: ");
    scanf("%d", &valor);
  } else if(tipoInst == 4){
    printf("Informe o valor da label: ");
    scanf("%li", &label);
  }

  bancoRegistradores(registradores, opcode, rs, rd, rt, funct, label, &PC, tipoInst, valor);

}

void bancoRegistradores(int registradores[], int opcode, char rs[3], char rd[3], char rt[3], int funct, long int label, int **PC, int tipoInst, int valor){

  int x, y, z;
  
  if(strcmp(rs, "$t0") == 0)  { x = 8; }
  if(strcmp(rs, "$t1") == 0)  { x = 9; }
  if(strcmp(rs, "$t2") == 0)  { x = 10; }
  if(strcmp(rs, "$t3") == 0)  { x = 11; }
  if(strcmp(rs, "$t4") == 0)  { x = 12; }
  if(strcmp(rs, "$t5") == 0)  { x = 13; }
  if(strcmp(rs, "$t6") == 0)  { x = 14; }
  if(strcmp(rs, "$t7") == 0)  { x = 15; }

  if(strcmp(rs, "$s0") == 0)  { x = 16; }
  if(strcmp(rs, "$s1") == 0)  { x = 17; } 
  if(strcmp(rs, "$s2") == 0)  { x = 18; } 
  if(strcmp(rs, "$s3") == 0)  { x = 19; } 
  if(strcmp(rs, "$s4") == 0)  { x = 20; } 
  if(strcmp(rs, "$s5") == 0)  { x = 21; } 
  if(strcmp(rs, "$s6") == 0)  { x = 22; } 
  if(strcmp(rs, "$s7") == 0)  { x = 23; } 

  if(strcmp(rs, "$t8") == 0)  { x = 24; } 
  if(strcmp(rs, "$t9") == 0)  { x = 25; }

  // rs = x | rt = y | rd = z

  // -------------------------------------------------- //

  if(strcmp(rt, "$t0") == 0)  { y = 8; }
  if(strcmp(rt, "$t1") == 0)  { y = 9; }
  if(strcmp(rt, "$t2") == 0)  { y = 10; }
  if(strcmp(rt, "$t3") == 0)  { y = 11; }
  if(strcmp(rt, "$t4") == 0)  { y = 12; }
  if(strcmp(rt, "$t5") == 0)  { y = 13; }
  if(strcmp(rt, "$t6") == 0)  { y = 14; }
  if(strcmp(rt, "$t7") == 0)  { y = 15; }

  if(strcmp(rt, "$s0") == 0)  { y = 16; }
  if(strcmp(rt, "$s1") == 0)  { y = 17; } 
  if(strcmp(rt, "$s2") == 0)  { y = 18; } 
  if(strcmp(rt, "$s3") == 0)  { y = 19; } 
  if(strcmp(rt, "$s4") == 0)  { y = 20; } 
  if(strcmp(rt, "$s5") == 0)  { y = 21; } 
  if(strcmp(rt, "$s6") == 0)  { y = 22; } 
  if(strcmp(rt, "$s7") == 0)  { y = 23; } 

  if(strcmp(rt, "$t8") == 0)  { y = 24; } 
  if(strcmp(rt, "$t9") == 0)  { y = 25; }

  // -------------------------------------------------- //

  if(strcmp(rd, "$t0") == 0)  { z = 8; }
  if(strcmp(rd, "$t1") == 0)  { z = 9; }
  if(strcmp(rd, "$t2") == 0)  { z = 10; }
  if(strcmp(rd, "$t3") == 0)  { z = 11; }
  if(strcmp(rd, "$t4") == 0)  { z = 12; }
  if(strcmp(rd, "$t5") == 0)  { z = 13; }
  if(strcmp(rd, "$t6") == 0)  { z = 14; }
  if(strcmp(rd, "$t7") == 0)  { z = 15; }

  if(strcmp(rd, "$s0") == 0)  { z = 16; }
  if(strcmp(rd, "$s1") == 0)  { z = 17; } 
  if(strcmp(rd, "$s2") == 0)  { z = 18; } 
  if(strcmp(rd, "$s3") == 0)  { z = 19; } 
  if(strcmp(rd, "$s4") == 0)  { z = 20; } 
  if(strcmp(rd, "$s5") == 0)  { z = 21; } 
  if(strcmp(rd, "$s6") == 0)  { z = 22; } 
  if(strcmp(rd, "$s7") == 0)  { z = 23; } 

  if(strcmp(rd, "$t8") == 0)  { z = 24; } 
  if(strcmp(rd, "$t9") == 0)  { z = 25; }

  ULA(registradores, opcode, rs, rd, rt, funct, label, &PC, x, y, z, tipoInst, valor);

}

void ULA(int registradores[], int opcode, char rs[5], char rd[5], char rt[5], int funct, long int label, int ***PC, int x, int y, int z, int tipoInst, int valor){

  switch(tipoInst){
    case 1:
    printf("Opcode = [%d] | RS = [%d] | RT = [%d] | RD = [%d] | Schamt = [0] | Funct = [%d]\n", opcode, x, y, z, funct);
    switch(funct){
      case 24: printf("%s = %s * %s\n", rs, rt, rd); registradores[x] = registradores[y] * registradores[z]; break;
      case 26: printf("%s = %s / %s\n", rs, rt, rd); registradores[x] = registradores[y] / registradores[z]; break;
      case 32: printf("%s = %s + %s\n", rs, rt, rd); registradores[x] = registradores[y] + registradores[z]; break;
      case 34: printf("%s = %s - %s\n", rs, rt, rd); registradores[x] = registradores[y] - registradores[z]; break;
      case 36: printf("%s = %s & %s\n", rs, rt, rd); break;
      case 37: printf("%s = %s | %s\n", rs, rt, rd); break;
    }
    break;
    case 2:
    // rs = x | rt = y | rd = z
    printf("Opcode = [%d] | RS = [%d] | RT = [%d] | End Label = [%li]\n", opcode, x, y, label);
    if(opcode == 4){
      printf("beq %s, %s = [%s == %s] branch to label\n", rs, rt, rs, rt);
      if(registradores[x] == registradores[y]){
        ***PC += label;
        printf("é igual\n");
      }
    }
    if(opcode == 5){
      printf("bne %s, %s = [%s != %s] branch to label\n", rs, rt, rs, rt);
      if(registradores[x] != registradores[y]){
        ***PC += label;
      }
    }
    break;

    case 3:
    printf("Opcode = [%d] | RS = [%d] | immediate = [%d]\n", opcode, x, valor);
    if(opcode == 35){
      registradores[x] = valor;
      printf("carrega a word %d, para o %s\n", valor, rs);
    }
    if(opcode == 43){
      valor = registradores[x];
      printf("copia a word %d, para o %s\n", valor, rs);
    }
    break;

    case 4:
    printf("Opcode = [%d] | End Label = [%li]\n", opcode, label);
    ***PC += label;
    printf("Código irá pular para o endereço | PC = [%li]\n", ***PC);
    break;

  }

}

void main(){

  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();

  SetConsoleOutputCP(CPAGE_UTF8);

  char instrucao[4];
  int registradores[26] = {0};
  long int PC = 0;

  while(instrucao[0] != '0'){
    system("cls");
    
    printf("Digite a instrução: ");
    scanf("%s", &instrucao);

    if(strcmp(instrucao, "0") != 0){
      PC += 4;
      buscaIntrucao(instrucao, &registradores, &PC);
    }

  }

  printf("$st0 = [%d]\n", registradores[8]);
  printf("$st1 = [%d]\n", registradores[9]);
  printf("$st2 = [%d]\n", registradores[10]);
  printf("$st3 = [%d]\n", registradores[11]);
  printf("$st4 = [%d]\n", registradores[12]);
  printf("$st5 = [%d]\n", registradores[13]);
  printf("$st6 = [%d]\n", registradores[14]);
  printf("$st7 = [%d]\n", registradores[15]);

  printf("$s0 = [%d]\n", registradores[16]);
  printf("$s1 = [%d]\n", registradores[17]);
  printf("$s2 = [%d]\n", registradores[18]);
  printf("$s3 = [%d]\n", registradores[19]);
  printf("$s4 = [%d]\n", registradores[20]);
  printf("$s5 = [%d]\n", registradores[21]);
  printf("$s6 = [%d]\n", registradores[22]);
  printf("$s7 = [%d]\n", registradores[23]);

  printf("$st8 = [%d]\n", registradores[24]);
  printf("$st9 = [%d]\n", registradores[25]);
  printf("valor do PC no final do simulador = [%li]\n", PC);

}