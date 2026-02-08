cmake_minimum_required(VERSION 3.16)
project(DemonButton)

# You are building an ANDROID mod
set(GEODE_TARGET_PLATFORM "Android64")

# Tell CMake where your SDK folder is
set(GEODE_SDK_PATH "${CMAKE_SOURCE_DIR}/Geode-sdk-real")

# Add the SDK's cmake folder to the module path
list(APPEND CMAKE_MODULE_PATH "${GEODE_SDK_PATH}/cmake")

# Load the SDK CMake files (use module names, NOT paths)
include(Platform)
include(GeodeFile)

# Build your mod
add_geode_mod(DemonButton
    src/main.cpp
)
