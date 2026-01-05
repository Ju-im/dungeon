
#include "Game.h"
#include <iostream>


Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
  srand(time(NULL));
}

Game::~Game() {}

bool Game::init()
{
  grid.init();
  grid.generateDungeon();
  spawnEnemy(1);
  grid.printGrid();
  enemy.printEnemiesInPlay();
  enemy.move(-1);
  return true;
}

// UPDATE FUNCTION
void Game::update(float dt)
{
  switch (game_state)
  {
    case MENU:
    {
    
    
    }
      break;
    case GAME:
        {
     
     
    }
        break;
    case PAUSE:
    {
    
    }
    break;
  }
 
  
}

void Game::render()
{
  
}

void Game::mouseClicked(sf::Event event)
{
  // get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
  
 
  
  
}

void Game::keyPressed(sf::Event event)
{
 
}



bool Game::collisionCheck(sf::Vector2i click, sf::Sprite& sprite)
{
  if (
    (click.x >= sprite.getPosition().x) &&
    (click.x <= sprite.getPosition().x + sprite.getGlobalBounds().width))
  {
    if (
      (click.y >= sprite.getPosition().y) &&
      click.y <= sprite.getPosition().y + sprite.getGlobalBounds().height)
    {
      sprite.setPosition(1000, 1000);
 
     
      
      return true;
      
    }
  }
  return false;
}

void Game::spawnEnemy(int amount)
{
  for (int i = 0; i < amount; i++)
  {
    int(*gridCopy)[60] = grid.getAllGrid();
    //int type            = ((rand()%6)+1)*-1; //Temp Number, change to be the enemy you want to spawn
    int type            = -1;
    sf::Vector3i result = enemy.spawn(gridCopy,type); 
    grid.setGrid(result.y, result.z, result.x);
  }
}