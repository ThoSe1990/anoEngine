

#define BOOST_PYTHON_STATIC_LIB

#include <boost/python.hpp>
#include <boost/python/scope.hpp>

#include "anoEngine.hpp"


class dummyTransform{};
class dummyPosition{};
class dummyUserInput{};
class dummySprite{};
class dummyCollider{};
class dummyTextlabel{};
class dummyTilemap{};
class dummyInputs{};



BOOST_PYTHON_MODULE(anoPyEngine)
{
    using namespace boost::python;

    Py_Initialize();

    class_<anoEngine::Vector2d>("Vector2d", init<>())
        .def(init<const int, const int>())
        .add_property("x", &anoEngine::Vector2d::x)
        .add_property("y", &anoEngine::Vector2d::y)
        ;
    class_<anoEngine::Rectangle>("Rectangle", init<>())
        .def(init<const int, const int, const int, const int>())
        .def(self / float())
        .def(self * float())
        .def(self + float())
        .def(self - float())
        .def("GetCenter", &anoEngine::Rectangle::GetCenter)
        .add_property("x", &anoEngine::Rectangle::x)
        .add_property("y", &anoEngine::Rectangle::y)
        .add_property("w", &anoEngine::Rectangle::w)
        .add_property("h", &anoEngine::Rectangle::h)
        ;
    class_<anoEngine::Color>("Color", init<>())
        .def(init<const unsigned char, const unsigned char, const unsigned char, const unsigned char>())
        .add_property("r", &anoEngine::Color::r)
        .add_property("g", &anoEngine::Color::g)
        .add_property("b", &anoEngine::Color::b)
        .add_property("a", &anoEngine::Color::a)
        ;



    class_<TransformComponent>("Transform", init<>())
        .add_property("entity", &TransformComponent::owner)
        .add_property("rectangle", &TransformComponent::rectangle)
        .add_property("velocity", &TransformComponent::velocity)
        .add_property("scale", &TransformComponent::scale)
        ;

    class_<PositionComponent>("Postion", init<>())
        .add_property("entity", &PositionComponent::owner)
        .add_property("setPosition", &PositionComponent::setPosition)
        .add_property("maxVelocity", &PositionComponent::maxVelocity)
        .add_property("kp", &PositionComponent::kp)
        .add_property("ki", &PositionComponent::ki)
        .add_property("kd", &PositionComponent::kd)
        .add_property("inPosition", &PositionComponent::inPosition)
        ;

    class_<UserInputComponent>("UserInput", init<>())
        .add_property("entity", &UserInputComponent::owner)
        .add_property("inputScript", &UserInputComponent::inputScript)
        ;

    class_<SpriteComponent>("Sprite", init<>())
        .add_property("entity", &SpriteComponent::owner)
        .add_property("textureId", &SpriteComponent::textureId)
        .add_property("source", &SpriteComponent::source)
        .add_property("destination", &SpriteComponent::destination)
        .add_property("flip", &SpriteComponent::flip)        
        .add_property("layer", &SpriteComponent::layer)        
        ;

    class_<ColliderComponent>("Collider", init<>())
        .add_property("entity", &ColliderComponent::owner)
        .add_property("offset", &ColliderComponent::offset)
        .add_property("type", &ColliderComponent::type)
        .add_property("active", &ColliderComponent::active)
        .add_property("collision", &ColliderComponent::collision)
        .add_property("collisionWithType", &ColliderComponent::collisionWithType)
        .add_property("collisionWithEntity", &ColliderComponent::collisionWithEntity)
        ;
    




    def("Initialize", anoEngine::Initialize);
    def("IsRunning", anoEngine::IsRunning);
    def("ProcessInput", anoEngine::ProcessInput);
    def("Update", anoEngine::Update);
    def("Render", anoEngine::Render);
    def("Destroy", anoEngine::Destroy);
    def("GetDeltaTime", anoEngine::GetDeltaTime);
    def("GetWindowSize", anoEngine::GetWindowSize);

    def("AddTexture", anoEngine::AddTexture);
    def("AddFont", anoEngine::AddFont);
    def("CreateEntity", anoEngine::CreateEntity);
    def("RemoveAllComponents", anoEngine::RemoveAllComponents);


    // scope anoPyEngine.Transform
    {
        void (*Create_1)(const Entity entity, const int x, const int y, const int width, const int height, const anoEngine::Vector2d& velocity, const int scale) = &anoEngine::Transform::Create;
        void (*Create_2)(const Entity entity, const anoEngine::Rectangle& size, const anoEngine::Vector2d& velocity, const int scale) = &anoEngine::Transform::Create;

        void (*SetVelocity_1)(const Entity entity, const int x, const int y) = &anoEngine::Transform::SetVelocity;
        void (*SetVelocity_2)(const Entity entity, const anoEngine::Vector2d& position) = &anoEngine::Transform::SetVelocity;

        scope s = class_<dummyTransform>("Transform");
        def("Create", Create_1);
        def("Create", Create_2);
        def("GetComponent", anoEngine::Transform::GetComponent);
        def("SetRectangle", anoEngine::Transform::SetRectangle);
        def("SetVelocity", SetVelocity_1);
        def("SetVelocity", SetVelocity_2);
        def("Remove", anoEngine::Transform::Remove);
    }

    // scope anoPyEngine.Position
    {
        scope s = class_<dummyPosition>("Position");
        def("Create", anoEngine::Position::Create);
        def("SetPosition", anoEngine::Position::SetPosition);
        def("SetMaxVelocity", anoEngine::Position::SetMaxVelocity);
        def("Remove", anoEngine::Position::Remove);
    }


    // scope anoPyEngine.UserInput
    {
        scope s = class_<dummyUserInput>("UserInput");
        def("Create", anoEngine::UserInput::Create);
        def("Remove", anoEngine::UserInput::Remove);
    }


    // scope anoPyEngine.Sprite
    {
        scope s = class_<dummySprite>("Sprite");

        enum_<anoEngine::Sprite::Layer>("Layer")
            .value("layer_0", anoEngine::Sprite::Layer::layer_0)
            .value("layer_1", anoEngine::Sprite::Layer::layer_1)
            .value("layer_2", anoEngine::Sprite::Layer::layer_2)
            .value("layer_3", anoEngine::Sprite::Layer::layer_3)
            .value("layer_4", anoEngine::Sprite::Layer::layer_4)
            .value("layer_count", anoEngine::Sprite::Layer::layer_count)
            ;

        enum_<anoEngine::Sprite::Flip>("Flip")
            .value("none", anoEngine::Sprite::Flip::none)
            .value("horizontal", anoEngine::Sprite::Flip::horizontal)
            .value("vertical", anoEngine::Sprite::Flip::vertical)
            ;

        def("Create", anoEngine::Sprite::Create);
        def("GetComponent", anoEngine::Sprite::GetComponent);
        def("UpdateSourceRect", anoEngine::Sprite::UpdateSourceRect);
        def("UpdateDestinationRect", anoEngine::Sprite::UpdateDestinationRect);
        def("UpdateTextureId", anoEngine::Sprite::UpdateTextureId);
        def("FlipSprite", anoEngine::Sprite::FlipSprite);
        def("Remove", anoEngine::Sprite::Remove);
    }

    // scope anoPyEngine.Collider
    {
        scope s = class_<dummyCollider>("Collider");
        def("Create", anoEngine::Collider::Create);
        def("GetComponent", anoEngine::Collider::GetComponent);
        def("Activate", anoEngine::Collider::Activate);
        def("Deactivate", anoEngine::Collider::Deactivate);
        def("Remove", anoEngine::Collider::Remove);
        def("CollisionDetected", anoEngine::Collider::CollisionDetected);
        def("CollidesWithType", anoEngine::Collider::CollidesWithType);
    }

    // scope anoPyEngine.Textlabel
    {
        scope s = class_<dummyTextlabel>("Textlabel");
        def("Create", anoEngine::Textlabel::Create);
    }

    // scope anoPyEngine.Tilemap
    {
        scope s = class_<dummyTilemap>("Tilemap");
        def("Create", anoEngine::TileMap::Create);
        def("LoadMap", anoEngine::TileMap::LoadMap);
    }

    // scope anoPyEngine.Inputs
    {
        scope s = class_<dummyInputs>("Inputs");
        def("MouseButtonLeftClick", anoEngine::Inputs::MouseButtonLeftClick);
        def("MouseButtonLeftUp", anoEngine::Inputs::MouseButtonLeftUp);
        def("MouseButtonLeftDown", anoEngine::Inputs::MouseButtonLeftDown);
        def("MouseButtonRightClick", anoEngine::Inputs::MouseButtonRightClick);
        def("MouseButtonRightUp", anoEngine::Inputs::MouseButtonRightUp);
        def("MouseButtonRightDown", anoEngine::Inputs::MouseButtonRightDown);
    }

}


