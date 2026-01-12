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




void Player::move(int x, int y , Grid& grid) {
  grid.setGrid(30 +y, 30, 99);
  grid.setGrid(30 , 30, 0);
  grid.printGrid();

}


