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

void Player::move(int x, int y , Grid& grid) {
  int x_pos = this->getPosition(grid).x;
  int y_pos = this->getPosition(grid).y;

  // y,x
  grid.setGrid(y_pos +y, x_pos, 99);
  grid.setGrid(y_pos , x_pos, 0);
  

}


