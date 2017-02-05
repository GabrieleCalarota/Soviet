#include "Node.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Inventario.hpp"
#include "Armor.hpp"
#include "Weapon.hpp"

 Node::Node(){
  x=0; 
  y=0; 
  right=NULL; 
  left=NULL; 
  up=NULL; 
  down=NULL; 
  med_pac=false; 
  armadietto=false; 
  enemy=NULL; 
  key=false;  
  head_weapons=NULL; 
  head_armature=NULL; 
  color_blue_river=false;}


 Node::Node(int coord_x,int coord_y){
  x=coord_x; 
  y=coord_y; 
  right=NULL; 
  left=NULL; 
  up=NULL; 
  down=NULL; 
  med_pac=false; 
  armadietto=false; 
  enemy=NULL; 
  key=false;  
  head_weapons=NULL; 
  head_armature=NULL; 
  color_blue_river=false;}
  
  
 void Node::change_med_pac(bool a) {med_pac=a;}
 bool Node::get_med_pac() {return med_pac;}


 bool Node::is_in_antidoto() {return antidoto;}
 void Node::change_antidoto(bool a) {antidoto=a;}


 bool Node::is_in_enemy() {return (enemy!=NULL);}
 Enemy* Node::get_enemy() {return enemy;}
 void Node::change_enemy(Enemy* m) {enemy=m;}


 int Node::get_x() {return x;}
 int Node::get_y() {return y;}

  
 bool Node::get_key() {return key;}
 void Node::change_key() {if (key) key=false; else key=true;}


 bool Node::is_in_weapon() {if (head_weapons==NULL) return false; else return true;}
 bool Node::is_in_armature() {if (head_armature==NULL) return false; else return true;}


 bool Node::is_in_weapon(Weapon* weapon){
  lista_weapons* tmp=head_weapons;
  bool flag=false;
  while ((tmp!=NULL)&&(!flag)){
   if (tmp->w->confronta(weapon))
    flag=true;
   else
    tmp=tmp->next;}
  return flag;}
  
 
 void Node::push_weapons(Weapon* weapon){
  lista_weapons* nhead=new lista_weapons;
  nhead->w=weapon;
  nhead->next=head_weapons;
  head_weapons=nhead;}
  

 Weapon* Node::pop_weapons(int number){
  lista_weapons* tmp=head_weapons;
  if (number==0){ 
   head_weapons=head_weapons->next; 
   Weapon* weapon=tmp->w;
   delete tmp;
   return weapon;}
  else{
   for (int i=0;((i<(number-1))&&(tmp->next!=NULL));i++) 
    tmp=tmp->next;
   lista_weapons* tmp2=tmp->next;
   tmp->next=tmp2->next;
   Weapon* weapon=tmp2->w;
   delete tmp2;
   return weapon;}}


 bool Node::is_in_armature(Armor* b){
  lista_armature* tmp=head_armature;
  bool flag=false;
  while ((tmp!=NULL)&&(!flag)){
   if (tmp->a->confronta(b))
    flag=true;
   else
    tmp=tmp->next;} 
  return flag;}
  
 
 void Node::push_armature(Armor* b){
  lista_armature* nhead=new lista_armature;
  nhead->a=b;
  nhead->next=head_armature;
  head_armature=nhead;}
  

 Armor* Node::pop_armature(int number){
  lista_armature* tmp=head_armature;
  if (number==0){ 
   head_armature=head_armature->next; 
   Armor* armor=tmp->a;
   delete tmp;
   return armor;}
  else{
   for (int i=0;(i<(number-1));i++) 
    tmp=tmp->next;
   lista_armature* tmp2=tmp->next;
   tmp->next=tmp2->next;
   Armor* armor=tmp2->a;
   delete tmp2;
   return armor;}}
   

 bool Node::print_weapons_list(int*num){
  bool equip=true;
  int i=0;
  lista_weapons* tmp=head_weapons;
  char lettera;
  do{
   clear_screen();
   cout<<"[Premi 'a' per scorrere indietro,'d' per scorrere avanti,'i' per le info,'e' per selezionare,'f' per uscire]\n"<<endl;
   tmp->w->print_name_and_ammos();
   lettera=getch();
   switch (lettera){
     case ('a'): {if (tmp==head_weapons){
                   i=0; 
                   while (tmp->next!=NULL){
                    tmp=tmp->next; 
                    i++;}} 
                  else{
                   lista_weapons* tmp2=head_weapons; 
                   while (tmp2->next!=tmp){
                    tmp2=tmp2->next;} 
                   tmp=tmp2; 
                   i--;} break;}
     case ('d'): {if (tmp->next==NULL){
                   tmp=head_weapons; 
                   i=0;} 
                  else{
                   tmp=tmp->next; 
                   i++;} break;}
     case ('i'): {tmp->w->print_scheda_arma(); 
                  getch(); break;}
     case ('e'): {*num=i; 
                  lettera='f'; break;}
     case ('f'): {equip=false; break;}
     default: {break;}}}
  while (lettera!='f');
  return equip;}


 bool Node::print_armature_list(int *num){  //bilista circolare con sentinella
  bool equip=true;
  int i=0;
  lista_armature* tmp=head_armature;
  char lettera;
  do{
   clear_screen();
   cout<<"[Premi 'a' per scorrere indietro,'d' per scorrere avanti,'i' per le info,'e' per selezionare,'f' per uscire]\n"<<endl;
   tmp->a->print_name_power_and_immunity();
   lettera=getch();
   switch (lettera){
     case ('a'): {if (tmp==head_armature){
                   i=0; 
                   while (tmp->next!=NULL){
                    tmp=tmp->next; 
                    i++;}}
                  else{
                   lista_armature* tmp2=head_armature; 
                   while (tmp2->next!=tmp){
                    tmp2=tmp2->next;} 
                   tmp=tmp2; 
                   i--;} break;}
     case ('d'): {if (tmp->next==NULL){
                   tmp=head_armature; 
                   i=0;} 
                  else{
                   tmp=tmp->next; 
                   i++;} break;}
     case ('i'): {tmp->a->print_armor_info(); 
                  getch(); break;}
     case ('e'): {*num=i; lettera='f'; break;}
     case ('f'): {equip=false; break;}
     default: {break;}}}
  while (lettera!='f');
  return equip;}
  

 void Node::pick_up_tools(Player* p){
  bool armi=true,armature=true;       
  if (is_in_weapon()||is_in_armature()){
   bool pick=true;
   while (pick){
    if (is_in_weapon()&&armi){
     clear_screen();
     int num;
     pick=print_weapons_list(&num);
     if (pick){
      Weapon* p_weapon=pop_weapons(num);
      bool flag2=true;
       if (p->is_in_weapon()){
        if (p->which_weapon()->confronta(p_weapon)){
         p->which_weapon()->merge(p_weapon); 
         flag2=false; 
         cout<<p_weapon->get_name()<<" refilled!\n";}}
       if (p->get_inventario()->is_in_weapons(p_weapon)){
        p->get_inventario()->push_weapons(p_weapon);
        cout<<p_weapon->get_name()<<" refilled!\n"; 
        flag2=false;}
       if (flag2){ 
        if (p->get_inventario()->light_enough(p_weapon->get_weight())){
         p->get_inventario()->push_weapons(p_weapon); 
         cout<<p_weapon->get_name()<<" in inventario!\n";}
        else{
         cout<<p_weapon->get_name()<<" è troppo pesante per il tuo inventario!\n";
          push_weapons(p_weapon);}}
       sleep(1);}}
    else 
     pick=false;}
   pick=true;
   while (pick){
    if (is_in_armature()&&armature){
     clear_screen();
     int num;
     pick=print_armature_list(&num);
     if (pick){
      Armor* p_armor=pop_armature(num);
      bool flag2=true; 
      if (p->is_in_armor()){
       if (p->which_armor()->confronta(p_armor)){
        flag2=false; 
        p->which_armor()->merge(p_armor);}}
      if (p->get_inventario()->is_in_armature(p_armor)){
       cout<<p_armor->get_name()<<" refilled!\n";
       p->get_inventario()->push_armor(p_armor);
       flag2=false;} 
      if (flag2){
       if (p->get_inventario()->light_enough(p_armor->get_weight()) ){ 
        p->get_inventario()->push_armor(p_armor);
        cout<<p_armor->get_name()<<" in inventario ora!\n";}
       else{
        cout<<"Con "<<p_armor->get_name()<<" diventeresti troppo pesante!\n"; 
        push_armature(p_armor);}}
      sleep(1);}}
    else pick=false;}}} 


 void Node::change_x(int num) {x=num;}
 void Node::change_y(int num) {y=num;}


 Node* Node::getnode_l() {return left;}
 Node* Node::getnode_r() {return right;}
 Node* Node::getnode_u() {return up;}
 Node* Node::getnode_d() {return down;}


 void Node::change_node_r(Node* node) {this->right=node;}
 void Node::change_node_l(Node* node) {this->left=node;}
 void Node::change_node_u(Node* node) {this->up=node;}
 void Node::change_node_d(Node* node) {this->down=node;}


 bool Node::get_color_blue() {return color_blue_river;}
 void Node::insert_color_blue() {color_blue_river=true;}


 bool Node::get_armadietto() {return armadietto;}
 void Node::change_armadietto(bool a) {armadietto=a;}



