#include "Armor.hpp"
#include "ArmorInfo.hpp"


 Armor::Armor(armor_type t){					
  a=t;
  set_name();
  set_power();
  set_weight();
  set_immunity_type();
  cont_immunity=set_max_immunity();}

 Armor::Armor(armor_type t,int i){				
  a=t;
  set_name();
  set_power();
  set_weight();
  set_immunity_type();
  set_immunity(i);}

 void Armor::set_name(){					
  switch (a){
    case (vesti_da_laboratorio): {strcpy(name,(char*)"Vesti da Laboratorio"); break;}
    case (completo_di_pelle): {strcpy(name,(char*)"Completo di Pelle"); break;}
    case (tuta_hazmat): {strcpy(name,(char*)"Tuta HAZMAT"); break;}
    case (scafandro): {strcpy(name,(char*)"Scafandro"); break;}
    case (giubotto_antiproiettile): {strcpy(name,(char*)"Giubotto Antiproiettile"); break;}
    case (corazza): {strcpy(name,(char*)"Corazza"); break;}
    default: {strcpy(name,(char*)"Armatura non identificata!"); break;}}}
    
    
 void Armor::set_name_immunity(){				
  switch (type){
    case (no_immunity): {strcpy(name_immunity,(char*)"Niente"); break;}
    case (chemical_agent): {strcpy(name_immunity,(char*)"Agenti chimici"); break;}
    case (poison): {strcpy(name_immunity,(char*)"Veleni"); break;}
    case (cutlass): {strcpy(name_immunity,(char*)"Armi da taglio"); break;}
    case (firearm): {strcpy(name_immunity,(char*)"Armi da fuoco"); break;}
    default: {strcpy(name_immunity,(char*)"Immunità non identificata!"); break;}}}
    
    
 void Armor::set_power(){				
  switch (a){
    case (vesti_da_laboratorio): {power=value_armor_vesti;}
    case (completo_di_pelle): {power=value_armor_pelle; break;}
    case (tuta_hazmat): {power=value_armor_hazmat; break;}
    case (scafandro): {power=value_armor_scafandro; break;}
    case (giubotto_antiproiettile): {power=value_armor_giubotto; break;}
    case (corazza): {power=value_armor_corazza; break;}
    default: {power=value_armor_free; break;}}}
    
    
 void Armor::set_immunity_type(){
  switch (a){
    case (vesti_da_laboratorio): {type=no_immunity; break;}
    case (completo_di_pelle): {type=cutlass; break;}
    case (tuta_hazmat): {type=chemical_agent; break;}
    case (scafandro): {type=poison; break;}
    case (giubotto_antiproiettile): {type=firearm; break;}
    case (corazza): {type=firearm; break;}}  
  set_name_immunity();}
  
  
 void Armor::set_weight(){
 switch (a){
   case (vesti_da_laboratorio): {weight=4; break;}
   case (completo_di_pelle): {weight=5; break;}
   case (tuta_hazmat): {weight=8; break;}
   case (scafandro): {weight=10; break;}
   case (giubotto_antiproiettile): {weight=12; break;}
   case (corazza): {weight=14; break;}
   default: {weight=0; break;}}}
   
   
 void Armor::set_immunity(int i){
  if ((i+cont_immunity)>(set_max_immunity())) 
   cont_immunity=set_max_immunity();
  else 
   cont_immunity+=i;}
 

 int Armor::set_max_immunity(){
  switch (type){
    case (no_immunity): {return 0; break;}
    case (chemical_agent): {return 15; break;}
    case (poison): {return 12; break;}
    case (cutlass): {return 10; break;}
    case (firearm): {return 7; break;}
    default: {return 0; break;}}}
    

 bool Armor::is_immune() {return (cont_immunity>0);}


 bool Armor::is_immune(type_of_immunity t) {return (t==type);}


 char* Armor::get_name(){
  char *n=name; 
  return n;}


 void Armor::print_power(){
  int a=(int) ((power/3)*100);
  cout<<"\t\tPotenza:\t"<<a<<"%"<<endl;}


 int Armor::get_weight() {return weight;}
  

 char* Armor::get_name_immunity(){
  char* n=name_immunity; 
  return n;}


 void Armor::print_immunity(){
  if (is_immune()){
   int a=(int) (((double) cont_immunity)/set_max_immunity()*100);
   a=100-a;
   cout<<"\t\tImmunità contro <"<<name_immunity<<"> al "<<a<<"%";
   cout<<" di usura"<<endl;}}

   
 void Armor::print_name_power_and_immunity(){
  cout<<"\t\t"<<name<<endl;
  print_power();
  print_immunity();}

  
 void Armor::print_armor_info(){
  switch (a){
    case (vesti_da_laboratorio): {cout<<vesti_da_laboratorio_armor_info; break;}
    case (completo_di_pelle): {cout<<completo_di_pelle_armor_info;break;}
    case (tuta_hazmat): {cout<<tuta_hazmat_armor_info;  break;}
    case (scafandro): {cout<<scafandro_armor_info; break;}
    case (giubotto_antiproiettile): {cout<<giubotto_armor_info; break;}
    case (corazza): {cout<<corazza_armor_info;break;}}}


 int Armor::get_cont_immunity() {return cont_immunity;}


 bool Armor::has_more_immunity(){
  return (cont_immunity>0);}


 void Armor::use_immunity(){
  cont_immunity--;}


 armor_type Armor::get_enum_armor() {return a;}


 bool Armor::confronta(Armor* b){
  return (b->get_enum_armor()==a);}
  

 int Armor::absorb(int c){
  c=(int) (c/power);
  return c;}
  

 void Armor::merge(Armor* b){					//FONDE DUE ARMATURE (PER TERRA E IN INVENTARIO)
  int i=b->get_cont_immunity();
  set_immunity(i);}
