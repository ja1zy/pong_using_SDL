cmake_minimum_required(VERSION 3.25)
project(pong_tutorial)

set(CMAKE_CXX_STANDARD 17)

add_executable(pong_tutorial main.cpp Game.h Game.cpp Paddle.cpp Paddle.h Utils.h Ball.cpp Ball.h Score.cpp Score.h Menu.cpp Menu.h)


set(SDL2_LIB "/Library/Frameworks/SDL2.framework/SDL2")
set(SDL2_LIB2 "/Library/Frameworks/SDL2_image.framework/SDL2_image")
set(SDL2_LIB3 "/Library/Frameworks/SDL2_ttf.framework/SDL2_ttf")


target_include_directories(pong_tutorial PRIVATE "/Library/Frameworks/SDL2.framework/Headers")
target_include_directories( pong_tutorial PRIVATE "/Library/Frameworks/SDL2_image.framework/Headers")
target_include_directories( pong_tutorial PRIVATE "/Library/Frameworks/SDL2_ttf.framework/Headers")


target_link_libraries( pong_tutorial ${SDL2_LIB})
target_link_libraries( pong_tutorial ${SDL2_LIB2})
target_link_libraries( pong_tutorial ${SDL2_LIB3})


