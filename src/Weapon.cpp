#include "Weapon.h"
Weapon::Weapon() {
  srand(static_cast<unsigned>(time(NULL)));


}
Weapon::~Weapon() {}

void Weapon::setAttackHeight(int height) {
  attackHeight = height;


}

void Weapon::setAttackWidth(int width)
{
  attackWidth = width;
}

void Weapon::attack(Player& player, Grid& grid)
{
  char dir = 'u';
  if (dir == 'u')
  {
    sf::Vector2i player_screen_pos = player.getScreenPosition(grid);
    for (int i = 0; i < attackHeight; i++)
    {
      int y = player_screen_pos.y;
      int x = player_screen_pos.x;
      box[i].setPosition(x, y + i + 1);
      box.pop_back();
      //white white white, white black white
    }
  
  
  }



}

void Weapon::setNumberOfBoxes(int num) {
  num_box = num;
  box.resize(num_box);
  for (int i = 0; i < box.size(); i++)
  {
    box[i].setFillColor(sf::Color::White);
    box[i].setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
  
  }

}

void Weapon::setEmptySpace(int num, sf::Vector2i pos) {



}

bool init() {



	return true;
}