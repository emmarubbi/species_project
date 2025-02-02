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
    src/../species.cpp 
    src/../unit_test.cpp    
    )

# Set arriving directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/executables)

# Finding SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Executable creation
add_executable(tests ${SOURCES_TESTS})

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
