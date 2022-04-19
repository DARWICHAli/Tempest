cmake_minimum_required(VERSION 3.6)

add_subdirectory(SDL)

project(Tempest LANGUAGES CXX)

add_executable (${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PRIVATE src/main.cpp src/tempest.cpp src/Draw.cpp src/shapes.cpp src/weapon.cpp src/monsters.cpp )
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}})
target_link_libraries(${PROJECT_NAME}  PUBLIC SDL2 SDL2main SDL2_mixer SDL2_ttf)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
