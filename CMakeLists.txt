cmake_minimum_required(VERSION 3.15)

project(Pacman)

set(CMAKE_CXX_STANDARD 20)

# Finde the SFML Library
find_package(SFML REQUIRED COMPONENTS graphics window system)


add_executable(TestEnv testEnv.cpp)

target_link_libraries(TestEnv 
            sfml-graphics
            sfml-window
            sfml-system)

# add_executable(TestMap testMap.cpp)

# target_link_libraries(TestMap 
#             sfml-graphics
#             sfml-window
#             sfml-system)

