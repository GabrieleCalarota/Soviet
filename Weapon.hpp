#ifndef WEAPON_HPP_
#define WEAPON_HPP_
#include "MyLibrary.hpp"
#ifndef tipi_armi_armature
#define tipi_armi_armature

 enum weapon_type{fasce_da_combattimento,mazza,manganello,scure_antincendio,laser_chirurgico,coltello,spara_chiodi,pistola,uzi,arpione,fucile_a_pompa,lanciagranate,balestra_esplosiva,sniper,
lanciafiamme,lanciarazzi,pistola_particellare,fucile_sperimentale};
enum armor_type{vesti_da_laboratorio,completo_di_pelle,tuta_hazmat,scafandro,giubotto_antiproiettile,corazza};
enum type_of_weapon{no_res,light_fire_weapon,heavy_fire_weapon,explosive_weapon,huddle_weapon,white_weapon,special_weapon};
enum type_of_immunity{no_immunity,chemical_agent,poison,firearm,cutlass};
#endif

 class Weapon{
  protected:
   char name[25];
   weapon_type w;
   int ammos;
   type_of_weapon type;
   double damage_min;
   double damage_max;
   int weight;
   void set_weight();
   void set_name();
   void set_damage();
   int set_max_ammos();
   void set_type();
   void set_ammos(int);
  public:
   Weapon(weapon_type);
   Weapon(weapon_type,int);
   void shoot();
   bool has_ammos();
   bool fire_gun();
   bool explosive_gun();
   bool white_gun();
   bool huddle_gun();
   void get_damage(double*,double*);
   void print_scheda_arma();
   void print_name_and_ammos();
   void print_ammos();
   int get_ammos();
   weapon_type get_enum_weapon();
   type_of_weapon which_type_of_weapon();
   char* get_name();
   int get_weight();
   void merge(Weapon*);
   bool confronta(Weapon*);
 };
#endif
