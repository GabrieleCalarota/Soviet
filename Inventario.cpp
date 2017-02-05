
#include "Inventario.hpp"
#include "Letters.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
#include "Player.hpp"
#include "Node.hpp"
#include "Database.hpp"

 Inventario::Inventario(){ 						
  med_pack=0; 
  weight=0; 
  keys=0; 
  adrenaline=0; 
  max_weight=0; 
  head_weapons=NULL; 
  head_armature=NULL; 
  indice_docs=-1; 
  indice_docs_letti=0;
  MAX_ADRENALINE=0;
  MAX_MED_KIT=0;
  antidoti=0;
  oggetti[0].name="CONSUMABILI";
  oggetti[0].usa=true;
  oggetti[1].name="GRIMALDELLI";
  oggetti[1].scritta=prestabilita;
  oggetti[2].name="DOCUMENTI";
  oggetti[2].usa=true;
  oggetti[2].max=10;
  oggetti[3].name="CREATURE";
  oggetti[3].max=10;
  oggetti[4].name="ARMI";
  oggetti[4].scritta="[Premi 'a' per scorrere indietro, 'd' per scorrere avanti, 'e' per scorrere le armi, 'p' per vedere le statistiche, 'f' per uscire]\n";
  oggetti[5].name="ARMATURE";
  oggetti[5].scritta="[Premi 'a' per scorrere indietro, 'd' per scorrere avanti, 'e' per scorrere le armature, 'p' per vedere le statistiche, 'f' per uscire]\n";
  MAX_ANTIDOTI=0;
  for (int i=0;i<max_letter;i++) 
   doc[i].read=false;
  strcpy(doc[0].s,letter_1);
  strcpy(doc[1].s,letter_2);
  strcpy(doc[2].s,letter_3);
  strcpy(doc[3].s,letter_4);
  strcpy(doc[4].s,letter_5);
  strcpy(doc[5].s,letter_6);
  strcpy(doc[6].s,letter_7);
  strcpy(doc[7].s,letter_8);
  strcpy(doc[8].s,letter_9);
  strcpy(doc[9].s,letter_10);}


 void Inventario::leggi_lettera(){
  clear_screen();
  bool esc=false;
  int n=indice_docs;
  if (n<0){
   slow_print((char*)"Nessuna lettera trovata"); cout<<endl<<endl<<"(Premi un tasto per continuare..)\n"; getch(); esc=true;}
  int i=0;
  while ((doc[i].read)&&(i<n)) 
   i++;
  while (!esc){
   cout<<prestabilita<<"\n\n\n";
   if (!doc[i].read){ 
    slow_print(doc[i].s); 
    indice_docs_letti++;}
   else 
    cout<<doc[i].s;
   doc[i].read=true;
   char c=getch();
   switch (c){
     case ('d'):{i++; if (i>n) i=0; break;}
     case ('a'):{i--; if (i<0) i=indice_docs; break;}
     case ('f'):{esc=true; break;}
     default:{esc=false; break;}}
   clear_screen();}}

   
 bool Inventario::task_2() {return (doc[0].read&&doc[1].read);}		//CONTROLLO MISSIONE 2
 bool Inventario::no_more_letter() {return (indice_docs==max_letter);}
 int Inventario::get_indice_doc() {return indice_docs;}
 void Inventario::inc_indice_doc() {indice_docs++;}
 int Inventario::get_indice_docs_letti() {return indice_docs_letti;} 
 
 
 int Inventario::get_med_pack() {return med_pack;}
 void Inventario::inc_med_pack() {cout<<"Hai trovato un kit di pronto soccorso\n"; if (med_pack<MAX_MED_KIT) med_pack++;}
 void Inventario::dec_med_pack() {if (med_pack>0){cout<<"Hai utilizzato un kit di pronto soccorso\n";  med_pack--;}}
 bool Inventario::more_med_pack() {return (med_pack>0);} 
 
 
 int Inventario::get_keys() {return keys;}
 void Inventario::dec_keys() { keys--;}
 void Inventario::inc_keys() {cout<<"Hai trovato un <Grimaldello Esplosivo>\n"; keys++;}
 bool Inventario::more_keys() {return (keys>0);} 
 
 
 bool Inventario::more_adrenaline() {return (adrenaline>0);}
 void Inventario::inc_adrenaline() {cout<<"Fiala di adrenalina guadagnata\n"; adrenaline++;}
 void Inventario::dec_adrenaline() {cout<<"Hai utilizzato una fiala di adrenalina\n"; adrenaline--;}
 int Inventario::get_adrenaline() {return adrenaline;}


 bool Inventario::more_antidoti(){return (antidoti>0);}
 int Inventario::get_antidoti(){return antidoti;}
 void Inventario::inc_antidoti(){if (!full_antidoti()) {cout<<"Hai trovato un antidoto contro il veleno\n"; antidoti++;}}
 void Inventario::dec_antidoti(){if (more_antidoti()){cout<<"Hai utilizzato un antidoto contro il veleno\n"; antidoti--;}}
 bool Inventario::full_antidoti(){return (antidoti>=MAX_ANTIDOTI);}
 int Inventario::get_max_antidoti(){return MAX_ANTIDOTI;}
 void Inventario::change_max_antidoti(Player* p){MAX_ANTIDOTI=1+((p->get_endurance()*2-(p->get_luck()/2))/((double)10)*1); }
 

 void Inventario::change_max_weight(Player* p) {max_weight=(p->get_strength()+p->get_level())*3/2;}
 int Inventario::get_max_weight(){return max_weight;}
 int Inventario::get_current_weight() {return weight;}
 

 bool Inventario::full_med_pack() {return (med_pack>=MAX_MED_KIT);}
   

 void Inventario::change_max_medpack(Player* p){
  MAX_MED_KIT=10+(p->get_intelligence()+p->get_endurance()/p->get_luck());}


 bool Inventario::full_adrenaline() {return (adrenaline>=MAX_ADRENALINE);}
  

 void Inventario::change_max_adrenaline(Player* p){
  MAX_ADRENALINE=7+(p->get_intelligence()+p->get_endurance()/p->get_luck());}
  

 int Inventario::get_max_adrenaline() {return MAX_ADRENALINE;}
 

 int Inventario::get_max_medpack() {return MAX_MED_KIT;}
 

 bool Inventario::is_in_weapons(Weapon* weapon){
  lista_weapons* tmp=head_weapons;
  bool flag=false;
  while ((tmp!=NULL)&&(!flag)){
   if (tmp->w->confronta(weapon)) 
    flag=true;
   else 
    tmp=tmp->next;}
  return flag;}

  
 bool Inventario::is_in_armature(Armor* armor){
  lista_armature* tmp=head_armature;
  bool flag=false;
  while ((tmp!=NULL)&&(!flag)){
   if (tmp->a->confronta(armor)) 
    flag=true;
   else 
    tmp=tmp->next;}
  return flag;}
  

 void Inventario::push_weapons(Weapon* weapon){
  if (is_in_weapons(weapon)){ 
   lista_weapons* tmp=head_weapons; 
   while (!tmp->w->confronta(weapon)) 
    tmp=tmp->next; 
   tmp->w->merge(weapon);}
  else{
   lista_weapons* nhead=new lista_weapons;
   nhead->w=weapon;
   weight+=weapon->get_weight();
   nhead->next=head_weapons;
   head_weapons=nhead;}}


 Weapon* Inventario::pop_weapons(int number){
  lista_weapons* tmp=head_weapons;
  if (number==0){ 
   head_weapons=head_weapons->next; 
   Weapon* weapon=tmp->w; 
   weight-=weapon->get_weight();
   delete tmp;
   return weapon;}
  else{
   for (int i=0;((i<(number-1))&&(tmp->next!=NULL));i++) 
    tmp=tmp->next;
   lista_weapons* tmp2=tmp->next;
   tmp->next=tmp2->next;
   Weapon* weapon=tmp2->w;
   weight-=weapon->get_weight();
   delete tmp2;
   return weapon;}}


 bool Inventario::light_enough(int a) {return ((a+weight)<=max_weight);}
 
 
 void Inventario::print_weapons_list(Player* p,Node* position){
  bool equip=true;
  int i=0;
  lista_weapons* tmp=head_weapons;
  char lettera;
  do{
   clear_screen();
   cout<<"[Premi 'a' per scorrere indietro,'d' per scorrere avanti,'i' per le info,'e' per equipaggiare,'l' per lasciare,'f' per uscire]\n"<<endl;
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
                   while (tmp2->next!=tmp)
                    tmp2=tmp2->next; 
                   tmp=tmp2; i--;} break;}
     case ('d'): {if (tmp->next==NULL) {
                    tmp=head_weapons; 
                     i=0;}
                  else {
                     tmp=tmp->next;  
                     i++;} 
                   break;}
     case ('i'): {tmp->w->print_scheda_arma(); getch(); break;}
     case ('e'): { Weapon *w=pop_weapons(i);
                   if (tmp->next==NULL) {
                      tmp=head_weapons; 
                      i=0;} 
                   else {
                      tmp=tmp->next; 
                      i++;} 
                   if (!p->is_in_weapon())
                     p->change_weapon(w);
                   else{
                       if (light_enough(p->which_weapon()->get_weight()))
                          push_weapons(p->which_weapon());
                       else{
                         Armor *a=p->which_armor();
                         p->change_armor(NULL);
                         p->unequip(position);
                         p->change_armor(a);}
                        p->change_weapon(w);} 
                   cout<<"Hai equipaggiato "<<(w->get_name())<<"!\n";
                   p->set_overload();
                   equip=false; 
                   break;}
     case ('l'): { Weapon *w=pop_weapons(i);
                   tmp=head_weapons;
                   i=0; 
                   position->push_weapons(w);
                   cout<<"Hai lasciato "<<w->get_name()<<endl;
                   break;}
     case ('f'): { equip=false; break;}}
   if (!more_weapons())
      equip=false;}
  while (equip);}


 void Inventario::print_armature_list(Player* p, Node* position){  
  bool equip=true;
  int i=0;
  lista_armature* tmp=head_armature;
  char lettera;
  do{
   clear_screen();
   cout<<"[Premi 'a' per scorrere indietro,'d' per scorrere avanti,'i' per le info,'e' per equipaggiare,'l' per lasciare,'f' per uscire]\n"<<endl;
   tmp->a->print_name_power_and_immunity();
   lettera=getch();
   switch (lettera){
     case ('a'): {if (tmp==head_armature){
                   i=0; 
                   while (tmp->next!=NULL){
                    tmp=tmp->next; i++;}} 
                  else{ 
                   lista_armature* tmp2=head_armature; 
                   while (tmp2->next!=tmp)
                    tmp2=tmp2->next;
                   tmp=tmp2; 
                   i--;} break;}
     case ('d'): {if (tmp->next==NULL) {tmp=head_armature; i=0;} else {tmp=tmp->next; i++;} break;}
     case ('i'): {tmp->a->print_armor_info(); getch(); break;}
          case ('e'):{ Armor *a=pop_armor(i);
                     if (tmp->next==NULL) {
                      tmp=head_armature; 
                      i=0;} 
                   else {
                      tmp=tmp->next; 
                      i++;} 
                   if (p->which_armor()==NULL)
                     p->change_armor(a);
                   else{
                       if (light_enough(p->which_armor()->get_weight()))
                          push_armor(p->which_armor());
                       else{
                         Weapon *w=p->which_weapon();
                         p->change_weapon(NULL);
                         p->unequip(position);
                         p->change_weapon(w);}
                        p->change_armor(a);} 
                   cout<<"Hai equipaggiato "<<(a->get_name())<<"!\n";
                   p->set_overload();
                   equip=false; 
                   break;}
     case ('l'): { Armor *a=pop_armor(i);
                   tmp=head_armature;
                   i=0;
                   position->push_armature(a);
                   cout<<"Hai lasciato "<<a->get_name()<<endl;
                   break;}
     case ('f'): { equip=false; break;}}
   if (!more_armor())
      equip=false;}
  while (equip);}


 bool Inventario::more_weapons() {if (head_weapons!=NULL) return true; else return false;}


 void Inventario::push_armor(Armor* b){
  if (!is_in_armature(b)){
   lista_armature* nhead=new lista_armature;
   nhead->a=b;
   nhead->next=head_armature;
   weight+=b->get_weight();
   head_armature=nhead;}
  else{
   lista_armature* tmp=head_armature;
   while (!tmp->a->confronta(b)) 
    tmp=tmp->next; 
   tmp->a->merge(b);}}


 Armor* Inventario::pop_armor(int number){
  lista_armature* tmp=head_armature;
  if (number==0){ 
   head_armature=head_armature->next; 
   Armor* armor=tmp->a; weight-=armor->get_weight();
   delete tmp;
   return armor;}
  else{
   for (int i=0;(i<(number-1));i++) 
    tmp=tmp->next;
   lista_armature* tmp2=tmp->next;
   tmp->next=tmp2->next;
   Armor* armor=tmp2->a;
   weight-=armor->get_weight();
   delete tmp2;
   return armor;}}


 bool Inventario::more_armor() {if (head_armature!=NULL) return true; else return false;}
 
 int Inventario::peso_armi(){
  lista_weapons* tmp=head_weapons;
  int peso=0;
  while (tmp!=NULL){
   peso+=tmp->w->get_weight();
   tmp=tmp->next;}
  return peso;}

 int Inventario::peso_armature(){
  lista_armature* tmp=head_armature;
  int peso=0;
  while (tmp!=NULL){
   peso+=tmp->a->get_weight();
   tmp=tmp->next;}
  return peso;}

 void Inventario::stampa_inventario(Player* p,Node* position,bool in_combat){
  oggetti[0].max=MAX_MED_KIT+MAX_ANTIDOTI+MAX_ADRENALINE;
  oggetti[1].val=get_keys();
  oggetti[1].usa=(oggetti[1].val>0);
  oggetti[2].val=indice_docs+1;
  oggetti[4].max=max_weight;
  oggetti[5].max=max_weight;
  oggetti[3].usa=!p->get_database()->is_empty();
  if (oggetti[3].usa){
     oggetti[3].val=p->get_database()->num_found();
    oggetti[3].scritta="[Premi 'a' per scorrere indietro, 'd' per scorrere avanti, 'e' per scorrere le creature trovate, 'f' per uscire]\n";}
  else
    oggetti[3].scritta=prestabilita;
  if (indice_docs<0)
     oggetti[2].scritta=prestabilita;
  else
     oggetti[2].scritta="[Premi 'a' per scorrere indietro, 'd' per scorrere avanti, 'e' per leggere i documenti, 'f' per uscire]\n";
  int i=0;
  while (!oggetti[i].usa){if (i==4) i=0; else i++;}
  char s;
  bool exit=false;
  do{
  if(((!more_med_pack())&&(!more_adrenaline())&&(!more_antidoti())))
     oggetti[0].scritta=prestabilita;
  else
    oggetti[0].scritta="[Premi 'a' per scorrere indietro, 'd' per scorrere avanti, 'e' per consumare, 'p' per vedere le statistiche, 'f' per uscire]\n";
  oggetti[0].val=get_antidoti()+get_med_pack()+get_adrenaline();
  oggetti[4].usa=more_weapons();
  oggetti[5].usa=more_armor();
  oggetti[4].val=peso_armi();
  oggetti[5].val=peso_armature();
  while (!oggetti[i].usa){if (i==5) i=0; else i++;}
  clear_screen();
  cout<<"INVENTARIO\n";
  cout<<"\t\t\t[PESO:  "<<weight<<"/"<<max_weight<<"]\n";
  cout<<oggetti[i].scritta<<endl;
  switch (i){
    case (0):{cout<<oggetti[0].name<<":\t\t["<<oggetti[0].val<<"/"<<oggetti[0].max<<"]\n"<<endl;
              cout<<"\tMed-Kit:\t"<<(get_med_pack())<<"/"<<MAX_MED_KIT<<endl;
              cout<<"\tFialette di Adrenalina:\t"<<(get_adrenaline())<<"/"<<MAX_ADRENALINE<<endl;
              cout<<"\tAntidoti:\t"<<get_antidoti()<<"/"<<MAX_ANTIDOTI<<endl; break;}
    case (1):{cout<<oggetti[1].name<<":\t\t"<<oggetti[1].val<<endl;
              break;}
    case (2):{cout<<oggetti[2].name<<":\t\t"<<oggetti[2].val<<"/"<<oggetti[2].max<<endl;
              break;}
    case (3):{cout<<oggetti[3].name<<":\t\t["<<oggetti[3].val<<"/"<<oggetti[3].max<<"]"<<endl; break;}
    case (4):{cout<<oggetti[4].name<<":\t\t[Peso  "<<oggetti[4].val<<"/"<<oggetti[4].max<<"]"<<endl;
              break;}
    case (5):{cout<<oggetti[5].name<<":\t\t[Peso  "<<oggetti[5].val<<"/"<<oggetti[5].max<<"]"<<endl;
              break;}}
  do
    s=getch();
  while ((s!='a')&&(s!='d')&&(s!='f')&&(s!='e')&&(s!='p'));
  switch (s){
   case ('a'):{if (i==0) i=5; else i--; while (!oggetti[i].usa){if (i==0) i=5; else i--;} break;}
   case ('d'):{if (i==5) i=0; else i++; while (!oggetti[i].usa){if (i==5) i=0; else i++;} break;}
   case ('f'):{exit=true; break;}
   case ('e'):{  switch (i){
                   case (0):{if (oggetti[i].usa){p->consuma(in_combat); exit=in_combat;} break;}
                   case (1):{clear_screen(); break;}
                   case (2):{if (indice_docs>=0) leggi_lettera(); else clear_screen(); break;}
                   case (3):{if (oggetti[i].usa) p->get_database()->show_database(); break;}
                   case (4):{Weapon *w=p->which_weapon(); print_weapons_list(p,position); if ((w!=p->which_weapon())&&(in_combat)) exit=true;
                              break;}
                   case (5):{Armor*a=p->which_armor(); print_armature_list(p,position); if ((a!=p->which_armor())&&(in_combat)) exit=true;
                              break;}}    
                 break;}
   case ('p'):{if ((i==0)||(i==4)||(i==5)) {clear_screen(); p->statistiche(); getch();} break;} } }
  while (!exit);
  clear_screen();}

