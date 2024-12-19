#include <stdio.h>
#include <stdlib.h>

#include "node.h"

Node node(int data){
  Node n = malloc(sizeof(struct node));
  n->data = data;
  n->next = NULL;
  n->prev = NULL;
  return n;
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