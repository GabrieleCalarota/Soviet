#ifndef BOSS_HPP
#define BOSS_HPP
#include "MyLibrary.hpp"

class Inventario;
class Weapon;
class Armor;
class Map;
class Player;
class SpecialAbility;
class Node;

#ifndef LISTA_PLAYERS
#define LISTA_PLAYERS
struct lista_players{ Player* p; lista_players* next;};
typedef lista_players* ptr_lista_players;
#endif


 class Boss{
  protected:
   int x;
   int y;
   int life;
   int strength;
   int damage_max;
   int damage_min;
   int smoke_bomb;
   int stunned;
   bool smoked;
   char name[25];
   int stop;
  public:
   Boss(int, int,int ,int);
   int get_x();
   int get_y();
   void change_currentx(int);
   void change_currenty(int);
   int get_life();
   void change_life(int);
   int get_damage_max();
   int get_damage_min();
   char* get_name();
   bool is_dead();
   bool boss_combat(Player*,bool,int*,Node*);
   int get_smoke_bomb();
   void dec_smoke_bomb();
   bool is_stunned();
   void set_stunned(int);
   void dec_stunned();
   bool is_smoked();
   void change_smoked(bool);
   int get_stop();
   void dec_stop();
   void set_stop(int);
   void check_boss(Player*,Map*,ptr_lista_players,bool,int*,Node*,int);
 };
#endif
