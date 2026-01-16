#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include <iostream>
#include <vector>
class Player
{
 public:
	 Player();
  ~Player();
     bool init();
  void render(sf::RenderWindow& window);
  sf::Vector2i getPosition(Grid& grid);
     sf::Vector2i getScreenPosition(Grid& grid);
     void moveX(int x, Grid& grid);
     void moveY(int y, Grid& grid);
     void spawnPlayer(Grid& grid);
     int CELL_SIZE = 10;
     sf::Vector2i currentPos;
     sf::Vector2i gridPos; 
     sf::RectangleShape test;
     void setDirection(int dir);
     int getDirection();
     int player_dir = -2;
     bool can_move  = true;



 private:
     
};
