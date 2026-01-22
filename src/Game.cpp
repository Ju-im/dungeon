
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
  spawnEnemy(5);
  grid.printGrid();
  enemy.printEnemiesInPlay();
  player.spawnPlayer(grid);
  weapon.init();
  //enemy.move(-9);
  //spawnPlayer();
  player.init();
  camera.setSize(16* 8, 16* 8);

  

  
  //spawnPlayer();



  //spawnPlayer();

  
 
  return true;
}

// UPDATE FUNCTION
void Game::update(float dt)
{
  //sf::Vector2f cameraCenter();

  weapon.update(dt, player, grid);
  switch (game_state)
  {
    case MENU:
    {
        break;
    }
      
    case GAME:
    {
      gameTurn();
      //enemy.takeDamage(0, weapon.getAttackPos());
      weapon.clearPos();
      updatePlayerExploreGrid();
      break;
            
            
    }
    case PAUSE:
    {
      break;
    }
  }
}

void Game::render()
{
    if (player_camera) {

        sf::Vector2i screenGridPos = player.getScreenPosition(grid);
      // player position screen
      float targetCx = static_cast<float>(screenGridPos.x) + CELL_SIZE / 2.f;
      float targetCy = static_cast<float>(screenGridPos.y) + CELL_SIZE / 2.f;

      sf::Vector2f viewHalf = camera.getSize() / 2.f;
      const float mapPixelW = 60.f * static_cast<float>(CELL_SIZE);
      const float mapPixelH = 60.f * static_cast<float>(CELL_SIZE);
      if (camera.getSize().x >= mapPixelW)
        targetCx = mapPixelW / 2.f;
      else
        targetCx = std::clamp(targetCx, viewHalf.x, mapPixelW - viewHalf.x);

      if (camera.getSize().y >= mapPixelH)
        targetCy = mapPixelH / 2.f;
      else
        targetCy = std::clamp(targetCy, viewHalf.y, mapPixelH - viewHalf.y);

      camera.setCenter(targetCx, targetCy);
      window.setView(camera);
      grid.drawDungeon(window);

      enemy.drawEnemies(window);
      weapon.render(window);
      player.render(window);
      player.renderUI(window, camera);


  }
    else
    {
      // Show the entire map: create a view that covers the whole map in pixels
      const float mapPixelW = 60.f * static_cast<float>(CELL_SIZE);
      const float mapPixelH = 60.f * static_cast<float>(CELL_SIZE);

      // Construct a view that maps the full map rectangle to the window
      sf::View fullView(sf::FloatRect(0.f, 0.f, mapPixelW, mapPixelH));
      // Optionally, keep aspect ratio: you can set center/size instead:
      // fullView.setCenter(mapPixelW / 2.f, mapPixelH / 2.f);
      // fullView.setSize(mapPixelW, mapPixelH);

      window.setView(fullView);
      grid.drawDungeon(window);
      enemy.drawEnemies(window);
      weapon.render(window);
      player.render(window);
      drawPlayerExploreGrid(window);
    
    }
  
 
  
  
}

void Game::mouseClicked(sf::Event event)
{
  // get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
  
 
  
  
}

void Game::keyPressed(sf::Event event)
{

  if (event.key.code == sf::Keyboard::W|| event.key.code == sf::Keyboard::Up)
  {
    /*std::cout << "W pressed" << std::endl;
    player.moveY(-1, grid);
    player.setDirection(-1);
    player.stats.weapon += 1;
    std::cout << player.stats.weapon << std::endl;*/
    if (type == attack)
    {
      type = Null;
    }
    else
    {
      type = Up;
    }
    
    
  }
  if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
  {
    /*std::cout << "A pressed" << std::endl;
    player.moveX(-1, grid);
    player.setDirection(-2);*/
    
     if (type == attack)
    {
      type = Null;
    }
    else
    {
      type = left;
    }
    
  }
  if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
  {
    /*std::cout << "S pressed" << std::endl;
    player.moveY(1, grid);
    player.setDirection(1);
    player.stats.weapon -= 1;
    std::cout << player.stats.weapon << std::endl;*/
    
    if (type == attack)
    {
      type = Null;
    }
    else
    {
      type = down;
    }
  }
  if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
  {
    /*std::cout << "D pressed" << std::endl;
    player.moveX(1, grid);
    player.setDirection(2);*/
    
    if (type == attack)
    {
      type = Null;
    }
    else
    {
      type = right;
    }

  }
  if (event.key.code == sf::Keyboard::Space)
  {
  type = attack;
 
  }
  
  if (event.key.code == sf::Keyboard::E)
  {
    player_camera = !player_camera;
  
  }

  if (event.key.code == sf::Keyboard::Space)
  {
    type = attack;
  }
  if (event.key.code == sf::Keyboard::Enter)
  {
  
  type = attackselected;
  }
   
  player.setInGrid(enemy.gridClassCopy);
}



