
set(target ezPyEngine)

project(${target})

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
find_package(Boost COMPONENTS python38 REQUIRED)
set(CMAKE_SHARED_MODULE_PREFIX "")

file(GLOB SRC
    "*.cpp"
)

add_library(${target} MODULE
    ${SRC}
)
set_property(TARGET ${target} PROPERTY POSITION_INDEPENDENT_CODE ON)
set_property(TARGET ${target} PROPERTY C_VISIBILITY_PRESET hidden)
set_property(TARGET ${target} PROPERTY VISIBILITY_INLINES_HIDDEN ON)


target_include_directories(${target} PUBLIC
    ${ezEngine_ROOT_DIR}/api
    ${ezEngine_ROOT_DIR}/lib
    ${Python3_INCLUDE_DIRS}
)


link_directories(${CMAKE_BINARY_DIR}/lib)
target_link_libraries(${target} PUBLIC
    ezEngine_api
    ezEngine_core
    Boost::python38
    ${Python3_LIBRARY}
)



install(TARGETS ${target} DESTINATION /usr/lib/python3.8)