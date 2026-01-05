#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
// Flying enemy class
// Contains specific attributes and methods for flying enemies
class EnemyFlying
{
	public:
		EnemyFlying();
		~EnemyFlying();
		void Attack(int enemy);
		void Move(int enemy);
        int getHealth(int enemy);
        int getDamage(int enemy);

       private:
		int health;
        int damage;
        enum EnemyFlyingTypes
        {
		  BAT = -2,
          BABY_DRAGON = -4,
		};
};
