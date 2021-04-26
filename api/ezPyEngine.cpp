



#include <boost/python.hpp>
#include "ezEngine.hpp"

using namespace boost::python;

BOOST_PYTHON_MODULE(ezPyEngine)
{

    class_<ezEngine::Vector2d>("Vector2d")
        .add_property("x", &ezEngine::Vector2d::x)
        .add_property("y", &ezEngine::Vector2d::y)
        ;
    class_<ezEngine::Rectangle>("Rectangle")
        .add_property("x", &ezEngine::Rectangle::x)
        .add_property("y", &ezEngine::Rectangle::y)
        .add_property("w", &ezEngine::Rectangle::w)
        .add_property("h", &ezEngine::Rectangle::h)
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

    def("TransformComponent_Create", ezEngine::TransformComponent::Create);
    def("TransformComponent_Update", ezEngine::TransformComponent::Update);
    def("TransformComponent_SetPosition", ezEngine::TransformComponent::SetPosition);
    def("TransformComponent_Remove", ezEngine::TransformComponent::Remove);

    def("SpriteComponent_Create", ezEngine::SpriteComponent::Create);
    def("SpriteComponent_Update", ezEngine::SpriteComponent::Update);
    def("SpriteComponent_Remove", ezEngine::SpriteComponent::Remove);

    def("ColliderComponent_Create", ezEngine::ColliderComponent::Create);
    def("ColliderComponent_Update", ezEngine::ColliderComponent::Update);
    def("ColliderComponent_Activate", ezEngine::ColliderComponent::Activate);
    def("ColliderComponent_Deactivate", ezEngine::ColliderComponent::Deactivate);
    def("ColliderComponent_Remove", ezEngine::ColliderComponent::Remove);

    def("UserInputs_MouseClicked", ezEngine::UserInputs::MouseClicked);
    def("UserInputs_GetMouseCoordinates", ezEngine::UserInputs::GetMouseCoordinates);

}
