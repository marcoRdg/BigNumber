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

int main(){
  Node novoNo = node(5);
  BigNumber novoBigNumber = bigNumber(novoNo,'+');
  printf("%d\n",  novoBigNumber->head->data);
  return 0;
}


