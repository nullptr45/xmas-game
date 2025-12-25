cmake_minimum_required(VERSION 3.16)
project(game)

file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS src/*.c)
add_executable(game ${SRCS})
