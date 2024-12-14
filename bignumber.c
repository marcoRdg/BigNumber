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

BigNumber bigNumber(Node first, char sign){
  BigNumber novoBig = malloc(sizeof(struct bigNumber));
  novoBig->sign = sign;
  novoBig->head = first;
  novoBig->tail = first;
  novoBig->qtd=1;
  return novoBig;
}

void adicionaNumero(BigNumber lista, Node n){
  n->prev = lista->tail;
  lista->tail->next = n;
  lista->tail = n;
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
  printf("%c", lista->sign);
  printCadeiaNo(lista->head);
  printf("\n");
}


int main(){
 
  BigNumber num = bigNumber(node(5),'+');
  adicionaNumero(num, node(5));
  adicionaNumero(num, node(5));
  adicionaNumero(num, node(7));
  BigNumber num2 = bigNumber(node(5),'-');
  adicionaNumero(num2, node(5));
  adicionaNumero(num2, node(5));
  adicionaNumero(num2, node(7));
  printBigNum(num);
  printBigNum(num2);
  return 0;
}


