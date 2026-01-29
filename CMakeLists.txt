cmake_minimum_required(VERSION 3.16)
project(DemonButton)

set(CMAKE_CXX_STANDARD 20)

# Load Geode SDK
include(${CMAKE_SOURCE_DIR}/tools/geode-sdk/cmake/Geode.cmake)

# Create the mod
add_geode_mod(DemonButton
    SOURCES
        src/main.cpp
)
