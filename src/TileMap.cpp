#include "TileMap.hpp"

using namespace std;
TileMap::TileMap()
{
    m_tile_map = new vector<Tile>(0);
}

TileMap::~TileMap()
{

    delete m_tile_map;
}