#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include <iostream>
#include <vector>
class Player
{
 public:
	 Player();
  ~Player();
     bool init();
  void render(sf::RenderWindow& window);
  sf::Vector2i getPosition(Grid& grid);
     sf::Vector2i getScreenPosition(Grid& grid);
     void moveX(int x, Grid& grid);
     void moveY(int y, Grid& grid);
     void spawnPlayer(Grid& grid);
     void setInGrid(Grid& grid);
     int CELL_SIZE = 10;
     sf::Vector2i currentPos;
     sf::Vector2i gridPos; 
     sf::RectangleShape test;
     void setDirection(int dir);
     int getDirection();
     int player_dir = -2;
     bool can_move  = true;
     sf::Texture WeaponUI;
     sf::Sprite WeaponUISprite;

     sf::Texture DaggerWeaponIcon;
     sf::Sprite DaggerIconSprite;

     sf::Texture SwordWeaponIcon;
     sf::Sprite SwordIconSprite;

      sf::Texture BowWeaponIcon;
     sf::Sprite BowIconSprite;

      sf::Texture AxeWeaponIcon;
     sf::Sprite AxeIconSprite;

      sf::Texture StaffWeaponIcon;
     sf::Sprite StaffIconSprite;

      sf::Texture SpearWeaponIcon;
     sf::Sprite SpearIconSprite;

     sf::Texture BackpackIconTexture;
     sf::Sprite BackpackIconSprite;

     sf::Texture Potion3IconTexture;
     sf::Sprite Potion3IconSprite;

     sf::Texture Potion2IconTexture;
     sf::Sprite Potion2IconSprite;

     sf::Texture Potion1IconTexture;
     sf::Sprite Potion1IconSprite;

     sf::Texture Potion0IconTexture;
     sf::Sprite Potion0IconSprite;

     void renderUI(sf::RenderWindow& window, sf::View camera);
     void drawHealthBar(sf::RenderWindow& window, sf::View camera);
     void drawWeaponSlot(sf::RenderWindow& window, sf::View camera);
     void drawSpellSlot(sf::RenderWindow& window, sf::View camera);
     void drawBackpack(sf::RenderWindow& window, sf::View camera);
     void drawPotion(sf::RenderWindow& window, sf::View camera);

     struct PlayerStats
     {
       int health;
       int weapon;
       int spell;
       int item;
     };
     PlayerStats stats;

     int getHealth();
     int getWeapon();
     int getSpell();
     int getItem();

 private:
     
};
enum PlayerWeaponType
{
  Sw  = 0,
  A    = 1,
  B   = 2,
  St = 3,
  D= 4,
  Sp = 5

};
