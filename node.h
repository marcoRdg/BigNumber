#ifndef NODE_H
#define NODE_H

typedef struct node* Node;

struct node {
  Node prev;
  int data;
  Node next;
};

Node node(int data);

int printCadeiaNo(Node no);

#endif