#ifndef DATABASE_HPP_
#define DATABASE_HPP_
#include "MyLibrary.hpp"

#ifndef monster_type
#define monster_type
enum type_monster{station_keeper,toxic_nurse,energumen_mutated,scaled_experiment,river_guardian,sewer_walker,underground_prisoner,mad_doctor,improved_soldier,cyborg_fighter};
#endif

 const int max_length=5000;
 struct info{ bool found; char i[max_length];};
 const int max_enemy=10; 

 class Database{
  protected:
   info enemy[max_enemy];
  public:
   Database();
   bool is_empty(info*,const int);
   bool is_empty();
   info* print_list(int*,bool&);
   void show_database();
   void add_enemy(type_monster);
   int num_found();
 };
#endif
