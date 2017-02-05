#include "Player.hpp"
#include "Node.hpp"
#include "Enemy.hpp"
#include "Task.hpp"
#include "Inventario.hpp"
#include "Database.hpp"
#include "Armor.hpp"
#include "Weapon.hpp"
#include "Boss.hpp"
#include "Map.hpp"
#include "SpecialAbility.hpp"
#include "Visore.hpp"

 Player::Player(){
  strcpy(name,"Player1");
  life=0;
  strength=3;  
  endurance=4;
  dexterity=3;
  intelligence=2;
  luck=0;
  level=1; 
  experience=0;
  MAX_EXPERIENCE=200;
  skill_points=0; 
  energy=100; 
  MAX_ENERGY=100;
  equipment_weight=0;
  MAX_EQUIPMENT_WEIGHT=12;
  perc_carico=0;
  agility_lost_point=0;
  cons[0].name="Med-kit:\t";
  cons[0].info="Un med-kit ti cura dalle ferite più gravi, ma non dai veleni.\n\nLa potenza del med-kit può dipendere anche dall'intelligenza e dalla fortuna.\n\nPotenzia la costituzione per poterne portare di più in inventario e avere più vita massima\n";
  cons[1].name="Fialette di Adrenalina:\t";
  cons[1].info="Queste fialette vengono iniettate dritte nello sterno e danno una scarica di adrenalina che ti permette di rilasciare potentissimi attacchi speciali.\n\nPotenzia la costituzione e l'intelligenza per ridurre l'energia necessaria a sprigionare attacchi speciali e per poterne portare di più di queste fialette in inventario.\n";
  cons[2].name="Antidoti:\t";   
  cons[2].info="Questi potentissimi antidoti sono in grado di debellare anche il più forte tra i veleni tossici.\n\nGli scienziati che hanno lavorato a questo esperimento conoscevano i rischi a cui erano sottoposti.\n\nIl numero massimo di antidoti trasportabili dipende dalla costituzione, ma gioca un ruolo fondamentale anche la fortuna.\n";
  armor=NULL;
  weapon=NULL; 
  currentx=0; 
  currenty=0; 
  i=new Inventario; 
  ability=new SpecialAbility(); 
  infected=false;
  task=new Task;
  database=new Database();
  visore=new Visore();}

 
 int Player::get_currentx() {return currentx;}
 int Player::get_currenty() {return currenty;}
 
 void Player::change_currentx(int x) {currentx=x;}
 void Player::change_currenty(int y) {currenty=y;}

 void Player::set_which_character(char n,int p) {
  switch(n){
   case ('1'): {player_t=Aalina; strength=6; endurance=10; intelligence=5; dexterity=5; luck=4; break;}
   case ('2'): {player_t=Borislav; strength=3; endurance=7; intelligence=10; dexterity=4; luck=5; break;}
   case ('3'): {player_t=Nikolai; strength=4; endurance=8; intelligence=4; dexterity=9; luck=6; break;}
   case ('4'): {player_t=Sergey; strength=10; endurance=9; intelligence=2; dexterity=2; luck=2; break;}
  }
  character_creation(p,false); change_life((endurance+level)*10); }
  
 int Player::get_endurance() {return endurance;}
 
 int Player::get_strength() {return strength;}
 
 int Player::get_level() {return level;}

 int Player::get_life() {return life;}

 int Player::get_dexterity() {return dexterity;}
 void Player::dec_dexterity() {if (dexterity>0) dexterity--;}

 int Player::get_intelligence() {return intelligence;}

 int Player::get_luck() {return luck;}
 
 int Player::get_damage_min() {return damage_min;}
 int Player::get_damage_max() {return damage_max;}

 SpecialAbility* Player::get_ability() {return ability;}

 Database* Player::get_database() {return database;}

 Task* Player::get_task() {return task;}
 
 Inventario* Player::get_inventario() {return i;}
 
 Visore* Player::get_visore() {return visore;}

 void Player::change_crippled(bool a) {crippled=a;}

 bool Player::is_crippled() {return crippled;}

 int Player::get_experience() {return experience;}
 
 void Player::inc_experience(int exp) {if (exp+experience>=MAX_EXPERIENCE) next_level(exp); else {experience+=exp;}}
 

 void Player::next_level(int exp){
  experience=(exp+experience-MAX_EXPERIENCE);
  level++; 
  cout<<"Livello "<<level<<" raggiunto.\nPotenzia le tue statistiche.\n";
  sleep(1);
  if (level<5)
   skill_points++;
  else
   skill_points+=(level-1)/2;
   MAX_EXPERIENCE+=50; 
   MAX_ENERGY+=(level*10);}

 
 void Player::change_damage(){
  double min=0.5,max=1.0;
  double s=strength+level;
  double mult_min=1.0,mult_max=1.0;
  switch(player_t){
    case (Aalina): {if (weapon!=NULL){
                     if (weapon->fire_gun()){
                      mult_min=1.2; 
                      mult_max=1.4;}} break;}
    case (Borislav): {if (weapon!=NULL){
                       if (weapon->explosive_gun()){
                        mult_min=1.2; 
                        mult_max=1.4;}} break;} 
    case (Nikolai): {if (weapon!=NULL){
                      if (weapon->white_gun()){
                       mult_min=1.2; 
                       mult_max=1.4;}} break;}
    case (Sergey): {if (weapon!=NULL){
                     if (weapon->huddle_gun()){
                      mult_min=1.2; 
                      mult_max=1.4;}} break;}
    default: {mult_min=1.0,mult_max=1.0; break;}}
  if (weapon!=NULL){
   weapon->get_damage(&min,&max);}
  damage_min=(int) (3+s*min*mult_min);
  damage_max=(int) (6+s*max*mult_max);}
  

 bool Player::enough_energy(int n){	                                                                                
  if ((n+energy)>=0)
   return true;
  else
   return false;}


 void Player::change_energy(int n){                                                                                             
  if (n+energy>MAX_ENERGY)
   energy=MAX_ENERGY;
  else{
   if ((n+energy)<0){
    energy=0;}
   else{
    energy+=n;}}}


 int Player::get_energy() {return energy;}

 int Player::get_max_life() {return MAX_LIFE;}
 
 int Player::get_max_energy() {return MAX_ENERGY;}

 int Player::get_max_experience() {return MAX_EXPERIENCE;}

 void Player::character_creation(int lpoints, bool flag){//true se può non spendere, false altrimenti
  int points=lpoints+skill_points;
  int temp1=strength;
  int temp2=endurance;
  int temp3=intelligence;
  int temp4=dexterity;
  int temp5=luck;
  int sub=1;
  int add=1;
  struct c_stats {int val; int min; int cap;};
  c_stats vec[5];	
  switch (player_t){
    case (Aalina): {vec[0].cap=11; vec[1].cap=19; vec[2].cap=9; vec[3].cap=9; vec[4].cap=8; break;}
    case (Borislav): {vec[0].cap=5; vec[1].cap=13; vec[2].cap=19; vec[3].cap=7; vec[4].cap=10; break;}
    case (Nikolai): {vec[0].cap=7; vec[1].cap=15; vec[2].cap=7; vec[3].cap=17; vec[1].cap=12; break;}
    case (Sergey): {vec[0].cap=19; vec[1].cap=17; vec[2].cap=3; vec[3].cap=3; vec[3].cap=4; break;}}
  vec[0].val=strength;
  vec[0].min=strength;
  vec[1].val=endurance;
  vec[1].min=endurance;
  vec[2].val=intelligence;
  vec[2].min=intelligence;
  vec[3].val=dexterity;
  vec[3].min=dexterity;
  vec[4].val=luck;
  vec[4].min=luck;
  int scelta_ability=ability->get_choose();
  const char* print_stat[5];
  print_stat[0]="FORZA";
  print_stat[1]="COSTITUZIONE";
  print_stat[2]="INTELLIGENZA";
  print_stat[3]="AGILITA'";
  print_stat[4]="FORTUNA";
  int index;
  char tmp='\0';
  while ((tmp!='f')||((points>0)&&(!flag))){
   strength=temp1;
   endurance=temp2;
   intelligence=temp3;
   dexterity=temp4; 
   luck=temp5;
   char inc_dec='\0';
   clear_screen();  
   cout<<"PUNTI DISPONIBILI: "<<points;
   cout<<"\nDigita una lettera per scegliere la statistica da modificare o 'f' per confermare:";
   cout<<"\n\na)Forza: "<<strength<<" + "<<vec[0].val-strength<<"			AUMENTA IL DANNO E IL CARICO MASSIMO CHE PUOI PORTARE\n";
   cout<<"\nb)Costituzione: "<<endurance<<" + "<<vec[1].val-endurance<<"		AUMENTA LA VITA MASSIMA \n";
   cout<<"\nc)Intelligenza: "<<intelligence<<" + "<<vec[2].val-intelligence<<"		DIMINUISCE IL COSTO DELLE ABILITA' SPECIALI E INCREMENTA LA POTENZA DEI MED-PAC\n";
   cout<<"\nd)Agilità: "<<dexterity<<" + "<<vec[3].val-dexterity<<"		AUMENTA LA PROBABILITA' DI EVITARE GLI ATTACCHI\n";
   cout<<"\ne)Fortuna: "<<luck<<" + "<<vec[4].val-luck<<"		PERMETTE DI TROVARE OGGETTI UTILI PIU' FACILMENTE\n";
   cout<<"\ns)Abilità speciale:\t"<<ability->get_name()<<endl;
   cout<<endl<<endl;
      strength=vec[0].val;
  endurance=vec[1].val;
  intelligence=vec[2].val,
  dexterity=vec[3].val;
  luck=vec[4].val;
    change_damage();
  set_life();  
  i->change_max_weight(this);
  set_max_equipment_weight();
  i->change_max_medpack(this);
  i->change_max_adrenaline(this);
  i->change_max_antidoti(this);
   cout<<"Statistiche correnti:\n\t<"<<name<<">\n\tDANNO DISARMATO:\t\t\t\t"<<3+(vec[0].val+level)/2<<"-"<<6+(vec[0].val+level)<<"\n\tVITA MASSIMA:\t\t\t\t\t"<<MAX_LIFE<<"\n";
   cout<<"\tPESO MASSIMO INVENTARIO:\t\t\t"<<i->get_max_weight()<<endl;
   cout<<"\tCARICO MASSIMO EQUIPAGGIAMENTO:\t\t\t"<<MAX_EQUIPMENT_WEIGHT<<endl;
   cout<<"\tENERGIA MASSIMA:\t\t\t\t"<<MAX_ENERGY<<endl;
   cout<<"\tPOTENZA MED-PAC:\t\t\t\t"<<force_med_pack+vec[2].val<<endl;
   int prob=(int) (vec[3].val*8/3+1);
   cout<<"\tPROBABILITA' DI EVITARE UN ATTACCO:\t\t"<<prob<<"%"<<endl;
   cout<<"\tSCOPERTA OGGETTI:\t\t\t\t"<<(vec[4].val)<<"%\n";
   cout<<"\tNUMERO MASSIMO DI MED-PAC:\t\t\t"<<i->get_max_medpack()<<endl;
   cout<<"\tNUMERO MASSIMO DI FIALE DI ADRENALINA:\t\t"<<i->get_max_adrenaline()<<endl;
   cout<<"\tNUMERO MASSIMO DI ANTIDOTI:\t\t\t"<<i->get_max_antidoti()<<endl;
   if (ability->get_energy_needed()!=0){
    cout<<endl;
    cout<<ability->get_name()<<"\n";
    cout<<"\tCOSTO:\t\t\t"<<ability->get_energy_needed(intelligence)*-1<<"\n";
    cout<<"\tPROPRIETA':"; ability->print_property(this);}
   tmp=getch();
   switch (tmp){
     case ('a'): {index=0; clear_screen(); break;}
     case ('b'): {index=1; clear_screen(); break;}
     case ('c'): {index=2; clear_screen(); break;}
     case ('d'): {index=3; clear_screen(); break;}
     case ('e'): {index=4; clear_screen(); break;}
     case ('s'): {inc_dec='f';
                  clear_screen();
                  ability->choose(&points,vec[2].val,scelta_ability);
                  clear_screen(); break;}
     case ('f'): {if ((points>0)&&!flag){
                   cout<<"Devi completare la creazione personaggio!\n"; 
                   clear_screen();} 
                  else{
                   cout<<"Personalizzazione completata!\n"; 
                   skill_points=points;} 
                  inc_dec='f'; 
                  sleep(1); break;}         
     default: {clear_screen(); inc_dec='f'; break;}}
   while(inc_dec!='f'){
    if (vec[index].val>=vec[index].cap) sub=2; else sub=1;
    if (vec[index].val>vec[index].cap) add=2; else add=1;
    cout<<"\nPUNTI DISPONIBILI: "<<points<<"\n\n Digita '+' per incrementare, '-' per decrementare e 'f' per tornare indietro.			"<<print_stat[index]<<": "<<vec[index].val<<"  COSTO: "<<sub<<endl<<endl;
      strength=vec[0].val;
  endurance=vec[1].val;
  intelligence=vec[2].val,
  dexterity=vec[3].val;
  luck=vec[4].val;
    change_damage();
  i->change_max_weight(this);
  set_max_equipment_weight();
  i->change_max_medpack(this);
  i->change_max_adrenaline(this);
  i->change_max_antidoti(this);
    cout<<"Statistiche correnti:\n\t<"<<name<<">\n\tDANNO DISARMATO:\t\t\t\t"<<3+(vec[0].val+level)/2<<"-"<<6+(vec[0].val+level)<<"\n\tVITA MASSIMA:\t\t\t\t\t"<<(vec[1].val+level)*10<<"\n";
   cout<<"\tPESO MASSIMO INVENTARIO:\t\t\t"<<i->get_max_weight()<<endl;
   cout<<"\tCARICO MASSIMO EQUIPAGGIAMENTO:\t\t\t"<<MAX_EQUIPMENT_WEIGHT<<endl;
   cout<<"\tENERGIA MASSIMA:\t\t\t\t"<<MAX_ENERGY<<endl;
   cout<<"\tPOTENZA MED-PAC:\t\t\t\t"<<force_med_pack+vec[2].val<<endl;
   int prob=(int) (vec[3].val*8/3+1);
   cout<<"\tPROBABILITA' DI EVITARE UN ATTACCO:\t\t"<<prob<<"%"<<endl;
   cout<<"\tSCOPERTA OGGETTI:\t\t\t\t"<<(vec[4].val)<<"%\n";
   cout<<"\tNUMERO MASSIMO DI MED-PAC:\t\t\t"<<i->get_max_medpack()<<endl;
   cout<<"\tNUMERO MASSIMO DI FIALE DI ADRENALINA:\t\t"<<i->get_max_adrenaline()<<endl;
   cout<<"\tNUMERO MASSIMO DI ANTIDOTI:\t\t\t"<<i->get_max_antidoti()<<endl;
    if (ability->get_energy_needed()!=0){
     cout<<endl;
     cout<<ability->get_name()<<"\n";
     cout<<"\tCOSTO:\t\t\t"<<ability->get_energy_needed(intelligence)*-1<<"\n";
     cout<<"\tPROPRIETA':"; ability->print_property(this);}
    inc_dec=getch();
    if ((inc_dec=='+')&&((points-sub)>=0)){
     vec[index].val++;
     points-=sub;
     clear_screen();}
    else if ((inc_dec=='-')&&(vec[index].val>vec[index].min)){
     vec[index].val--;
     points+=add;
     clear_screen();}
    else 
     clear_screen();}}
  strength=vec[0].val;
  endurance=vec[1].val;
  intelligence=vec[2].val,
  dexterity=vec[3].val;
  luck=vec[4].val;
  set_life();  
  change_damage(); 
  i->change_max_weight(this);
  set_max_equipment_weight();
  i->change_max_medpack(this);
  i->change_max_adrenaline(this);
  i->change_max_antidoti(this);
  delete ability;
  ability=new SpecialAbility(scelta_ability,intelligence);}
         
      
 void Player::set_life() {MAX_LIFE=(endurance+level)*10;}


 void Player::set_max_equipment_weight() {MAX_EQUIPMENT_WEIGHT=12+((endurance+strength+level)/10);}

 
 void Player::change_life(int points){ 
  if ((points+life)>(MAX_LIFE))
   life=MAX_LIFE;
  else if ((points+life)>(MIN_LIFE)) 
   life+=points;  
  else
   life=MIN_LIFE;}

   
 void Player::change_name(const char* n) {strcpy(name,n);}


 char* Player::get_name(){
  char* n=name;
  return n;}


 char Player::get_init_name() {return name[0];}
                                                                                  

 bool Player::is_in_weapon() {return weapon!=NULL;}
 bool Player::is_in_armor() {return armor!=NULL;}			


 Weapon* Player::which_weapon() {return  weapon;}
 Armor* Player::which_armor() {return  armor;}
 
 
 bool Player::dead(){
  if (life<=MIN_LIFE)
   return true;
  else 
   return false;}


 bool Player::is_infected() {return infected;}

 void Player::poison_check(bool a){
  if (a){
   int poison=(((double)life)/100)*2+1;
   change_life(-poison);}
  else{
   if (infected)
    change_life(-1);}}


 void Player::change_infected(bool b) {infected=b;}
 
 
 bool Player::is_in_p(int x, int y) { 
  if ((x==(currentx))&&(y==(currenty)))
   return true;
  else return false;}

 
 void Player::set_overload(){
  equipment_weight=0;
  bool sett=false,cento=false;
  if (perc_carico<70){
   sett=true;}
  else{
   if (perc_carico<100) 
    cento=true;}
  if (armor!=NULL){
   equipment_weight+=armor->get_weight();}
  if (weapon!=NULL){
   equipment_weight+=weapon->get_weight();}
  perc_carico=(int) ((((double)equipment_weight)/MAX_EQUIPMENT_WEIGHT)*100);
  if (perc_carico<70){
   if (agility_lost_point>0){
    dexterity+=agility_lost_point; 
    agility_lost_point=0;}}
  else{
   if ((perc_carico>70)&&(perc_carico<=100)){
    if (agility_lost_point>0){
     dexterity+=agility_lost_point;}
    agility_lost_point=dexterity*3/10;
    dexterity-=agility_lost_point;
    if (sett){
     slow_print((char*)"L'equipaggiamento ha superato il 70% della soglia di carico\n");}}
   else{
    if (agility_lost_point>0){
     dexterity+=agility_lost_point;}
     agility_lost_point=dexterity*4/5;
     dexterity-=agility_lost_point;
    if (cento){
     slow_print((char*)"L'equipaggiamento ha superato la soglia di carico. Perdi molta agilità\n");}}}}
     

 void Player::statistiche() {
  cout<<"STATISTICHE DI GIOCO:\n     "<<name<<"\n";
  if (((life/((double)MAX_LIFE))*100) <20){
   cout<<BOLD(FRED("\tVITA:\t")); cout<<life; cout<<BOLD(FRED("/")); cout<<MAX_LIFE<<endl;} 
  else{
   if (infected)
    cout<<BOLD(FGRN("\tVITA:\t"))<<life<<BOLD(FGRN("/"))<<MAX_LIFE<<BOLD(FGRN("\t[INFETTO]"))<<endl;
   else
    cout<<"\tVITA:\t"<<life<<"/"<<MAX_LIFE<<endl;}
  cout<<"\tDANNO:\t"<<damage_min<<"-"<<damage_max<<endl;
  cout<<BOLD(FRED("\n\tFORZA:\t\t"))<<strength<<endl;
  cout<<BOLD(FBLU("\tCOSTITUZIONE:\t"))<<endurance<<endl;
  cout<<BOLD(FGRN("\tINTELLIGENZA:\t"))<<intelligence<<endl;
  cout<<BOLD(FYEL("\tAGILITA':\t"))<<dexterity<<endl;
  cout<<BOLD("\tFORTUNA:\t")<<luck<<endl;
  cout<<"\n\tLIVELLO:\t"<<level<<endl;
  cout<<"\tESPERIENZA:\t"<<experience<<"/"<<MAX_EXPERIENCE<<endl;
  cout<<"\tENERGIA:\t"<<energy<<"/"<<MAX_ENERGY<<endl;
  cout<<endl;
  cout<<"\t"; visore->print_battery();
  cout<<endl<<endl;
  if (equipment_weight>0){
   cout<<"\tEQUIPAGGIAMENTO:\t["<<equipment_weight<<"/"<<MAX_EQUIPMENT_WEIGHT<<"]\n";
   cout<<endl;
   if (weapon!=NULL){
   cout<<"\tARMA:\n\t";
   weapon->print_name_and_ammos();}
   if (armor!=NULL){
   cout<<"\tARMATURA:\n"; 
   armor->print_name_power_and_immunity();}
   cout<<endl;
   cout<<"\tFATTORE DI CARICO:\t"<<perc_carico<<"%"<<endl<<endl<<endl;}
  if (ability->get_energy_needed()<0){
  cout<<endl;
  cout<<"\tABILITA' SPECIALE:\n\t\t"<<ability->get_name()<<endl;
  cout<<"\t\tCOSTO IN ENERGIA:\t"<<-1*(ability->get_energy_needed())<<endl;
  ability->print_property(this);
  cout<<endl;}}
 

 void Player::change_weapon(Weapon* w){ weapon=w;}
 void Player::change_armor(Armor* a){armor=a;}

 

 void Player::consuma(bool in_combat) {
  bool flag=true;
  cons[0].more=i->more_med_pack();
  cons[0].val=i->get_med_pack();
  cons[0].max=i->get_max_medpack();
  cons[1].more=i->more_adrenaline();
  cons[1].val=i->get_adrenaline();
  cons[1].max=i->get_max_adrenaline();
  cons[2].more=i->more_antidoti();
  cons[2].val=i->get_antidoti();
  cons[2].max=i->get_max_antidoti();
  int s=0;
  while ((cons[0].more||cons[1].more||cons[2].more)&&(flag)){
   clear_screen();
   cout<<"Scegli cosa vuoi consumare:\t['a' per scorrere indietro, 'd' per scorrere in avanti,'i' per le info,'e' per consumare,'f' per uscire]\n";
   while (!cons[s].more){
    if (s==2) 
     s=0; 
    else 
     s++;}
   cout<<endl;
   cout<<cons[s].name<<cons[s].val<<"/"<<cons[s].max<<endl;
   cout<<endl<<endl;
   if (((life/((double)MAX_LIFE))*100) <20){
    cout<<BOLD(FRED("\tVITA:\t")); cout<<life; cout<<BOLD(FRED("/")); cout<<MAX_LIFE<<endl;} 
   else{
    if (infected)
     cout<<BOLD(FGRN("\tVITA:\t"))<<life<<BOLD(FGRN("/"))<<MAX_LIFE<<BOLD(FGRN("\t[INFETTO]"))<<endl;
    else
     cout<<"\tVITA:\t"<<life<<"/"<<MAX_LIFE<<endl;}
   cout<<"\tENERGIA\t"<<energy<<"/"<<MAX_ENERGY<<endl;
   char c;
   c=getch();
   switch (c){
     case ('a'): {if (s==0) s=2; else s--; break;}
     case ('d'): {if (s==2) s=0; else s++; break;}
     case ('i'): {cout<<endl; cout<<cons[s].info; getch(); clear_screen(); break;}
     case ('e'): {switch (s){
                    case (0): {change_life(force_med_pack+intelligence); i->dec_med_pack(); if (in_combat) flag=false; break;}
                    case (1): {i->dec_adrenaline(); change_energy(ADRENALINE_TOKEN); if (in_combat) flag=false; break;}
                    case (2): {i->dec_antidoti(); change_infected(false);if (in_combat) flag=false; break;}} break;}
     case ('f'): {flag=false;  break;}
     default: {break;}}
   cons[0].val=i->get_med_pack();
   cons[1].val=i->get_adrenaline();
   cons[2].val=i->get_antidoti();
   if (cons[s].val<1) cons[s].more=false;}}


  
 void Player::unequip(Node* position) {
  bool armor_t=true, armi=true;
  if ((armor!=NULL)&&(weapon!=NULL)){
   char c;
   bool flag=true;
   bool testa=true;
   do{
    clear_screen();
    cout<<"Cosa vuoi lasciare?\t[Premi 'a' per scorrere indietro, 'd' per scorrere avanti, 'e' per selezionare,'f' per uscire]\n";
    if (testa)
     weapon->print_name_and_ammos();
    else
     armor->print_name_power_and_immunity();
    c=getch();
    switch (c){
      case ('a'): {testa=!testa; break;}
      case ('d'): {testa=!testa; break;}
      case ('e'): {if (testa) {armor_t=false;} else {armi=false;} flag=false; break;}
      case ('f'): {flag=false; armor_t=false; armi=false; break;}
      case ('p'): {this->statistiche(); break;}}}
   while (flag);}
   if ((armor!=NULL)&&armor_t){
    cout<<"Non sei più protetto da "<<(armor->get_name())<<"!\n";
    position->push_armature(armor);
    armor=NULL;}
   if ((weapon!=NULL)&&armi){
    cout<<"Hai lasciato "<<(weapon->get_name())<<". Ora sei a mani nude!\n";
    position->push_weapons(weapon);
    weapon=NULL;
    change_damage();}
   set_overload();
   clear_screen();}

