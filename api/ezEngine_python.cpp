



#include <boost/python.hpp>
#include "ezEngine.hpp"


BOOST_PYTHON_MODULE(ezEngine_python)
{
    boost::python::def("Initialize", ezEngine::Initialize);
    boost::python::def("Initialize_sdl", ezEngine::Initialize_sdl);
    boost::python::def("IsRunning", ezEngine::IsRunning);
    boost::python::def("ProcessInput", ezEngine::ProcessInput);
    boost::python::def("Update", ezEngine::Update);
    boost::python::def("Render", ezEngine::Render);
    boost::python::def("Destroy", ezEngine::Destroy);
}
