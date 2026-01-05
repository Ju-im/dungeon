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
    {
      enemyGround.Attack(SLIME);
      break;
    }
    case BAT:
    {
      enemyFlying.Attack(BAT);
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

  if (enemy == BAT || enemy == BABY_DRAGON)
  {
    enemyFlying.Move(enemy);
  }
  else
  {
    enemyGround.Move(enemy);
  }
}

int Enemy::getHealth(int enemy)
{
  if (enemy == BAT || enemy == BABY_DRAGON)
  {
    return enemyFlying.getHealth(enemy);
    //std::cout << "Ground enemy health retrieved." << std::endl;
  }
  else 
  {
    return enemyGround.getHealth(enemy);
  }
}

int Enemy::getDamage(int enemy)
{
  if (enemy == BAT || enemy == BABY_DRAGON)
  {
    return enemyFlying.getDamage(enemy);
  }
  else
  {
    return enemyGround.getDamage(enemy);
  }
}

sf::Vector3i Enemy::spawn(int (*matrix)[60],int type)
{
  int x  = 0;
  int y = 0;
  do
  {
    x = rand() % 60;
    y = rand() % 60;
  } while (matrix[x][y] != 0);
  int health = getHealth(type);
  int damage = getDamage(type);
  enemies_in_play.push_back({ type,health,damage, x, y });
  return sf::Vector3i(type, x, y);
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

