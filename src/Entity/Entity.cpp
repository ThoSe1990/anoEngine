#include <iostream>
#include "Entity/Entity.hpp"

Entity::Entity(EntityManager& manager): entityManager(manager) 
{
    this->isActive = true;
}

Entity::Entity(EntityManager& manager, std::string name): entityManager(manager), name(name) 
{
    this->isActive = true;
}

void Entity::Update(float deltaTime) 
{
    for (auto& component: components) 
    {
        component->Update(deltaTime);
    }
}

void Entity::Render() 
{
    for (auto& component: components) 
    {
        component->Render();
    }
}

void Entity::Destroy() 
{
    this->isActive = false;
}

bool Entity::IsActive() const 
{
    return this->isActive;
}

void Entity::ListAllComponents() const 
{
    for (auto mapElement: componentTypes) {
        std::cout << "    Component<" << mapElement.first->name() << ">" << std::endl;
    }
}