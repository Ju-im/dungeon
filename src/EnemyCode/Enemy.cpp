#include "Enemy.h"
#include <iostream>

Enemy::Enemy() {}

Enemy::~Enemy() {}

void Enemy::init() {

    gridClassCopy.init();
  gridClassCopy.generateDungeon();

}


void Enemy::takeDamage(int amount, std::vector<sf::Vector3i> attack_positions)
{
  // Apply damage to specific enemy
  if (attack_positions.size() > 0)
  {
    for (int i = 0; i < attack_positions.size(); i++)
    {
      //std::cout << attack_positions.size();
      for (int enemy_selected = 0; enemy_selected < enemies_in_play.size(); enemy_selected++)
      {
        if (attack_positions[i].y == enemies_in_play[enemy_selected].x && attack_positions[i].x == enemies_in_play[enemy_selected].y)
        {
          enemies_in_play[enemy_selected].health -= attack_positions[i].z;
          std::cout << attack_positions[i].z;
          std::cout << "Enemy: " << enemies_in_play[enemy_selected].type << " is on [" << enemies_in_play[enemy_selected].health << "] health!" << std::endl;
        }
      }
    }
  }
  // If enemy dies, remove from enemies_in_play
  for (int i = 0; i < enemies_in_play.size(); i++)
  {
    if (enemies_in_play[i].health <= 0)
    {
      enemies_in_play.erase(enemies_in_play.begin() + i);
    }
  }
}

void Enemy::takeTurn(sf::Vector2i player_pos, Grid& grid)
{
  std::cout << "test! :)";
  // Placeholder logic for taking a turn
  // In a real implementation, this would involve deciding whether to move,
  // attack, etc.
  
  player_position = player_pos;
  for (int enemy_selected = 0; enemy_selected < enemies_in_play.size(); enemy_selected++)
  {
   //std::cout << "Enemies in play: " << enemies_in_play.size() << std::endl;
    if (checkIfAttackPossible(NULL)) // Replace NULL with actual matrix
    {
      attack(enemy_selected,enemies_in_play[enemy_selected].type);
    }
    else
    {
      move(enemy_selected, player_pos, grid);
    }
  }

  setInGrid(grid);
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

void Enemy::attack(int enemy_index, int enemy)
{
  
    attackTiles.clear();
  
  switch (enemy)
  {
    case SLIME:
    {
      int attack_grid[4][3] = {
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 1, 0 }, { 1, 9, 1 }
      };
      
      int enemy_x = enemies_in_play[enemy_index].y;
      int enemy_y = enemies_in_play[enemy_index].x;

     int distance_of_x = player_position.y - enemy_x;
      int distance_of_y = player_position.x - enemy_y;

      for (int y = 0; y < Y; y++)
      {
        for (int x = 0; x < X; x++)
        {
            //point down
          if (enemy_y <= player_position.x && (distance_of_y >= distance_of_x))
          {
            if (attack_grid[y][x] != 0 && attack_grid[y][x] != 9)
            {

              // point down
              int dir_x   = 3 - y;
              int dir_y   = 1 - x;
              int tileRow = enemies_in_play[enemy_index].x + dir_x;
              int tileCol = enemies_in_play[enemy_index].y + dir_y;
              sf::RectangleShape rect;
              rect.setSize(sf::Vector2f((float)CELL_SIZE, (float)CELL_SIZE));
              rect.setFillColor(sf::Color(200, 40, 40, 220)); // translucent red
              rect.setPosition(
                (float)(tileCol * CELL_SIZE), (float)(tileRow * CELL_SIZE));
              attackTiles.push_back(rect);
            }
           
          }
          
          else if (enemy_y >= player_position.x && (distance_of_y <= distance_of_x))
          {
            if (attack_grid[y][x] != 0 && attack_grid[y][x] != 9)
            {
              int dir_x   = 3 - y;
              int dir_y   = 1 - x;
              int tileRow = enemies_in_play[enemy_index].x - dir_x;
              int tileCol = enemies_in_play[enemy_index].y + dir_y;
              sf::RectangleShape rect;
              rect.setSize(sf::Vector2f((float)CELL_SIZE, (float)CELL_SIZE));
              rect.setFillColor(sf::Color(200, 40, 40, 220)); // translucent red
              rect.setPosition(
                (float)(tileCol)*CELL_SIZE, (float)(tileRow)*CELL_SIZE);
              attackTiles.push_back(rect);

              // point up
            }
            
          }
          else if (enemy_x <= player_position.y - 1 && (distance_of_x >= distance_of_y))
          {
            if (attack_grid[y][x] != 0 && attack_grid[y][x] != 9)
            {

              int dir_x   = 1 - x;
              int dir_y   = 3 - y;
              int tileRow = enemies_in_play[enemy_index].x + dir_x;
              int tileCol = enemies_in_play[enemy_index].y + dir_y;
              sf::RectangleShape rect;
              rect.setSize(sf::Vector2f((float)CELL_SIZE, (float)CELL_SIZE));
              rect.setFillColor(sf::Color(200, 40, 40, 220)); // translucent red
              rect.setPosition(
                (float)(tileCol)*CELL_SIZE, (float)(tileRow)*CELL_SIZE);
              attackTiles.push_back(rect);
              // point right
            }
           
          }
          else if (enemy_x >= player_position.y+1 && (distance_of_x <= distance_of_y))
          {
            if (attack_grid[y][x] != 0 && attack_grid[y][x] != 9)
           {

              // point left
              int dir_x   = 1 - x;
              int dir_y   = 3 - y;
              int tileRow = enemies_in_play[enemy_index].x + dir_x;
              int tileCol = enemies_in_play[enemy_index].y - dir_y;
              sf::RectangleShape rect;
              rect.setSize(sf::Vector2f((float)CELL_SIZE, (float)CELL_SIZE));
              rect.setFillColor(sf::Color(200, 40, 40, 220)); // translucent red
              rect.setPosition(
                (float)(tileCol)*CELL_SIZE, (float)(tileRow)*CELL_SIZE);
              attackTiles.push_back(rect);
            }
            
          }
         
         
        }
        std::cout<<std::endl;
      }
      
        
    break;
    }
    case SKELETON:
    {
      int attack_grid[4][3] = {
        { 0, 1, 0 }, { 0, 1, 0 }, { 0, 1, 0 }, { 0, 9, 0 }
      };


        break;
    }
    case SPIDER:
    {
      int attack_grid[4][3] = {
        { 0, 0, 0 }, { 0, 0, 0 }, { 1, 0, 1 }, { 0, 9, 0 }
      };
      break;
    
    
    }
      
    case WOLF:
    {
      int attack_grid[4][3] = {
        { 0, 0, 0 }, { 0, 1, 0 }, { 0, 1, 0 }, { 0, 9, 0}
      };
      break;
    }
    case DRAGON:
    {
    
    break;
    }
    case GIANT:
    {
      break;
    }
    case SLIME_KING:
    {
      
      break;
    }
    case BAT:
    {
      int attack_grid[4][3] = {
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 1, 0 }, { 0, 9, 0 }
      };
      break;
    }
      

    case BABY_DRAGON:
    {
      int attack_grid[4][3] = {
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 1, 0 }, { 1, 9, 1 }
      };
      break;
    
    }
      
    
    default:
    {
      std::cout << "Unknown enemy type cannot attack!" << std::endl;
      break;
    }
  }
}

