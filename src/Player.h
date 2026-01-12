#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
class Player
{
 public:
	 Player();
  ~Player();
     bool init();
     void move(int x, int y, Grid& grid);



 private:
     
};
