#include "SpecialAbility.hpp"
#include "Player.hpp"
#include "Boss.hpp"
#include "Enemy.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"

 SpecialAbility::SpecialAbility(int n,int intelligence){
  type=(special_ability_type) n;
  set_energy(intelligence);}


 SpecialAbility::SpecialAbility(){
  type=nessuna;
  energy_needed=0;}


 int SpecialAbility::get_choose(){
  return (int)type;}


 char* SpecialAbility::get_name(){								
  char* s=new char[25];
  switch (type){
    case (mira_perfetta): {strcpy(s,(char*)"<Mira Perfetta>"); break;}
    case (stordimento): {strcpy(s,(char*)"<Stordimento>"); break;}
    case (furtivita_letale): {strcpy(s,(char*)"<Furtività Letale>"); break;}
    case (impeto_di_forza): {strcpy(s,(char*)"<Impeto di Forza>"); break;}
    default: {strcpy(s,(char*)"Nessuna abilità speciale\n"); break;}}
  return s;}


 bool SpecialAbility::use(Player* p,Enemy* m, Boss* b){
  switch (type){
    case (mira_perfetta): {if (p->is_in_weapon()) return (p->which_weapon()->fire_gun()&&p->which_weapon()->has_ammos()); else return false; break;}
    case (stordimento): {if (m!=NULL){return (!m->is_stunned());}else{if (b!=NULL) return (!b->is_stunned());} break;}
    case (furtivita_letale): {if (p->is_in_weapon()){ if (p->which_weapon()->white_gun()) return true;}else{ int n=rand()%100+1; return (n<(40));}   break;}
    case (impeto_di_forza): {return (!p->is_in_weapon()); break;}
    default: {return false; break;}}}
    

 void SpecialAbility::unleash_special_ability(Enemy* m,Player* p){
  switch (type){
    case (mira_perfetta): {slow_print((char*)"Hai usato <Mira Perfetta>, togliendo ");
                          cout<<p->get_damage_max(); 
                          slow_print((char*)" punti vita a "); slow_print(m->get_name()); cout<<"!\n"; m->change_life(p->get_damage_max()); p->which_weapon()->shoot(); break;}
    case (stordimento): {
                         int s=rand()%((p->get_intelligence()/5))+2;
                         m->set_stunned(s); 
                         slow_print((char*)"Hai stordito "); 
                         slow_print(m->get_name()); slow_print((char*)"\n"); break;}
    case (furtivita_letale): {slow_print((char*)"Hai utilizzato le ombre per andare dietro a ");
                              slow_print(m->get_name());
                              int n=rand()%100+1; int tot=(int)(((double)p->get_dexterity())*(p->get_intelligence()/100*9+1));
                              if (n<tot){
                               slow_print((char*)" e gli hai tagliato la gola!\n"); 
                               m->change_life(m->get_life());}
                              else{ 
                               slow_print((char*)"\n");
                               slow_print(m->get_name()); 
                               slow_print((char*)" ti ha scoperto, ma sei comunque riuscito a infliggere un colpo da ");cout<<m->get_life()/4; 
                               slow_print((char*)" danni\n"); 
                               m->change_life(m->get_life()/4);} break;}
    case (impeto_di_forza): {slow_print((char*)"Hai usato <Impeto di Forza>, togliendo "); 
                             cout<<(p->get_damage_max()*2); slow_print((char*)" punti vita a ");
                             slow_print(m->get_name()); cout<<"!\n"; m->change_life(p->get_damage_max()*2); p->change_crippled(true); break;}  
    default: {bool attacco=true; 
              if (p->is_in_weapon()){
               if (p->which_weapon()->has_ammos()){
                p->which_weapon()->shoot(); 
                if (!p->which_weapon()->has_ammos()) 
                 cout<<"Questo era il tuo ultimo colpo che potevi infliggere con "<<(p->which_weapon()->get_name())<<"!\n";}
                else{
                 attacco=false; 
                 cout<<(p->which_weapon()->get_name())<<" non è più utilizzabile!\n";}} 
              if (attacco){
               int danno_curr=(rand()%(p->get_damage_max()-p->get_damage_min())+(p->get_damage_min()));
               cout<<"ATTACCO!\nHai sferrato un colpo da "<<danno_curr<<" danni";
               if (m->has_armor()){
                danno_curr=m->get_armor()->absorb(danno_curr); 
                cout<<"\n"<<m->get_name()<<" ne assorbe "<<danno_curr<<endl;} 
               else{ 
                cout<<" togliendoli a "<<m->get_name()<<endl;} 
               m->change_life(danno_curr);} break;}}}
 

 void SpecialAbility::unleash_special_ability(Boss* m,Player* p){
  switch (type){
    case (mira_perfetta): {slow_print((char*)"Hai usato <Mira Perfetta>, togliendo ");
                           cout<<p->get_damage_max(); 
                           slow_print((char*)" punti vita a "); slow_print(m->get_name()); cout<<"!\n"; m->change_life(p->get_damage_max()); break;}
    case (stordimento): {int s=rand()%2+1;
                         m->set_stunned(s); 
                         slow_print((char*)"Hai stordito "); 
                         slow_print(m->get_name()); slow_print((char*)"\n"); break;}
    case (furtivita_letale): {slow_print((char*)"Hai utilizzato le ombre per andare dietro a ");
                              slow_print(m->get_name()); 
                              int n=rand()%100+1; 
                              int tot=(int)(((double)p->get_dexterity())*(p->get_intelligence()/100*9+1));
                              if (n<tot){
                               slow_print((char*)" e lo hai ferito gravemente!\n"); 
                               m->change_life(m->get_life()/(n+1));}
                              else{ 
                               slow_print((char*)"\n");
                               slow_print(m->get_name()); 
                               slow_print((char*)" ti ha scoperto, ma sei comunque riuscito a infliggere un colpo da ");
                               cout<<((int)(((double)p->get_damage_max())/100*85)); 
                               slow_print((char*)" danni\n"); 
                               m->change_life((int)(((double)p->get_damage_max())/100*85));} break;}
    case (impeto_di_forza): {slow_print((char*)"Hai usato <Impeto di Forza>, togliendo "); 
                             cout<<(p->get_damage_max()*2); 
                             slow_print((char*)" punti vita a "); slow_print(m->get_name()); cout<<"!\n"; m->change_life(p->get_damage_max()*2); p->change_crippled(true); break;}  
    default: {bool attacco=true; 
              if (p->is_in_weapon()){
               if (p->which_weapon()->has_ammos()){
                p->which_weapon()->shoot(); 
                if (!p->which_weapon()->has_ammos()) 
                 cout<<"Questo era il tuo ultimo colpo che potevi infliggere con "<<(p->which_weapon()->get_name())<<"!\n";} 
                else{
                 attacco=false; 
                cout<<(p->which_weapon()->get_name())<<" non è più utilizzabile!\n";}} 
              if (attacco){
               int danno_curr=(rand()%(p->get_damage_max()-p->get_damage_min())+(p->get_damage_min()));
               cout<<"ATTACCO!\nHai sferrato un colpo da "<<danno_curr<<" danno";
               m->change_life(danno_curr);} break;}}}


 void SpecialAbility::print_info(){
  switch (type){
    case (mira_perfetta): {cout<<"Infliggi un danno all'avversario pari al massimo danno disponibile.\nUtilizzabile solamente con armi da fuoco.\n"; break;}
    case (stordimento): {cout<<"Stordisci l'avversario, rendendolo incapace di attaccarti. Il numero di turni in cui viene stordito dipendono dall'intelligenza.\n"; break;}
    case (furtivita_letale): {cout<<"Sfrutti il fattore sorpresa per colpire, con una probabilità di finire istantaneamente l'avversario.\nUtilizzabile solamente con armi da taglio equipaggiate.\n"; break;}
    case (impeto_di_forza): {cout<<"Infliggi un enorme danno all'avversario pari al doppio del danno massimo corrente, ma rimani incapace di attaccare per alcuni turni.\nUtilizzabile solamente a mani nude.\n"; break;}
    default: {cout<<endl; break;}}}


 int SpecialAbility::get_energy(){
  switch (type){
    case (mira_perfetta): {return 160; break;}
    case (stordimento): {return 220; break;}
    case (furtivita_letale): {return 170; break;}
    case (impeto_di_forza): {return 130; break;}
    default: {return 0; break;}}}


 void SpecialAbility::set_energy(int intelligence){
  switch (type){
    case (mira_perfetta): {energy_needed=-30-get_energy()/intelligence; break;}
    case (stordimento): {energy_needed=-45-get_energy()/intelligence; break;}
    case (furtivita_letale): {energy_needed=-35-get_energy()/intelligence; break;}
    case (impeto_di_forza): {energy_needed=-40-get_energy()/intelligence; break;}
    default: {energy_needed=0; break;}}}


 int SpecialAbility::get_energy_needed(){
  return energy_needed;}

 int SpecialAbility::get_energy_needed(int i){
  set_energy(i);
  return energy_needed;}

 int SpecialAbility::get_points_needed(){
  switch (type){
    case (mira_perfetta): {return 10; break;}
    case (stordimento): {return 6; break;}
    case (furtivita_letale): {return 7; break;}
    case (impeto_di_forza): {return 11; break;}
    default: {return 0; break;}}}


 void SpecialAbility::print_property(Player* p){
  switch (type){
    case(mira_perfetta): {int damage=p->get_damage_max();
                         cout<<"\t\tCon "<<get_name()<<" sferri un attacco da "<<damage<<" punti vita. (Solo con armi da fuoco equipaggiate)\n"; break; }
    case (stordimento): {int intelligence=p->get_intelligence();
                        cout<<"\t\tCon "<<get_name()<<" stordisci l'avversario per 1-"<<2+(p->get_intelligence()/5)<<" turni di attacco.\n"; break;}
    case (furtivita_letale): {int n=(int)(((double)p->get_dexterity())*(p->get_intelligence())/100*9+1) ;
                              char art[5]; 
                              if ((n==1)||(n==8)||(n==11)) 
                               strcpy(art,(char*)"l'");
                              else 
                               strcpy(art,(char*)"il");
                              cout<<"\t\tCon "<<get_name()<<" hai "<<art<<"  "<<n<<"%   di uccidere l'avversario.\n"; break;}
    case (impeto_di_forza): {int n=p->get_damage_max()*2;
                             cout<<"\t\tCon "<<get_name()<<" sferri un attacco da "<<n<<" danni. (Solo a mani nude)\n";}} }


 void SpecialAbility::choose(int* points,int intelligence,int& scelta){
  int i=1;
  char s;
  if (scelta!=0) {
   type= (special_ability_type) scelta;
   *points+=get_points_needed();}
  do{
   cout<<"\nPUNTI DISPONIBILI: "<<*points<<"\n\n Digita 'd' per scorrere in avanti, 'a' per scorrere indietro,'e' per selezionare,'f' per uscire senza modificare nulla.\n";
   switch (i){
     case (1): {type=mira_perfetta; break;} 
     case (2): {type=stordimento; break;} 
     case (3): {type=furtivita_letale; break;} 
     case (4): {type=impeto_di_forza; break;}}
   set_energy(intelligence); 
   cout<<"\t"<<get_name()<<"\n\n"; 
   cout<<"\tEnergia richiesta:\t"<<-1*energy_needed<<endl; 
   cout<<"\tPunti richiesti:\t"<<get_points_needed()<<endl<<endl; 
   print_info();
   s=getch();
   clear_screen();
   switch (s){
     case ('a'): {if (i==1) i=4; else i--; break;}
     case ('d'): {if (i==4) i=1; else i++; break;}
     case ('f'): {type=(special_ability_type) scelta; if (scelta!=0){*points=*points-get_points_needed();} i=0; break;}
     case ('e'): {if (get_points_needed()<=(*points)) {*points=(*points)-get_points_needed(); scelta=i;} else {s='n'; } break;}}}
  while ((s!='e')&&(s!='f'));}
