#ifndef TILEMAP_H
#define TILEMAP_H
#include <vector>
#include "Tile.hpp"

class TileMap
{
    public:
        TileMap();
        ~TileMap();

        void Load();
    protected:

        std::vector<Tile> *m_tile_map;

};


#endif //TILEMAP_H