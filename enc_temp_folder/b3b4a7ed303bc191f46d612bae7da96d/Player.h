#pragma once
class Player
{
 public:
	 Player();
  ~Player();
     void move(int x, int y);
  int getHealth();
     int getDamage();
  Playerstats();

 private:
     int health;
  int damage; 
};
