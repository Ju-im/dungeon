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
     void getScreenPosition(Grid& grid, sf::RenderWindow& window);
     void moveX(int x, Grid& grid);
     void moveY(int y, Grid& grid);
     int CELL_SIZE = 10;


 private:
     
};
