#ifndef START_SOVIET_HPP
#define START_SOVIET_HPP

#include "MyLibrary.hpp"

 class Player;
 class Map;
 class Node;
 class Tutorial;
 
#ifndef LISTA_PLAYERS
#define LISTA_PLAYERS
 struct lista_players{ Player* p; lista_players* next;};
 typedef lista_players* ptr_lista_players;
#endif
   
 struct Mondo{
  Map* mappa;
  int num;
  Mondo* next;
  Mondo* prec;};
 
 const int max_livelli=5;
 const int max_length_input=1000;
 
 class StartSoviet{
  protected:
   enum command_type{nothing, fruga, spendi, apri, prendi};
   int n_players;
   bool single_player;
   char c[max_length_input];
   char* input;
   Node* position;
   int currentx;
   int currenty;
   ptr_lista_players head_players;
   Mondo* livello;
   bool win;
   bool muovi;
   int punti;
   int difficulty;
   int cont_mosse;
   Tutorial* tutorial;

   Mondo* inc_floor();
   void Multiplayer();
   int choose_facility();
   void help(int);
   void start_game();
  public:
   StartSoviet();
   ptr_lista_players push(Player*, ptr_lista_players);
   void choose_mod(); 
   void choose_player();
   void play();
 };
#endif
