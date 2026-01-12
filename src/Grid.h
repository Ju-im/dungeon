#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
enum RoomIndex
{
  Wall         = 1,
  Floor        = 0,
  StartRoom    = 6,
  CombatRoom   = 2,
  TreasureRoom = 3,
  ShopRoom     = 4,
  BossRoom     = 5
};
enum class RoomType
{
  Start,
  Combat,
  Treasure,
  Shop,
  Boss
};
struct Room
{
  sf::IntRect rect;
  RoomType type;
};

class Grid
{
 public:
  Grid();
  ~Grid();
  bool init();
  void update(float dt);
  void render();
  sf::Vector2f getStartPosition();
  sf::IntRect generateRoom(RoomType type);
  int sizeBonus(RoomType type);
  bool placeRoom(sf::IntRect& newRoom);
  void writeRoom(Room& room);
  void carveTile(int x, int y);
  bool inBounds(int x, int y);
  int tileForRoom(RoomType type);
  void connectRooms(const sf::IntRect& a, const sf::IntRect& b, int width);
  void drawDungeon(sf::RenderWindow& window);
  void generateDungeon();
  void printGrid();
  void fillRoom(RoomType type, sf::IntRect rect);
  int getGrid(int x, int y);
  int (*getAllGrid())[60];
  void setGrid(int x, int y, int value);
  sf::Vector2i getSpaenableTile();
  int MAXROOMS      = 50;
  int roomCount     = 0;
  int MAX_ROOM_SIZE = 20;
  int MIN_ROOM_SIZE = 5;
  int CELL_SIZE     = 10;

  float X_value = 0;
  float Y_value = 0;

  int grid[60][60];

  std::vector<Room> rooms;
  std::vector<RoomType> roomPlan = { RoomType::Start,    RoomType::Combat,
                                     RoomType::Combat,   RoomType::Combat,
                                     RoomType::Treasure, RoomType::Shop,
                                     RoomType::Boss };
  bool start                     = true;
  sf::Vector2f startpos;

 private:
  int X = 60;
  int Y = 60;
};