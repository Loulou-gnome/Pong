#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>
#include "Configs.hpp"

class Entity
{
    public:
        /// Load all entities from a specific file 
        /// that means that you could change the entity at any time you want.
        static bool LoadEntities(std::string entities_config_path);
        static sf::Texture DrawEntities();
        Entity();
        Entity(std::string texture_path);
        virtual void SetTexturePath(std::string path) { m_texture_path = path; }
        /// Load the graphical parts of an Entity.
        virtual bool Load();
        /// Init all logical parts of an Entity.
        virtual void Init();
        /// give the sprite from Entity to a RenderWindow::Draw() method.
        virtual sf::Sprite Draw();


        /// entities currently displayed.
        static std::vector<Entity> entities;
    protected:

        std::string m_texture_path;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        
};

#endif //ENTITY_H