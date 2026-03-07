set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/arduino-avr-toolchain.cmake)
# I target a recent cmake, it shouldn't be a problem on a dev machine
cmake_minimum_required( VERSION 3.10 )
# Largely inspired from https://www.kuon.ch/post/2018-07-11-avr-cmake/
# Project name
project("Atmega328p serial debugging")

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

## AVR Chip Configuration
set(F_CPU 16000000UL)
set(PROC_ID __AVR_ATmega328P__ CACHE STRING "MCU include guard")
set(MCU atmega328p CACHE STRING "Processor")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Pass defines to compiler
add_definitions(
  -DF_CPU=${F_CPU}
  -D${PROC_ID}
)

# mmcu MUST be passed to both the compiler and linker, this handle the
# linker
set(CMAKE_EXE_LINKER_FLAGS -mmcu=${MCU})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_compile_options(
  -mmcu=${MCU} # MCU
  -Os # optimize
  -Wall # enable warnings
  -Wno-main
  -Wundef
  -pedantic
  -Wstrict-prototypes
  -Werror
  -Wfatal-errors
  -Wl,--relax,--gc-sections
  -g
  -gdwarf-2
  -funsigned-char
  -Wconversion
  # a few
  # optimizations
  -funsigned-bitfields
  -fpack-struct
  -fshort-enums
  -ffunction-sections
  -fdata-sections
  -fno-split-wide-types
  -fno-tree-scev-cprop
)

enable_testing()

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/tests)
