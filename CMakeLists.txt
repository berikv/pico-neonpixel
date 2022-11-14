cmake_minimum_required(VERSION 3.12)

# include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
include(pico_sdk_import.cmake)

project(pico-neopixel-demo)

pico_sdk_init()

add_subdirectory(pico-neonpixel)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE demo/main.c)

target_link_libraries(${PROJECT_NAME} PRIVATE pico_stdlib PUBLIC pico-neonpixel)

pico_add_extra_outputs(${PROJECT_NAME})
