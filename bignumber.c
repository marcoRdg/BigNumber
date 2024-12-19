#include <stdio.h>
#include <stdlib.h>

#include "bignumber.h"

BigNumber bigNumber(){
  BigNumber novoBig = malloc(sizeof(struct bigNumber));
  novoBig->sign = '+';
  novoBig->head = NULL;
  novoBig->tail = NULL;
  novoBig->qtd=0;
  return novoBig;
}

void adicionaNumeroTail(BigNumber lista, Node n){
  if(lista->head==NULL){
    lista->head = n;
    lista->tail = n;
    lista->qtd+=1;
  }else{
    n->prev = lista->tail;
    lista->tail->next = n;
    lista->tail = n;
    lista->qtd+=1;
  }
  
}

void adicionaNumeroHead(BigNumber lista, Node n){
  if(lista->head==NULL){
    lista->head=n;
    lista->tail =n;
    lista->qtd+=1;
  }else{
    n->next = lista->head;
    lista->head->prev = n;
    lista->head = n;
    lista->qtd+=1;
  }
  
}

void printBigNum(BigNumber lista){
  //printf("Num Digitos:%d\n", lista->qtd);
  lista->sign=='-'?printf("%c", lista->sign):0;
  printCadeiaNo(lista->head);
  printf("\n");
}

int maiorBigNum(BigNumber num1, BigNumber num2){
  if (num1->qtd>num2->qtd){
   return 1;
    
  }else if(num2->qtd>num1->qtd){
    return 2;
  }else{
    Node a = num1->head;
    Node b = num2->head;
    do{
      if((a->data>b->data) || (a != NULL && b == NULL)){
        return 1;
      }else if((a->data<b->data) || (b !=NULL && a == NULL)){
        return 2;
      }
      a=a->next;
      b=b->next;
    //}while(a->prev!=NULL || b->prev!=NULL);
    }while(a!=NULL || b!=NULL);
    return 0;
  }
}

void removerZeros(BigNumber num1){
  Node no = num1->head;
  while(no != NULL && no->data == 0 && no->next != NULL){
    Node aux = no;
    no = no->next;
    no->prev = NULL;
    free(aux);
    num1->qtd-=1;
    num1->head=no;
  }

}

BigNumber copiaBigNumber(BigNumber num1){
  BigNumber copia = bigNumber();
  Node no = num1->head;

  while(no){
    adicionaNumeroTail(copia, node(no->data));
    no=no->next;
  }

  copia->sign = num1->sign;
  return copia;
}

void liberaMemoria(BigNumber lista){
  Node atual = lista->head;
  while(atual!=NULL){
    Node aux = atual;
    atual = atual->next;
    free(aux);
  }
  free(lista);
}

BigNumber somar(BigNumber num1, BigNumber num2, char sign){

  char sinal1=num1->sign;
  char sinal2=num2->sign;

  Node numero1 = num1->tail;
  Node numero2 = num2->tail;
  
  int aux =0;
  BigNumber result = bigNumber();
  
  num2->sign = (sign==num2->sign) ? '+':'-';
  
  if(num1->sign==num2->sign){
    result->sign = num1->sign;
    while(numero1!=NULL || numero2!=NULL||aux!=0){
    
      int valor1 = (numero1 != NULL) ? numero1->data:0;
      int valor2 = (numero2 != NULL) ? numero2->data:0;
      
      int soma = valor1+valor2+aux;
      aux = soma/10;
      
      soma = soma%10;
      
      
      adicionaNumeroHead(result,node(soma));
      
      if(numero1!=NULL) numero1=numero1->prev;
      if(numero2!=NULL) numero2=numero2->prev;
    }
    num1->sign=sinal1;
    num2->sign=sinal2;
    removerZeros(result);
    return result;
  
  }else{
    int maior = maiorBigNum(num1,num2);
    if (maior==1){
      result->sign = num1->sign;
      while(numero1!=NULL || numero2!=NULL||aux!=0){
        int soma=0;
        int valor1 = (numero1 != NULL) ? numero1->data:0;
        int valor2 = (numero2 != NULL) ? numero2->data:0;
        if(valor1>=valor2){
          soma = valor1-valor2;
        }else{
          numero1->prev->data = numero1->prev->data-1;
          soma = (valor1+10)-valor2;
          //printf("%d",soma);
        }
        
        adicionaNumeroHead(result,node(soma));
        
        if(numero1!=NULL) numero1=numero1->prev;
        if(numero2!=NULL) numero2=numero2->prev;
      }
      num1->sign=sinal1;
      num2->sign=sinal2;

      removerZeros(result);
      return result;
  
    }else if (maior ==2){
      result->sign = num2->sign;
      while(numero1!=NULL || numero2!=NULL||aux!=0){
        int soma=0;
        int valor1 = (numero1 != NULL) ? numero1->data:0;
        int valor2 = (numero2 != NULL) ? numero2->data:0;
        if(valor2>=valor1){
          soma = valor2-valor1;
        }else{
          numero2->prev->data = numero2->prev->data-1;
          soma = (valor2+10)-valor1;
          //printf("%d",soma);
        }
        
        adicionaNumeroHead(result,node(soma));
        
        if(numero1!=NULL) numero1=numero1->prev;
        if(numero2!=NULL) numero2=numero2->prev;
      }
      num1->sign=sinal1;
      num2->sign=sinal2;

      removerZeros(result);
      return result;
    }else{
      
      adicionaNumeroTail(result, node(0));
      num1->sign=sinal1;
      num2->sign=sinal2;

      removerZeros(result);
      return result;
    }
  }
  num1->sign=sinal1;
  num2->sign=sinal2;
  return 0;
}

