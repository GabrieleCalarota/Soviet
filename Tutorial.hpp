#ifndef TUTORIAL_HPP_
#define TUTORIAL_HPP_

#include "MyLibrary.hpp"


 class Player;
 class Node;
 class Weapon;
 class Map;
 class StartSoviet;

 #ifndef LISTA_PLAYERS
 #define LISTA_PLAYERS
 struct lista_players{ Player* p; lista_players* next;};
 typedef lista_players* ptr_lista_players;
 #endif


 class Tutorial{
    protected:
      Node* nod;
      Map* m;
      Player* p;
      char n[25];
      char input;
      Weapon* w;
      ptr_lista_players h;
      int x;
      int y;
      bool esci;
   public:
      Tutorial(StartSoviet*);
      void Play();
      void Introduction();
      void Move();
      void Check_inventario();
      void Check_statistiche();
  };
#endif
