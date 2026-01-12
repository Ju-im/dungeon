#pragma once
class Player
{
 public:
	 Player();
  ~Player();
     void move(int x, int y);
  int getHealth();
     int getDamage();


 private:
     int health;
  int damage; 
      struct PlayersIndividualStats
  {
    int health;
    int damage;
    int x;
    int y;
  };
  PlayersIndividualStats stats;
};
