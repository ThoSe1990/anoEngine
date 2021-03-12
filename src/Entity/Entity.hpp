
#ifndef _ENTITY_ENTITY_HPP_
#define _ENTITY_ENTITY_HPP_

#include <vector>
#include <string>
#include <map>
#include <memory>
#include <iostream>

#include "Constants.hpp"

#include "Entity/EntityManager.hpp"
#include "Components/Component.hpp"

class EntityManager;
class Component;

class Entity : public std::enable_shared_from_this<Entity>
{
private:
    std::shared_ptr<EntityManager> entityManager;

    bool isActive;    
    std::vector<Component*> components;
    std::map<const std::type_info*, Component*> componentTypes;

public:
    bool operator==(const Entity & rhs) const;
    bool operator!=(const Entity & rhs) const;

    std::string name;  
    Layer layer_;

    Entity(std::shared_ptr<EntityManager> manager);
    Entity(std::shared_ptr<EntityManager> manager, std::string name);
    Entity(std::shared_ptr<EntityManager> manager, std::string name, Layer layer);

    void Update(float deltaTime);
    void Render();
    void Deactivate();
    void Activate();
    bool IsActive() const;
    void ListAllComponents() const;

    template <typename T, typename... TArgs>
    T& AddComponent(TArgs&&... args) 
    {
        T* newComponent(new T(std::forward<TArgs>(args)...));
        newComponent->Owner = shared_from_this();
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

    template <typename T>
    bool HasComponent() const 
    {
        return componentTypes.count(&typeid(T));
    }
    
};

#endif