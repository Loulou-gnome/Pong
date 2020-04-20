#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>
#include "Config.hpp"
#include "Drawable.hpp"

class Entity : Drawable
{
    public:
        /// Load all entities from a specific file 
        /// that means that you could change the entity at any time you want.
        //static void LoadEntities(std::string, Entity*);
        //static sf::Texture DrawEntities(Entity[]);

        Entity();
        Entity(Config);
        /// create an entity with the desired texture.
        Entity(std::string);
        virtual ~Entity();
        /// Load the graphical parts of an Entity.
        virtual bool Load();
        /// Init all logical parts of an Entity.
        virtual void Init();
        /// give the sprite from Entity to a RenderWindow::Draw() method.
        virtual sf::Sprite Draw();


    
    protected:

        std::string m_texture_path;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        
};

#endif //ENTITY_H