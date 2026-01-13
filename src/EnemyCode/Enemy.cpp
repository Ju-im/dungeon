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

void Enemy::takeTurn(sf::Vector2i player_pos)
{
  // Placeholder logic for taking a turn
  // In a real implementation, this would involve deciding whether to move,
  // attack, etc.
  std::cout << "Enemy";

  for (int enemy_selected = 0; enemy_selected < enemies_in_play.size(); enemy_selected++)
  {
    if (checkIfAttackPossible(NULL)) // Replace NULL with actual matrix
    {
      attack(enemy_selected);
    }
    else
    {
      move(enemy_selected, player_pos);
    }
  }

}
bool Enemy::checkIfAttackPossible(int (*matrix)[60])
{
	// Placeholder logic for checking if an attack is possible
	// In a real implementation, this would involve checking the player's position relative to the enemy
	// For now, this function checks if there is a tile in the matrix that is an enemy
  //std::cout << "Checking if attack is possible based on the matrix." << std::endl;
    //for (int i = 0; i < enemies_in_play.size(); i++)
   // {
   //   attack(enemies_in_play[i].type);
	//}
    return false;
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

void Enemy::move(int enemy_selected, sf::Vector2i player_pos)
{
  // Placeholder logic for enemy movement
  // In a real implementation, this would involve pathfinding and movement
  // towards the player
  int x_move_distance = 0;
  int y_move_distance = 0;
  int sight_range     = 0;
  switch (enemies_in_play[enemy_selected].type)
  {
    case SLIME:
    case SKELETON:
    case SPIDER:
    case WOLF:
    {
      //std::cout << "Ground enemy moves." << std::endl;
      sf::Vector3i enemy_stats = enemyGround.Move(enemies_in_play[enemy_selected].type);
      x_move_distance = enemy_stats.x;
      y_move_distance = enemy_stats.y;
      sight_range     = enemy_stats.z;
      break;
    }
    case DRAGON:
    case GIANT:
    case SLIME_KING:
    {
      break;
    }
    case BAT:
    case BABY_DRAGON:
    {
      //std::cout << "Flying enemy moves." << std::endl;
      break;
    }
    default:
    {
      //std::cout << "Unknown enemy type cannot move!" << std::endl;
      break;
    }
  }
  // Update enemy position based on movement logic
  if ((enemies_in_play[enemy_selected].x - sight_range) < player_pos.x && player_pos.x < enemies_in_play[enemy_selected].x + sight_range)
  {  
    if ((enemies_in_play[enemy_selected].y - sight_range) < player_pos.y && player_pos.y < enemies_in_play[enemy_selected].y + sight_range)
    {
      // if player is within sight range, move towards player
      if (player_pos.y < enemies_in_play[enemy_selected].y)
      {
        enemies_in_play[enemy_selected].y -= y_move_distance;
      }
      else if (player_pos.y > enemies_in_play[enemy_selected].y)
      {
        enemies_in_play[enemy_selected].y += y_move_distance;
      }
      if (player_pos.x < enemies_in_play[enemy_selected].x)
      {
        enemies_in_play[enemy_selected].x -= x_move_distance;
      }
      else if (player_pos.x > enemies_in_play[enemy_selected].x)
      {
        enemies_in_play[enemy_selected].x += x_move_distance;
      }
      enemies_in_play[enemy_selected].turn_taken = true;
      std::cout << "enemy moves towards player. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
    }
  }
  //if (!enemies_in_play[enemy_selected].turn_taken)
  //{
  //  // Random movement if player not in sight range
  //  std::cout << "Enemy moves randomly." << std::endl;

  //  //int random_direction = (rand() % 2) -1;
  //  enemies_in_play[enemy_selected].x +=  x_move_distance;
  //  enemies_in_play[enemy_selected].y += ( y_move_distance);
  //}
  //std::cout << "Enemy" << enemies_in_play[enemy_selected].type << " new position: (" << enemies_in_play[enemy_selected].x << ", " << enemies_in_play[enemy_selected].y << ")" << std::endl;
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
        } while (matrix[x][y] != 5);
        try
        {
          if (matrix[x][y + 1] == 5)
          {
            if (matrix[x + 1][y] == 5)
            {
              if (matrix[x + 1][y + 1] == 5)
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
      } while (matrix[x][y] == 1);
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
              << "Turn Taken: " << enemies_in_play[i].turn_taken << std::endl
              << "----------------------\n";
  }
}

void Enemy::drawEnemies(sf::RenderWindow& window)
{
  int CELL_SIZE = 10;
  for (int i = 0; i < enemies_in_play.size(); i++)
  {
    sf::RectangleShape startTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    startTile.setFillColor(sf::Color(128, 128, 128));
    startTile.setPosition(enemies_in_play[i].y * CELL_SIZE, enemies_in_play[i].x * CELL_SIZE);
    window.draw(startTile);
  }
}