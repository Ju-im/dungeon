#include "Player.h"

Player::Player() {
  srand(static_cast<unsigned>(time(NULL)));
}

Player::~Player() {

}

bool Player::init()
{
  stats.health = 2;
  stats.weapon = 4;
  stats.spell  = 0;
  stats.item   = 2;

   if (!WeaponUI.loadFromFile("../Data/Images/UI/Weapons/Weapon-UI.png"))
  {
    std::cout << "Failed to load weapon UI texture" << std::endl;
  }
  WeaponUI.setSmooth(false);
  WeaponUISprite.setTexture(WeaponUI);
  WeaponUISprite.setScale(0.5f, 0.5f);

  if (!DaggerWeaponIcon.loadFromFile("../Data/Images/UI/Weapons/Dagger-Layer.png"))
  {
    std::cout << "Failed to load weapon UI texture" << std::endl;
  }
  DaggerWeaponIcon.setSmooth(false);
  DaggerIconSprite.setTexture(DaggerWeaponIcon);
  DaggerIconSprite.setScale(0.5f, 0.5f);

  if (!SwordWeaponIcon.loadFromFile("../Data/Images/UI/Weapons/Sword-Layer.png"))
  {
    std::cout << "Failed to load weapon UI texture" << std::endl;
  }
  SwordWeaponIcon.setSmooth(false);
  SwordIconSprite.setTexture(SwordWeaponIcon);
  SwordIconSprite.setScale(0.5f, 0.5f);
  //--------------------------------------
  if (!BowWeaponIcon.loadFromFile("../Data/Images/UI/Weapons/Bow-Layer.png"))
  {
    std::cout << "Failed to load weapon UI texture" << std::endl;
  }
  BowWeaponIcon.setSmooth(false);
  BowIconSprite.setTexture(BowWeaponIcon);
  BowIconSprite.setScale(0.5f, 0.5f);

  if (!AxeWeaponIcon.loadFromFile("../Data/Images/UI/Weapons/Axe-Layer.png"))
  {
    std::cout << "Failed to load weapon UI texture" << std::endl;
  }
  AxeWeaponIcon.setSmooth(false);
  AxeIconSprite.setTexture(AxeWeaponIcon);
  AxeIconSprite.setScale(0.5f, 0.5f);

  if (!StaffWeaponIcon.loadFromFile("../Data/Images/UI/Weapons/Staff-Layer.png"))
  {
    std::cout << "Failed to load weapon UI texture" << std::endl;
  }
  StaffWeaponIcon.setSmooth(false);
  StaffIconSprite.setTexture(StaffWeaponIcon);
  StaffIconSprite.setScale(0.5f, 0.5f);

  if (!SpearWeaponIcon.loadFromFile("../Data/Images/UI/Weapons/Spear-Layer.png"))
  {
    std::cout << "Failed to load weapon UI texture" << std::endl;
  }
  SpearWeaponIcon.setSmooth(false);
  SpearIconSprite.setTexture(SpearWeaponIcon);
  SpearIconSprite.setScale(0.5f, 0.5f);

  if (!BackpackIconTexture.loadFromFile("../Data/Images/UI/Items and bag/Backpack-Layer.png"))
  {
    std::cout << "Failed to load weapon UI texture" << std::endl;
  }
  BackpackIconTexture.setSmooth(false);
  BackpackIconSprite.setTexture(BackpackIconTexture);
  BackpackIconSprite.setScale(0.5f, 0.5f);

  if(!Potion3IconTexture.loadFromFile("../Data/Images/UI/Items and bag/Potion-3Charge.png"))
  {
    std::cout << "Failed to load weapon UI texture" << std::endl;
  }
  Potion3IconTexture.setSmooth(false);
  Potion3IconSprite.setTexture(Potion3IconTexture);
  Potion3IconSprite.setScale(0.5f, 0.5f);

   if (!Potion2IconTexture.loadFromFile("../Data/Images/UI/Items and bag/Potion-2Charge.png"))
  {
    std::cout << "Failed to load weapon UI texture" << std::endl;
  }
  Potion2IconTexture.setSmooth(false);
  Potion2IconSprite.setTexture(Potion2IconTexture);
  Potion2IconSprite.setScale(0.5f, 0.5f);

   if (!Potion1IconTexture.loadFromFile("../Data/Images/UI/Items and bag/Potion-1Charge.png"))
  {
    std::cout << "Failed to load weapon UI texture" << std::endl;
  }
  Potion1IconTexture.setSmooth(false);
  Potion1IconSprite.setTexture(Potion1IconTexture);
  Potion1IconSprite.setScale(0.5f, 0.5f);

   if (!Potion0IconTexture.loadFromFile("../Data/Images/UI/Items and bag/Potion-Empty.png"))
  {
    std::cout << "Failed to load weapon UI texture" << std::endl;
  }
  Potion0IconTexture.setSmooth(false);
  Potion0IconSprite.setTexture(Potion0IconTexture);
  Potion0IconSprite.setScale(0.5f, 0.5f);

  if (!HeartTexture.loadFromFile("../Data/Images/UI/Hearts/Full red heart.png"))
  {
    std::cout << "Failed to load heart texture" << std::endl;
  }
  HeartTexture.setSmooth(false);
  HeartSprite.setTexture(HeartTexture);
  
  if (!HalfRedHeartTexture.loadFromFile("../Data/Images/UI/Hearts/Half empty heart.png"))
  {
    std::cout << "Failed to load heart empty texture" << std::endl;
  }
  if (!EmptyHeartTexture.loadFromFile("../Data/Images/UI/Hearts/Empty heart.png"))
  {
    std::cout << "Failed to load empty texture" << std::endl;
  }
  EmptyHeartTexture.setSmooth(false);

  if (!FullSteelHeartTexture.loadFromFile("../Data/Images/UI/Hearts/Full steel heart.png"))
  {
    std::cout << "Failed to load full steel texture" << std::endl;
  }
  FullSteelHeartTexture.setSmooth(false);

  if (!HalfSteel_HalfRedHeartTexture.loadFromFile("../Data/Images/UI/Hearts/"
                                                  "Half steel heart.png"))
  {
    std::cout << "Failed to load half steel half red heart texture" << std::endl;
  }
  HalfSteel_HalfRedHeartTexture.setSmooth(false);


  if (!HalfRedHeartTexture.loadFromFile("../Data/Images/UI/Hearts/Half empty heart.png"))
  {
    std::cout << "Failed to load half red texture" << std::endl;
  }

  if (!HalfSteel_HalfEmptyTexture.loadFromFile("../Data/Images/UI/Hearts/"
                                              "Half empty half steel.png"))
  {
    std::cout << "Failed to load half empty half steel texture" << std::endl;
  }
  HalfSteel_HalfEmptyTexture.setSmooth(false);
  for (int i = 0; i < stats.health; i++)
  {
    sf::Sprite heart;
    heart.setTexture(HeartTexture);
   heart.setScale(0.5f, 0.5f);
    hearts.push_back(heart);
  } 
  

  

  return true;
}

