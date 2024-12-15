#include <stdio.h>
#include <stdlib.h>

typedef struct node* Node;
typedef struct bigNumber* BigNumber;

struct node {
  Node prev;
  int data;
  Node next;
};

struct bigNumber {
  Node head;
  Node tail;
  int qtd;
  char sign;
};

Node node(int data){
  Node n = malloc(sizeof(struct node));
  n->data = data;
  n->next = NULL;
  n->prev = NULL;
  return n;
}

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

int printCadeiaNo(Node no){
  if (no->next!=NULL){
    printf("%d", no->data);
    printCadeiaNo(no->next);
  }else{
    printf("%d", no->data);
    return 0;
  }
  return 0;
}

void printBigNum(BigNumber lista){
  printf("Num Digitos:%d\n", lista->qtd);
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
      if(a->data>b->data){
        return 1;
      }else if(a->data<b->data){
        return 2;
      }
      a=a->next;
      b=b->next;
    }while(a->next!=NULL);
    return 0;
  }
}

BigNumber soma(BigNumber num1, BigNumber num2){

  Node numero1 = num1->tail;
  Node numero2 = num2->tail;
  
  int aux =0;
  BigNumber result = bigNumber();
  
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
          numero2->prev->data = numero2->prev->data-1;
          soma = (valor1+10)-valor2;
          printf("%d",soma);
        }
        
        
        
        adicionaNumeroHead(result,node(soma));
        
        if(numero1!=NULL) numero1=numero1->prev;
        if(numero2!=NULL) numero2=numero2->prev;
      }
      return result;
  
      
    }else if (maior ==2){
    }else{
      
      adicionaNumeroTail(result, node(0));
      return result;
    }
  }
  return 0;
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

int main(){
 
  BigNumber num = bigNumber();
  num->sign = '-';
  adicionaNumeroTail(num, node(5));
  adicionaNumeroTail(num, node(5));
  adicionaNumeroTail(num, node(7));
  adicionaNumeroTail(num, node(7));
  adicionaNumeroTail(num, node(7));
  adicionaNumeroTail(num, node(7));
  adicionaNumeroTail(num, node(7));
  adicionaNumeroTail(num, node(7));
  adicionaNumeroTail(num, node(7));
  adicionaNumeroTail(num, node(7));
  adicionaNumeroTail(num, node(7));
  BigNumber num2 = bigNumber();
  num2->sign = '-';
  adicionaNumeroTail(num2, node(5));
  adicionaNumeroTail(num2, node(0));
  adicionaNumeroTail(num2, node(7));
  printBigNum(num);
  printBigNum(num2);
  printBigNum(soma(num,num2));
  
  printBigNum(num2);
  adicionaNumeroHead(num2, node(7));
  printBigNum(num2);
  printf("%d", maiorBigNum(num,num2));
  printf("%d", maiorBigNum(num2,num2));
  BigNumber num3 = bigNumber();
  adicionaNumeroHead(num3, node(7));
  adicionaNumeroHead(num3, node(7));
  adicionaNumeroHead(num3, node(3));
  printBigNum(num3);
  liberaMemoria(num);
  liberaMemoria(num2);
  liberaMemoria(num3);
  return 0;
}


