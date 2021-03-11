

#include <iostream>
#include "Entity/EntityManager.hpp"
#include "Log.hpp"

void EntityManager::ClearData() 
{
    for (auto& entity: entities) 
        entity->Deactivate();
}

void EntityManager::Update(float deltaTime) 
{
    for (auto& entity: entities) 
        entity->Update(deltaTime);
}

void EntityManager::Render() 
{
    for (int layer = 0; layer < static_cast<int>(Layer::layer_count); layer++) 
        for (auto& entity: GetEntities(static_cast<Layer>(layer)))
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

std::vector<std::shared_ptr<Entity>> EntityManager::GetEntities() const 
{
    return entities;
}

void EntityManager::DeleteEntity(std::shared_ptr<Entity> entity) 
{
    int id = 0;
    for (auto& e : entities)
    {
        if (e == entity)
        {
            entities.erase(entities.begin()+id);
            break;
        }   
        id++;
    }
}

std::vector<std::shared_ptr<Entity>> EntityManager::GetEntities(Layer layer) const
{
    std::vector<std::shared_ptr<Entity>> selectedEntities;
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

std::shared_ptr<Entity> EntityManager::AddEntity(const std::string& entityName) 
{
    auto entity = std::make_shared<Entity>(shared_from_this(), entityName);
    entities.emplace_back(entity);
    return entity;
}

std::shared_ptr<Entity> EntityManager::AddEntity(const std::string& entityName, Layer layer) 
{
    auto entity = std::make_shared<Entity>(shared_from_this(), entityName, layer);
    entities.emplace_back(entity);
    return entity;
}

