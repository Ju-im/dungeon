#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include <math.h>
class Weapon
{
 public:
  Weapon();
  ~Weapon();
  bool init();


  void attack(Player& player, Grid& grid, int type);

  void update(float dt, Player& player, Grid& grid);

  void render(sf::RenderWindow& window);
  std::vector<sf::Vector3i> getAttackPos();
  sf::RectangleShape hitbox;
  std::vector<sf::Vector3f> pos;
  
  std::vector<sf::Vector3i> grid_pos;
  sf::Vector3i grid_pos_selected;



  void clearPos();
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
   sf::Clock clock;
   float t = 0.0f;
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

	
