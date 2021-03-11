#ifndef _ENTITY_ENTITYMANAGER_HPP_
#define _ENTITY_ENTITYMANAGER_HPP_

#include "Entity/Entity.hpp"
#include "Components/Component.hpp"
#include <vector>


class EntityManager : public std::enable_shared_from_this<EntityManager>
{
private:
    std::vector<std::shared_ptr<Entity>> entities;        

public:
    void ClearData();
    void Update(float deltaTime);
    void Render();
    bool HasNoEntities() const;

    void DeleteEntity(std::shared_ptr<Entity> entity) ;

    unsigned int GetEntityCount() const;
    void ListAllEntities() const;

    std::vector<std::shared_ptr<Entity>> GetEntities() const;
    std::vector<std::shared_ptr<Entity>> GetEntities(Layer layer) const;

    std::shared_ptr<Entity> AddEntity(const std::string& entityName);
    std::shared_ptr<Entity> AddEntity(const std::string& entityName, Layer layer);

};

#endif