void Player::render(sf::RenderWindow& window) {

    window.draw(test);
}

 sf::Vector2i Player::getPosition(Grid& grid) {

  return gridPos;
}


void Player::spawnPlayer(Grid& grid) {

    float spawn_x = static_cast<float>(CELL_SIZE);
  

  
  int(*gridCopy)[60]             = grid.getAllGrid();
  std::vector<sf::Vector2i> pos;
  for (int y = 0; y < 60; y++)
  {
    for (int x = 0; x < 60; x++)
    {
      if (gridCopy[y][x] == 6)
      {
        pos.push_back({ y, x });
      
      }
    }
  }
  sf::Vector2i gridspawnPosition =pos[rand() % pos.size()];
  gridPos = gridspawnPosition;
  sf::Vector2i actual_screen_pos = { gridspawnPosition.y * CELL_SIZE,
                                     gridspawnPosition.x * CELL_SIZE };
  test.setSize({spawn_x, spawn_x});
  test.setFillColor(sf::Color::White);
  test.setPosition(actual_screen_pos.x, actual_screen_pos.y);
  currentPos = actual_screen_pos;
  std::cout << test.getPosition().y << std::endl;



}


void Player::setDirection(int dir) {

    player_dir = dir;


}


int Player::getDirection() {


    return player_dir;
}


sf::Vector2i Player::getScreenPosition(Grid& grid)
{
  currentPos = { gridPos.y * CELL_SIZE, gridPos.x * CELL_SIZE };
  return currentPos;

}



void Player::moveX(int x, Grid& grid) 
{

  if (gridPos.y + x > -1 && gridPos.y + x < 60)
  {
     
     int y_grid         = gridPos.y + x;
     int x_grid         = gridPos.x;
     int(*gridCopy)[60] = grid.getAllGrid();
     if (gridCopy[x_grid][y_grid] != 1 && can_move)
    {
       gridPos = { gridPos.x, gridPos.y + x };

       sf::Vector2i actual_screen_pos = this->getScreenPosition(grid);
       test.setPosition(actual_screen_pos.x, actual_screen_pos.y);
    }
  }



  // y,x
  
  
  

}


