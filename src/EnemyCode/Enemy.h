#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "EnemyGround.h"
#include "EnemyFlying.h"
#include "EnemyBoss.h"
#include "../Player.h"
// Enemy class
// Container Class for different enemy types
// Allows Enemy logic to be handled in one place,
// while specific enemy behaviors are delegated to their respective classes
class Enemy
{
	public:
	Enemy();
	~Enemy();
    void init();
	void attack(int enemy_index,int enemy);
    bool checkIfAttackPossible(int (*matrix)[60]);
    void move(int enemy, sf::Vector2i player_pos, Grid& grid);
    void takeDamage(int amount, std::vector<sf::Vector3i>); 
    sf::Vector3i spawn(int (*matrix)[60], int type);
    void setInGrid(Grid& grid);
    void printEnemiesInPlay();
    int getHealth(int enemy);
    int getDamage(int enemy);
    void takeTurn(sf::Vector2i player_pos, Grid& grid);
    void drawEnemies(sf::RenderWindow& window);
    bool checkIfCanMove(Grid& grid, int direction, int x_move_distance, int y_move_distance,int enemy_selected, sf::Vector2i player_pos);
    sf::RectangleShape wallTile;
    int (*getAllCopyGrid())[60];
    Grid gridClassCopy;

	private:
    
    int type;
    bool spawned = false;
    int CELL_SIZE= 10;
    int X         = 3;
    int Y         = 4;
    sf::Vector2i player_position;
    enum EnemyTypes
    {
      SLIME = -1, 
      BAT = -2,
      SKELETON = -3,
      BABY_DRAGON = -4,
      SPIDER      = -5,
      WOLF        = -6,
      DRAGON      = -7,
      GIANT       = -8,
      SLIME_KING  = -9,
    };
    struct EnemyIndividualStats
    {
      int type;
      int health;
      int damage;
      int x;
      int y;
      bool turn_taken;
    };
    enum RoomIndex
    {
      Wall         = 1,
      Floor        = 0,
      CombatRoom   = 2,
      TreasureRoom = 3,
      ShopRoom     = 4,
      BossRoom     = 5,
      StartRoom    = 6,
    };
    std::vector<sf::RectangleShape> attackTiles;
    EnemyIndividualStats stats;
    std::vector<EnemyIndividualStats> enemies_in_play;
	EnemyGround enemyGround;
    EnemyFlying enemyFlying;
    EnemyBoss enemyBoss;
    Player player;

};
