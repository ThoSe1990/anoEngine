
#include <boost/python.hpp>
#include <boost/python/scope.hpp>

#include "ezEngine.hpp"


class dummyTransform{};
class dummyPosition{};
class dummyUserInput{};
class dummySprite{};
class dummyCollider{};
class dummyTextlabel{};
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
    class_<ezEngine::Color>("Color", init<>())
        .def(init<const unsigned char, const unsigned char, const unsigned char, const unsigned char>())
        .add_property("r", &ezEngine::Color::r)
        .add_property("g", &ezEngine::Color::g)
        .add_property("b", &ezEngine::Color::b)
        .add_property("a", &ezEngine::Color::a)
        ;



    class_<TransformComponent>("Transform", init<>())
        .add_property("entity", &TransformComponent::owner)
        .add_property("position", &TransformComponent::position)
        .add_property("velocity", &TransformComponent::velocity)
        .add_property("width", &TransformComponent::width)
        .add_property("height", &TransformComponent::height)
        .add_property("scale", &TransformComponent::scale)
        ;

    class_<PositionComponent>("Postion", init<>())
        .add_property("entity", &PositionComponent::owner)
        .add_property("setPosition", &PositionComponent::setPosition)
        .add_property("velocity", &PositionComponent::velocity)
        ;

    class_<UserInputComponent>("UserInput", init<>())
        .add_property("entity", &UserInputComponent::owner)
        .add_property("inputScript", &UserInputComponent::inputScript)
        ;

    class_<SpriteComponent>("Sprite", init<>())
        .add_property("entity", &SpriteComponent::owner)
        ;

    class_<ColliderComponent>("Collider", init<>())
        .add_property("entity", &ColliderComponent::owner)
        .add_property("type", &ColliderComponent::type)
        .add_property("active", &ColliderComponent::active)
        .add_property("collision", &ColliderComponent::collision)
        .add_property("collisionWithType", &ColliderComponent::collisionWithType)
        ;
    




    enum_<ezEngine::Sprite::Layer>("Layer")
        .value("layer_0", ezEngine::Sprite::Layer::layer_0)
        .value("layer_1", ezEngine::Sprite::Layer::layer_1)
        .value("layer_2", ezEngine::Sprite::Layer::layer_2)
        .value("layer_3", ezEngine::Sprite::Layer::layer_3)
        .value("layer_4", ezEngine::Sprite::Layer::layer_4)
        .value("layer_count", ezEngine::Sprite::Layer::layer_count)
        ;










    def("Initialize", ezEngine::Initialize);
    def("Initialize_sdl", ezEngine::Initialize_sdl);
    def("IsRunning", ezEngine::IsRunning);
    def("ProcessInput", ezEngine::ProcessInput);
    def("Update", ezEngine::Update);
    def("Render", ezEngine::Render);
    def("Destroy", ezEngine::Destroy);
    def("GetDeltaTime", ezEngine::GetDeltaTime);

    def("AddTexture", ezEngine::AddTexture);
    def("AddFont", ezEngine::AddFont);
    def("CreateEntity", ezEngine::CreateEntity);
    def("RemoveAllComponents", ezEngine::RemoveAllComponents);


    // scope ezPyEngine.Transform
    {
        void (*Create_1)(const Entity entity, const int x, const int y, const int width, const int height, const ezEngine::Vector2d& velocity, const int scale) = &ezEngine::Transform::Create;
        void (*Create_2)(const Entity entity, const ezEngine::Rectangle& size, const ezEngine::Vector2d& velocity, const int scale) = &ezEngine::Transform::Create;

        scope s = class_<dummyTransform>("Transform");
        def("Create", Create_1);
        def("Create", Create_2);
        def("GetComponent", ezEngine::Transform::GetComponent);
        def("SetPosition", ezEngine::Transform::SetPosition);
        def("Remove", ezEngine::Transform::Remove);
    }


    // scope ezPyEngine.Position
    {
        scope s = class_<dummyPosition>("Position");
        def("Create", ezEngine::Position::Create);
        def("SetPosition", ezEngine::Position::SetPosition);
        def("SetVelocity", ezEngine::Position::SetVelocity);
        def("Remove", ezEngine::Position::Remove);
    }


    // scope ezPyEngine.UserInput
    {
        scope s = class_<dummyUserInput>("UserInput");
        def("Create", ezEngine::UserInput::Create);
        def("Remove", ezEngine::UserInput::Remove);
    }


    // scope ezPyEngine.Sprite
    {
        scope s = class_<dummySprite>("Sprite");
        def("Create", ezEngine::Sprite::Create);
        def("UpdateSourceRect", ezEngine::Sprite::UpdateSourceRect);
        def("UpdateDestinationRect", ezEngine::Sprite::UpdateDestinationRect);
        def("UpdateTextureId", ezEngine::Sprite::UpdateTextureId);
        def("Remove", ezEngine::Sprite::Remove);
    }

    // scope ezPyEngine.Collider
    {
        scope s = class_<dummyCollider>("Collider");
        def("Create", ezEngine::Collider::Create);
        def("Activate", ezEngine::Collider::Activate);
        def("Deactivate", ezEngine::Collider::Deactivate);
        def("Remove", ezEngine::Collider::Remove);
        def("CollisionDetected", ezEngine::Collider::CollisionDetected);
        def("CollidesWithType", ezEngine::Collider::CollidesWithType);
    }

    // scope ezPyEngine.Textlabel
    {
        scope s = class_<dummyTextlabel>("Textlabel");
        def("Create", ezEngine::Textlabel::Create);
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


