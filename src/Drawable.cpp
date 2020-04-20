#include "Drawable.hpp"



using namespace std;

Drawable::Drawable()
{

    m_texture_path = "";
}

Drawable::Drawable(Config conf)
{
    m_texture_path = conf.GetValueFromLabel("TexturePath");
}
Drawable::~Drawable()
{
    
}
void Drawable::Init()
{

    
}

bool Drawable::Load()
{
    if(m_texture.loadFromFile(m_texture_path))
        return false;
    cout << "Loaded Texture: " << m_texture_path << '\n';
    return true;
}


sf::Sprite Drawable::Draw()
{
    return m_sprite;
}
