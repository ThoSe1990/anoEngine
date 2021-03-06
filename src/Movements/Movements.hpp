#ifndef _MOVEMENTS_MOVEMENT_HPP_
#define _MOVEMENTS_MOVEMENT_HPP_

#include "Entity/Entity.hpp"
#include "Components/ChesspieceComponent.hpp"

class Movement
{
protected: 
public:
    virtual ~Movement() {}
    virtual std::map<std::string, std::string> GetMovements(Entity* piece) { }
};


class Pawn : public Movement
{
public:
   
    std::map<std::string, std::string> GetMovements(Entity* piece) override 
    {
        std::map<std::string, std::string> result;
        result.emplace("H3", "validation_circle");
        result.emplace("H4", "validation_splash");
        return result;
    }
};


class MovementFactory
{
public:
    static std::unique_ptr<Movement> Create(Entity* entity)
    {
        Logger::Log(logging::trivial::debug, log_location, "creating movements for " , entity->name);

        ChesspieceComponent* cp = entity->GetComponent<ChesspieceComponent>();
        if (cp->type_.compare("pawn") == 0)
        {
            return std::make_unique<Pawn>();
        }
        else
        {
            Logger::Log(logging::trivial::debug, log_location, "no movements found for " , entity->name);
            return std::make_unique<Movement>();
        }
    }   
};

#endif