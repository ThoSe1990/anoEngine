

#include <iostream>
#include "Entity/EntityManager.hpp"
#include "Log.hpp"

void EntityManager::ClearData() 
{
    for (auto& entity: entities) 
        entity->Destroy();
}

void EntityManager::Update(float deltaTime) 
{
    for (auto& entity: entities) 
        entity->Update(deltaTime);
}

void EntityManager::Render() 
{

    for (auto& entity: entities) 
        entity->Render();
}

bool EntityManager::HasNoEntities() const 
{
    return entities.size() == 0;
}

unsigned int EntityManager::GetEntityCount() const 
{
    return entities.size();
}

std::vector<Entity*> EntityManager::GetEntities() const 
{
    return entities;
}

std::vector<Entity*> EntityManager::GetEntities(Layer layer) const
{
    std::vector<Entity*> selectedEntities;
    for (auto& entity: entities) 
    {
        if (entity->layer_ == layer) 
            selectedEntities.emplace_back(entity);
    }
    return selectedEntities;
}

void EntityManager::ListAllEntities() const 
{
    unsigned int i = 0;
    for (auto& entity: entities) 
    {
        Logger::Log(logging::trivial::debug, log_location, " Entity[" , i , "]: " , entity->name);
        entity->ListAllComponents();
        i++;
    }
}


Entity& EntityManager::AddEntity(std::string entityName) 
{
    Entity *entity = new Entity(*this, entityName);
    entities.emplace_back(entity);
    return *entity;
}

Entity& EntityManager::AddEntity(std::string entityName, Layer layer) 
{
    Entity *entity = new Entity(*this, entityName, layer);
    entities.emplace_back(entity);
    return *entity;
}

