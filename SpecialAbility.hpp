#ifndef SPECIAL_ABILITY_HPP
#define SPECIAL_ABILITY_HPP
#include "MyLibrary.hpp"

 class Player;
 class Enemy;
 class Boss;

 class SpecialAbility{
  protected:
   enum special_ability_type{nessuna,mira_perfetta,stordimento,furtivita_letale,impeto_di_forza};
   special_ability_type type;
   int energy_needed;
   int get_energy();
   void set_energy(int);
   int get_points_needed();
  public:
   SpecialAbility(int,int);
   SpecialAbility();
   char* get_name();
   void unleash_special_ability(Enemy*,Player*);
   void unleash_special_ability(Boss*,Player*);
   int get_energy_needed(int);
   int get_energy_needed();
   bool use(Player*,Enemy*,Boss*);
   void print_info();
   int get_choose();
   void choose(int*,int,int&);
   void print_property(Player*);
 };
#endif