void Player::setInGrid(Grid& grid)
{
  // get the enemy positions amd copy them into the gridClassCopy
  int(*gridCopy)[60] = grid.getAllGrid();
  grid.setGrid(gridPos.x, gridPos.y, 88);
  
}





void Player::moveY(int y, Grid& grid)
{

  if (gridPos.x + y > -1 && gridPos.x+y < 60)
  {
    
    int y_grid = gridPos.y;
    int x_grid = gridPos.x + y;
    int(*gridCopy)[60] = grid.getAllGrid();
    if (gridCopy[x_grid][y_grid] != 1 && can_move)
    {
      gridPos                        = { gridPos.x + y, gridPos.y };
      sf::Vector2i actual_screen_pos = this->getScreenPosition(grid);
      
      test.setPosition(actual_screen_pos.x, actual_screen_pos.y);
    
    }
    
  }
  
}


void Player::renderUI(sf::RenderWindow& window, sf::View camera)
{
  drawHealthBar(window, camera);
  drawWeaponSlot(window, camera);
  drawBackpack(window, camera);
  drawSpellSlot(window, camera);
  drawPotion(window, camera);
}

void Player::drawHealthBar(sf::RenderWindow& window, sf::View camera)
{
  for (int i = 0; i < stats.health; i++)
  {
    hearts[0].setPosition(camera.getCenter().x + 30 + (0 * 16), camera.getCenter().y - 58);
    window.draw(hearts[0]);
  }
 
}
void Player::drawWeaponSlot(sf::RenderWindow& window, sf::View camera)
{
  //sf::RectangleShape weaponSlot(sf::Vector2f(12, 12));
  //weaponSlot.setFillColor(sf::Color(150, 150, 150));
  WeaponUISprite.setPosition(camera.getCenter().x - 60, camera.getCenter().y - 58);
  window.draw(WeaponUISprite);
  switch (stats.weapon)
  {
    case PlayerWeaponType::Sw:
      SwordIconSprite.setPosition(camera.getCenter().x - 60, camera.getCenter().y - 58);
      window.draw(SwordIconSprite);
      break;
    case PlayerWeaponType::B:
       BowIconSprite.setPosition(camera.getCenter().x - 60, camera.getCenter().y - 58);
      window.draw(BowIconSprite);
        break;
    case PlayerWeaponType::A:
       AxeIconSprite.setPosition(camera.getCenter().x - 60, camera.getCenter().y - 58);
      window.draw(AxeIconSprite);
        break;
    case PlayerWeaponType::D:
      DaggerIconSprite.setPosition(camera.getCenter().x - 60, camera.getCenter().y - 58);
      window.draw(DaggerIconSprite);
      break;
    case PlayerWeaponType::St:
      StaffIconSprite.setPosition(camera.getCenter().x - 60, camera.getCenter().y - 58);
      window.draw(StaffIconSprite);
      break;
    case PlayerWeaponType::Sp:
      SpearIconSprite.setPosition(camera.getCenter().x - 60, camera.getCenter().y - 58);
      window.draw(SpearIconSprite);
      break;
    default:
      break;
  }
}
void Player::drawSpellSlot(sf::RenderWindow& window, sf::View camera)
{
  sf::RectangleShape spellSlot(sf::Vector2f(12, 12));
  spellSlot.setFillColor(sf::Color(150, 150, 150));
  spellSlot.setPosition(camera.getCenter().x - 45, camera.getCenter().y - 58);
  window.draw(spellSlot);
}

void Player::drawBackpack(sf::RenderWindow& window, sf::View camera)
{
  BackpackIconSprite.setPosition(camera.getCenter().x - 30, camera.getCenter().y - 58);
  window.draw(BackpackIconSprite);
}

void Player::drawPotion(sf::RenderWindow& window, sf::View camera)
{
  switch (stats.item)
  {
    case 1:
      Potion1IconSprite.setPosition(camera.getCenter().x - 30, camera.getCenter().y - 58);
      window.draw(Potion1IconSprite);
      break;
    case 2:
      Potion2IconSprite.setPosition(camera.getCenter().x - 30, camera.getCenter().y - 58);
      window.draw(Potion2IconSprite);
      break;
    case 3:
      Potion3IconSprite.setPosition(camera.getCenter().x - 30, camera.getCenter().y - 58);
      window.draw(Potion3IconSprite);
      break;
    default:
      Potion0IconSprite.setPosition(camera.getCenter().x - 30, camera.getCenter().y - 58);
      window.draw(Potion0IconSprite);
      break;
      break;
  }
}

int Player::getHealth()
{
  return stats.health;
}
int Player::getWeapon()
{
  return stats.weapon;
}
int Player::getSpell()
{
  return stats.spell;
}
int Player::getItem()
{
  return stats.item;
}