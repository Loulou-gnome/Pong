#ifndef WORLD_H
#define WORLD_H
#include <fstream>
#include <iostream>
#include <string>
#include "Entity.hpp"
class World
{
    public:
        World();
        virtual ~World();
        
        unsigned int entities_count = 0;
        
        void LoadMap(std::string);
        /// Load an Entities.ini file into an Entity vector
        void LoadEntities(std::string);
    
    protected:

        //TileMap *map = nullptr;
    
    public:
        std::vector<Entity> *entities = nullptr;

};

#endif //WORLD_H