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
      /*
      for (each tile in a shape around slime)
      {
        if (tile has player)
        {
          apply damage to player.
        }
      }
      */
      // Slime attacks in a + shape around it, low damage.
      break;
    }
    case SKELETON:
    {
      std::cout << "Skeleton swings its rusty sword!" << std::endl;
      // Skeleton attacks three tiles in front of it. in a line, moderate damage.
      break;
    }
    case SPIDER:
    {
      std::cout << "Spider bites viciously!" << std::endl;
      // Spider attacks one adjacent tile, low damage.
      break;
    }
    case WOLF:
    {
      std::cout << "Wolf lunges with sharp fangs!" << std::endl;
      // Wolf attacks two tiles in front of it, in a line, high damage.
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
        set can_see_player to true.
      }
      else
      {
        int direction = rand() % 4;
      }
      set speed to how many tiles slime moves.
      */
      // Slime moves slowly, a basic ground enemy.
      break;
    }
    case SKELETON:
    {
      std::cout << "Skeleton clatters as it moves." << std::endl;
      // Skeleton moves at a moderate speed.
      break;
    }
    case SPIDER:
    {
      std::cout << "Spider scurries quickly." << std::endl;
      // Spider moves quickly.
      break;
    }
    case WOLF:
    {
      std::cout << "Wolf prowls stealthily." << std::endl;
      // Wolf moves moderate, but wont wander randomly if player not in sight.
      break;
    }
    default:
    {
      std::cout << "Unknown ground enemy moves!" << std::endl;
      break;
    }
  }
  /*
  if (enemy can_see_enemy)
  {
  check path to player isnt in a wall,
  move towards player by speed amount.
  }
  else
  {
  move in random direction by speed amount and the direction chosen earlier.
  }
  
  update enemy position on grid, and in enemy struct in Enemy class.
  */
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