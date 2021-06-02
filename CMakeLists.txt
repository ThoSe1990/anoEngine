cmake_minimum_required(VERSION 3.16)

project(anoEngine)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(Boost COMPONENTS log log_setup system thread REQUIRED)

set(CMAKE_CXX_STANDARD 14)

set(anoEngine_ROOT_DIR ${PROJECT_SOURCE_DIR})

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/api)
add_subdirectory(${PROJECT_SOURCE_DIR}/api/python)
add_subdirectory(${PROJECT_SOURCE_DIR}/examples/Chess)