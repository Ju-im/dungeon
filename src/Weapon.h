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


  void attack(Player& player, Grid& grid, int type);
  void drawFrontAttack(sf::Vector2i pos);
  void update(float dt, Player& player, Grid& grid);
  void setNumberOfBoxes(int num);
  void render(sf::RenderWindow& window);
  std::vector<sf::Vector2f> getAttackPos();
  sf::RectangleShape hitbox;
  std::vector<sf::Vector2f> pos;

  private:
  int CELL_SIZE    = 10;
  int attackHeight = 2;
   int attackWidth  = 2;
  int num_box          = 1;

   std::vector<sf::RectangleShape> box;
   std::vector<sf::Vector2i> drawPos;
   int attack_grid[4][3];
   int X = 3;
   int Y = 4;
   sf::Vector2i player_pos;
   int player_dir = 0;
   bool loop      = true;
};

enum WeaponType
{
	Sword=0,
	Axe = 1,
	Bow =2,
	Staff = 3,
	Dagger = 4,
	Spear =5


};

	
