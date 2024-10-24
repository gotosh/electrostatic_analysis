cmake_minimum_required(VERSION 3.13)
project(electrostatic_analyze CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories((${CMAKE_SOURCE_DIR}/include))
set(SOURCES
    src/main.cpp
    src/solver_sor.cpp
    src/util.cpp
)
add_executable(electrostatic_analyze ${SOURCES})
target_link_libraries(electrostatic_analyze)
add_subdirectory(src)
