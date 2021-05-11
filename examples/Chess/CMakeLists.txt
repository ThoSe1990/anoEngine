
set(target chess_example)

project(${target})

file(GLOB SRC
    "./src/*.cpp"
)

add_executable(${target}
    ${SRC}
)

target_include_directories(${target} PUBLIC
	${ezEngine_ROOT_DIR}
)


link_directories(${CMAKE_BINARY_DIR}/lib)
target_link_libraries(${target} PUBLIC
    ezEngine_api
    ezEngine_core
)

install(TARGETS ${target} DESTINATION ${ezEngine_ROOT_DIR})