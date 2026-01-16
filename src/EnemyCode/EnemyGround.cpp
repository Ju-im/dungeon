#include "EnemyGround.h"

EnemyGround::EnemyGround(){}

EnemyGround::~EnemyGround() {}


int (*EnemyGround::Attack(int enemy))[4][3]
{
  switch (enemy)
  {
    case SLIME:
    {
      std::cout << "Slime attacks with a sticky slap!" << std::endl;
      int attack_grid[4][3] = {
        { 0, 0, 0 }, 
        { 0, 0, 0 }, 
        { 0, 1, 0 }, 
        { 1, 99, 1 }
      };
      return &attack_grid;
      break;
    }
    case SKELETON:
    {
      std::cout << "Skeleton swings its rusty sword!" << std::endl;
      int attack_grid[4][3] = {
        { 0, 1, 0 }, 
        { 0, 1, 0 }, 
        { 0, 1, 0 }, 
        { 0, 99, 0 }
      };
      break;
    }
    case SPIDER:
    {
      std::cout << "Spider bites viciously!" << std::endl;
      int attack_grid[4][3] = {
        { 0, 0, 0 }, 
        { 0, 0, 0 }, 
        { 1, 1, 1 }, 
        { 0, 99, 0 }
      };
      return &attack_grid;
      break;
    }
    case WOLF:
    {
      std::cout << "Wolf lunges with sharp fangs!" << std::endl;
      int attack_grid[4][3] = {
        { 0, 0, 0 }, 
        { 0, 1, 0 }, 
        { 0, 1, 0 }, 
        { 0, 99, 0 }
      };
      return &attack_grid;
      break;
    }
    default:
    {
      std::cout << "Unknown ground enemy attacks!" << std::endl;
      break;
    }
  }
}

sf::Vector3i EnemyGround::Move(int enemy)
{
  int x_move_distance = 0;
  int y_move_distance = 0;
  int sight_range     = 0;
  switch (enemy)
  {
    case SLIME:
    {
      //std::cout << "Slime oozes forward slowly." << std::endl;
      x_move_distance = 1;
      y_move_distance = 1;
      sight_range     = 3;
      break;
    }
    case SKELETON:
    {
      //std::cout << "Skeleton clatters as it moves." << std::endl;
      x_move_distance = 1;
      y_move_distance = 1;
      sight_range     = 3;
      break;
    }
    case SPIDER:
    {
      //std::cout << "Spider scurries quickly." << std::endl;
      x_move_distance = 2;
      y_move_distance = 2;
      sight_range     = 3;
      break;
    }
    case WOLF:
    {
      //std::cout << "Wolf prowls stealthily." << std::endl;
      x_move_distance = 1;
      y_move_distance = 1;
      sight_range     = 3;
      break;
    }
    default:
    {
      std::cout << "Unknown ground enemy moves!" << std::endl;
      break;
    }
  }
  return sf::Vector3i(x_move_distance, y_move_distance,sight_range);
}

int EnemyGround::getDamage(int enemy)
{
  switch (enemy)
  {
    case SLIME:
    {
      damage = 5;
      break;
    }
    case SKELETON:
    {
      damage = 10;
      break;
    }
    case SPIDER:
    {
      damage = 8;
      break;
    }
    case WOLF:
    {
      damage = 12;
      break;
    }
    default:
    {
      damage = 0;
      break;
    }
  }
  return damage;
}
int EnemyGround::getHealth(int enemy)
{
  switch (enemy)
  {
    case SLIME:
    {
      health = 10;
      break;
    }
    case SKELETON:
    {
      health = 20;
      break;
    }
    case SPIDER:
    {
      health = 15;
      break;
    }
    case WOLF:
    {
      health = 25;
      break;
    }
    default:
    {
      health = 0;
      break;
    }
  }
  return health;
}