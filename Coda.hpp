#ifndef CODA_HPP_
#define CODA_HPP_
class Node;

class Coda{
 protected:
  int dimensione;
  int testa;
  int n;
  Node** a;
 public:
  Coda(int,int,int,Node**);
  Coda* Enqueue(Node*);
  Node* Dequeue();
  bool Is_Empty();
};
#endif
