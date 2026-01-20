#include "Grid.h"
#include <algorithm>
#include <iostream>

Grid::Grid()
{
  srand(static_cast<unsigned>(time(NULL)));
}
Grid::~Grid() {}
bool Grid::init()
{

  for (int i = 0; i < X ; i++)
  {
    for (int j = 0; j < Y ; j++)
    {
      grid[i][j] = RoomIndex::Wall;
    }
    std::cout << std::endl;

  }
  if (!WallTileTexture.loadFromFile("../Data/Images/Map Tiles/Wall.png"))
  {
    std::cout << "Failed to load weapon UI texture" << std::endl;
  }
  WallTileTexture.setSmooth(false);
  WallTileSprite.setTexture(WallTileTexture);
  WallTileSprite.setScale(0.3f, 0.3f);
  return true;
}

sf::IntRect Grid::generateRoom(RoomType type)
{
    //add specific roomsize to start
  int roomWidth = MIN_ROOM_SIZE + rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) +
                  sizeBonus(type);
  int roomHeight = MIN_ROOM_SIZE +
                   rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) +
                   sizeBonus(type);

  int x_gridPos = rand() % (X - roomWidth - 2) + 1;
  int y_gridPos = rand() % (Y - roomHeight - 2) + 1;
  if (type == RoomType::Start)
  {
    roomWidth = 5;
    roomHeight = 5;
  
  
  }
  return sf::IntRect(x_gridPos, y_gridPos, roomWidth, roomHeight);
}

int Grid::sizeBonus(RoomType type)
{
  switch (type)
  {
    case RoomType::Treasure:
      return 1;
      break;
    case RoomType::Shop:
      return 2;
      break;
    case RoomType::Boss:
      return 5;
    default:
      break;
  }
}

bool Grid::placeRoom(sf::IntRect& newRoom)
{
  for (int x = newRoom.left - 1; x <= newRoom.left + newRoom.width; x++)
  {
    for (int y = newRoom.top - 1; y <= newRoom.top + newRoom.height; y++)
    {
      if (!inBounds(x, y) || grid[x][y] != RoomIndex::Wall)
      {
        return false;
      }
    }
  }
  return true;
}

void Grid::writeRoom(Room& room)
{
  int tile = tileForRoom(room.type);
  for (int i = room.rect.left; i < room.rect.left + room.rect.width; i++)
  {
    for (int j = room.rect.top; j < room.rect.top + room.rect.height; j++)
    {
      grid[i][j] = tile;
    }
  }
}

void Grid::carveTile(int x, int y)
{
  if (inBounds(x, y))
  {
    grid[x][y] = RoomIndex::Floor;
  }
}

bool Grid::inBounds(int x, int y)
{
  return x >= 0 && x < X && y >= 0 && y < Y;
}

int Grid::tileForRoom(RoomType type)
{
  switch (type)
  {
    case RoomType::Start:
      return RoomIndex::StartRoom;
      break;
    case RoomType::Combat:
      return RoomIndex::CombatRoom;
      break;
    case RoomType::Treasure:
      return RoomIndex::TreasureRoom;

      break;
    case RoomType::Shop:
      return RoomIndex::ShopRoom;
      break;
    case RoomType::Boss:
      return RoomIndex::BossRoom;
      break;
    default:
      break;
  }
  return 0;
}

void Grid::connectRooms(const sf::IntRect& a, const sf::IntRect& b, int width)
{
  int ax = a.left + a.width / 2;
  int ay = a.top + a.height / 2;
  int bx = b.left + b.width / 2;
  int by = b.top + b.height / 2;

  bool horizontalFirst = rand() % 2;

  if (horizontalFirst)
  {
    for (int x = std::min(ax, bx); x <= std::max(ax, bx); ++x)
      for (int w = -width / 2; w <= width / 2; ++w)
        carveTile(x, ay + w);

    for (int y = std::min(ay, by); y <= std::max(ay, by); ++y)
      for (int w = -width / 2; w <= width / 2; ++w)
        carveTile(bx + w, y);
  }
  else
  {
    for (int y = std::min(ay, by); y <= std::max(ay, by); ++y)
      for (int w = -width / 2; w <= width / 2; ++w)
        carveTile(ax + w, y);

    for (int x = std::min(ax, bx); x <= std::max(ax, bx); ++x)
      for (int w = -width / 2; w <= width / 2; ++w)
        carveTile(x, by + w);
  }
}

