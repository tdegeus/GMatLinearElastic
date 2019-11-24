
cmake_minimum_required(VERSION 3.0)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    project(GMatElastic-test)
    find_package(GMatElastic REQUIRED CONFIG)
    set(GMATELASTIC_INCLUDE_DIR ${GMatElastic_INCLUDE_DIRS})
endif()

option(WARNINGS "Show build warnings" ON)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DXTENSOR_USE_XSIMD=ON")

if(NOT MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
endif()

find_package(Catch2 REQUIRED)
find_package(xtensor REQUIRED)
find_package(xtl REQUIRED)
find_package(xsimd REQUIRED)

add_executable(main main.cpp Cartesian3d.cpp)
target_link_libraries(main PUBLIC Catch2::Catch2 xtensor xtl xsimd)
target_include_directories(main PRIVATE "${GMATELASTIC_INCLUDE_DIR}")
if(WARNINGS)
    if(MSVC)
        target_compile_options(main PRIVATE /W4)
    else()
        target_compile_options(main PRIVATE -Wall -Wextra -pedantic -Wno-unknown-pragmas)
    endif()
endif()