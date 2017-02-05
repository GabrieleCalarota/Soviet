#include "StartSoviet.hpp"

 int main() {
   srand(time(0));    
   StartSoviet game;
   game.choose_mod();
   game.choose_player();
   game.play();
   return 0;
 }
