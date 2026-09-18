cmake_minimum_required(VERSION 3.14)
project(conways_game_of_life)

set(CMAKE_CXX_STANDARD 17)

add_executable(game src/main.cpp src/grid.cpp src/update_system.cpp)

target_include_directories(game PRIVATE /opt/homebrew/include)
target_link_directories(game PRIVATE /opt/homebrew/lib)
target_link_libraries(game sfml-graphics sfml-window sfml-system)
