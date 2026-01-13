#include "Player.h"

Player::Player() {
  srand(static_cast<unsigned>(time(NULL)));
}

Player::~Player() {

}

bool Player::init()
{
  return true;
}

void Player::render(sf::RenderWindow& window) {

    window.draw(test);
}

 sf::Vector2i Player::getPosition(Grid& grid) {
	//Change the hardcoded 60 into something else
 // int(*gridCopy)[60] = grid.getAllGrid();
 ///* for (int y = 0; y < 60; y++)
 // {
 //   for (int x = 0; x < 60; x++)
 //   {
 //     if (gridCopy[y][x] == 99)
 //     {
 //       std::cout << "Player position found at: (" << x << ", " << y << ")" << std::endl;
 //       return sf::Vector2i(x, y);
 //     }
 //   }
 // }*/
 
  return gridPos;
}


void Player::spawnPlayer() {

    float spawn_x = static_cast<float>(CELL_SIZE);
  int spawn_y   = 30;

  sf::Vector2i actual_screen_pos = { 30 * CELL_SIZE, 30 * CELL_SIZE };
  
  gridPos = { 30, 30 };
  test.setSize({spawn_x, spawn_x});
  test.setFillColor(sf::Color::White);
  test.setPosition(actual_screen_pos.x, actual_screen_pos.y);
  currentPos = actual_screen_pos;
  std::cout << test.getPosition().y << std::endl;



}
sf::Vector2i Player::getScreenPosition(Grid& grid)
{
  currentPos = { gridPos.y * CELL_SIZE, gridPos.x * CELL_SIZE };
  return currentPos;

}
void Player::moveX(int x, Grid& grid) 
{

  
  gridPos                        = { gridPos.x, gridPos.y + x };
  
  sf::Vector2i actual_screen_pos = this->getScreenPosition(grid);
  test.setPosition(actual_screen_pos.x, actual_screen_pos.y + x);
  

  std::cout << "gridPos x: " << gridPos.y << " gridPos y: " << gridPos.x
            << std::endl;

  // y,x
  
  
  

}
void Player::moveY(int y, Grid& grid)
{
  
  gridPos                        = { gridPos.x + y, gridPos.y  };
  sf::Vector2i actual_screen_pos = this->getScreenPosition(grid);
  std::cout << "gridPos x: " << gridPos.y << " gridPos y: " << gridPos.x
            << std::endl;
  test.setPosition(actual_screen_pos.x + y, actual_screen_pos.y);
}


