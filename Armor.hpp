#ifndef ARMOR_HPP_
#define ARMOR_HPP_
#include "MyLibrary.hpp"
#ifndef tipi_armi_armature
#define tipi_armi_armature
enum weapon_type{fasce_da_combattimento,mazza,manganello,scure_antincendio,laser_chirurgico,coltello,spara_chiodi,pistola,uzi,arpione,fucile_a_pompa,lanciagranate,balestra_esplosiva,sniper,
lanciafiamme,lanciarazzi,pistola_particellare,fucile_sperimentale};
enum armor_type{vesti_da_laboratorio,completo_di_pelle,tuta_hazmat,scafandro,giubotto_antiproiettile,corazza};
enum type_of_weapon{no_res,light_fire_weapon,heavy_fire_weapon,explosive_weapon,huddle_weapon,white_weapon,special_weapon};
enum type_of_immunity{no_immunity,chemical_agent,poison,firearm,cutlass};
#endif

 const double value_armor_vesti=1.1;      
 const double value_armor_pelle=1.4;      //TAGLIO
 const double value_armor_hazmat=1.8;     //CHIMICI
 const double value_armor_scafandro=2.2;  //POISON
 const double value_armor_giubotto=2.6;   //ANTIPROIETTILE
 const double value_armor_corazza=3.0;    //ANTIPROIETTILE
 const double value_armor_free=1.0;
 
 class Armor{
  protected:
   char name[25];
   armor_type a;
   double power;
   int weight;
   char name_immunity[25];
   type_of_immunity type;
   int cont_immunity;
   void set_name();
   void set_power();
   void set_immunity_type();
   void set_immunity(int);
   void set_name_immunity();
   int set_max_immunity();
   void set_weight();
  public:
   Armor(armor_type);
   Armor(armor_type,int);
   bool is_immune();
   bool is_immune(type_of_immunity);
   bool has_more_immunity();
   int get_weight();
   int get_cont_immunity();
   void merge(Armor*);
   void use_immunity();
   int absorb(int);
   char* get_name_immunity();
   armor_type get_enum_armor();
   bool confronta(Armor*);
   char* get_name();
   void print_power();
   void print_immunity();
   void print_name_power_and_immunity();
   void print_armor_info();
 };
#endif
