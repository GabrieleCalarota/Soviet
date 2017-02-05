#ifndef TASK_HPP_
#define TASK_HPP_

#include "MyLibrary.hpp"

 class Map;
 class Player;

 class Task{
  protected:
   int i_task;
   int clues;
  public:
  
   Task();
 
   void curr_task(Player*,bool,Map*);
   int get_current_task();
      
   void inc_clues();

   void print_task_1();
   bool task_1(Player*);
 
   void print_task_2(Player*);
   bool task_2(Player*,Map*);
 
   void print_task_3();
   bool task_3(Player*,Map*);
 
 
   void print_task_4();
   bool task_4(Player*);
  
   void print_task_5();
   bool task_5(Map*,Player*); 
 
   void print_task_6();
   bool task_6(Player*,Map*);
 
   void print_task_7();
   bool task_7(Player*);
   
   void print_task_8(Player*);
   bool task_8(Player*,Map*);

   void print_task_9();
   bool task_9(Player*,Map*);
 };
#endif
