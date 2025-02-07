cmake_minimum_required(VERSION 3.10) 
project(SpeciesSimulation) 


# Executables are in the "executables" directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/executables)


# Debug and address sanitizer
set(SANITIZE_FLAGS "-fsanitize=address,undefined -g -D_GLIBCXX_ASSERTIONS")

# Global flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SANITIZE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SANITIZE_FLAGS}")

# Test executable sources
set(SOURCES_TESTS
    src/../parameters.cpp
    src/../simulation.cpp
    src/../unit_test.cpp
    src/../input_output.cpp    
    )

# Main executable sources
set(SOURCES_SIMULATION
    src/../parameters.cpp
    src/../simulation.cpp
    src/../input_output.cpp
    src/../data_main_definitive.cpp)

# Set arriving directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/executables)

# Finding SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Executable creation
add_executable(tests ${SOURCES_TESTS})
add_executable(simulation ${SOURCES_SIMULATION})

target_compile_options(tests PRIVATE
    -Wall
    -Wextra
    -Wpedantic 
    -Wconversion 
    -Wsign-conversion 
    -Wshadow 
    -Wimplicit-fallthrough 
    -Wextra-semi 
    -Wold-style-cast 
    -D_GLIBCXX_ASSERTIONS 
    -fsanitize=address,undefined
)

target_compile_options(simulation PRIVATE
    -Wall
    -Wextra
    -Wpedantic 
    -Wconversion 
    -Wsign-conversion 
    -Wshadow 
    -Wimplicit-fallthrough 
    -Wextra-semi 
    -Wold-style-cast 
    -D_GLIBCXX_ASSERTIONS 
    -fsanitize=address,undefined
)

# SFML linking

target_link_libraries(simulation sfml-system)