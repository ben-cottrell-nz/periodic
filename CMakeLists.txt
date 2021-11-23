cmake_minimum_required(VERSION 3.20)
project(periodic)

set(CMAKE_CXX_STANDARD 17)
set(CINDER_PATH /home/ben/Documents/repositories/Cinder)
set(JSONCPP_PATH /home/ben/Documents/repositories/jsoncpp)

if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
include(${CINDER_PATH}/build/lib/linux/x86_64/ogl/Debug/cinderTargets.cmake)
include_directories(
        ${JSONCPP_PATH}/include/
)
elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
set(CINDER_PATH C:/Users/ben/Documents/repositories/Cinder)
set(JSONCPP_PATH C:/Users/ben/Documents/repositories/jsoncpp)
include(${CINDER_PATH}/build-windows/lib/msw/x86/Debug/cinderTargets.cmake)
include_directories(
		${CINDER_PATH}/include
        ${JSONCPP_PATH}/include
)
endif()

if (MSVC)
link_directories(BEFORE ${CINDER_PATH}/lib/msw/x64/Debug/v142)
endif()
add_executable(periodic
        main.cpp
        shader_data.h
        ${JSONCPP_PATH}/src/lib_json/json_reader.cpp
        ${JSONCPP_PATH}/src/lib_json/json_tool.h
        ${JSONCPP_PATH}/src/lib_json/json_value.cpp
        ${JSONCPP_PATH}/src/lib_json/json_writer.cpp table.cpp eleminfodlg.cpp appdatamanager.cpp)
target_link_libraries(periodic cinder)
