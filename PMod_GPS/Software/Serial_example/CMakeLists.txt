cmake_minimum_required(VERSION 3.12)

# include(pico_sdk_import.cmake)
include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

# Change your executable name to something creative!
set(NAME pSerial-GPS) # <-- Name your project/executable here!

# Gooey boilerplate
project(${NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

# Add your source files
add_executable(${NAME}
    serial_gps.c # <-- Add source files here!
)

# Don't forget to link the libraries you need!
target_link_libraries(${NAME}
	 pico_stdlib
)

# enables usb serial
pico_enable_stdio_usb(${NAME} 1)
pico_enable_stdio_uart(${NAME} 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})
