#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include <iostream>
class Player
{
 public:
	 Player();
  ~Player();
     bool init();
  sf::Vector2i getPosition(Grid& grid);
     void moveX(int x, Grid& grid);
     void moveY(int y, Grid& grid);



 private:
     
};
