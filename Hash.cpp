#include "Hash.hpp"
#include "Node.hpp"


 Hash::Hash(int dim,int cost){
  costante=cost;
  dim_attuale=0;
  a=new tab[dim];
  for (int i=0;i<dim;i++)
   a[i].is_in=false;
  dimensione=dim;}


 int Hash::scansione_secondaria(int key,int x,int y){ //funzione quadratica secondaria (SECONDARY CLUSTERING) k=[(h(k)+h*(i^2))]
 int i=1;
 int h=doppio_hash(x,y);
 int k=( (key+(i*i*costante)) % dimensione );
 while (a[k].is_in){
  i++;
  k=( (key+(i*i*costante)) % dimensione );}
 return k;}

 
 int Hash::doppio_hash(int x,int y){
  x=x+costante;
  y=y+costante;
  return (x*y);}



 void Hash::Copy(tab* prov,int n_prov){
  dim_attuale=0;
  for (int i=0;i<n_prov;i++){
   if (prov[i].is_in){
    dim_attuale++;
    int key=generate_key(prov[i].x,prov[i].y);
    key=key%dimensione;
    if (a[key].is_in){ 
     int new_key=scansione_secondaria(key,prov[i].x,prov[i].y);
     a[new_key].is_in=true;
     a[new_key].x=prov[i].x;
     a[new_key].y=prov[i].y; 
     a[new_key].node=prov[i].node;}
    else{
     a[key].is_in=true;
     a[key].x=prov[i].x;
     a[key].y=prov[i].y;
     a[key].node=prov[i].node;}}}}


 int Hash::generate_key(int x,int y){
  int h=y+costante;
  int k=x+costante;
  int i=1;
  while (h>9){h=h/10; i++;}
  for (int j=0;j<i;j++) k=k*10;
  return (k+h) ;}


 Hash* Hash::Hash_Insert(int x,int y,Node* s){
  if ((x<(-1*costante))||(y<(-1*costante))){
   Hash* tmp=new Hash(dimensione,2*costante);
   tmp->Copy(a,dimensione);
   tmp=tmp->Hash_Insert(x,y,s);
   return tmp;}
  else{
   int key=generate_key(x,y);
   key=key%dimensione;
   if (a[key].is_in){
    key=scansione_secondaria(key,x,y);}
   a[key].is_in=true;
   a[key].x=x;
   a[key].y=y;
   a[key].node=s;
   dim_attuale++;
   if (dim_attuale>=(dimensione/3)){
    Hash* tmp=new Hash(2*dimensione,costante);
    tmp->Copy(a,dimensione);
    return tmp;}
   else {
  return this;}}}


 bool Hash::Look_Up(int x,int y){
  if ((x< (-1*costante)) || (y<(-1*costante))){
   return false;}
  else{
   int key=generate_key(x,y);
   key=key%dimensione;
   if (!a[key].is_in){
    return false;}
   else{
    if ((a[key].x==x)&&(a[key].y==y)){ return true;}
    else{ 
     int i=1;
     int h=doppio_hash(x,y);
     int k=((key+(i*i*costante))%dimensione);  
     while ((a[k].is_in)&&((a[k].x!=x)||(a[k].y!=y))){
      i++;
      k=((key+(i*i*costante))%dimensione);}
     return a[k].is_in;}}}}


 Node* Hash::get_node(int x,int y){
  int key=generate_key(x,y);
  key=key%dimensione;
  if ((a[key].x==x)&&(a[key].y==y)){ 
   return a[key].node;}
  else{  
   int i=1;
   int h=doppio_hash(x,y);
   int k=((key+(i*i*costante))%dimensione);
   while ((a[k].is_in)&&((a[k].x!=x)||(a[k].y!=y))){
    i++;
    k=((key+(i*i*costante))%dimensione);}
   return a[k].node;}}
