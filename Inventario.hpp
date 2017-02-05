#ifndef INVENTARIO_HPP_
#define INVENTARIO_HPP_

#include "MyLibrary.hpp"

 class Armor;
 class Weapon;
 class Player;
 class Node;

 const int force_med_pack=15;
 const int max_letter=10;
 const int max_char=1000;


 class Inventario{
  protected: 
   int med_pack;
   int keys;
   int weight;
   int max_weight;
   int adrenaline;
   int MAX_ADRENALINE;
   int MAX_MED_KIT;
   int antidoti;
   int MAX_ANTIDOTI;
   struct lista_weapons{Weapon* w; lista_weapons* next;};
   lista_weapons* head_weapons;
   struct lista_armature{Armor* a; lista_armature* next;};
   lista_armature* head_armature;
   struct docs{ char s[max_char]; bool read;};
   struct ide_inv{const char* name; bool usa; int val; int max; const char* scritta;};
   ide_inv oggetti[6];
   docs doc[max_letter];
   int indice_docs;
   int indice_docs_letti;


   int peso_armi();
   int peso_armature();
  public:
   Inventario();
   bool task_2();
   int get_indice_doc();
   int get_indice_docs_letti();
   void inc_indice_doc();
   
   int get_med_pack();
   void inc_med_pack();
   void dec_med_pack();
   bool more_med_pack();
   bool full_med_pack();
   int get_max_medpack();
   void change_max_medpack(Player*);
   
   void dec_keys();
   void inc_keys();
   int get_keys();
   bool more_keys();

   bool more_antidoti();
   int get_antidoti();
   void inc_antidoti();
   void dec_antidoti();
   bool full_antidoti();
   int get_max_antidoti();
   void change_max_antidoti(Player*);
   
   bool more_adrenaline();
   int get_adrenaline();
   void inc_adrenaline();
   void dec_adrenaline();
   bool full_adrenaline();
   int get_max_adrenaline();
   void change_max_adrenaline(Player*);
   
   bool no_more_letter();
   void leggi_lettera();
   
   bool more_weapons();
   bool more_armor();
   
   bool is_in_weapons(Weapon*);
   bool is_in_armature(Armor*);
   
   void stampa_inventario(Player*,Node*,bool);
   
   void push_weapons(Weapon*);
   void push_armor(Armor*);
   
   Weapon* pop_weapons(int);
   Armor* pop_armor(int);
   
   void print_weapons_list(Player*,Node*);
   void print_armature_list(Player*,Node*);
   
   void change_max_weight(Player* );
   int get_max_weight();
   int get_current_weight();
   bool light_enough(int);
};
#endif
