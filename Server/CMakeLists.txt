cmake_minimum_required(VERSION 3.17)

project(Server)
set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH ./../Executable)

set(SourceFiles main.cpp)
add_executable(Server ${SourceFiles})

find_package(SFML 2.5.1 REQUIRED COMPONENTS system window graphics audio network PATHS D:/C++/Library/packages/sfml)
target_link_libraries(Server sfml-system sfml-window sfml-graphics sfml-audio sfml-network)