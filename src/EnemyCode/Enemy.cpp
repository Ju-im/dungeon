#include "Enemy.h"
#include <iostream>

Enemy::Enemy() {}

Enemy::~Enemy() {}

void Enemy::takeDamage(int amount)
{
  // Apply damage to specific enemy

  // If enemy dies, remove from enemies_in_play
  for (int i = 0; i < enemies_in_play.size(); i++)
  {
    if (enemies_in_play[i].health <= 0)
    {
      enemies_in_play.erase(enemies_in_play.begin() + i);
    }
  }
}

void Enemy::checkIfAttackPossible(int (*matrix)[60])
{
	// Placeholder logic for checking if an attack is possible
	// In a real implementation, this would involve checking the player's position relative to the enemy
	// For now, this function checks if there is a tile in the matrix that is an enemy
  //std::cout << "Checking if attack is possible based on the matrix." << std::endl;
    for (int i = 0; i < enemies_in_play.size(); i++)
    {
      attack(enemies_in_play[i].type);
	}
}

void Enemy::attack(int enemy) 
{
  switch (enemy)
  {
    case SLIME:
    case SKELETON:
    case SPIDER:
    case WOLF:
    {
      enemyGround.Attack(enemy);
      break;
    }
    case DRAGON:
    case GIANT:
    case SLIME_KING:
    {
      enemyBoss.Attack(enemy);
      break;
    }
    case BAT:
    case BABY_DRAGON:
    {
      enemyFlying.Attack(enemy);
      break;
    }
    default:
    {
      std::cout << "Unknown enemy type cannot attack!" << std::endl;
      break;
    }
  }
}

void Enemy::move(int enemy)
{
  // Placeholder logic for enemy movement
  // In a real implementation, this would involve pathfinding and movement
  // towards the player
  std::cout << "Enemy is moving towards the player." << std::endl;
  switch (enemy)
  {
    case SLIME:
    case SKELETON:
    case SPIDER:
    case WOLF:
    {
      std::cout << "Ground enemy moves." << std::endl;
      break;
    }
    case DRAGON:
    case GIANT:
    case SLIME_KING:
    {
      enemyBoss.Move(enemy);
      break;
    }
    case BAT:
    case BABY_DRAGON:
    {
      std::cout << "Flying enemy moves." << std::endl;
      break;
    }
    default:
    {
      std::cout << "Unknown enemy type cannot move!" << std::endl;
      break;
    }
  }
}

int Enemy::getHealth(int enemy)
{
  switch (enemy)
  {
    case SLIME:
    case SKELETON:
    case SPIDER:
    case WOLF:
    {
      return enemyGround.getHealth(enemy);
      break;
    }
    case DRAGON:
    case GIANT:
    case SLIME_KING:
    {
      return enemyBoss.getHealth(enemy);
      break;
    }
    case BAT:
    case BABY_DRAGON:
    {
      return enemyFlying.getHealth(enemy);
      break;
    }
  }
}

int Enemy::getDamage(int enemy)
{
    switch (enemy)
  {
    case SLIME:
    case SKELETON:
    case SPIDER:
    case WOLF:
    {
      return enemyGround.getDamage(enemy);
      break;
    }
    case DRAGON:
    case GIANT:
    case SLIME_KING:
    {
      return enemyBoss.getDamage(enemy);
      break;
    }
    case BAT:
    case BABY_DRAGON:
    {
      return enemyFlying.getDamage(enemy);
      break;
    }
  }
}

sf::Vector3i Enemy::spawn(int (*matrix)[60],int type)
{
  int x  = 0;
  int y = 0;
  bool can_spawn = false;
  switch (type)
  {
    case DRAGON:
    case GIANT:
    case SLIME_KING:
    {
      //can_spawn = false;
      while (!can_spawn)
      {
        do
        {
          x = rand() % 60;
          y = rand() % 60;
        } while (matrix[x][y] != 0);
        try
        {
          if (matrix[x][y + 1] == 0)
          {
            if (matrix[x + 1][y] == 0)
            {
              if (matrix[x + 1][y + 1] == 0)
              {
                can_spawn = true;
              }
            }
          }
        }
        catch (const std::out_of_range& e)
        {
          can_spawn = false;
        }
      }
      break;
    }
    default:
    {
      do
      {
        x = rand() % 60;
        y = rand() % 60;
      } while (matrix[x][y] != 0);
      can_spawn = true;
      break;
    }
  }
  if (can_spawn)
  {
    int health = getHealth(type);
    int damage = getDamage(type);
    enemies_in_play.push_back({ type, health, damage, x, y });
    return sf::Vector3i(type, x, y);
  }
  else
  {
    return sf::Vector3i(0, 0, 0);
  }
}

void Enemy::printEnemiesInPlay() 
{
  for (int i = 0; i < enemies_in_play.size(); i++)
  {
    std::cout << "----------------------\n"
              << "Type: " << enemies_in_play[i].type << std::endl
              << "Health: " << enemies_in_play[i].health << std::endl
              << "Damage: " << enemies_in_play[i].damage << std::endl
              << "X: " << enemies_in_play[i].x << std::endl
              << "Y: " << enemies_in_play[i].y << std::endl
              << "----------------------\n";
  }
}

