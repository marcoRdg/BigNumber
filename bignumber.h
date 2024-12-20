#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#include "node.h"

typedef struct bigNumber* BigNumber;

struct bigNumber {
  Node head;
  Node tail;
  int qtd;
  char sign;
};

BigNumber bigNumber();
BigNumber lerNumero();

void adicionaNumeroTail(BigNumber lista, Node n);
void adicionaNumeroHead(BigNumber lista, Node n);

void printBigNum(BigNumber lista);

int maiorBigNum(BigNumber num1, BigNumber num2);

int parImpar(BigNumber num);

int verificaIgualdade(BigNumber num1, BigNumber num2);

BigNumber copiaBigNumber(BigNumber num1);

void liberaMemoria(BigNumber lista);

BigNumber somar(BigNumber num1, BigNumber num2, char sign);
BigNumber multiplicar(BigNumber num1, BigNumber num2);
BigNumber dividir(BigNumber num1, BigNumber num2, int saida);
BigNumber exponencial (BigNumber num1, BigNumber num2);

#endif