void Grid::drawDungeon(sf::RenderWindow& window)
{
  for (int i = 0; i < X ; i++)
  {
    for (int j = 0; j < Y ; j++)
    {
      if (grid[i][j] == RoomIndex::Wall)
      {
        // Draw wall tile at (i, j)
        /*sf::RectangleShape wallTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        wallTile.setFillColor(sf::Color::Green);
        wallTileSprite.setPosition(j * CELL_SIZE, i * CELL_SIZE);*/
        WallTileSprite.setPosition(j * CELL_SIZE, i * CELL_SIZE);
       window.draw(WallTileSprite);
      }
      else if (grid[i][j] == RoomIndex::BossRoom)
      {
        sf::RectangleShape bossTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        bossTile.setFillColor(sf::Color::Red);
        bossTile.setPosition(j * CELL_SIZE, i * CELL_SIZE);
        window.draw(bossTile);
      }
      else if (grid[i][j] == RoomIndex::CombatRoom)
      {
        sf::RectangleShape combatTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        combatTile.setFillColor(sf::Color::Yellow);
        combatTile.setPosition(j * CELL_SIZE, i * CELL_SIZE);
        window.draw(combatTile);
      }
      else if (grid[i][j] == RoomIndex::StartRoom)
      {
        sf::RectangleShape startTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        startTile.setFillColor(sf::Color::Magenta);
        startTile.setPosition(j * CELL_SIZE, i * CELL_SIZE);
        if (start)
        {
          startpos = startTile.getPosition();
        }
        window.draw(startTile);
      }
      else if (grid[i][j] == RoomIndex::ShopRoom)
      {
        sf::RectangleShape startTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        startTile.setFillColor(sf::Color::Cyan);
        startTile.setPosition(j * CELL_SIZE, i * CELL_SIZE);
        window.draw(startTile);
      }
      else if (grid[i][j] == RoomIndex::TreasureRoom)
      {
        sf::RectangleShape startTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        startTile.setFillColor(sf::Color::Black);
        startTile.setPosition(j * CELL_SIZE, i * CELL_SIZE);
        window.draw(startTile);
      }
     
      
      else if (grid[i][j] == RoomIndex::Floor)
      {
        // Draw floor tile at (i, j)
        sf::RectangleShape floorTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        floorTile.setFillColor(sf::Color::Blue);
        floorTile.setPosition(j * CELL_SIZE, i * CELL_SIZE);
        window.draw(floorTile);
      }
    }
  }
}

void Grid::generateDungeon()
{
  rooms.clear();

  for (RoomType type : roomPlan)
  {
    sf::IntRect rect;
    do
    {
      rect = generateRoom(type);
    } while (!placeRoom(rect));

    Room room{ rect, type };

    if (!rooms.empty())
    {
      if (type == RoomType::Treasure && rooms.size() > 2)
      {
        int branch = rand() % (rooms.size() - 1);
        connectRooms(rooms[branch].rect, rect, 1);
      }
      else
      {
        connectRooms(rooms.back().rect, rect, 2);
      }
    }

    writeRoom(room);
    rooms.push_back(room);
  }
  for (Room& room : rooms)
  {
    fillRoom(room.type, room.rect);
  }
  printGrid();
}

void Grid::printGrid()
{
  for (int i = 0; i < X ; i++)
  {
    for (int j = 0; j < Y ; j++)
    {
      std::cout << grid[i][j];
    }
    std::cout << std::endl;
  }
}

