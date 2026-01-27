cmake_minimum_required(VERSION 3.16)
set(CMAKE_TOOLCHAIN_FILE "$ENV{HOME}/.local/share/Geode/cross-tools/native.cmake")
project(DemonButton)

geode_mod("DemonButton" "main.cpp")
