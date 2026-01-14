#include "EnemyFlying.h"
EnemyFlying::EnemyFlying() {}
EnemyFlying::~EnemyFlying() {}
void EnemyFlying::Attack(int enemy) 
{
  switch (enemy)
  {
    case BAT:
	{
	  std::cout << "Bat swoops down to attack!" << std::endl;
	  /* 
	  for (each tile adjacent to bat)
	  {
		if (tile has player)
		{
		  apply damage to player.
		}
	  }
      */
      // Bat attacks one adjacent tile, low damage.
	  break;
	}
	case BABY_DRAGON:
	{
	  std::cout << "Baby Dragon breathes fire!" << std::endl;
      // Baby Dragon attacks in a t in front of it, moderate damage.
	  break;
    }
	default:
	{
	  std::cout << "Unknown flying enemy attacks!" << std::endl;
	  break;
	}
  }
	
}
sf::Vector3i EnemyFlying::Move(int enemy)
{
  int x_move_distance = 0;
  int y_move_distance = 0;
  int sight_range     = 0;
  switch (enemy)
  {
	case BAT:
	{
      x_move_distance = 2;
      y_move_distance = 1;
      sight_range     = 4;
	  break;
    }
    case BABY_DRAGON:
    {
      x_move_distance = 1;
      y_move_distance = 2;
      sight_range     = 4;
      break;
    }
	default:
	{
	  std::cout << "Unknown flying enemy flies!" << std::endl;
	  break;
    }
  }
  return sf::Vector3i(x_move_distance, y_move_distance, sight_range);
}

int EnemyFlying::getHealth(int enemy) 
{
  switch (enemy)
  {
	case BAT:
	{
	  health = 15;
	  break;
	}
	case BABY_DRAGON:
	{
	  health = 35;
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

int EnemyFlying::getDamage(int enemy) 
{
  switch (enemy)
  {
	case BAT:
	{
	  damage = 5;
	  break;
	}
	case BABY_DRAGON:
	{
	  damage = 15;
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