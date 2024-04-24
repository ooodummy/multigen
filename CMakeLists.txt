cmake_minimum_required(VERSION 3.0)
project(multigen)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(lib)

add_executable(${PROJECT_NAME} src/multigen.cpp)

target_compile_definitions(${PROJECT_NAME} PRIVATE WIN32_LEAN_AND_MEAN NOMINMAX)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE raw_pdb)