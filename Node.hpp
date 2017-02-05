#ifndef NODE_HPP_
#define NODE_HPP_
#include "MyLibrary.hpp"

 class Player;
 class Enemy;
 class Armor;
 class Weapon;

 class Node{
  protected:
   int x;
   int y;
   Node *right;
   Node *left;
   Node *up;
   Node *down;
   bool color_blue_river;
   bool antidoto;
   bool med_pac;          
   Enemy* enemy;            
   bool armadietto;                
   bool key;              
   struct lista_weapons{Weapon* w; lista_weapons* next;};
   lista_weapons* head_weapons;
   struct lista_armature{Armor* a; lista_armature* next;};
   lista_armature* head_armature;
  public:
   Node();
   Node(int,int);
   
   int get_x();
   int get_y();
   
   void change_x(int);
   void change_y(int);
   
   void change_key();
   bool get_key();
   
   bool get_color_blue();
   void insert_color_blue();
   
   void change_med_pac(bool);
   bool get_med_pac();
   
   bool is_in_antidoto();
   void change_antidoto(bool);
   
   bool is_in_enemy();
   Enemy* get_enemy();
   void change_enemy(Enemy*);
   
   bool is_in_weapon();
   bool is_in_armature();
   
   bool is_in_weapon(Weapon*);
   bool is_in_armature(Armor*);
   
   void push_weapons(Weapon*);
   Weapon* pop_weapons(int);
   
   void push_armature(Armor*);
   Armor* pop_armature(int);
   
   bool get_armadietto();
   void change_armadietto(bool);
   
   Node* getnode_l();
   Node* getnode_r();
   Node* getnode_u();
   Node* getnode_d();
   
   void change_node_r(Node*);
   void change_node_l(Node*);
   void change_node_u(Node*);
   void change_node_d(Node*);
   
   bool is_in_p(int,int);
   void pick_up_tools(Player*);
   
   bool print_weapons_list(int*);
   bool print_armature_list(int*);
 };
#endif