void Grid::fillRoom(RoomType type, sf::IntRect rect)
{
  switch (type)
  {
    case RoomType::Start:
      for (int i = rect.left; i < rect.left + rect.width; i++)
      {
        for (int j = rect.top; j < rect.top + rect.height; j++)
        {
          grid[i][j] = RoomIndex::StartRoom;
        }
      }
      break;
    case RoomType::Combat:
      for (int i = rect.left; i < rect.left + rect.width; i++)
      {
        for (int j = rect.top; j < rect.top + rect.height; j++)
        {
          grid[i][j] = RoomIndex::CombatRoom;
        }
      }

      break;
    case RoomType::Treasure:
      for (int i = rect.left; i < rect.left + rect.width; i++)
      {
        for (int j = rect.top; j < rect.top + rect.height; j++)
        {
          grid[i][j] = RoomIndex::TreasureRoom;
        }
      }

      break;
    case RoomType::Shop:
      for (int i = rect.left; i < rect.left + rect.width; i++)
      {
        for (int j = rect.top; j < rect.top + rect.height; j++)
        {
          grid[i][j] = RoomIndex::ShopRoom;
        }
      }

      break;
    case RoomType::Boss:
      for (int i = rect.left; i < rect.left + rect.width; i++)
      {
        for (int j = rect.top; j < rect.top + rect.height; j++)
        {
          grid[i][j] = RoomIndex::BossRoom;
        }
      }
      break;
  }
}

sf::Vector2f Grid::getStartPosition()
{
  return startpos;
}

int (*Grid::getAllGrid())[60]
{
  return grid;
}

int Grid::getGrid(int x, int y)
{
  return grid[x][y];
}

void Grid::setGrid(int x, int y, int value)
{
  grid[x][y] = value;
}

void Grid::drawArea(int x, int y, sf::RenderWindow& window) {

for (int Y = camera_height; Y > 0; Y--)
  {
  for (int X = camera_width; X > 0; X--)
  {
    int true_x = x - X;
    int true_y = y - Y;
    if (true_x < 0 || true_y < 0)
    {
      continue;
    }
    if (grid[true_y][true_x] == RoomIndex::Wall)
    {
      // Draw wall tile at (i, j)
      sf::RectangleShape wallTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
      wallTile.setFillColor(sf::Color::Green);
      wallTile.setPosition(true_x * CELL_SIZE, true_y * CELL_SIZE);
      window.draw(wallTile);
    }
    else if (grid[true_y][true_x] == RoomIndex::BossRoom)
    {
      sf::RectangleShape bossTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
      bossTile.setFillColor(sf::Color::Red);
      bossTile.setPosition(true_x * CELL_SIZE, true_y * CELL_SIZE);
      window.draw(bossTile);
    }
    else if (grid[true_y][true_x] == RoomIndex::CombatRoom)
    {
      sf::RectangleShape combatTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
      combatTile.setFillColor(sf::Color::Yellow);
      combatTile.setPosition(true_x * CELL_SIZE, true_y * CELL_SIZE);
      window.draw(combatTile);
    }
    else if (grid[true_y][true_x] == RoomIndex::StartRoom)
    {
      sf::RectangleShape startTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
      startTile.setFillColor(sf::Color::Magenta);
      startTile.setPosition(true_x * CELL_SIZE, true_y * CELL_SIZE);
      if (start)
      {
        startpos = startTile.getPosition();
      }
      window.draw(startTile);
    }
    else if (grid[true_y][true_x] == RoomIndex::ShopRoom)
    {
      sf::RectangleShape startTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
      startTile.setFillColor(sf::Color::Cyan);
      startTile.setPosition(true_x * CELL_SIZE, true_y * CELL_SIZE);
      window.draw(startTile);
    }
    else if (grid[true_y][true_x] == RoomIndex::TreasureRoom)
    {
      sf::RectangleShape startTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
      startTile.setFillColor(sf::Color::Black);
      startTile.setPosition(true_x * CELL_SIZE, true_y * CELL_SIZE);
      window.draw(startTile);
    }
    else if (grid[true_y][true_x] < 0)
    {
      sf::RectangleShape startTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
      startTile.setFillColor(sf::Color(128, 128, 128));
      startTile.setPosition(true_x * CELL_SIZE, true_y * CELL_SIZE);
      window.draw(startTile);
    
    }
    else if (grid[true_y][true_x] == 99)
    {
      sf::RectangleShape startTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
      startTile.setFillColor(sf::Color::White);
      window.draw(startTile);
    }
     
    else
    {
      // Draw floor tile at (i, j)
      sf::RectangleShape floorTile(sf::Vector2f(CELL_SIZE, CELL_SIZE));
      floorTile.setFillColor(sf::Color::Blue);
      floorTile.setPosition(true_x * CELL_SIZE, true_y * CELL_SIZE);
      window.draw(floorTile);
    }
  }
}



}
