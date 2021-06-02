
set(target anoEngine_core)

project(${target})

file(GLOB SRC
    "*.cpp"
)

add_library(${target} SHARED
    ${SRC}
)
set_property(TARGET ${target} PROPERTY POSITION_INDEPENDENT_CODE ON)
set_property(TARGET ${target} PROPERTY C_VISIBILITY_PRESET hidden)
set_property(TARGET ${target} PROPERTY VISIBILITY_INLINES_HIDDEN ON)

target_include_directories(${target} PUBLIC
	${anoEngine_ROOT_DIR}/examples/Chess/src
	${anoEngine_ROOT_DIR}/api
	${anoEngine_ROOT_DIR}/src
	${anoEngine_ROOT_DIR}/lib
	${anoEngine_ROOT_DIR}/src/lua
)

target_link_libraries(${target} PUBLIC
    ${SDL2_LIBRARIES} 
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    Boost::log_setup 
    Boost::log
    Boost::system
    Boost::thread
    lua5.3
    pthread
)

SET(Boost_USE_STATIC_LIBS ON)

install(TARGETS ${target} DESTINATION /usr/lib)