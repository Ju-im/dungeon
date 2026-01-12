#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
// Boss enemy class
// Contains specific attributes and methods for boss enemies
class EnemyBoss
{
	public:
	EnemyBoss();
	~EnemyBoss();
	void Attack(int enemy);
	void Move(int enemy);
	int getHealth(int enemy);
    int getDamage(int enemy);

   private:
	   int health;
	   int damage;
       enum EnemyBossTypes
	   {
		 DRAGON = -7,
         GIANT      = -8,
         SLIME_KING = -9,
	   };

};
