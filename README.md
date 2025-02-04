# BigNumber

Projeto em C para execução de operações matemáticas padrões com numeros grandes


## Membros do Grupo

**Nome:**  Marco Antonio Lopes Rodrigues <br>

---

## Motivação

Pensando na limitação numérica das linguagens de programação a motivação para o projeto é desenvolver uma interface de manipulação de números grandes, e aqui se entende por números grandes, números não suportados pelos tipos númericos padrões (Int - Big Int).
Desenvolver um algoritmo de manipulação de números em que a única limitação seja a memoria disponível no computador.


## Organização do Código e Métodos de solução

A estrutura padrão utilizada para o projeto é uma lista duplamente encadeada, de modo a permitir armazenamento com limitação única à memoria do computador, foi utilizado alocação dinâmica de memória pela utilização de uma lista duplamente encadeada e nós independentes para cada algarismo do número; cada manipulação matematica entre os números é feita pela manipulação direta da lista.
O projeto foi divido em arquivo auxiliares (bibliotecas) e client padrão para manipulação das estruturas. O arquivo bignumber.c é a implementação da estrutura de dados e manipulação matematica dos números grandes, bignumber.h sua interface pública; node.c e node.h são respectivamente a implementação e interface dos nós da lista duplamente encadeada

Estrutura do Projeto:

```project-folder/
├── BigNumber/
│   ├── bignumber.c
│   ├── bignumber.h
│   ├── node.c
│   ├── node.h
│   ├── client.c
│   ├── Makefile
│   └── README.MD
└──|
```

---

## Funcionalidades Implementadas Corretamente

- <b>printBigNum: </b> Função para imprimir um BigNumber na tela;
- <b>maiorBigNum: </b> Função retorna o maior número entre o modulos de dois números (retorno inteiro: 1- Num1 2-Num2 0-iguais);
- <b>parImpar:</b> Retorna se um número é par ou impar (Retorno inteiro: 1-Par 0-Impar);
- <b>verificaIgualdade:</b> Retorna se dois BigNumber são iguais (Retorno Inteiro: 1-Iguais 0-Diferentes);
- <b>copiaBigNumber: </b>Faz uma copia independente de um BigNumber;
- <b>removerZeros: </b>Remover zeros excedentes à esquerda do primeiro digito diferente de zero;
- <b>liberaMemoria: </b>Liberar a memória alocada para o armazenamento do BigNumber;

```c
void printBigNum(BigNumber lista);

int maiorBigNum(BigNumber num1, BigNumber num2);
int parImpar(BigNumber num);
int verificaIgualdade(BigNumber num1, BigNumber num2);

BigNumber copiaBigNumber(BigNumber num1);
void removerZeros(BigNumber num1);
void liberaMemoria(BigNumber lista);
```
Além das funções padrões de criação e leitura do objeto BigNum, o projeto possui  as implementações (Todas operações com números/operações inteiras):

- <b>Soma/Subtração +/- :</b> função para soma de dois BigNumber; função trata tanto casos positivos como negativos, relação de troca de parametro por sinal para Soma/Subtração;
- <b>Multiplicação * :</b> Função para multiplicação de dois Bignumber;
- <b>Divisão / :</b> Função para divisão Inteira (Com opção de retorno do quociente ou resto).
```c
BigNumber bigNumber();
BigNumber lerNumero();

void adicionaNumeroTail(BigNumber lista, Node n);
void adicionaNumeroHead(BigNumber lista, Node n);

BigNumber somar(BigNumber num1, BigNumber num2, char sign);
BigNumber multiplicar(BigNumber num1, BigNumber num2);
BigNumber dividir(BigNumber num1, BigNumber num2, int saida);
```
## Funcionalidades Extras

### Exemplos de funcionalidades:

- <b>Resto</b> : Algoritmo de Divisão calcula quociente e resto, retorno pela passagem de parãmetro (1- quociente, 2- resto);
- <b>Exponenciação Rápida</b> : Efetua exponenciação pelo método recursivo de exponenciação rápida;
- <b>Karatsuba</b> : Efetua multiplicação pelo método recursivo Karatsuba.

```c
BigNumber dividir(BigNumber num1, BigNumber num2, int saida);
BigNumber exponencial (BigNumber num1, BigNumber num2);
BigNumber karatsuba (BigNumber num1, BigNumber num2);
```

### Interface Client

Interface de manipulação do usuario para resolução de operações de forma continua (implementada em client.c). Faz a leitura de dois numeros e efetua uma operação perante o próximo caracter; pela análise de desempenho dos algoritmos foi escolhido permanecer com o algoritmo de multiplicação usual ao método Karatsuba (devido os diversos objetos criados para manipulação do BigNumber durante a execução do Karatsuba, o programa não obteve melhor desempenho comparado a função multipliação implementada):

```c
switch(caracter1){

      case '+':
        result = somar(num1,num2,'+');
        printBigNum(result);
        break;

      case '-':
        result = somar(num1,num2,'-');
        printBigNum(result);
        break;

      case '/':
        result = dividir(num1,num2,1);
        printBigNum(result);
        break;

      case '*':
        result = multiplicar(num1,num2);
        printBigNum(result);
        break;

      case '%':
        result = dividir(num1,num2,0);
        printBigNum(result);
        break;

      case '^':
        result = exponencial(num1,num2);
        printBigNum(result);
        break;

      case 'x':
        result = karatsuba(num1,num2);
        printBigNum(result);
        break;
}
```
