#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Player.h"
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
  void attack(Player& player, Grid& grid);
  void setNumberOfBoxes(int num);
  void setEmptySpace(int num, sf::Vector2i pos);
  sf::RectangleShape hitbox;


  private:
  int CELL_SIZE    = 10;
  int attackHeight = 1;
   int attackWidth  = 1;
  int num_box          = 1;
   std::vector<sf::RectangleShape> box;
   std::vector<std::vector<sf::RectangleShape>> boxes;
};

enum class WeaponType
{



};

	
