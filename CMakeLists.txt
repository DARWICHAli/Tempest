cmake_minimum_required(VERSION 3.7)
include( CMakeParseArguments )

project(Tetris LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

find_package(SDL2 REQUIRED)

function(ADD_PRG)
    set(options OPTIONAL)
    set(oneValueArgs TARGET )
    set(multiValueArgs SOURCES)
    cmake_parse_arguments(ADD_PRG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

    add_executable(${ADD_PRG_TARGET} "")
    target_sources(${ADD_PRG_TARGET} PUBLIC ${ADD_PRG_SOURCES})

    target_include_directories(${ADD_PRG_TARGET} PUBLIC /usr/include/SDL2)
    target_link_libraries(${ADD_PRG_TARGET} PUBLIC SDL2 SDL2main SDL2_mixer SDL2_ttf)

    target_compile_definitions(${ADD_PRG_TARGET} PUBLIC _USE_MATH_DEFINES)
endfunction()

ADD_PRG(TARGET Tempest SOURCES src/main.cpp src/tempest.cpp src/Draw.cpp src/shapes.cpp src/weapon.cpp src/monsters.cpp headers/tempest.hpp headers/Defs.hpp headers/Draw.hpp headers/shapes.hpp headers/weapon.hpp headers/monsters.hpp headers/sdlwrap.hpp)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/ressources
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
