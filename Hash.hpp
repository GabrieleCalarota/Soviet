#ifndef HASH_HPP_
#define HASH_HPP_

#include "MyLibrary.hpp"

class Node;

 class Hash{
  protected:
   int dimensione;
   int dim_attuale;
   struct tab{bool is_in; int x;int y; Node* node;};
   tab* a;
   int costante;
   int scansione_secondaria(int,int,int);
   int doppio_hash(int,int);
   void Copy(tab*,int);
   int generate_key(int,int);
  public:
   Hash(int,int);
   Hash* Hash_Insert(int,int,Node*);
   bool Look_Up(int,int);
   Node* get_node(int,int);
};
#endif
