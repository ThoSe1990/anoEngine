#ifndef _SYSTEMS_SYSTEM_HPP_
#define _SYSTEMS_SYSTEM_HPP_

#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>

using Entity = unsigned int;

template<typename C> class ComponentManager;

class System
{
    template<typename C> friend class ComponentManager;

    static unsigned int entitiesCount;
    static std::unordered_map<Entity, size_t> componentsPerEntity;

    static Entity getEntity()
    {
        for( const auto& entity : componentsPerEntity ) 
        {
            if (entity.second == 0)
                return entity.first;
        }
        return entitiesCount++;
    }


    static void AddedComponent(Entity entity)
    {
        auto it = componentsPerEntity.find(entity);
        if (it != componentsPerEntity.end())
        {
            it->second++;
        }
    }

    static void RemoveComponent(Entity entity)
    {
        auto it = componentsPerEntity.find(entity);
        if (it != componentsPerEntity.end())
        {
            it->second--;
            
        }
    }

public:
    virtual ~System() {}
    virtual void Initialize() {}
    virtual void Update(float deltaTime) {}
    virtual void Render() {}
    
    static Entity AddEntity()
    {   
        auto newEntity = getEntity();
        std::cout << "adding entity " << newEntity << " max:" << entitiesCount << std::endl;
        componentsPerEntity[newEntity] = 0;
        return newEntity;
    }
};



#endif