#include "Weapon.hpp"
#include "WeaponInfo.hpp"

 Weapon::Weapon(weapon_type a){
  w=a;
  set_name();
  set_weight();
  set_damage();
  ammos=set_max_ammos();
  set_type();}

  
 Weapon::Weapon(weapon_type a,int m){
  w=a;
  set_name();
  set_weight();
  set_damage();
  ammos=m;
  set_type();}


 void Weapon::set_weight(){
  switch (w){
    case (pistola): {weight= 4; break;}
    case (fucile_a_pompa): {weight= 7; break;}
    case (uzi): {weight= 5; break;}
    case (fasce_da_combattimento): {weight= 2; break;}
    case (coltello): {weight= 3; break;}
    case (mazza): {weight= 4; break;}
    case (scure_antincendio): {weight= 3; break;}
    case (spara_chiodi): {weight= 5; break;}
    case (laser_chirurgico): {weight= 2; break;}
    case (manganello): {weight= 3; break;}
    case (arpione): {weight= 4; break;}
    case (lanciagranate): {weight= 7; break;}
    case (balestra_esplosiva): {weight= 6; break;}
    case (sniper): {weight= 7; break;}
    case (lanciafiamme): {weight= 9; break;}
    case (lanciarazzi): {weight= 8; break;}
    case (pistola_particellare): {weight= 5; break;}
    case (fucile_sperimentale): {weight= 6; break;}
    default: {weight= 0; break;}}}

    
 void Weapon::set_name(){
  switch (w){
    case (pistola): {strcpy(name,(char*)"Pistola"); break;}
    case (fucile_a_pompa): {strcpy(name,(char*)"Fucile a Pompa"); break;}
    case (uzi): {strcpy(name,(char*)"UZI"); break;}
    case (fasce_da_combattimento): {strcpy(name,(char*)"Tirapugni"); break;}
    case (coltello): {strcpy(name,(char*)"Bisturi"); break;}
    case (mazza): {strcpy(name,(char*)"Mazza chiodata"); break;}
    case (scure_antincendio): {strcpy(name,(char*)"Scure Antincendio"); break;}
    case (spara_chiodi): {strcpy(name,(char*)"Sparachiodi"); break;}
    case (laser_chirurgico): {strcpy(name,(char*)"Laser Chirurgico"); break;}
    case (manganello): {strcpy(name,(char*)"Manganello"); break;}
    case (balestra_esplosiva): {strcpy(name,(char*)"Balestra Esplosiva"); break;}
    case (sniper): {strcpy(name,(char*)"Fucile di Precisione"); break;}
    case (arpione): {strcpy(name,(char*)"Arpione"); break;}
    case (lanciafiamme): {strcpy(name,(char*)"Lanciafiamme"); break;}
    case (lanciarazzi): {strcpy(name,(char*)"Lanciarazzi"); break;}
    case (lanciagranate): {strcpy(name,(char*)"Lanciagranate"); break;}
    case (pistola_particellare): {strcpy(name,(char*)"Pistola Particellare"); break;}
    case (fucile_sperimentale): {strcpy(name,(char*)"Fucile Sperimentale"); break;}
    default: {strcpy(name,(char*)"Arma non identificata!"); break;}}}

    
 void Weapon::set_damage(){
  switch (w){
    case (fasce_da_combattimento): {damage_min=0.6; damage_max=1.1; break;}
    case (manganello): {damage_min=0.6; damage_max=1.2; break;}
    case (scure_antincendio): {damage_min=0.7; damage_max=1.0; break;}
    case (laser_chirurgico): {damage_min=0.7; damage_max=1.2; break;}
    case (mazza): {damage_min=0.8; damage_max=1.3; break;} 
    case (coltello): {damage_min=0.8; damage_max=1.3; break;}
    case (spara_chiodi): {damage_min=0.7; damage_max=1.4; break;}
    case (pistola): {damage_min=1.2; damage_max=1.7; break;}
    case (uzi): {damage_min=1.3; damage_max=1.9; break;}
    case (arpione): {damage_min=1.4; damage_max=2.1; break;}
    case (fucile_a_pompa): {damage_min=1.5; damage_max=2.2; break;}
    case (lanciagranate): {damage_min=1.7; damage_max=2.4; break;}
    case (balestra_esplosiva): {damage_min=1.8; damage_max=2.5; break;}
    case (sniper): {damage_min=2.0; damage_max=2.1; break;}
    case (lanciafiamme): {damage_min=1.2; damage_max=2.8; break;}
    case (lanciarazzi): {damage_min=1.6; damage_max=3.0; break;}
    case (pistola_particellare): {damage_min=2.5; damage_max=3.3; break;}
    case (fucile_sperimentale): {damage_min=3.0; damage_max=4.0; break;}
    default: {damage_min=1.0; damage_max=1.0; break;}}}

    
 int Weapon::set_max_ammos(){
  switch (w){
    case (pistola): { return 16; break;}
    case (fucile_a_pompa): { return 8; break;}
    case (uzi): { return 12; break;}
    case (fasce_da_combattimento): { return 25; break;}
    case (coltello): { return 20; break;}
    case (mazza): {return 15; break;}
    case (scure_antincendio): {return 25; break;}
    case (spara_chiodi): {return 11; break;}
    case (laser_chirurgico): {return 10; break;}
    case (manganello): {return 20; break;}
    case (arpione): {return 6; break;}
    case (lanciagranate): {return 4; break;}
    case (balestra_esplosiva): {return 6; break;}
    case (sniper): {return 7; break;}
    case (lanciafiamme): {return 3; break;}
    case (lanciarazzi): {return 2; break;}
    case (pistola_particellare): {return 4; break;}
    case (fucile_sperimentale): {return 2; break;}
    default: {return 0; break;}}}
    

 void Weapon::set_type(){
  if ((w==pistola)||(w==uzi)||(w==spara_chiodi))
   type= light_fire_weapon;
  else if ((w==fucile_a_pompa)||(w==sniper)||(w==arpione))
   type= heavy_fire_weapon;
  else if ((w==lanciagranate)||(w==balestra_esplosiva)||(w==lanciarazzi)||(w==lanciafiamme))
   type= explosive_weapon;
  else if ((w==mazza)||(w==manganello)||(w==fasce_da_combattimento))
   type=huddle_weapon;
  else if ((w==coltello)||(w==scure_antincendio))
   type= white_weapon;
  else 
   type= special_weapon;}


 void Weapon::set_ammos(int m){
  if ((ammos+m)>set_max_ammos()) 
   ammos=set_max_ammos();
  else 
   ammos+=m;}


 void Weapon::shoot(){
  ammos--;}


 bool Weapon::has_ammos() {return (ammos>0);}


 void Weapon::get_damage(double* min,double* max){
  *min=damage_min;
  *max=damage_max;}

  
 void Weapon::print_scheda_arma(){
  switch(w){
    case (pistola): {cout<<pistola_weapon_info; break;}
    case (fucile_a_pompa): {cout<<fucile_a_pompa_weapon_info;break;}
    case (uzi): {cout<<uzi_weapon_info;break;}
    case (fasce_da_combattimento): {cout<<fasce_da_combattimento_weapon_info;  break;}
    case (coltello): {cout<<coltello_weapon_info; break;}
    case (mazza): {cout<<mazza_weapon_info; break;}
    case (scure_antincendio): {cout<<scure_weapon_info; break;}
    case (spara_chiodi): {cout<<sparachiodi_weapon_info; break;}
    case (laser_chirurgico): {cout<<laser_chirurgico_weapon_info; break;}
    case (manganello): {cout<<manganello_weapon_info; break;}
    case (arpione): {cout<<arpione_weapon_info; break;}
    case (lanciagranate): {cout<<lanciagranate_weapon_info; break;}
    case (balestra_esplosiva): {cout<<balestra_esplosiva_weapon_info;break;}
    case (sniper): {cout<<sniper_weapon_info;break;}
    case (lanciafiamme): {cout<<lanciafiamme_weapon_info; break;}
    case (lanciarazzi): {cout<<lanciarazzi_weapon_info; break;}
    case (pistola_particellare): {cout<<pistola_particellare_weapon_info; break;}
    case (fucile_sperimentale): {cout<<fucile_sperimentale_weapon_info; break;}
    default: {cout<<"ARMA non identificata"<<endl; break;}}}

    
 void Weapon::print_ammos(){
  if ((w==pistola)||(w==fucile_a_pompa)||(w==uzi)||(w==sniper)||(w==pistola_particellare)||(w==fucile_sperimentale)) {
   int m=1;
   if (w==uzi) 
    m=10;
   cout<<"\t\tMunizioni:\t"<<(ammos*m)<<"/"<<(set_max_ammos()*m)<<endl;}
  else{
   if ((w==arpione)||(w==lanciagranate)||(w==balestra_esplosiva)||(w==lanciarazzi)||(w==spara_chiodi)||(w==lanciafiamme)){
    cout<<"\t\tRicariche:\t"<<(ammos)<<"/"<<(set_max_ammos())<<endl;}
   else{
    int a=(int) ((((double)ammos)/set_max_ammos())*100) ;
    cout<<"\t\tFunzionante al:\t"<<a<<"%"<<endl;}}}


 void Weapon::print_name_and_ammos(){
  cout<<"\t"<<name<<endl;
  print_ammos();}


 int Weapon::get_ammos() {return ammos;}



 weapon_type Weapon::get_enum_weapon() {return w;}

 type_of_weapon Weapon::which_type_of_weapon() {return type;}


 void Weapon::merge(Weapon* b){
  int i=b->get_ammos();
  set_ammos(i);}


 bool Weapon::confronta(Weapon* b){
  return (b->get_enum_weapon()==w);}
  

 bool Weapon::fire_gun(){
  return ((type==light_fire_weapon)||(type==heavy_fire_weapon));}

 bool Weapon::huddle_gun(){
  return (type==huddle_weapon);}

 bool Weapon::explosive_gun(){
  return (type==explosive_weapon);}

 bool Weapon::white_gun(){
 return (type==white_weapon);}


 int Weapon::get_weight(){
  return weight;}

 char* Weapon::get_name(){
  char* s=name; return s;}
