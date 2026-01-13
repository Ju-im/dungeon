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


sf::Vector2i Player::getPosition(Grid& grid) {
	//Change the hardcoded 60 into something else
  int(*gridCopy)[60] = grid.getAllGrid();
  for (int y = 0; y < 60; y++)
  {
    for (int x = 0; x < 60; x++)
    {
      if (gridCopy[y][x] == 99)
      {
        std::cout << "Player position found at: (" << x << ", " << y << ")" << std::endl;
        return sf::Vector2i(x, y);
      }
    }
  }
}
void Player::getScreenPosition(Grid& grid, sf::RenderWindow& window)
{
  float spawn_x                  = static_cast<float>(CELL_SIZE) * 10;
  int spawn_y                    = 30;
  sf::Vector2i actual_screen_pos = { 30 * CELL_SIZE, 30 * CELL_SIZE };
  sf::RectangleShape test(sf::Vector2f(CELL_SIZE , CELL_SIZE ));

    //test.setSize({spawn_x, spawn_x});
    test.setFillColor(sf::Color::White);
  test.setPosition(
    actual_screen_pos.x , actual_screen_pos.y);
    std::cout << test.getPosition().y << std::endl;
    window.draw(test);

}
void Player::moveX(int x, Grid& grid) 
{
  int x_pos = this->getPosition(grid).x;
  int y_pos = this->getPosition(grid).y;

  // y,x
  grid.setGrid(y_pos , x_pos+x, 99);
  grid.setGrid(y_pos , x_pos, 0);
  

}
void Player::moveY(int y, Grid& grid)
{
  int x_pos = this->getPosition(grid).x;
  int y_pos = this->getPosition(grid).y;

  // y,x
  grid.setGrid(y_pos + y, x_pos, 99);
  grid.setGrid(y_pos, x_pos, 0);
}


