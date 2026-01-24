#include "ItemPickup.h"



ItemPickup::ItemPickup() {


}
ItemPickup::~ItemPickup() {



}


bool ItemPickup::init() {

	itemShape.setSize(sf::Vector2f(10.f, 10.f));
  itemShape.setFillColor(sf::Color::White);
    for (int i = 0; i < 20; i++)
    {
      sf::RectangleShape item;
      item.setSize(sf::Vector2f(10.f, 10.f));
      item.setFillColor(sf::Color::White);
      
     items.push_back(item);
    } 
	return true;
}


void ItemPickup::itemSpawn(Grid& grid) {

	   int(*gridCopy)[60] = grid.getAllGrid();
  for (int y = 0; y < 60; y++) {
	for (int x = 0; x < 60; x++) {
      if (gridCopy[y][x] == 0 || gridCopy[y][x]==3)
      {
        spawnPositions.push_back({ y, x });
		
	  }
	}
  }
  sf::Vector2i gridspawnPosition =
    spawnPositions[rand() % spawnPositions.size()];
  for (size_t i = 0; i < items.size(); i++)
  {
  
  items[i].setPosition(static_cast<float>(gridspawnPosition.y * 10),
      static_cast<float>(gridspawnPosition.x * 10));
  }


}

void ItemPickup::renderItems(sf::RenderWindow& window, ItemPickup& itemPickup) {
  for (size_t i = 0; i < itemPickup.items.size(); i++)
  {
    window.draw(itemPickup.items[i]);
  }
}