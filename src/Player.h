#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
class Player
{
 public:
	 Player();
  ~Player();
     bool init();
  sf::Vector2i getPosition(Grid& grid);
  void move(int x, int y, Grid& grid);



 private:
     
};
