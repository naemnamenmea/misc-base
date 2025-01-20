cmake_minimum_required(VERSION 3.27)

if (MSVC)
    # warning level 4
    add_compile_options(/W4 /WX)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_SUPPRESS_REGENERATION OFF)

file(GLOB SOURCE_FILES
    *.cpp
    *.h
    *.hpp
    public/*.hpp
    public/*.h
    src/*.cpp
)

add_library(misc-base STATIC ${SOURCE_FILES})

target_include_directories(misc-base PUBLIC public)