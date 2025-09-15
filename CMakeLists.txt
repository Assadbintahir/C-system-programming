cmake_minimum_required(VERSION 3.16)

project(C-system-programming C)

# Use modern C standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Generate compile_commands.json (useful for tooling)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define the executable entry point
add_executable(scratchpad scratchpad.c)

# Enable useful warnings
if(MSVC)
  target_compile_options(scratchpad PRIVATE /W4 /permissive-)
else()
  target_compile_options(scratchpad PRIVATE -Wall -Wextra -Wpedantic)
endif()