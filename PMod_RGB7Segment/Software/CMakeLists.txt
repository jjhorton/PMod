cmake_minimum_required(VERSION 3.12)

# include(pico_sdk_import.cmake)
include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

# Change your executable name to something creative!
set(NAME pico-rgb) # <-- Name your project/executable here!

# Gooey boilerplate
project(${NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

# Add your source files
add_executable(${NAME}
    main.cpp # <-- Add source files here!
	rgb7seg.h 
	rgb7seg.cpp
)

# Don't forget to link the libraries you need!
target_link_libraries(${NAME}
	 pico_stdlib
	 hardware_i2c
)

# Serial through USB
pico_enable_stdio_uart(${NAME} 0)
pico_enable_stdio_usb(${NAME} 1)

# Serial through pin outs
#pico_enable_stdio_uart(${project_name} 1)
#pico_enable_stdio_usb(${project_name} 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})
