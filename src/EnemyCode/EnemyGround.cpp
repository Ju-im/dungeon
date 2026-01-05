#include "EnemyGround.h"

EnemyGround::EnemyGround(){}

EnemyGround::~EnemyGround() {}

void EnemyGround::Attack(int enemy) 
{
  switch (enemy)
  {
    case SLIME:
    {
      std::cout << "Slime attacks with a sticky slap!" << std::endl;
      break;
    }
    case SKELETON:
    {
      std::cout << "Skeleton swings its rusty sword!" << std::endl;
      break;
    }
    case SPIDER:
    {
      std::cout << "Spider bites viciously!" << std::endl;
      break;
    }
    case WOLF:
    {
      std::cout << "Wolf lunges with sharp fangs!" << std::endl;
      break;
    }
    default:
    {
      std::cout << "Unknown ground enemy attacks!" << std::endl;
      break;
    }
  }
}

void EnemyGround::Move(int enemy)
{
  switch (enemy)
  {
    case SLIME:
    {
      std::cout << "Slime oozes forward slowly." << std::endl;
      /* if (slime can see the player)
      {
        move towards player
      }
      else
      {
        int random_direction = rand() % 4;
      }
      */

      break;
    }
    case SKELETON:
    {
      std::cout << "Skeleton clatters as it moves." << std::endl;
      break;
    }
    case SPIDER:
    {
      std::cout << "Spider scurries quickly." << std::endl;
      break;
    }
    case WOLF:
    {
      std::cout << "Wolf prowls stealthily." << std::endl;
      break;
    }
    default:
    {
      std::cout << "Unknown ground enemy moves!" << std::endl;
      break;
    }
  }
  std::cout << "hello! : )." << std::endl;
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