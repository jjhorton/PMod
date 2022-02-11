cmake_minimum_required(VERSION 3.12)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

# Change your executable name to something creative!
set(NAME thermalhub75) # <-- Name your project/executable here!

# Gooey boilerplate
project(${NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_executable(${NAME} thermal_hub75.c)

pico_generate_pio_header(${NAME} ${CMAKE_CURRENT_LIST_DIR}/hub75.pio)

target_sources(${NAME} PRIVATE thermal_hub75.c)

target_compile_definitions(${NAME} PRIVATE
 	PICO_DEFAULT_UART_TX_PIN=28
 	PICO_DEFAULT_UART_RX_PIN=29
)

target_link_libraries(${NAME} PRIVATE pico_stdlib hardware_pio hardware_i2c)
pico_add_extra_outputs(${NAME})
