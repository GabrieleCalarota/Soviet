#include "Visore.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Armor.hpp"
#include "Weapon.hpp"
#include "SpecialAbility.hpp"

 Visore::Visore(){
  charge_battery=100;
  use=true;
  reserve_battery=0;}

 void Visore::use_visore(){
  if (enough_battery()){
   use=true;
   cout<<"Visore equipaggiato\n";}}

 void Visore::drop_visore(){
  use=false;}

 bool Visore::get_use(){
   return use;}

 bool Visore::enough_battery(){
  return (charge_battery>0);}

 void Visore::consume_battery(){
  if (use){
   int n=rand()%3;
   charge_battery-=n;
  if (!enough_battery()){
   cout<<"BATTERIA VISORE SCARICA\n";
   charge_battery=0;
   drop_visore();}}}

 void Visore::inc_reserve(){
  slow_print((char*)"Nuova batteria di riserva!\n");
  reserve_battery++;}

 bool Visore::enough_reserve(){
  return (reserve_battery>0);}

 void Visore::refill_battery(){
  reserve_battery--;
  charge_battery=100;
  use_visore();}

 void Visore::recharge(){
  if (enough_reserve()){
   refill_battery();}}

 void Visore::options(){
  if (use){
   if (enough_reserve()){
    cout<<"VISORE:\t['f' per uscire]\n\n";
    cout<<"a) Spegni visore\n";
    cout<<"b) Ricarica visore\t["<<reserve_battery<<" ricariche rimaste]\n";
    char s;
    do
     s=getch();
    while ((s!='a')&&(s!='b')&&(s!='f'));
    if (s=='a')
     drop_visore();
    else
     if (s=='b')
      recharge();}
   else
    drop_visore();}
  else{
   if (enough_reserve()){
    cout<<"VISORE:\t['f' per uscire]\n\n";
    cout<<"a) Accendi visore\n";
    cout<<"b) Ricarica visore\t["<<reserve_battery<<" ricariche rimaste]\n";
    char s;
    do
     s=getch();
    while ((s!='a')&&(s!='b')&&(s!='f'));
    if (s=='a')
     use_visore();
    else
     if (s=='b')
      recharge();}
   else
    use_visore();}}

 void Visore::print_recharge(){
  if (enough_reserve())
   cout<<"BATTERIE DI RISERVA:\t"<<reserve_battery<<endl;}
 
 void Visore::print_battery(){
  if (charge_battery<=20){
   cout<<BOLD(FRED("BATTERIA VISORE:\t")); cout<<charge_battery<<BOLD(FRED("%\n"));}
  else
   cout<<"BATTERIA VISORE:\t"<<charge_battery<<"%\n";}

 bool Visore::combat_visore(Enemy* m,Player* p){
  cout<<endl;
  cout<<endl;
  bool ability=false;
  cout<<"Scegli cosa fare:\n\n\ta) Attacca "<<m->get_name()<<"\n\tf) Scappa\n";
  if (p->get_ability()->use(p,m,NULL)){
   if (p->enough_energy(p->get_ability()->get_energy_needed()))
    ability=true;}
  if (ability)
   cout<<"\ts) Usa abilità speciale\n";
  char s;
  do
   s=getch();
  while ((s!='a')&&(s!='s')&&(s!='f'));
  clear_screen();
  if ((s=='f'))
   return true;
  else{
   if (s=='a'){
    clear_screen();
    bool attacco=true; 
    if (p->which_weapon()!=NULL){
     if (p->which_weapon()->has_ammos()) {
      p->which_weapon()->shoot();
      if (!p->which_weapon()->has_ammos())
       cout<<"Questo era il tuo ultimo colpo che potevi infliggere con "<<(p->which_weapon()->get_name())<<"!\n";} 
     else{
      attacco=false;
      cout<<(p->which_weapon()->get_name())<<" non è più utilizzabile!\n";}} 
    if (attacco){ 
     int danno_curr=p->get_damage_max(); 
     cout<<"Hai utilizzato l'effetto sorpresa contro "<<m->get_name()<<" infliggendo "<<danno_curr<<" danni\n";
 if (m->has_armor()){
                     danno_curr=m->get_armor()->absorb(danno_curr); 
                     cout<<"\n"<<m->get_name()<<" ne assorbe "<<danno_curr<<endl;} 
                    else{ 
                     cout<<" togliendoli a "<<m->get_name()<<endl;}  
                    m->change_life(danno_curr);}}
    else{
     if (ability){
      p->change_energy(p->get_ability()->get_energy_needed());
      p->get_ability()->unleash_special_ability(m,p);}}
    int n=rand()%100+1; 
    if (!(m->is_dead())){
     slow_print((char*)"Vita "); 
     slow_print(m->get_name()); 
     slow_print((char*)" = "); 
     cout<<m->get_life()<<endl;
     cout<<endl;
     if (m->is_stunned()){
      slow_print(m->get_name());
      slow_print((char*)" non attacca perchè stordito..\n");
      m->dec_stunned();}
     else{
      slow_print(m->get_name());
      slow_print(" ti attacca!\n");  
      if (n<(p->get_dexterity()*2)){
       slow_print((char*)"Attacco evitato!\n");
       cout<<endl;}
      else{
       int danno_curr=(rand()%(m->get_damage_max()-m->get_damage_min()))+m->get_damage_min();
       if (p->which_armor()!=NULL)
        danno_curr=p->which_armor()->absorb(danno_curr);
       if (p->which_armor()!=NULL){
        if (p->which_armor()->is_immune(m->get_offense())&&((p->which_armor()->has_more_immunity()))){
         p->which_armor()->use_immunity();
         danno_curr=m->get_damage_min(); 
         slow_print((char*)"Grazie all'immunità di ");
         slow_print(p->which_armor()->get_name()); 
         slow_print((char*)" contro ");
         slow_print(p->which_armor()->get_name_immunity()); 
         slow_print((char*)" ");}}
       if (danno_curr>0){
        p->change_life(-danno_curr);
        slow_print(m->get_name()); 
        slow_print((char*)" ti infligge ");
        cout<<danno_curr;
        slow_print((char*)" danni!\n");
        if (!(p->dead())){
         slow_print((char*)"La tua vita ora è: ");
         cout<<p->get_life()<<endl;    
         if ( (m->is_poisoned())  &&  (!p->is_infected())){
          bool rando=true;
          if (p->which_armor()!=NULL){ 
           if (p->which_armor()->is_immune(poison)&&p->which_armor()->has_more_immunity()){
            p->which_armor()->use_immunity(); 
            slow_print(m->get_name());
            slow_print((char*)" ha provato ad avvelenarti ma "); 
            slow_print((char*)"grazie all'immunità di "); 
            slow_print(p->which_armor()->get_name()); 
            slow_print((char*)" contro "); 
            slow_print(p->which_armor()->get_name_immunity()); 
            slow_print((char*)" sei riuscito ad evitarlo\n"); rando=false;}  
           if (rando){
            int n=rand()%100;
            if (n<30){
             p->change_infected(true); 
             slow_print(m->get_name()); cout<<" ti ha avvelenato\n";}}}}
         if (p->is_infected()) 
          p->poison_check(true);}}
       else{ 
        slow_print((char*)"Grazie a "); 
        slow_print(p->which_armor()->get_name()); 
        slow_print((char*)" sei riuscito ad evitare l'attacco di ");     
        slow_print(m->get_name()); 
        cout<<"!\n";}}}
     sleep(1);
     clear_screen();
     return false;}}}
