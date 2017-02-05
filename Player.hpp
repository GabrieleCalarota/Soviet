#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include "MyLibrary.hpp"
 class Inventario;
 class Node;
 class Task;
 class Enemy;
 class Database;
 class Weapon;
 class Armor;
 class Map;
 class Boss;
 class SpecialAbility;
 class Visore;

 const int ADRENALINE_TOKEN=40;
 const int EXPERIENCE_TOKEN=40;



 class Player {
  protected:
   enum player_type{Aalina,Borislav,Nikolai,Sergey};  
   struct consumabili{bool more; int val; const char* name; const char* info; int max;};
   char name[25];
   player_type player_t;
   int life;
   int strength;
   int endurance;
   int dexterity;
   int intelligence;
   int luck;
   int MAX_LIFE;
   int level;
   int experience;
   int MAX_EXPERIENCE;
   int skill_points;
   int energy;
   int MAX_ENERGY;
   consumabili cons[3];
   Weapon* weapon;
   Armor* armor;
   bool infected;
   bool crippled;
   int currentx;
   int currenty;
   int damage_min;
   int damage_max;
   int equipment_weight;
   int MAX_EQUIPMENT_WEIGHT;
   int perc_carico;
   int agility_lost_point;
   SpecialAbility* ability;
   Task* task;
   Database* database;
   Visore* visore;
   Inventario* i; 
   void set_max_equipment_weight();
  public:
   Player();
   int get_currentx();
   int get_currenty();

   
   void change_currentx(int);
   void change_currenty(int);

    
   void set_which_character(char,int); 

   
   int get_life();
   int get_max_life();
   void set_life();
   void change_life(int);

  
   int get_level();
   void next_level(int);

  
   int get_intelligence();
   int get_strength();
   int get_endurance();
   int get_dexterity();  
   void dec_dexterity();
   int get_luck();

  
   int get_experience();
   int get_max_experience();
   void inc_experience(int);

  
   void change_energy(int);
   bool enough_energy(int);
   int get_energy();
   int get_max_energy();

  
   void change_damage();
   int get_damage_min();
   int get_damage_max();


   SpecialAbility* get_ability();
   Database* get_database();
   Visore* get_visore();
   Inventario* get_inventario();
   Task* get_task();

   void change_crippled(bool);
   bool is_crippled();
    
   void character_creation(int,bool);
  
   void change_name(const char*);
   char get_init_name();
   char* get_name();
   
   bool is_in_weapon();
   bool is_in_armor();
   Weapon* which_weapon();
   Armor* which_armor(); 
   void set_overload();
   void change_armor(Armor*);
   void change_weapon(Weapon*);

   void poison_check(bool);

  
   bool dead();
   bool is_in_p(int,int);
   void statistiche();
   void consuma(bool);
   void unequip(Node*);
   bool is_infected();
   void change_infected(bool);
 };
#endif
