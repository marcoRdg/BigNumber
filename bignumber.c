#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


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
    }while(a->prev!=NULL || b->prev!=NULL);
    return 0;
  }
}

BigNumber somar(BigNumber num1, BigNumber num2, char sign){

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
      return result;
    }else{
      
      adicionaNumeroTail(result, node(0));
      return result;
    }
  }
  return 0;
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

void liberaMemoria(BigNumber lista){
  Node atual = lista->head;
  while(atual!=NULL){
    Node aux = atual;
    atual = atual->next;
    free(aux);
  }
  free(lista);
}

BigNumber lerNumero(){

  BigNumber num1 = bigNumber();
  char caracter1;
  caracter1 = getchar();
  
  if(caracter1=='\n'){
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

void lerEquacao(){
  
  char caracter1='0';
  
  while(1){
    
    BigNumber num1 = lerNumero();
    if(num1==NULL){
      break;
    }
    BigNumber num2 = lerNumero();
    //printBigNum(num1);
    //printBigNum(num2);

    BigNumber result = bigNumber();
    
    
    
    caracter1 = getchar();
    getchar();

    
    switch(caracter1){
      case '+':
        result = somar(num1,num2,'+');
        removerZeros(result);
        printBigNum(result);
        break;
      case '-':
        result = somar(num1,num2,'-');
        removerZeros(result);
        printBigNum(result);
        break;
      case '/':
        //result = somar(num1,num2);
        break;
      case '*':
        //result = somar(num1,num2);
        break;
    }
    
    liberaMemoria(num1);
    liberaMemoria(num2);
    liberaMemoria(result);
    
    
    
   
    
  }
}

int main(){
  
  lerEquacao();
  return 0;
}