void Game::gameTurn() {
 
    switch (type)
  {
      case Up:
      {
        player.moveY(-1, grid);
        player.setDirection(-1);
       /* player.stats.weapon += 1;
        if (player.stats.weapon > 5) {
            player.stats.weapon = 1;
        }
        int player_weapon_type = player.stats.weapon;
        std::cout << "Player Weapon Type: " << player_weapon_type << std::endl;
        weapon.attack(player, grid, player_weapon_type); */
        player.stats.item += 1;
        //std::cout << player.stats.item << std::endl;
        if (player.can_move == true)
        {
          type = enemyturn;
        }
      
      
      
      }
        break;
      case down:
      {
      
          player.moveY(1, grid);
        player.setDirection(1);
       /* player.stats.weapon -= 1;
        if (player.stats.weapon < 1) {
            player.stats.weapon = 5;
        }
        int player_weapon_type = player.stats.weapon;
        std::cout << "Player Weapon Type: " << player_weapon_type << std::endl;
        weapon.attack(player, grid, player_weapon_type); */
        player.stats.item -= 1;
        //std::cout << player.stats.item << std::endl;
        
         if (player.can_move == true)
        {
          type = enemyturn;
        }
      }
        break;
      case left:
      {
        
        player.moveX(-1, grid);
        player.setDirection(-2);
        if (player.can_move == true)
        {
          type = enemyturn;
        }
        
        
        
      }
        break;
      case right:
      {
        player.moveX(1, grid);
        player.setDirection(2);
        if (player.can_move == true)
        {
          type = enemyturn;
        }
        
      
      
      }
        break;
      case attack:
      {
        
      player.can_move = !player.can_move;
        if (player.can_move == false) {
          weapon.attack(player, grid, player.getWeapon());
        }
        else
        {
          weapon.attack(player, grid, 99);
        
        }
        
     



        break;
      case attackselected:
      {
        
        weapon.attack(player, grid, player.getWeapon());
        player.can_move = true;
        while (attackselected == type)
        {
          weapon.attack(player, grid, 99);

          player.can_move = true;
          type            = enemyturn;
          enemy.takeDamage(0, weapon.getAttackPos());
        }
      }
      }
        break;
    
  };
 
  if (type == enemyturn)
  {
    std::cout << "Enemy Turn" << std::endl;
    enemy.takeTurn(player.getPosition(grid), grid);
  }

  type = Null;

   
  
  



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
  for (int i = 0; i < amount-1; i++)
  {
    int(*gridCopy)[60] = grid.getAllGrid();
  /*  int type            = ((rand()%6)+1)*-1*/; //Temp Number, change to be the enemy you want to spawn
    int type            = -1;
    sf::Vector3i result = enemy.spawn(gridCopy,type); 
    //grid.setGrid(result.y, result.z, result.x);
  }
 /* int type = ((rand() % 3) + 1) * -1;
  type += -6;
  int(*gridCopy)[60]  = grid.getAllGrid();*/
  //sf::Vector3i result = enemy.spawn(gridCopy, type);
      // For boss enemies, occupy a 2x2 space
      //grid.setGrid(result.y, result.z, result.x);
      //grid.setGrid(result.y + 1, result.z, result.x);
     // grid.setGrid(result.y, result.z + 1, result.x);
      //grid.setGrid(result.y + 1, result.z + 1, result.x);
} 
//void Game::spawnPlayer() 
//{
//  grid.setGrid(30, 30, 99);
//}

void Game::updatePlayerExploreGrid()
{
  for (int x = 0; x < 7; x++)
  {
    for (int y = 0; y < 7; y++)
    {
        playerExploreGrid[player.getPosition(grid).x+x][player.getPosition(grid).y+y] = 1;
        playerExploreGrid[player.getPosition(grid).x-x][player.getPosition(grid).y-y] = 1;
        playerExploreGrid[player.getPosition(grid).x+x][player.getPosition(grid).y-y] = 1;
        playerExploreGrid[player.getPosition(grid).x-x][player.getPosition(grid).y+y] = 1;
    }
  }
}

void Game::resetPlayerExploreGrid()
{
  for (int i = 0; i < 60; i++)
  {
    for (int j = 0; j < 60; j++)
    {
      playerExploreGrid[i][j] = 0;
    }
  }
}

void Game::drawPlayerExploreGrid(sf::RenderWindow& window)
{
  for (int i = 0; i < 60; i++)
  {
    for (int j = 0; j < 60; j++)
    {
      if (playerExploreGrid[i][j] != 1)
      {
        sf::RectangleShape exploredTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        exploredTile.setFillColor(sf::Color(0,0,0));
        exploredTile.setPosition(j * CELL_SIZE, i * CELL_SIZE);
        window.draw(exploredTile);
      }
    }
  }
}