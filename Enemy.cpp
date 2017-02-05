#include "Weapon.hpp"
#include "Armor.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Colors.hpp"
#include "Task.hpp"
#include "Inventario.hpp"
#include "Database.hpp"
#include "SpecialAbility.hpp"
#include "Node.hpp"
#include "Visore.hpp"

 Enemy::Enemy(int level,int piano){					
  weapon=NULL;
  armor=NULL;
  switch(piano){
    case (1):{
     stunned=0;
     res=no_res;
     vul=no_res;
     offense_type=no_immunity;
     set_level(level);
     set_weapon(piano);
     set_armor(piano);
     type=(type_monster) (rand()%3);
     switch(type){
       case (energumen_mutated):{  
        life=60+((level-1)*3);
        strength=8+level;
        offense_type=chemical_agent;
        change_damage();
        res=huddle_weapon;
        vul=white_weapon;
        strcpy(name,"Energumeno Mutato"); break;}
       case (toxic_nurse):{ 
        life=40+((level-1)*3);
        strength=4+level;
        offense_type=poison;
        change_damage();
        res=no_res;
        vul=huddle_weapon;
        strcpy(name,"Infermiera Tossica"); break;}
       case (station_keeper):{
        life=50+((level-1)*3);
        strength=6+level;
        offense_type=firearm;
        change_damage();
        res=white_weapon;
        vul=special_weapon;
        strcpy(name,"Guardiano della Base"); break;}
       default: {life=0; strength=0; level=0; strcpy(name,"ERROR!");}}break;}
    case(2):{
     stunned=0;
     res=no_res;
     offense_type=no_immunity;
     set_level(level);
     set_weapon(piano);
     set_armor(piano);
     type=(type_monster) ((rand()%4)+3);
     switch (type){
       case (scaled_experiment):{
        life=60+((level-1)*3);
        strength=10+level;
        offense_type=poison;
        change_damage();
        res=white_weapon;
        vul=heavy_fire_weapon;
        strcpy(name,"Esperimento squamato"); break;}
       case (river_guardian):{
        life=70+((level-1)*3);
        strength=11+level;
        offense_type=firearm;
        change_damage();
        res=light_fire_weapon;
        vul=white_weapon;
        strcpy(name,"Guardiano del fiume"); break;}
       case (sewer_walker):{
        life=80+((level-1)*3);
        strength=12+level;
        offense_type=cutlass;
        change_damage();
        res=huddle_weapon;
        vul=explosive_weapon;
        strcpy(name,"Camminatore delle fogne"); break;}
       case (underground_prisoner):{
        life=70+((level-1)*3);
        strength=13+level;
        offense_type=chemical_agent;
        change_damage();
        res=no_res;
        vul=light_fire_weapon;
        strcpy(name,"Prigioniero dei sotteranei"); break;}
       default: {life=0; strength=0; level=0; strcpy(name,"ERROR!"); break;}} break;}
    case(3):{    
     stunned=0;
     res=no_res;
     offense_type=no_immunity;
     set_level(level);
     set_weapon(piano);
     set_armor(piano);
     type=(type_monster) ((rand()%3)+7);
     switch (type){
       case (mad_doctor):{
        life=80+((level-1)*3);
        strength=15+level;
        offense_type=poison;
        change_damage();
        res=special_weapon;
        vul=white_weapon;
        strcpy(name,"Dottore pazzo"); break;}
       case (improved_soldier):{
        life=70+((level-1)*3);
        strength=14+level;
        offense_type=cutlass;
        change_damage();
        res=heavy_fire_weapon;
        vul=explosive_weapon;
        strcpy(name,"Soldato modificato"); break;}
       case (cyborg_fighter):{
        life=70+((level-1)*3);
        strength=15+level;
        offense_type=firearm;
        change_damage();
        res=explosive_weapon;
        vul=special_weapon;
        strcpy(name,"Combattente cyborg"); break;}
       default: {life=0; strength=0; level=0; strcpy(name,"ERROR!"); break;}} break; }break;}    
    }



 type_of_immunity Enemy::get_offense() {return offense_type;}	
 
 bool Enemy::is_poisoned(){ return (offense_type==poison);}	

 char* Enemy::get_name() {char* n=name; return n;}		
 
 int Enemy::get_level() {return level;}				
 
 int Enemy::get_life() {return life;}				

 int Enemy::get_damage_min() {return damage_min;} 		
 int Enemy::get_damage_max() {return damage_max;}		

 type_of_weapon Enemy::get_resistance() {return res;}		

 type_monster Enemy::get_monster_type() {return type;}		

 bool Enemy::is_dead() {return (!(life>0));}			
 
 void Enemy::set_stunned(int n) {stunned=n;}			
 bool Enemy::is_stunned() {return (stunned>0);}			
 void Enemy::dec_stunned() {if (stunned>0) stunned--;}		
 

 void Enemy::change_life(int n) {				
  if ((life-n)>MIN_LIFE)
   life-=n;
  else 
   life=MIN_LIFE;} 
 

 void Enemy::set_level(int l){					
  if (l>1)
   level=rand()%(3)+(l-1);
  else
   level=rand()%2+1;}
   

 void Enemy::set_weapon(int piano){				
  switch (piano){
    case (1):{ 
     if (level==1){
      int n=rand()%100;
      if (n<80){
       weapon=NULL;}
      else{
       weapon_type w=(weapon_type) (rand()%2);
       weapon=new Weapon(w); }}
     else{
      weapon_type w=(weapon_type) (rand()%4+(2));   
      weapon=new Weapon(w);} break;}
    case (2):{ 
     if (level==1){
      int n=rand()%100; 
      if (n<60){
       weapon=NULL;}
      else{
       weapon_type w=(weapon_type) (rand()%2+6); 
       weapon=new Weapon(w); }}
     else{
      weapon_type w=(weapon_type) (rand()%4+8);   
      weapon=new Weapon(w);} break;}
    case (3):{ 
     if (level==1){
      int n=rand()%100; 
      if (n<50){
       weapon=NULL;}
      else{
       weapon_type w=(weapon_type) (rand()%2+12); 
       weapon=new Weapon(w); }}
     else{
      weapon_type w=(weapon_type) (rand()%4+14);   
      weapon=new Weapon(w);} break;}}} 


 void Enemy::set_armor(int piano){				
  switch (piano){
    case (1):{ 
     switch (level){
       case (1): { armor=NULL; break;}
       case (2): {int n=rand()%100; if (n<10) {armor=new Armor(vesti_da_laboratorio);} else {armor=NULL;} break;}
       case(3): {int n=rand()%100; if (n<40) {armor=new Armor(vesti_da_laboratorio);} else {armor=NULL;} break;}
       default: { armor_type a=(armor_type) (rand()%2); armor=new Armor(a); break;}}  break;}
    case (2):{
     switch (level){
       case (1): {armor=NULL; break;}
       case (2): {int n=rand()%100; if (n<10) {armor=new Armor(completo_di_pelle);} else {armor=NULL;} break;}
       case(3): {int n=rand()%100; if (n<40) {armor=new Armor(completo_di_pelle);} else {armor=NULL;} break;}
       default : { armor_type a=(armor_type) (rand()%2+2); armor=new Armor(a); break;}}  break;}
    case (3):{
     switch (level){
       case (1): { armor=NULL; break;}
       case (2): {int n=rand()%100; if (n<10) {armor=new Armor(tuta_hazmat);} else {armor=NULL;} break;}
       case(3): {int n=rand()%100; if (n<40) {armor=new Armor(tuta_hazmat);} else {armor=NULL;} break;}
       default: {armor_type a=(armor_type) (rand()%2+4); armor=new Armor(a); break;}}  break;}}}
       
 
 void Enemy::change_damage(){					
  double m;
  double min=1.0,max=1.0;
  switch(offense_type){
    case (chemical_agent): {m=1.1; break;}
    case (poison): {m=1.3; break;}
    case (cutlass): {m=1.2; break;}
    case (firearm): {m=1.4; break;}
    default: {m=1.2; break;}}
  if (weapon!=NULL) weapon->get_damage(&min,&max);
  damage_min=(int)  ((strength+level)-(min));
  damage_max=(int) ((strength+level)+(max)+m);}



 bool Enemy::has_weapon() {return (weapon!=NULL);}		
 bool Enemy::has_armor() {return (armor!=NULL);}		
  
 Weapon* Enemy::get_weapon() {return weapon;}
 Armor* Enemy::get_armor() {return armor;}


 bool Enemy::combat(Node* position,Player* p,int num){		
  int cont=0;	
  p->get_database()->add_enemy(type);
  clear_screen();
  cout<<name; slow_print((char*)"  Livello "); cout<<level; 
  slow_print((char*)" Vita = "); cout<<life<<endl<<endl;
  if (has_weapon()){ cout<<name; slow_print((char*)" ha equipaggiato un'arma!\n");}
  if (has_armor()){ cout<<name; slow_print((char*)" è protetto da un'armatura!\n");}
  if (p->which_weapon()!=NULL){ 
   if (vul==(p->which_weapon()->which_type_of_weapon())){
    cout<<"Il nemico è vulnerabile alla tua arma!\n";} 
   if (res==(p->which_weapon()->which_type_of_weapon())){
    cout<<"Il nemico è resistente alla tua arma!\n";}}
  bool fuggi=false;
  if (p->get_visore()->get_use()){
   fuggi=p->get_visore()->combat_visore(this,p);}
  if (!fuggi){
  while ((!(is_dead())) && (!p->dead())){
   bool flag=false;
   do{ 
    cout<<"\nScegli cosa fare:\na) Attacca "<<name;
    if (p->is_in_weapon()||p->is_in_armor())
        cout<<"\nh) Lascia equipaggiamento";
    cout<<"\ni) Inventario\np) Statistiche\n";
    if (p->get_ability()->use(p,this,NULL)) cout<<"s) Usa Abilità Speciale\n";
    cout<<endl<<endl<<endl;
    if (((p->get_life()/((double)p->get_max_life()))*100) <20){
     cout<<BOLD(FRED("\t\tVITA\t")); cout<<p->get_life(); cout<<BOLD(FRED("/")); cout<<p->get_max_life()<<endl;} 
    else if (p->is_infected()){
     cout<<BOLD(FGRN("\tVITA:\t"))<<p->get_life()<<BOLD(FGRN("/"))<<p->get_max_life()<<BOLD(FGRN("\t[INFETTO]"))<<endl;}
    else{ 
     cout<<"\t\tVITA\t"<<p->get_life()<<"/"<<p->get_max_life()<<endl;}
    cout<<"\t\tENERGIA\t"<<p->get_energy()<<"/"<<p->get_max_energy()<<endl;
    cout<<endl<<endl<<endl;
    cout<<"<"<<name<<">"<<endl;
    cout<<"VITA\t\t"<<life<<endl;
    cout<<"LIVELLO\t\t"<<level<<endl;
    cout<<"ARMA\t\t";
    if (has_weapon()){
     cout<<"SI"<<endl;} 
    else 
     cout<<"NO"<<endl;
    cout<<"ARMATURA\t";
    if (has_armor()){
     cout<<"SI"<<endl;} 
    else 
     cout<<"NO"<<endl;
    char n;
    n=getch();
    clear_screen();
    switch (n){  
      case ('a'): {bool attacco=true; 
                   if (p->which_weapon()!=NULL){
                    if (p->which_weapon()->has_ammos()){
                     p->which_weapon()->shoot(); 
                     if (!p->which_weapon()->has_ammos()) 
                      cout<<"Questo era l'ultimo colpo che potevi infliggere con "<<(p->which_weapon()->get_name())<<"!\n";}
                    else{
                     attacco=false; 
                     cout<<(p->which_weapon()->get_name())<<" non è più utilizzabile!\n";}} 
                   if (attacco){
                    int danno_curr=(rand()%(p->get_damage_max()-p->get_damage_min())+(p->get_damage_min()));
                    if (p->which_weapon()!=NULL){ 
                     if (vul==(p->which_weapon()->which_type_of_weapon())){
                      danno_curr*=2;} 
                     if (res==(p->which_weapon()->which_type_of_weapon())){
                      danno_curr/=2;}} 
                    cout<<"ATTACCO!\nHai sferrato un colpo da "<<danno_curr<<" danni";
                    if (has_armor()){
                     danno_curr=armor->absorb(danno_curr); 
                     cout<<"\n"<<name<<" ne assorbe "<<danno_curr<<endl;} 
                    else{ 
                     cout<<" togliendoli a "<<name<<endl;}  
                    change_life(danno_curr);} 
                   flag=true; break;}
      case ('i'): { int tmp_l=p->get_life();
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
      case ('s'): {
                    if (p->enough_energy(p->get_ability()->get_energy_needed())){
                     p->change_energy(p->get_ability()->get_energy_needed()); 
                     p->get_ability()->unleash_special_ability(this,p); 
                     flag=true;} 
                    else{
                     cout<<"Energia insufficiente per utilizzare "<<p->get_ability()->get_name()<<"!\n"; 
                     flag=false;}  break;}
      case ('h'): {Weapon *w=NULL;
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
      case ('p'): {p->statistiche(); 
                   flag=false;  
                   cout<<"Premi un tasto per continuare..\n"; 
                   getch(); 
                   clear_screen(); break;}
      default : {flag=false; break;}}} 
    while (!flag);
    int n=rand()%100+1; 
    if (!(is_dead())){
     slow_print((char*)"Vita "); slow_print(name); cout<<" "<<life<<endl<<endl;
     if (is_stunned()){
      slow_print(name); 
      slow_print((char*)" non attacca perchè stordito..\n"); 
      dec_stunned();}
     else{
      do{
      slow_print(name);
      slow_print(" sferra un attacco da ");
      int danno_curr=(rand()%(damage_max-damage_min))+damage_min;
      cout<<danno_curr<<" danni\n";   
      if (n<(p->get_dexterity()*2)){
       slow_print((char*)"Attacco evitato!\n");}
      else{
       if (p->is_crippled())
        cont++;
       if (cont==3)
        p->change_crippled(false);
       if (p->which_armor()!=NULL){
        if (p->which_armor()->is_immune(offense_type)&&((p->which_armor()->has_more_immunity()))){
         p->which_armor()->use_immunity(); danno_curr=damage_min; 
         p->which_armor()->absorb(danno_curr);
         slow_print((char*)"Grazie all'immunità di "); slow_print(p->which_armor()->get_name()); slow_print((char*)" contro "); slow_print(p->which_armor()->get_name_immunity()); 
         slow_print((char*)" ");}
        else{
         danno_curr=p->which_armor()->absorb(danno_curr);
         slow_print((char*)"Grazie a "); 
         slow_print(p->which_armor()->get_name()); cout<<" ";}}
         p->change_life(-danno_curr);
         slow_print(name); slow_print((char*)" ti infligge "); cout<<danno_curr; slow_print((char*)" danni!\n");}
      if (!(p->dead())){   
       if ((offense_type==poison) && (!p->is_infected())){
        bool rando=true;
        if (p->which_armor()!=NULL){ 
         if (p->which_armor()->is_immune(poison)&&p->which_armor()->has_more_immunity()){
          p->which_armor()->use_immunity(); 
          slow_print(name); slow_print((char*)" ha provato ad avvelenarti ma "); slow_print((char*)"grazie all'immunità di "); slow_print(p->which_armor()->get_name()); 
          slow_print((char*)" contro "); slow_print(p->which_armor()->get_name_immunity()); slow_print((char*)" sei riuscito ad evitarlo\n"); rando=false;} 
         if (rando){
          int n=rand()%100; 
          if (n<30) {p->change_infected(true); 
          slow_print(name); cout<<" ti ha avvelenato\n";}}}}
      if (p->is_infected()){
        p->poison_check(true);}
      slow_print((char*)"La tua vita ora è: "); cout<<p->get_life()<<endl;}}
      while (p->is_crippled());}}
    p->change_crippled(false);
    sleep(1); 
    clear_screen();}}
  if (is_dead()){
   cout<<"Hai ucciso "<<name<<endl; 
   if (has_weapon()){
    Weapon* w=weapon; 
    position->push_weapons(w); 
    cout<<"Hai trovato\t"<<w->get_name()<<endl;} 
   if (has_armor()){ 
    Armor* a=armor; 
    position->push_armature(a); 
    cout<<"Hai trovato\t"<<a->get_name()<<endl;}  
   p->inc_experience(EXPERIENCE_TOKEN+5*(level+num)); 
   p->get_task()->inc_clues(); 
   sleep(1); 
   clear_screen();}
  return p->dead();}
