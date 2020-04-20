#include "Entity.hpp"

using namespace std;

Entity::Entity() : Drawable()
{

}

Entity::Entity(Config conf) : Drawable(conf)
{

}
Entity::~Entity()
{
    
}
void Entity::Init() 
{
    Drawable::Init();
}

bool Entity::Load()
{
    return Drawable::Load();
}


sf::Sprite Entity::Draw()
{
    return Drawable::Draw();
}

//void Entity::LoadEntities(std::string entities_config_path, Entity *entities_configs = nullptr )
//{
//    //TODO: Load Entities from a file.ini inside a world folder
//
//    Entity _instance;
//    std::vector<Entity> _instEnt;
//    MasterConfig entities_configs = Configs::LoadEntities(entities_config_path, entities_configs);
//    string text_path;
//    for(int i = 0; i <= entities_configs; i++)
//    {
//        Config entity_conf = entities_configs.ById(i);
//        text_path = entity_conf.GetValueFromLabel("Texture");
//        _instance.SetTexturePath(text_path);
//
//        _instEnt.push_back(_instance);
//
//    }
//
//    return _instEnt;
//}

//sf::Texture Entity::DrawEntities(Entity entities[])
//{
//    sf::RenderTexture fake;
//    fake.clear();
//    for(unsigned int i = 0; i < Entity::entities.size(); i++)
//    {
//        fake.draw(Entity::entities[i].Draw());
//    }
//    
//    return fake.getTexture();
//
//}