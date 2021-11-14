cmake_minimum_required(VERSION 3.20)
project(periodic)

set(CINDER_PATH /home/ben/Documents/repositories/Cinder)
set(JSONCPP_PATH /home/ben/Documents/repositories/jsoncpp)
include(${CINDER_PATH}/build/lib/linux/x86_64/ogl/Debug/cinderTargets.cmake)
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
include_directories(
        ${CINDER_PATH}/blocks/Cairo/include
        ${CINDER_PATH}/blocks/Cairo/include/cinder/cairo
        /usr/include/cairo
        /usr/include/freetype2
        ${JSONCPP_PATH}/include/
)
endif()
set(CMAKE_CXX_STANDARD 17)
add_executable(periodic
        main.cpp
        shader_data.h
        ${CINDER_PATH}/blocks/Cairo/src/Cairo.cpp
        ${JSONCPP_PATH}/src/lib_json/json_reader.cpp
        ${JSONCPP_PATH}/src/lib_json/json_tool.h
        ${JSONCPP_PATH}/src/lib_json/json_value.cpp
        ${JSONCPP_PATH}/src/lib_json/json_writer.cpp table.cpp eleminfodlg.cpp appdatamanager.cpp)
target_link_libraries(periodic cinder cairo)