bool Enemy::checkIfCanMove(Grid& grid, int direction, int x_move_distance, int y_move_distance, int enemy_selected, sf::Vector2i player_pos) 
{
  switch (direction)
  {
    case 1: // Up
    {
        if (grid.getGrid(enemies_in_play[enemy_selected].x, enemies_in_play[enemy_selected].y - y_move_distance) == Wall) 
        {
          return false;
        }
        if (grid.getGrid(enemies_in_play[enemy_selected].x, enemies_in_play[enemy_selected].y - y_move_distance) == ShopRoom) 
        {
          return false;
        }
        if (grid.getGrid(enemies_in_play[enemy_selected].x, enemies_in_play[enemy_selected].y - y_move_distance) == StartRoom) 
        {
          return false;
        }
        for (int each_enemy = 0; each_enemy < enemies_in_play.size(); each_enemy++) 
        {
            if (enemies_in_play[enemy_selected].y - y_move_distance == enemies_in_play[each_enemy].y)
            {
              return false; 
            }
        }
        if (enemies_in_play[enemy_selected].x + x_move_distance == player_pos.x)
        {
          return false;
        }
        if (enemies_in_play[enemy_selected].y + y_move_distance == player_pos.y)
        {
          return false;
        }
        break;
    }
    case 2: // Down
    {
        if (grid.getGrid(enemies_in_play[enemy_selected].x, enemies_in_play[enemy_selected].y + y_move_distance) == Wall) 
        {
          return false;
        }
        if (grid.getGrid(enemies_in_play[enemy_selected].x, enemies_in_play[enemy_selected].y + y_move_distance) == ShopRoom) 
        {
          return false;
        }
        if (grid.getGrid(enemies_in_play[enemy_selected].x, enemies_in_play[enemy_selected].y + y_move_distance) == StartRoom) 
        {
          return false;
        }
        for (int each_enemy = 0; each_enemy < enemies_in_play.size(); each_enemy++) 
        {
            if (enemies_in_play[enemy_selected].y + y_move_distance == enemies_in_play[each_enemy].y)
            {
              return false; 
            }
        }
        if (enemies_in_play[enemy_selected].x + x_move_distance == player_pos.x)
        {
          return false;
        }
        if (enemies_in_play[enemy_selected].y + y_move_distance == player_pos.y)
        {
          return false;
        }
        break;
    }
    case 3: // Left
    {
        if (grid.getGrid(enemies_in_play[enemy_selected].x - x_move_distance, enemies_in_play[enemy_selected].y) == Wall) 
        {
          return false;
        }
        if (grid.getGrid(enemies_in_play[enemy_selected].x - x_move_distance, enemies_in_play[enemy_selected].y) == ShopRoom) 
        {
          return false;
        }
        if (grid.getGrid(enemies_in_play[enemy_selected].x - x_move_distance, enemies_in_play[enemy_selected].y) == StartRoom) 
        {
          return false;
        }
        for (int each_enemy = 0; each_enemy < enemies_in_play.size(); each_enemy++) 
        {
            if (enemies_in_play[enemy_selected].x - x_move_distance == enemies_in_play[each_enemy].x)
            {
              return false; 
            }
        }
        if (enemies_in_play[enemy_selected].x + x_move_distance == player_pos.x)
        {
          return false;
        }
        if (enemies_in_play[enemy_selected].y + y_move_distance == player_pos.y)
        {
          return false;
        }
        break;
    }
    case 4: // Right
    {
        if (grid.getGrid(enemies_in_play[enemy_selected].x + x_move_distance, enemies_in_play[enemy_selected].y) == Wall) 
        {
          return false;
        }
        if (grid.getGrid(enemies_in_play[enemy_selected].x + x_move_distance, enemies_in_play[enemy_selected].y) == ShopRoom) 
        {
          return false;
        }
        if (grid.getGrid(enemies_in_play[enemy_selected].x + x_move_distance, enemies_in_play[enemy_selected].y) == StartRoom) 
        {
          return false;
        }
        for (int each_enemy = 0; each_enemy < enemies_in_play.size(); each_enemy++) 
        {
            if (enemies_in_play[enemy_selected].x + x_move_distance == enemies_in_play[each_enemy].x)
            {
              return false; 
            }
        }
        if (enemies_in_play[enemy_selected].x + x_move_distance == player_pos.x) 
        {
          return false;
        }
        if (enemies_in_play[enemy_selected].y + y_move_distance == player_pos.y)
        {
          return false;
        }
        break;
    }
  }
  return true;
}




