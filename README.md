# 🖥️ Simulador de Processador MIPS em C

Este projeto é um **simulador simples de um processador MIPS**, desenvolvido em **C**, com o objetivo de reproduzir o funcionamento básico de instruções da arquitetura MIPS.  

O simulador implementa um pequeno conjunto de instruções, permitindo a manipulação de registradores, memória e o fluxo de execução através de desvios.

---

## 📌 Funcionalidades

O simulador permite:

- Representar a **estrutura básica de um processador MIPS** (registradores, memória, PC).
- Executar **instruções aritméticas, lógicas, de desvio e de memória**.
- Visualizar a execução **passo a passo**, incluindo os estágios do pipeline (IF, ID, EX, MEM, WB).
- Manipular registradores `$t0 - $t9`, `$s0 - $s7` e `$zero`.
- Exibir o estado final dos registradores e do PC após o encerramento.

---

## ⚙️ Instruções Implementadas

### 🔹 Tipo R
- `add` → Soma (`rd = rs + rt`)
- `sub` → Subtração (`rd = rs - rt`)
- `mult` → Multiplicação (`rd = rs * rt`)
- `div` → Divisão (`rd = rs / rt`)
- `and` → Operação lógica AND (`rd = rs & rt`)
- `or` → Operação lógica OR (`rd = rs | rt`)
- `move` → Move valor (`rs = rt`)

### 🔹 Tipo I
- `beq` → Desvio condicional se igual (`if rs == rt → PC += label`)
- `bne` → Desvio condicional se diferente (`if rs != rt → PC += label`)
- `lw` → Load Word (carrega valor da memória para registrador)
- `sw` → Store Word (salva valor do registrador na memória)
- `li` → Load Immediate (carrega valor imediato em registrador)

### 🔹 Tipo J
- `j` → Jump (pula para um endereço/label)

---

## 🏗️ Estrutura do Projeto

- **Registradores:** vetor de 26 posições representando os registradores MIPS.
- **Memória:** vetor de 500 posições representando a memória RAM simulada.
- **PC (Program Counter):** contador de instruções, atualizado a cada operação.
- **ULA (Unidade Lógica e Aritmética):** responsável pelas operações aritméticas e lógicas.
- **Banco de Registradores:** identifica os registradores a partir de nomes (`$t0, $s0, $zero`, etc.).
- **Banco de Memória:** responsável pelas operações `lw` e `sw`.

---

## ▶️ Como Executar

### 🔹 Windows
1. Compile o código:
   ```bash
   gcc simulador_mips.c -o simulador.exe
   ```

Execute:
```bash
./simulador.exe
```

🔹 Linux / WSL (remover dependências do Windows)
Se estiver em Linux, remova as chamadas do windows.h e system("cls"), substituindo por:
```c
#include <stdlib.h>
#define CLEAR "clear"
```
e troque system("cls") por system(CLEAR).

Depois compile normalmente:
```bash
gcc simulador_mips.c -o simulador
./simulador
```

📖 Exemplo de Uso
```yaml
Digite a instrução: li
Informe RS: $t0
Informe o valor: 10

Digite a instrução: li
Informe RS: $t1
Informe o valor: 5

Digite a instrução: add
Informe RS: $t2
Informe RT: $t0
Informe RD: $t1
```

Saída esperada:
```bash
$t0 = [10]
$t1 = [5]
$t2 = [15]
```