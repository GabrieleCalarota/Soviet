#ifndef MAP_HPP_
#define MAP_HPP_
 class Node;
 class Player;
 class Coda;
 class Hash;
 class Boss;
 #include "MyLibrary.hpp"
 
#ifndef LISTA_PLAYERS
#define LISTA_PLAYERS
 struct lista_players{ Player* p; lista_players* next;};
 typedef lista_players* ptr_lista_players;
#endif
 const int enemies_constant=300;
 const int keys_constant=100;
 const int lockers_constant=100;
 const int antidotes_constant=100;
 const int med_pack_constant=100;
 const int max_length_river=100;
 const int L_Mappa=12;
 const int max_letter_level_1=3;
 const int max_letter_level_2=4;
 const int max_adrenaline_level_1=25;
 const int max_adrenaline_level_2=50;
 const int max_adrenaline_level_3=25;
 const int max_cadaveri_livello_2=50;
 const int max_battery_per_level=5;
 class Map{
  protected:
   struct insieme{ int x; int y;};
   enum cardinali{nord,sud,ovest,est};
   enum gift_type{a_weapon,a_armor,letter,adrenaline,battery};
   enum insert_type{i_enemy,i_med_pack,i_key,i_locker,i_antidote};
   Node* firstnode;
   int piano;
   int adrenalina_data;
   int battery_data;
   int enemies_found;
   int MAX_ENEMY;
   int lockers_found;
   int MAX_ARMADIETTI;
   int keys_found;
   int MAX_CHIAVI;
   int med_pack_found;
   int MED_PACK;
   int antidotes_found;
   int MAX_ANTIDOTI;
   insieme river[max_length_river];
   Hash* head_coordinate;
   Boss* boss;

   void generate_river(insieme[],const int);
   bool is_in_object(insieme[],int,int,int);
   void visit();
   void print_color_text(char);
   void move_boss(Player*);
   bool insert_chance(insert_type, Player*);
  public:
   Map(Node*,int);
   void delete_map();
   void stampa(ptr_lista_players, Player*);
   Node* pushNode(int,int);
   Node* get_node(int, int);
   void insert_things_node(Node*,int,Player*);
   void give_gift(Node*,Player*);
   void generate_boss(Player*);
   bool boss_alive();
   void chase_player(ptr_lista_players);
   Boss* get_boss();
   bool end_of_river();
};
#endif
