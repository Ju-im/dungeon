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

     enum WeaponType
     {
       Sword  = 0,
       Axe    = 1,
       Bow    = 2,
       Staff  = 3,
       Dagger = 4,
       Spear  = 5

     };

     struct Inventory
     {
       int gold = 0;
       int weapon = Dagger;
       int spell_one = -1;
       int spell_two = -1;
       int spell_three = -1;
       int spell_four  = -1;
     };



 private:
     
};
