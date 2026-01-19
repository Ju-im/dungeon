#include "Player.h"

Player::Player() {
  srand(static_cast<unsigned>(time(NULL)));
}

Player::~Player() {

}

bool Player::init()
{
  stats.health = 4;
  stats.weapon = 4;
  stats.spell  = 0;
  stats.item   = 0;
  return true;
}

void Player::render(sf::RenderWindow& window) {

    window.draw(test);
}

 sf::Vector2i Player::getPosition(Grid& grid) {

  return gridPos;
}


void Player::spawnPlayer(Grid& grid) {

    float spawn_x = static_cast<float>(CELL_SIZE);
  int spawn_y   = 30;

  
  int(*gridCopy)[60]             = grid.getAllGrid();
  std::vector<sf::Vector2i> pos;
  for (int y = 0; y < 60; y++)
  {
    for (int x = 0; x < 60; x++)
    {
      if (gridCopy[y][x] == 6)
      {
        pos.push_back({ y, x });
      
      }
    }
  }
  sf::Vector2i gridspawnPosition =pos[rand() % pos.size()];
  gridPos = gridspawnPosition;
  sf::Vector2i actual_screen_pos = { gridspawnPosition.y * CELL_SIZE,
                                     gridspawnPosition.x * CELL_SIZE };
  test.setSize({spawn_x, spawn_x});
  test.setFillColor(sf::Color::White);
  test.setPosition(actual_screen_pos.x, actual_screen_pos.y);
  currentPos = actual_screen_pos;
  std::cout << test.getPosition().y << std::endl;



}
void Player::setDirection(int dir) {

    player_dir = dir;


}
int Player::getDirection() {


    return player_dir;
}
sf::Vector2i Player::getScreenPosition(Grid& grid)
{
  currentPos = { gridPos.y * CELL_SIZE, gridPos.x * CELL_SIZE };
  return currentPos;

}
void Player::moveX(int x, Grid& grid) 
{

   if (gridPos.y + x > -1 && gridPos.y + x < 59)
  {
     
     int y_grid         = gridPos.y + x;
     int x_grid         = gridPos.x;
     int(*gridCopy)[60] = grid.getAllGrid();
     if (gridCopy[x_grid][y_grid] != 1 && can_move)
     {
       gridPos = { gridPos.x, gridPos.y + x };

       sf::Vector2i actual_screen_pos = this->getScreenPosition(grid);
       test.setPosition(actual_screen_pos.x, actual_screen_pos.y);
     }
  }

  // y,x
  
  
  

}
void Player::moveY(int y, Grid& grid)
{

  if (gridPos.x + y > -1 && gridPos.x+y < 59)
  {
    
    int y_grid = gridPos.y;
    int x_grid = gridPos.x + y;
    int(*gridCopy)[60] = grid.getAllGrid();
    if (gridCopy[x_grid][y_grid] != 1 && can_move)
    {
      gridPos                        = { gridPos.x + y, gridPos.y };
      sf::Vector2i actual_screen_pos = this->getScreenPosition(grid);
      
      test.setPosition(actual_screen_pos.x, actual_screen_pos.y);
    
    }
    
  }
  
}


void Player::renderUI(sf::RenderWindow& window, sf::View camera)
{
  drawHealthBar(window, camera);
  drawWeaponSlot(window, camera);
  drawSpellSlot(window, camera);
  drawItemSlot(window, camera);
}

void Player::drawHealthBar(sf::RenderWindow& window, sf::View camera)
{
  sf::RectangleShape healthBar(sf::Vector2f(30, 10));
  healthBar.setFillColor(sf::Color(100, 100, 100));
  healthBar.setPosition(camera.getCenter().x + 30,camera.getCenter().y-58);
  window.draw(healthBar);
}
void Player::drawWeaponSlot(sf::RenderWindow& window, sf::View camera)
{
  sf::RectangleShape weaponSlot(sf::Vector2f(12, 12));
  weaponSlot.setFillColor(sf::Color(150, 150, 150));
  weaponSlot.setPosition(camera.getCenter().x - 60, camera.getCenter().y - 58);
  window.draw(weaponSlot);
}
void Player::drawSpellSlot(sf::RenderWindow& window, sf::View camera)
{
  sf::RectangleShape spellSlot(sf::Vector2f(12, 12));
  spellSlot.setFillColor(sf::Color(150, 150, 150));
  spellSlot.setPosition(camera.getCenter().x - 45, camera.getCenter().y - 58);
  window.draw(spellSlot);
}
void Player::drawItemSlot(sf::RenderWindow& window, sf::View camera)
{
  sf::RectangleShape itemSlot(sf::Vector2f(12, 12));
  itemSlot.setFillColor(sf::Color(150, 150, 150));
  itemSlot.setPosition(camera.getCenter().x - 30, camera.getCenter().y - 58);
  window.draw(itemSlot);
}

int Player::getHealth()
{
  return stats.health;
}
int Player::getWeapon()
{
  return stats.weapon;
}
int Player::getSpell()
{
  return stats.spell;
}
int Player::getItem()
{
  return stats.item;
}