BigNumber multiplicar(BigNumber num1, BigNumber num2) {

  if (((num1->head == num1->tail) && num1->head->data == 0) || 
      ((num2->head == num2->tail) && num2->head->data == 0)) {
    BigNumber result = bigNumber();
    adicionaNumeroTail(result, node(0));

    removerZeros(result);
    return result;
  }

  char sinal = (num1->sign == num2->sign) ? '+' : '-';
  num1->sign = num2->sign = '+';

  BigNumber result = bigNumber();
  adicionaNumeroTail(result, node(0));

  Node n2 = num2->tail;
  int shift = 0;

  while (n2 != NULL) {
    BigNumber temp = bigNumber();
    for (int i = 0; i < shift; i++) {
      adicionaNumeroTail(temp, node(0));
    }

    int aux = 0;
    Node n1 = num1->tail;

    while (n1 != NULL) {
      int product = n1->data * n2->data + aux;
      aux = product / 10;
      adicionaNumeroHead(temp, node(product % 10));
      //printBigNum(temp);
      n1 = n1->prev;
    }

    if (aux > 0) {
      adicionaNumeroHead(temp, node(aux));
    }

    BigNumber newResult = somar(result, temp, '+');
    liberaMemoria(result);
    liberaMemoria(temp);
    result = newResult;

    n2 = n2->prev;
    shift++;
  }

  removerZeros(result);
  result->sign = sinal;

  removerZeros(result);
  return result;
}

BigNumber dividir(BigNumber num1, BigNumber num2, int saida) {
    if (num2->qtd == 1 && num2->head->data == 0 && saida==1) {
      BigNumber result = bigNumber();
      adicionaNumeroTail(result, node(0));

      removerZeros(result);
      return result;
    }

    if (num2->qtd == 1 && num2->head->data == 0 && saida==1) {
      BigNumber result = bigNumber();
      adicionaNumeroTail(result, node(0));

      removerZeros(result);
      return result;
    }

    BigNumber quociente = bigNumber();
    BigNumber resto = bigNumber();
    Node atual = num1->head;

    quociente->sign = (num1->sign == num2->sign) ? '+' : '-';

    num1->sign='+';
    num2->sign='+';

    BigNumber aux;

    while (atual) {
        
        adicionaNumeroTail(resto, node(atual->data));
        removerZeros(resto);

        int contador = 0;
        while (maiorBigNum(resto, num2)<2) {
            aux = resto;
            resto = somar(resto, num2, '-'); 
            removerZeros(resto);
            contador++;

            liberaMemoria(aux);
            //printf("teste");
        }

        adicionaNumeroTail(quociente, node(contador));
        atual = atual->next;
    }

    removerZeros(quociente);
    if(quociente->qtd==1 && quociente->head->data==0){
      quociente->sign='+';
    }
    if(saida==1){

      liberaMemoria(resto);

      removerZeros(quociente);
      return quociente;

    }else{

      liberaMemoria(quociente);

      removerZeros(resto);
      return resto;
    }
    
}

BigNumber lerNumero(){

  BigNumber num1 = bigNumber();
  char caracter1;
  caracter1 = getchar();
  
  if(caracter1==-1){
    liberaMemoria(num1);
    return NULL;
  }
  
    if (caracter1=='-' || caracter1=='+'){
      num1->sign =caracter1;
      caracter1 = getchar();
    }
    while(caracter1!='\n'){
      adicionaNumeroTail(num1,node(caracter1-'0'));
      caracter1 = getchar();
      
    }

    return num1;
}



