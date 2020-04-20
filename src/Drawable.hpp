#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Config.hpp"
class Drawable
{

    public:
        Drawable();
        Drawable(Config);
        Drawable(std::string);

         virtual ~Drawable();
        /// set the path of sprite's texture.
        inline virtual void SetTexturePath(std::string path) { m_texture_path = path; }
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
#endif //DRAWABLE_H