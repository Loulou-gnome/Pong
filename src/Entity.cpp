#include "include/Entity.hpp"

using namespace std;

Entity::Entity()
{

    m_texture_path = "";
}

Entity::Entity(string texture_path)
{
    m_texture_path = texture_path;
}

bool Entity::Load()
{
    if(m_texture.loadFromFile(m_texture_path))
        return false;
    cout << "Loaded Texture: " << m_texture_path << '\n';
    return true;
}


sf::Sprite Entity::Draw()
{
    return m_sprite;
}

bool Entity::LoadEntities(std::string entities_config_path)
{
    //TODO: Load Entities from a file.ini inside a world folder
    Entity _instance;
    
    ConfigRig entities_configs = Configs::LoadEntities(entities_config_path);
    string text_path;
    for(int i = 0; i <= entities_configs.GetCount()-1; i++)
    {
        Config entity_conf = entities_configs.ById(i);
        text_path = entity_conf.GetValueFromLabel("Texture");
        _instance.SetTexturePath(text_path);

        entities.push_back(_instance);

    }

    return true;
}

sf::Texture Entity::DrawEntities()
{
    sf::RenderTexture fake;
    fake.clear();
    for(unsigned int i = 0; i < Entity::entities.size(); i++)
    {
        fake.draw(Entity::entities[i].Draw());
    }
    
    return fake.getTexture();

}