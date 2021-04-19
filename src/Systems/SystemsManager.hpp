#ifndef _SYSTEMS_SYSTEMMANAGER_HPP_
#define _SYSTEMS_SYSTEMMANAGER_HPP_

#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <string>

#include "Systems/System.hpp"


class SystemManager
{
    std::vector<std::shared_ptr<System>> systems;
    std::map<const std::type_info*, std::shared_ptr<System>> systemTypes;

public: 
    void Update(float deltaTime)
    {
        for (auto& s: systems) 
            s->Update(deltaTime);
    }

    void Render()
    {
        for (auto& s: systems) 
            s->Render();
    }

    // TODO: return type void??? 
    template <typename T, typename... TArgs>
    std::shared_ptr<T> AddSystem(TArgs&&... args)
    {
        auto newSystem = std::make_shared<T>(std::forward<TArgs>(args)...);
        systems.emplace_back(newSystem);
        systemTypes[&typeid(newSystem)] = newSystem;
        newSystem->Initialize();
        return newSystem;
    }
    
    template <typename T>
    std::shared_ptr<T> GetSystem()
    {
        return std::static_pointer_cast<T>(systemTypes[&typeid(std::shared_ptr<T>)]);
    }

    template <typename T>
    bool HasSystem() const 
    {
        return systemTypes.count(&typeid(std::shared_ptr<T>));
    }

    void ListAllSystems() const 
    {
        unsigned int i = 0;
        for (auto& s: systemTypes) 
        {
            std::cout << "found system[" << i <<  "]: " << s.first->name() << std::endl;
            i++;
        }
    }


};


#endif