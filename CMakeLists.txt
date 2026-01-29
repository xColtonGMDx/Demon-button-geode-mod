cmake_minimum_required(VERSION 3.16)
project(DemonButton)

set(CMAKE_CXX_STANDARD 20)

# Use the SDK installed by the Geode CLI
include($ENV{HOME}/.local/share/Geode/sdk/cmake/Geode.cmake)

add_geode_mod(DemonButton
    SOURCES
        src/main.cpp
)
