#ifndef WHACKAMOLESFML_GAME_H
#define WHACKAMOLESFML_GAME_H

#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "EnemyCode/Enemy.h"
#include "Player.h"
#include "Weapon.h"
#include "ItemPickup.h"

enum GAME_STATE
{
  MENU,
  GAME,
  PAUSE
};

enum PlayerOptions
{
    Null =0,
  Up     = 1,
  down   = 2,
  left   = 3,
  right  = 4,
  attack = 5,
  attackselected = 6,
  enemyturn      = 7    

};
  class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  sf::RenderWindow& window;
  sf::View camera;
  int CELL_SIZE = 10;
  sf::Vector2f halfSize;
  void gameTurn();
  bool player_camera = true;
  void updatePlayerExploreGrid();
  void resetPlayerExploreGrid();
  void drawPlayerExploreGrid(sf::RenderWindow& window);
 

 private:
  PlayerOptions type = PlayerOptions::Up;
  sf::CircleShape ball;
  bool collisionCheck(sf::Vector2i click, sf::Sprite& sprite);
  void spawnEnemy(int amount);
  void spawnPlayer();
  int x = 0;
  int y = 0;
  Grid grid;
  /// <summary>
   int (*gridCopy)[60]   = grid.getAllGrid();
  /// </summary>
   sf::Clock clock;
   float t               = 0.0f;
  GAME_STATE game_state = GAME;
   Enemy enemy;
  Player player;
  Weapon weapon;
  ItemPickup itemPickup;

  enum GameMenuOptions
  {
    None = 0,
    Move = 1,
    WeponAttack = 2,
    SpellAttack = 3,
    Item = 4,
  };

  
  int loop = 300;
  
  int option_selected = None;
  int option_highlighted = 0;
  bool Player_Turn = false;


  int playerExploreGrid[60][60];
};

#endif // WHACKAMOLESFML_GAME_H
