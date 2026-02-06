cmake_minimum_required(VERSION 3.21)
project(DemonButton)

set(GEODE_SDK_PATH "/termux/Geode-sdk-real")

include(${GEODE_SDK_PATH}/cmake/Platform.cmake)
include(${GEODE_SDK_PATH}/cmake/GeodeFile.cmake)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)

geode_add_mod(${PROJECT_NAME})