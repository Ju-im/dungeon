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
void EnemyFlying::Move(int enemy) 
{
  switch (enemy)
  {
	case BAT:
	{
	  std::cout << "Bat flutters its wings and flies." << std::endl;
      /* if (bat can see the player)
      {
        set can_see_player to true.
      }
      else
      {
        int direction = rand() % 4;
      }
      set speed to how many tiles bat moves.
      */

	  break;
    }
    case BABY_DRAGON:
    {
      std::cout << "Baby Dragon soars through the air." << std::endl;
      break;
    }
	default:
	{
	  std::cout << "Unknown flying enemy flies!" << std::endl;
	  break;
    }
  }
  /*
  if (enemy can_see_enemy)
  {
  check path to player isnt in a wall,
  (path can include flying over ground obstacles or though walls,
  but, must end on a tile that is not a wall)
  move towards player by speed amount.
  }
  else
  {
  move in random direction by speed amount and the direction chosen earlier.
  (can fly over ground obstacles or though walls, but cant end on a wall)
  }
  
  update enemy position on grid, and in enemy struct in Enemy class.
  */
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