#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Player.h"
class ItemPickup
{
 public:
  ItemPickup();
  ~ItemPickup();
  bool init();
  void itemSpawn(Grid& grid);
  void renderItems(sf::RenderWindow& window, ItemPickup& itemPickup);
  sf::RectangleShape itemShape;
  std::vector<sf::RectangleShape> items;
  std::vector<sf::Vector2i> spawnPositions;


};



