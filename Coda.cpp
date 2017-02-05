#include "Coda.hpp"
#include "Node.hpp"

 Coda::Coda(int dim,int head, int dim_attuale,Node** b){	
  testa=0;
  n=dim_attuale;
  dimensione=dim;
  a=(new Node*[dim]);
  for (int i=0; i<dim_attuale; i++) 
   a[i]=b[(head+i)%dim_attuale];}

   
 Coda* Coda::Enqueue(Node* v){//n<dimensione			
  if (n>=dimensione){
   Coda* tmp=new Coda(2*dimensione,testa,n,a);
   tmp=tmp->Enqueue(v);
   delete this;
   return tmp;}
  else{
   a[(testa+n)%dimensione]=v;
   n=n+1;
   return this;}}

   
 Node* Coda::Dequeue(){ 					
  Node* t=a[testa];
  testa=((testa+1)%dimensione);
  n=n-1;
  return t;}

  
 bool Coda::Is_Empty(){						
  return (n==0);}
