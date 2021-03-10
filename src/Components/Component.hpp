#ifndef _COMPONENTS_COMPONENT_HPP_
#define _COMPONENTS_COMPONENT_HPP_

class Entity;

class Component
{
public:
    virtual ~Component() {}
    std::shared_ptr<Entity> Owner;
    virtual void Initialize() {}
    virtual void Update(float deltaTime) {}
    virtual void Render() {}
};

#endif