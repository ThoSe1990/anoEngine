
#include <boost/python.hpp>
#include <boost/python/scope.hpp>

#include "ezEngine.hpp"


class dummyTransform{};
class dummyPosition{};
class dummyUserInput{};
class dummySprite{};
class dummyCollider{};
class dummyInputs{};



BOOST_PYTHON_MODULE(ezPyEngine)
{
    using namespace boost::python;

    class_<ezEngine::Vector2d>("Vector2d", init<>())
        .def(init<const int, const int>())
        .add_property("x", &ezEngine::Vector2d::x)
        .add_property("y", &ezEngine::Vector2d::y)
        ;
    class_<ezEngine::Rectangle>("Rectangle", init<>())
        .def(init<const int, const int, const int, const int>())
        .add_property("x", &ezEngine::Rectangle::x)
        .add_property("y", &ezEngine::Rectangle::y)
        .add_property("w", &ezEngine::Rectangle::w)
        .add_property("h", &ezEngine::Rectangle::h)
        ;
        
    enum_<ezEngine::SpriteComponent::Layer>("Layer")
        .value("layer_0", ezEngine::SpriteComponent::Layer::layer_0)
        .value("layer_1", ezEngine::SpriteComponent::Layer::layer_1)
        .value("layer_2", ezEngine::SpriteComponent::Layer::layer_2)
        .value("layer_3", ezEngine::SpriteComponent::Layer::layer_3)
        .value("layer_4", ezEngine::SpriteComponent::Layer::layer_4)
        .value("layer_count", ezEngine::SpriteComponent::Layer::layer_count)
        ;
    enum_<ezEngine::TransformComponent::ControlType>("ControlType")
        .value("position", ezEngine::TransformComponent::ControlType::Position)
        .value("velocity", ezEngine::TransformComponent::ControlType::Velocity)
        ;

    def("Initialize", ezEngine::Initialize);
    def("Initialize_sdl", ezEngine::Initialize_sdl);
    def("IsRunning", ezEngine::IsRunning);
    def("ProcessInput", ezEngine::ProcessInput);
    def("Update", ezEngine::Update);
    def("Render", ezEngine::Render);
    def("Destroy", ezEngine::Destroy);

    def("AddTexture", ezEngine::AddTexture);
    def("CreateEntity", ezEngine::CreateEntity);
    


    // scope ezPyEngine.TransformComponent
    {
        scope s = class_<dummyTransform>("TransformComponent");
        def("Create", ezEngine::TransformComponent::Create);
        def("SetPosition", ezEngine::TransformComponent::SetPosition);
        def("Remove", ezEngine::TransformComponent::Remove);
    }


    // scope ezPyEngine.PositionComponent
    {
        scope s = class_<dummyPosition>("PositionComponent");
        def("Create", ezEngine::PositionComponent::Create);
        def("SetPosition", ezEngine::PositionComponent::SetPosition);
        def("SetVelocity", ezEngine::PositionComponent::SetVelocity);
        def("Remove", ezEngine::PositionComponent::Remove);
    }


    // scope ezPyEngine.UserInputComponent
    {
        scope s = class_<dummyUserInput>("UserInputComponent");
        def("Create", ezEngine::UserInputComponent::Create);
        def("Remove", ezEngine::UserInputComponent::Remove);
    }


    // scope ezPyEngine.SpriteComponent
    {
        scope s = class_<dummySprite>("SpriteComponent");
        def("Create", ezEngine::SpriteComponent::Create);
        def("UpdateSourceRect", ezEngine::SpriteComponent::UpdateSourceRect);
        def("UpdateDestinationRect", ezEngine::SpriteComponent::UpdateDestinationRect);
        def("UpdateTexture", ezEngine::SpriteComponent::UpdateTexture);
        def("Remove", ezEngine::SpriteComponent::Remove);
    }

    // scope ezPyEngine.ColliderComponent
    {
        scope s = class_<dummyCollider>("ColliderComponent");
        def("Create", ezEngine::ColliderComponent::Create);
        def("Activate", ezEngine::ColliderComponent::Activate);
        def("Deactivate", ezEngine::ColliderComponent::Deactivate);
        def("Remove", ezEngine::ColliderComponent::Remove);
    }

    // scope ezPyEngine.Inputs
    {
        scope s = class_<dummyInputs>("Inputs");
        def("MouseButtonLeftClick", ezEngine::Inputs::MouseButtonLeftClick);
        def("MouseButtonLeftUp", ezEngine::Inputs::MouseButtonLeftUp);
        def("MouseButtonLeftDown", ezEngine::Inputs::MouseButtonLeftDown);
        def("MouseButtonRightClick", ezEngine::Inputs::MouseButtonRightClick);
        def("MouseButtonRightUp", ezEngine::Inputs::MouseButtonRightUp);
        def("MouseButtonRightDown", ezEngine::Inputs::MouseButtonRightDown);
    }

}


