cmake_minimum_required(VERSION 3.0)
project(multigen)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(lib)

include(FetchContent)

FetchContent_Declare(imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG        v1.90)
FetchContent_MakeAvailable(imgui)

add_library(libimgui STATIC
        ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/imgui_tables.cpp
        ${imgui_SOURCE_DIR}/imgui_widgets.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_win32.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_dx11.cpp)

target_include_directories(libimgui PUBLIC ${imgui_SOURCE_DIR})

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/multigen.cpp)

target_compile_definitions(${PROJECT_NAME} PRIVATE WIN32_LEAN_AND_MEAN NOMINMAX)
target_include_directories(${PROJECT_NAME} PRIVATE include libimgui)
target_link_libraries(${PROJECT_NAME} PRIVATE raw_pdb libimgui d3d11)