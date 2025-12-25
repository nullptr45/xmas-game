cmake_minimum_required(VERSION 3.16)
project(game)

find_package(raylib REQUIRED)

file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS src/*.c)
add_executable(game ${SRCS})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")
