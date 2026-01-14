#include <SFML/Graphics.hpp>
#include "Grid.h"
#include <iostream>
#include <vector>
class Weapon
{
 public:
  Weapon();
  ~Weapon();
  bool init();

  void setAttackHeight(int height);
  void setAttackWidth(int width);
  void attack();


  private:
  int attackHeight = 1;
   int attackWidth  = 1;

};
