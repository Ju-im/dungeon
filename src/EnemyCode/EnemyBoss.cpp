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

void EnemyBoss::Move(int enemy) 
{
  switch (enemy)
  {
	case DRAGON:
	{
	  std::cout << "Dragon soars through the skies." << std::endl;
	  /* if (dragon can see the player)
	  {
		set can_see_player to true.
	  }
	  else
	  {
		int direction = rand() % 4;
	  }
	  set speed to how many tiles dragon moves.
      // Dragon will try to keep some distance from the player while moving.
	  */
	  break;
	}
	case GIANT:
	{
	  std::cout << "Giant stomps heavily across the ground." << std::endl;
      // Giant moves slowly, but always tries to get into close range.
	  break;
	}
	case SLIME_KING:
	{
	  std::cout << "Slime King oozes menacingly." << std::endl;
      // Slime King tends to move randomly within the boss room, occasionally
      // moving away the player.
	  break;
	}
	default:
	{
	  std::cout << "Unknown boss enemy moves!" << std::endl;
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
  This movemnet is capped to a certan area, formed by the boss room.
  }

  update enemy position on grid, and in enemy struct in Enemy class.
  */
}

int EnemyBoss::getDamage(int enemy)
{
  switch (enemy)
  {
	case DRAGON:
	{
	  damage = 25;
	  break;
	}
	case GIANT:
	{
	  damage = 20;
	  break;
	}
	case SLIME_KING:
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

