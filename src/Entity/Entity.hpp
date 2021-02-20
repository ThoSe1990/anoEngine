
#ifndef _ENTITY_ENTITY_HPP_
#define _ENTITY_ENTITY_HPP_


#include <vector>
#include <string>
#include <map>

#include "Entity/EntityManager.hpp"
#include "Components/Component.hpp"

class EntityManager;
class Component;

class Entity
{
private:
    EntityManager& entityManager;
    bool isActive;
    std::vector<Component*> components;
    std::map<const std::type_info*, Component*> componentTypes;

public:

    Entity(EntityManager& manager);
    Entity(EntityManager& manager, std::string name);

    void Update(float deltaTime);
    void Render();
    void Destroy();
    bool IsActive() const;
    void ListAllComponents() const;
    
    template <typename T, typename... TArgs>
    T& AddComponent(TArgs&&... args) 
    {
        T* newComponent(new T(std::forward<TArgs>(args)...));
        newComponent->Owner = this;
        components.emplace_back(newComponent);
        componentTypes[&typeid(*newComponent)] = newComponent;
        newComponent->Initialize();
        return *newComponent;
    }
    
    template <typename T>
    T* GetComponent() 
    {
        return static_cast<T*>(componentTypes[&typeid(T)]);
    }

    std::string name;
};

#endif