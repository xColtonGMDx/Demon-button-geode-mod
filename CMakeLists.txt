cmake_minimum_required(VERSION 3.16)
project(DemonButton)

set(CMAKE_CXX_STANDARD 20)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/../geode-sdk/sdk/include
)

add_library(DemonButton SHARED
    src/main.cpp
)

# Optional: link against GeodeLoader if needed
# target_link_libraries(DemonButton
#     ${CMAKE_SOURCE_DIR}/../geode-sdk/sdk/lib/libGeodeLoader.a
# )
