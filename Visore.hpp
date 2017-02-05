#ifndef VISORE_HPP_
#define VISORE_HPP_

#include "MyLibrary.hpp"

class Enemy;
class Player;

class Visore{
 protected:
  bool use;
  int charge_battery;
  int reserve_battery;

  
  bool enough_battery();
  bool enough_reserve();
  void refill_battery();
 public:
  
  Visore();

  void use_visore();
  void drop_visore();
  bool get_use();
  void consume_battery();
  void inc_reserve();
  void recharge();
  void options();
  void print_battery();
  void print_recharge();
  
  bool combat_visore(Enemy*,Player*);
};
#endif
