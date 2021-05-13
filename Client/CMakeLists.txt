cmake_minimum_required(VERSION 3.17)

project(Client)
set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH ./../Executable)

set(SourceFiles main.cpp)
add_executable(Client ${SourceFiles})

find_package(SFML 2.5.1 REQUIRED COMPONENTS system window graphics audio network PATHS D:/C++/Library/packages/sfml)
target_link_libraries(Client sfml-system sfml-window sfml-graphics sfml-audio sfml-network)