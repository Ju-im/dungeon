#include "Weapon.h"
Weapon::Weapon() {
  srand(static_cast<unsigned>(time(NULL)));


}
Weapon::~Weapon() {}



void Weapon::attack(Player& player, Grid& grid, int type)
{
  this->init();
  sf::Vector2i grid_pos =player.getScreenPosition(grid);

  switch (type)
  {
    case (Dagger):
    {
      attack_grid[2][1] = 3;
      attack_grid[3][0] = 4;
      attack_grid[3][2] = 2;
      break;
    }
  
    case (Spear):
    {
      attack_grid[2][1] = 3;
      attack_grid[1][1] = 1;
      attack_grid[0][1] = 2;

        break;
    }
    case (Bow):
    {
    
      attack_grid[1][1] = 1;
      attack_grid[0][1] = 2;

      break;
    }
    case (Axe):
    {
      attack_grid[2][0] = 3;
      attack_grid[2][2] = 1;
      attack_grid[1][0] = 2;
      attack_grid[1][1] = 1;
      attack_grid[1][2] = 2;


      break;
    }
    case (Sword):
    {
      attack_grid[2][0] = 3;
      attack_grid[2][1] = 1;
      attack_grid[2][2] = 2;
      attack_grid[1][1] = 2;

      break;
    }
    case (Staff):
    {
      attack_grid[2][1] = 3;
      attack_grid[1][1] = 1;
      attack_grid[0][0] = 2;
      attack_grid[0][2] = 2;

      break;
    }
   
    default:
      break;
  }



}

void Weapon::update(float dt, Player& player , Grid& grid) {

    player_pos = player.getPosition(grid);
  player_dir = player.getDirection();
    


}







void Weapon::clearPos() 
{
  pos.clear();
}

void Weapon::render(sf::RenderWindow& window)
{
  t           = clock.getElapsedTime().asSeconds();
  sf::Uint8 a = static_cast<sf::Uint8>(std::sin(t * 6.0f) * 127 + 128);
  for (int y = 0; y < Y; y++)
  {
    for (int x = 0; x < X; x++)
    {
      switch (player_dir)
      {
          //down
          case (1):
        {
          if (attack_grid[y][x] != 0 && attack_grid[y][x] != 9)
          {
            //pos.clear();
            int dir_x = 3 - y;
            int dir_y = 1 - x;
            // Draw wall tile at (i, j)
            sf::RectangleShape wallTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            sf::Text damagetext;
            
            damagetext.setFont(font1); 
            damagetext.setString(std::to_string(attack_grid[y][x]));
            
            damagetext.setPosition(
              ((player_pos.y + dir_y) * CELL_SIZE)+1,
              (player_pos.x + dir_x) * CELL_SIZE);
            damagetext.setCharacterSize(8);
            damagetext.setFillColor(sf::Color::White);
            wallTile.setFillColor(sf::Color(0,0,0,a));
            wallTile.setPosition(
              (player_pos.y + dir_y) * CELL_SIZE,
              (player_pos.x + dir_x) * CELL_SIZE);
            pos.push_back(sf::Vector3f(wallTile.getPosition().x,wallTile.getPosition().y, attack_grid[y][x]));
          
            
            window.draw(wallTile);
            window.draw(damagetext);
            
            break;
          }
        }
        
          //up
          case(-1) :
          {
            if (attack_grid[y][x] != 0 && attack_grid[y][x] != 9)
            {
              //pos.clear();
              int dir_x = 3 - y;
              int dir_y = 1 - x;
              sf::Text damagetext;

              damagetext.setFont(font1);
              damagetext.setString(std::to_string(attack_grid[y][x]));

              damagetext.setPosition(
                (player_pos.y + dir_y) * CELL_SIZE,
                (player_pos.x - dir_x) * CELL_SIZE);
              damagetext.setCharacterSize(8);
              damagetext.setFillColor(sf::Color::White);
              // Draw wall tile at (i, j)
              sf::RectangleShape wallTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
              wallTile.setFillColor(sf::Color(0, 0, 0, a));
              wallTile.setPosition(
                (player_pos.y + dir_y) * CELL_SIZE,
                (player_pos.x - dir_x) * CELL_SIZE);
              
              pos.push_back(sf::Vector3f(wallTile.getPosition().x,wallTile.getPosition().y, attack_grid[y][x]));
              window.draw(wallTile);
              window.draw(damagetext);
              
              break;
            }
          }
          
          //left
        case (-2):
        {
          if (attack_grid[y][x] != 0 && attack_grid[y][x] != 9)
          {
            // pos.clear();
            int dir_x = (1 - x);
            int dir_y = (3 - y);
            sf::Text damagetext;

            damagetext.setFont(font1);
            damagetext.setString(std::to_string(attack_grid[y][x]));

            damagetext.setPosition(
              (player_pos.y - dir_y) * CELL_SIZE,
              (player_pos.x + dir_x) * CELL_SIZE);
            damagetext.setCharacterSize(8);
            damagetext.setFillColor(sf::Color::White);
            // Draw wall tile at (i, j)
            sf::RectangleShape wallTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            wallTile.setFillColor(sf::Color(0, 0, 0, a));
            wallTile.setPosition(
              (player_pos.y - dir_y) * CELL_SIZE,
              (player_pos.x + dir_x) * CELL_SIZE);
            pos.push_back(sf::Vector3f(
              wallTile.getPosition().x,
              wallTile.getPosition().y,
              attack_grid[y][x]));
            window.draw(wallTile);
            window.draw(damagetext);

            break;
          }
         
        }
        //right
        case (2):
        {
          if (attack_grid[y][x] != 0 && attack_grid[y][x] != 9)
          {
            // pos.clear();
            int dir_x = 1 - x;
            int dir_y = 3 - y;
            sf::Text damagetext;

            damagetext.setFont(font1);
            damagetext.setString(std::to_string(attack_grid[y][x]));

            damagetext.setPosition(
              (player_pos.y + dir_y) * CELL_SIZE,
              (player_pos.x + dir_x) * CELL_SIZE);
            damagetext.setCharacterSize(8);
            damagetext.setFillColor(sf::Color::White);
            // Draw wall tile at (i, j)
            sf::RectangleShape wallTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            wallTile.setFillColor(sf::Color(0, 0, 0, a));
            wallTile.setPosition(
              (player_pos.y + dir_y) * CELL_SIZE,
              (player_pos.x + dir_x) * CELL_SIZE);
            pos.push_back(sf::Vector3f(
              wallTile.getPosition().x,
              wallTile.getPosition().y,
              attack_grid[y][x]));
            window.draw(wallTile);
            window.draw(damagetext);
            break;
          }
        

          default:
            break;
        }
      }
    }
  }
}

std::vector<sf::Vector3i> Weapon::getAttackPos()
{
  grid_pos.clear();

  for (int i = 0; i < pos.size(); i++)
  {
    grid_pos_selected.x = pos[i].x / CELL_SIZE;
    grid_pos_selected.y = pos[i].y / CELL_SIZE;
    int grid_x          = pos[i].x / CELL_SIZE;
    int grid_y          = pos[i].y / CELL_SIZE;
    grid_pos_selected.z = pos[i].z;

    grid_pos.push_back(grid_pos_selected);
  }
  pos.clear();
  return grid_pos;
}








bool Weapon::init() {
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 3; j++)
    {
    
    attack_grid[i][j] = 0;
    
    }
  }
  attack_grid[3][1] = 9;
  
  if (!font1.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "Failed to load font!" << std::endl;
    return false;
  }
  font1.setSmooth(false);
  damageText.setFont(font1);


	return true;
}