#ifndef ENEMY_HPP_
#define ENEMY_HPP_
#include "MyLibrary.hpp"

#define MIN_LIFE 0
class Weapon;
class Armor;
class Player;
class Node;
#ifndef tipi_armi_armature
#define tipi_armi_armature
enum weapon_type{fasce_da_combattimento,mazza,manganello,scure_antincendio,laser_chirurgico,coltello,spara_chiodi,pistola,uzi,arpione,fucile_a_pompa,lanciagranate,balestra_esplosiva,sniper,
lanciafiamme,lanciarazzi,pistola_particellare,fucile_sperimentale};
enum armor_type{vesti_da_laboratorio,completo_di_pelle,tuta_hazmat,scafandro,giubotto_antiproiettile,corazza};
enum type_of_weapon{no_res,light_fire_weapon,heavy_fire_weapon,explosive_weapon,huddle_weapon,white_weapon,special_weapon};
enum type_of_immunity{no_immunity,chemical_agent,poison,firearm,cutlass};
#endif

#ifndef monster_type
#define monster_type
enum type_monster{station_keeper,toxic_nurse,energumen_mutated,scaled_experiment,river_guardian,sewer_walker,underground_prisoner,mad_doctor,improved_soldier,cyborg_fighter};
#endif

 const int num_enemy=10;

 class Enemy{ 
  protected:
   int life;
   int strength;
   int level;
   type_monster type;
   int damage_min;
   int damage_max;
   type_of_immunity offense_type;
   int stunned;
   char name[25];
   type_of_weapon res;
   type_of_weapon vul;
   Weapon* weapon;
   Armor* armor;
   void set_level(int);
   void set_weapon(int);
   void set_armor(int);
   void change_damage();
  public:
   Enemy(int,int);
   int get_life();
   int get_damage_min();
   int get_damage_max();
   char* get_name();
   
   type_of_weapon get_resistance();
   type_of_immunity get_offense();
   bool is_poisoned();
  
   bool has_weapon();
   bool has_armor();
  
   Weapon* get_weapon();
   Armor* get_armor();
   
   bool is_stunned();
   void dec_stunned();
   void set_stunned(int);

   type_monster get_monster_type();
   int get_level();
   void change_life(int n);
   bool is_dead();
   bool combat(Node*,Player*,int);
};
#endif
