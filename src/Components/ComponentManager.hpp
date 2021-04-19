#ifndef _COMPONENTS_COMPONENTMANAGER_HPP_
#define _COMPONENTS_COMPONENTMANAGER_HPP_

#include <vector>
#include <unordered_map>
#include <cassert>

#include "Systems/System.hpp"

using Entity = unsigned int;


template<typename C>
class ComponentManager
{
private:
    std::vector<std::shared_ptr<C>> components;
    std::vector<Entity> entities;
    std::unordered_map<Entity, size_t> lookup;

public:

    std::shared_ptr<C> Create(Entity entity)
    {
        assert(lookup.find(entity) == lookup.end());
        assert(entities.size() == components.size());
        assert(lookup.size() == components.size());

		lookup[entity] = components.size();

        components.push_back(std::move(std::make_shared<C>()));
        entities.push_back(entity);
        
        System::AddedComponent(entity);

        return components.back();
    }

    template <typename... TArgs>
    std::shared_ptr<C> Create(Entity entity, TArgs&&... args)
    {
        assert(lookup.find(entity) == lookup.end());
        assert(entities.size() == components.size());
        assert(lookup.size() == components.size());

		lookup[entity] = components.size();

        components.push_back(std::move(std::make_shared<C>(entity, std::forward<TArgs>(args)...)));
        entities.push_back(entity);

        System::AddedComponent(entity);

        return components.back();
    }

    void Remove(Entity entity)
    {
        std::cout << "removing entity " << entity << std::endl;
        auto it = lookup.find(entity);
        if (it != lookup.end())
        {
            const size_t index = it->second;
            const Entity entity = entities[index];

            if (index < components.size() - 1)
            {
                components[index] = std::move(components.back());
                entities[index] = entities.back();
                lookup[entities[index]] = index;
            }
            components.pop_back();
            entities.pop_back();
            lookup.erase(entity);

            System::RemoveComponent(entity);
        }
    }

    void MoveItem(size_t index_from, size_t index_to)
    {
        assert(index_from < GetCount());
        assert(index_to < GetCount());
        if (index_from == index_to)
            return;
        
        std::shared_ptr<C> component = std::move(components[index_from]);
        Entity entity = entities[index_from];

        const int direction = index_from < index_to ? 1 : -1;
        for (size_t i = index_from; i != index_to; i += direction)
        {
            const size_t next = i + direction;
            components[i] = std::move(components[next]);
            entities[i] = entities[next];
            lookup[entities[i]] = i;
        }
        components[index_to] = std::move(component);
        entities[index_to] = entity;
        lookup[entity] = index_to;
    }


    bool Has(Entity entity) const
    {
        return lookup.find(entity) != lookup.end();
    }

    std::shared_ptr<C> GetComponent(Entity entity) const
    {
        auto it = lookup.find(entity);
        if (it != lookup.end())
        {
            return components[it->second];
        }
        return nullptr;
    }

    template<typename L>
    std::shared_ptr<C> GetComponent(L &lambda)
    {
        auto it = std::find_if(components.begin(), components.end(), lambda);
        return (it != components.end()) ? (*it) : nullptr;
    }

    const std::shared_ptr<C> GetComponent(Entity entity)
    {
        auto it = lookup.find(entity);
        if (it != lookup.end())
        {
            return components[it->second];
        }
        return nullptr;
    }

    void Clear()
    {
        components.clear();
        entities.clear();
    }

    std::shared_ptr<C> operator[](size_t index) const
    {
        return components[index];
    }
    std::shared_ptr<C> at(size_t index) const
    { 
        return components[index]; 
    }
    size_t GetCount() const 
    { 
        return components.size();
    }
    Entity GetEntity(size_t index) const 
    { 
        return entities[index];
    }
};


#endif 