void Enemy::move(int enemy_selected, sf::Vector2i player_pos, Grid& grid)
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
      sf::Vector3i enemy_stats = enemyBoss.Move(enemies_in_play[enemy_selected].type);
      x_move_distance = enemy_stats.x;
      y_move_distance = enemy_stats.y;
      sight_range     = enemy_stats.z;
      break;
    }
    case BAT:
    case BABY_DRAGON:
    {
      sf::Vector3i enemy_stats = enemyFlying.Move(enemies_in_play[enemy_selected].type);
      x_move_distance = enemy_stats.x;
      y_move_distance = enemy_stats.y;
      sight_range     = enemy_stats.z;
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

      switch (enemies_in_play[enemy_selected].type)
      {
        case DRAGON:
        case GIANT:
        case SLIME_KING:
        {
          if (player_pos.y < enemies_in_play[enemy_selected].y)
          {
            if (grid.getGrid(enemies_in_play[enemy_selected].x, enemies_in_play[enemy_selected].y - y_move_distance) == BossRoom) 
            {
              enemies_in_play[enemy_selected].y -= y_move_distance;
              std::cout << "Move y -1" << std::endl;
              std::cout << "Room: " << grid.getGrid(enemies_in_play[enemy_selected].x, enemies_in_play[enemy_selected].y - y_move_distance) << std::endl;
            }
            std::cout << "!No Move y -1 No!" << std::endl;
          }
          else if (player_pos.y > enemies_in_play[enemy_selected].y)
          {
            if (grid.getGrid(enemies_in_play[enemy_selected].x, enemies_in_play[enemy_selected].y + y_move_distance) == BossRoom) 
            {
              enemies_in_play[enemy_selected].y += y_move_distance;
              std::cout << "Move y +1" << std::endl;
              std::cout << "Room: " << grid.getGrid(enemies_in_play[enemy_selected].x, enemies_in_play[enemy_selected].y + y_move_distance) << std::endl;
            }
            std::cout << "!No Move y +1 No!" << std::endl;
          }
          if (player_pos.x < enemies_in_play[enemy_selected].x)
          {
            if (grid.getGrid(enemies_in_play[enemy_selected].x - x_move_distance, enemies_in_play[enemy_selected].y) == BossRoom) 
            {
              enemies_in_play[enemy_selected].x -= x_move_distance;
              std::cout << "Move x -1" << std::endl;
              std::cout << "Room: " << grid.getGrid(enemies_in_play[enemy_selected].x - x_move_distance, enemies_in_play[enemy_selected].y) << std::endl;
            }
            std::cout << "!No Move x -1 No!" << std::endl;
          }
          else if (player_pos.x > enemies_in_play[enemy_selected].x)
          {
            if (grid.getGrid(enemies_in_play[enemy_selected].x  + x_move_distance, enemies_in_play[enemy_selected].y) == BossRoom) 
            {
              enemies_in_play[enemy_selected].x += x_move_distance;
              std::cout << "Move x +1" << std::endl;
              std::cout << "Room: " << grid.getGrid(enemies_in_play[enemy_selected].x + x_move_distance, enemies_in_play[enemy_selected].y) << std::endl;
            }
            std::cout << "!No Move x +1 No!" << std::endl;
          }
          enemies_in_play[enemy_selected].turn_taken = true;
          break;
        }
        default:
        {
          // if player is within sight range, move towards player
          if (player_pos.y < enemies_in_play[enemy_selected].y)
          {
            if (checkIfCanMove(grid,1,0,y_move_distance,enemy_selected,player_pos) == true)
            {
                enemies_in_play[enemy_selected].y -= y_move_distance;
            }
          }
          else if (player_pos.y > enemies_in_play[enemy_selected].y)
          {
            if (checkIfCanMove(grid,2,0,y_move_distance,enemy_selected,player_pos) == true)
            {
                enemies_in_play[enemy_selected].y += y_move_distance;
            }
          }
          if (player_pos.x < enemies_in_play[enemy_selected].x)
          {
            if (checkIfCanMove(grid,3,x_move_distance,0,enemy_selected,player_pos) == true)
            {
              enemies_in_play[enemy_selected].x -= x_move_distance;
            }
          }
          else if (player_pos.x > enemies_in_play[enemy_selected].x)
          {
            if (checkIfCanMove(grid,4,x_move_distance,0,enemy_selected,player_pos) == true)
            {
              enemies_in_play[enemy_selected].x += x_move_distance;
            }
          }
          enemies_in_play[enemy_selected].turn_taken = true;
          std::cout << "enemy moves towards player. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
        }
      }
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
        } while (matrix[x][y] != BossRoom);
        try
        {
          if (matrix[x][y + 1] == BossRoom)
          {
            if (matrix[x + 1][y] == BossRoom)
            {
              if (matrix[x + 1][y + 1] == BossRoom)
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
      } while (matrix[x][y] == Wall);
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

void Enemy::setInGrid(Grid& grid) {
  // get the enemy positions amd copy them into the gridClassCopy
  int(*gridCopy)[60] = grid.getAllGrid(); 
  for (int i = 0; i < 60; i++)
  {
    for (int j = 0; j < 60; j++)
    {
      gridClassCopy.setGrid(i, j, gridCopy[i][j]);
    }
  }
    for (int i = 0; i < enemies_in_play.size(); i++)
  {

      gridClassCopy.setGrid(enemies_in_play[i].x, enemies_in_play[i].y, 99);
  }
  //gridClassCopy.printGrid();




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
  
  for (int i = 0; i < attackTiles.size(); i++)
  {
    window.draw(attackTiles[i]);
  }
  for (int i = 0; i < enemies_in_play.size(); i++)
  {
    if (enemies_in_play[i].type == 7)
    {
      sf::RectangleShape startTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
      startTile.setFillColor(sf::Color(255, 255, 0));
      startTile.setPosition(
        enemies_in_play[i].y * CELL_SIZE, enemies_in_play[i].x * CELL_SIZE);
      window.draw(startTile);
    }
    else
    {
      sf::RectangleShape startTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
      startTile.setFillColor(sf::Color(128, 128, 128));
      startTile.setPosition(
        enemies_in_play[i].y * CELL_SIZE, enemies_in_play[i].x * CELL_SIZE);
      window.draw(startTile);
    }
  }
}