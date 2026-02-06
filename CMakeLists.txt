cmake_minimum_required(VERSION 3.16)
project(DemonButton)

# tell Geode what platform this is
set(GEODE_TARGET_PLATFORM "Linux")

# tell CMake where your SDK folder is
set(GEODE_SDK_PATH "${CMAKE_SOURCE_DIR}/Geode-sdk-real")

# load the SDK CMake files
include("${GEODE_SDK_PATH}/cmake/Platform.cmake")
include("${GEODE_SDK_PATH}/cmake/GeodeFile.cmake")

# build your mod
add_geode_mod(DemonButton src/main.cpp)
