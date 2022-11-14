cmake_minimum_required(VERSION 3.12)

include(../pico_sdk_import.cmake)

project(pico-neonpixel)

pico_sdk_init()

add_library(${PROJECT_NAME} INTERFACE)

pico_generate_pio_header(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio)

target_include_directories(${PROJECT_NAME} INTERFACE .)

target_link_libraries(${PROJECT_NAME} INTERFACE pico_stdlib hardware_pio)
