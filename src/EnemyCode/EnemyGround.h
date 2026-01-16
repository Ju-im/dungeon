#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
// Ground-based enemy class
// Inherits to the Enemy class and contains specific attributes and methods for ground enemies
class EnemyGround
{
	public:
		EnemyGround();
		~EnemyGround();
        //int (*(Attack(int enemy)))[4];
        int (*Attack(int enemy))[4][3];
        sf::Vector3i Move(int enemy);
        int getHealth(int enemy);
        int getDamage(int enemy);
	private:
	 int health;
     int damage;
	 enum EnemyGroundTypes
	 {
	   SLIME = -1,
       SKELETON = -3,
       SPIDER   = -5,
       WOLF     = -6,
	 };
};
