#include "EnemyBoss.h"
EnemyBoss::EnemyBoss() {}
EnemyBoss::~EnemyBoss() {}

void EnemyBoss::Attack(int enemy) 
{
  switch (enemy)
  {
    
	case DRAGON:
	{
	  std::cout << "Dragon unleashes a fiery breath attack!" << std::endl;
	  /*
      int random_attack_type is random between 1 and 3.
	  if (attack type 1)
      {
	  // Dragon attacks in a large cone in front of it, moderate damage.
	  }
	  else if (attack type 2)
	  {
	  // Dragon fires fireball to attack a 3X3 tile on player, very high damage.
	  }
	  else
	  {
      // Dragon fires a beam of fire in a straight line, attacking all tiles in
      that line, high damage.
      }
	  */
	  
	  break;
	}
	case GIANT:
	{
	  std::cout << "Giant swings its massive club!" << std::endl;
      /*
	  if (attack type 1)
      {
      // Giant attacks in a line in front of it, high damage.
	  }
	  if (attack type 2)
	  {
	  // Giant stomps the ground towards the player multiple times, attacking all adjacent tiles, moderate damage.
      }
	  if (attack type 3)
	  {
      // Giant tries to pull the player closer, if successful, player is moved
      to adjacent tile and takes low damage.
      }
	  */
	  break;
	}
	case SLIME_KING:
	{
	  std::cout << "Slime King summons minions to attack!" << std::endl;
      /*
	  if (attack type 1)
	  {
      // Slime King spawns two regular slimes at adjacent tiles.
      }
      if (attack type 2)
	  {
	  // Slime King attacks all adjacent tiles with a corrosive splash, moderate damage.
	  }
	  if (attack type 3)
	  {
      // Slime King soaks into the ground, teleporting to a random tile within
      the boss room.
      }
	  */
	  break;
	}
	default:
	{
	  std::cout << "Unknown boss enemy attacks!" << std::endl;
	  break;
	}
  }
}

sf::Vector3i EnemyBoss::Move(int enemy)
{
  int x_move_distance = 0;
  int y_move_distance = 0;
  int sight_range     = 0;
  switch (enemy)
  {
	case DRAGON:
	{
	  std::cout << "Dragon soars through the skies." << std::endl;
      x_move_distance = 1;
      y_move_distance = 1;
      sight_range     = 5;
	  break;
	}
	case GIANT:
	{
	  std::cout << "Giant stomps heavily across the ground." << std::endl;
      x_move_distance = 1;
      y_move_distance = 1;
      sight_range     = 5;
	  break;
	}
	case SLIME_KING:
	{
	  std::cout << "Slime King oozes menacingly." << std::endl;
      x_move_distance = 1;
      y_move_distance = 1;
      sight_range     = 5;
	  break;
	}
	default:
	{
	  std::cout << "Unknown boss enemy moves!" << std::endl;
	  break;
	}
  }
  return sf::Vector3i(x_move_distance, y_move_distance, sight_range);
}

int EnemyBoss::getDamage(int enemy)
{
  switch (enemy)
  {
	case DRAGON:
	{
	  damage = 1;
	  break;
	}
	case GIANT:
	{
	  damage = 1;
	  break;
	}
	case SLIME_KING:
	{
      damage = 1;
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

int EnemyBoss::getHealth(int enemy) 
{
  switch (enemy)
  {
	case DRAGON:
	{
	  health = 150;
	  break;
	}
	case GIANT:
	{
	  health = 200;
	  break;
	}
	case SLIME_KING:
	{
	  health = 150;
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

