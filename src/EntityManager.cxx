#include<vector>
#include"include/Entity.h"
void EntityManager::init()
{

}

void EntityManager::run()
{
    drawEntities();
}

void EntityManager::deinit()
{
    mEntities.clear();
}
void EntityManager::addEntity(Entity* entity)
{
    mEntities.push_back(entity);
}
void EntityManager::removeEntity(Entity* entity)
{
    vector<Entity*>::iterator it;
    for(it = mEntities.begin(); it < mEntities.end(); it++)
    {
        if(it == entity)
        {
            break;
        }
    }
    mEntities.erase(it);
}
void EntityManager::drawEntities()
{
    for(it = mEntities.begin(); it < mEntities.end(); it++)
    {
        if(it == entity)
        {
            it->draw();
        }
    }
}
std::vector<Entity*> *EntityManager::getEntities()
{
    return(mEntities);
}
