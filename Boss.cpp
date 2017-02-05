#include "Boss.hpp"
#include "Map.hpp"
#include "Inventario.hpp"
#include "SpecialAbility.hpp"
#include "Colors.hpp"
#include "Player.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
#include "Node.hpp"

 Boss::Boss(int n_players, int floor,int currx,int curry){			
  x=currx;
  y=curry;
  smoke_bomb=3;
  stop=0;
  stunned=0;
  smoked=false;
  switch (floor){
    case (1): {strcpy(name,"Abominio"); life=120+(n_players*50); strength=8+n_players; damage_min=strength*2; damage_max=strength*5/2; break;}
    case (2): {strcpy(name,"Aqua Behemot");life=230; strength=20; damage_min=15*3; damage_max=30*3; break;}
    case (3): {strcpy(name,"Exomorph"); life=340; strength=20; damage_min=20*3; damage_max=40*3; break;}}}
    

 int Boss::get_x(){return x;}							
 int Boss::get_y(){return y;}							
 

 void Boss::change_currentx(int n) {x=n;}					
 void Boss::change_currenty(int n) {y=n;}					
 

 int Boss::get_damage_max() {return damage_max;}				
 int Boss::get_damage_min() {return damage_min;}				
 

 int Boss::get_smoke_bomb() {return smoke_bomb;}				
 void Boss::dec_smoke_bomb() {if (smoke_bomb>0) smoke_bomb--;}			
 

 bool Boss::is_stunned() {return stunned>0;}					
 void Boss::set_stunned(int b) {stunned=b;}					
 void Boss::dec_stunned() {if (stunned>0) stunned--;}				
 

 bool Boss::is_smoked() {return smoked;}					
 void Boss::change_smoked(bool b) {smoked=b;}					
 

 int Boss::get_stop() {return stop;}						
 void Boss::set_stop(int n) {stop=n;}						
 void Boss::dec_stop() {stop--;}						
 

 char* Boss::get_name() {char* c=name; return c;}				
 

 int Boss::get_life() {return life;}						
 

 bool Boss::is_dead() {return (life<=0);}					
 

 void Boss::change_life(int n){							
  if ((life-n)>0)
   life-=n;
  else 
   life=0;}
   
  
 bool Boss::boss_combat(Player* p,bool multi,int* turni,Node* position) {	
  int cont=0;
  bool scappa=false;				
  if (!multi||((*turni)<1)){*turni=1;}
  else {*turni=*turni%7;}
  while (((!(p->dead()))&&(!is_dead()))&&(!scappa)&&((*turni)<7)) {
   bool flag=false;
   do{
    cout<<"\nScegli cosa fare:\na) Attacca "<<name;
    if (p->is_in_weapon()||p->is_in_armor())
        cout<<"\nh) Lascia equipaggiamento";
    cout<<"\ni) Inventario\np) Statistiche\n";
    if (p->get_ability()->use(p,NULL,this)) cout<<"s) Usa Abilità Speciale\n";
    if (smoke_bomb>0) cout<<"f) Usa fumogeno ("<<smoke_bomb<<" disponibili)\n";
    cout<<endl<<endl<<endl;
    if (((p->get_life()/((double)p->get_max_life()))*100) <20){
     cout<<BOLD(FRED("\t\tVITA\t")); cout<<p->get_life(); cout<<BOLD(FRED("/")); cout<<p->get_max_life()<<endl;}
    else if (p->is_infected()){
     cout<<BOLD(FGRN("\tVITA:\t"))<<p->get_life()<<BOLD(FGRN("/"))<<p->get_max_life()<<BOLD(FGRN("\t[INFETTO]"))<<endl;} 
    else {cout<<"\t\tVITA\t"<<p->get_life()<<"/"<<p->get_max_life()<<endl;}
    cout<<"\t\tENERGIA\t"<<p->get_energy()<<"/"<<p->get_max_energy()<<endl;
    cout<<endl<<endl<<endl;
    cout<<"<"<<name<<">"<<endl;
    cout<<"VITA\t\t"<<life<<endl;
    char n;
    n=getch();
    clear_screen();
    switch (n){  
      case ('a'):{ bool attacco=true; 
                   if (p->which_weapon()!=NULL){
                    if (p->which_weapon()->has_ammos()){
                     p->which_weapon()->shoot(); 
                     if (!p->which_weapon()->has_ammos()) 
                      cout<<"Questo era l' ultimo colpo che potevi infliggere con "<<(p->which_weapon()->get_name())<<"!\n"; } 
                    else{
                     attacco=false; 
                     cout<<(p->which_weapon()->get_name())<<" non è più utilizzabile!\n";}} 
                   if (attacco){
                    int danno_curr=(rand()%(p->get_damage_max()-p->get_damage_min())+(p->get_damage_min())); 
                    cout<<"ATTACCO!\nHai sferrato un colpo da "<<danno_curr<<" danni togliendoli a "<<name<<endl; 
                    change_life(danno_curr);} 
                    flag=true; break;}
                    
      case ('i'):{int tmp_l=p->get_life();
                    int tmp_e=p->get_energy();
                    Weapon *w=NULL;
                    Armor *a=NULL;
                    if (p->is_in_weapon())
                     w=p->which_weapon();
                    if (p->is_in_armor()) 
                     a=p->which_armor();
                    p->get_inventario()->stampa_inventario(p,position,true);
                    if ((p->get_life()>tmp_l)||(p->get_energy()>tmp_e))
                     flag=true;
                    else{ 
                     if ((a!=p->which_armor())||(w!=p->which_weapon()))
                        flag=true;
                     else
                        flag=false;} break;}
                    
      case ('s'):{ 
                    if (p->enough_energy(p->get_ability()->get_energy_needed())){
                     p->change_energy(p->get_ability()->get_energy_needed()); 
                     p->get_ability()->unleash_special_ability(this,p); 
                     flag=true;} 
                    else{
                     cout<<"Energia insufficiente per utilizzare "<<p->get_ability()->get_name()<<"!\n"; 
                     flag=false;} 
                    break;}

                    
      case ('f'):{ if (smoke_bomb>0){
                    dec_smoke_bomb(); 
                    change_smoked(true); 
                    flag=true;}
                   else{
                    cout<<"Nessun fumogeno disponibile\n"; 
                    flag=false;} break;}
                    
      case ('h'):{  Weapon *w=NULL;
                    Armor *a=NULL;
                    if (p->is_in_weapon())
                     w=p->which_weapon();
                    if (p->is_in_armor()) 
                     a=p->which_armor();
                    p->unequip(position); 
                    if ((a!=p->which_armor())||(w!=p->which_weapon()))
                        flag=true;
                     else
                        flag=false; break;} 
      case ('p'):{ p->statistiche(); 
                   flag=false;  
                   cout<<"Premi un tasto per continuare..\n"; 
                   getch(); 
                   clear_screen(); break;}
      default:{ flag=false; break;}}} 
      
   while (!flag);
   int n=rand()%100+1; 
   if (!(is_dead())){
    if (is_smoked()){
     slow_print((char*)"Fumogeno andato a segno! Il nemico è disorientato, una buona occasione per rimettersi in forze e cercare rifornimenti!\n"); 
     scappa=true;}
    else if (is_stunned()){
     slow_print(name); 
     slow_print((char*)" non attacca perchè stordito..\n"); 
     dec_stunned();}
    else{
     slow_print((char*)"Vita "); slow_print(name); slow_print((char*)" = "); cout<<life<<endl;
     cout<<endl;
     do{
      slow_print(name);
      slow_print(" sferra un attacco da ");
      int danno_curr=(rand()%(damage_max-damage_min))+damage_min;
      cout<<danno_curr<<" danni\n";  
      if (n<(p->get_dexterity()*2))
       slow_print((char*)"Attacco evitato!\n\n");
      else{
       if (p->is_crippled()) 
        cont++;
       if (cont==3) 
        p->change_crippled(false);
       int danno_curr=(rand()%(damage_max-damage_min)+damage_min);
       if (p->which_armor()!=NULL)
        danno_curr=p->which_armor()->absorb(danno_curr);
       if (danno_curr>0){
        p->change_life(-danno_curr);
        slow_print(name); slow_print((char*)" ti infligge "); cout<<danno_curr; slow_print((char*)" danni!\n");
        if (!(p->dead())){
         slow_print((char*)"La tua vita ora è: "); cout<<p->get_life()<<endl;}}
       clear_screen();}}
     while (p->is_crippled());}}
   p->change_crippled(false);
   sleep(1); 
   clear_screen();
   if (multi)
    (*turni)++;}
  change_smoked(false);
  set_stunned(0);
  return p->dead();}
  

 void Boss::check_boss(Player* p, Map* mappa, ptr_lista_players head_players,bool multiplayer,int* turni,Node* position,int n_players){	//CONTROLLI TURNO
  if (stop<=0){
   mappa->chase_player(head_players); 
   clear_screen(); 
   mappa->stampa(head_players,p);}  
  else dec_stop();
  if ((x==p->get_currentx())&&(y==p->get_currenty())){
   for (int st=8; st>0; st--){ 
    usleep(50000);
    clear_screen();
    mappa->stampa(head_players,p);}
   clear_screen();
   sleep(1);
         if (mappa->boss_alive()&&(!multiplayer||((*turni>0))))
          set_stop(10+p->get_dexterity());
   if (!boss_combat(p,multiplayer,turni,position))
    mappa->stampa(head_players,p);
   if ((!is_dead())&&(!multiplayer||((*turni)<7) ) )
    set_stop((10+p->get_dexterity())*n_players);}}
