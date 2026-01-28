cmake_minimum_required(VERSION 3.16)
project(DemonButton)

set(CMAKE_CXX_STANDARD 20)

include_directories(
    ${CMAKE_SOURCE_DIR}
    /root/geode-sdk/sdk/loader/include
)

add_library(DemonButton SHARED
    src/main.cpp
)
