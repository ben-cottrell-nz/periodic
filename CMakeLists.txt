cmake_minimum_required(VERSION 3.20)
project(periodic)

set(CINDER_PATH /home/ben/Documents/repositories/Cinder)
include(${CINDER_PATH}/build/lib/linux/x86_64/ogl/Debug/cinderTargets.cmake)
include_directories(
        ${CINDER_PATH}/blocks/Cairo/include
        ${CINDER_PATH}/blocks/Cairo/include/cinder/cairo
        /usr/include/cairo
        /usr/include/freetype2
)
set(CMAKE_CXX_STANDARD 17)
add_executable(periodic main.cpp shader_data.h ${CINDER_PATH}/blocks/Cairo/src/Cairo.cpp)
target_link_libraries(periodic cinder cairo)
