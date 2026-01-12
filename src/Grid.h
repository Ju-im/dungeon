#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Grid
{
 public:
  Grid();
  ~Grid();
  bool init();
  void update(float dt);
  void render();
  sf::FloatRect generateRoom();
  bool placeRoom(sf::FloatRect newRoom);
  void connectRooms(sf::FloatRect room1, sf::FloatRect room2 , int hallway_width=2);
  void generateDungeon();
  void printGrid();
  int getGrid(int x, int y);
  int (*getAllGrid())[60];
  void setGrid(int x, int y, int value);
  sf::Vector2i getSpaenableTile();
 int MAXROOMS = 50;
  int roomCount = 0;
 int MAX_ROOM_SIZE = 20;
  int MIN_ROOM_SIZE = 3;
 int CELL_SIZE     = 10;

  float X_value = 0;
  float Y_value = 0;

  int grid[60][60];
  std::vector<sf::FloatRect> rooms;
  
private:
  int X = 60;
  int Y = 60;

  enum class RoomType
  {
    Start,
    Combat,
    Treasure,
    Shop,
    Boss
  };
};
