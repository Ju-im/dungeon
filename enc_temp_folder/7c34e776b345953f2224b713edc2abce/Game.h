#ifndef WHACKAMOLESFML_GAME_H
#define WHACKAMOLESFML_GAME_H

#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "EnemyCode/Enemy.h"

enum GAME_STATE
{
  MENU,
  GAME,
  PAUSE
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
 
  

 private:
  bool collisionCheck(sf::Vector2i click, sf::Sprite& sprite);
  void spawnEnemy(int amount);


  GAME_STATE game_state = MENU;
  Grid grid;
  Enemy enemy{};
  
  
  
 
};

#endif // WHACKAMOLESFML_GAME_H
