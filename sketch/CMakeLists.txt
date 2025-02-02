cmake_minimum_required(VERSION 3.10) # Versione minima di CMake
project(SpeciesSimulation) # Nome del progetto


#specifica che l'eseguibile binario va nella cartella executables 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/executables)



# Attiva debug e AddressSanitizer
set(SANITIZE_FLAGS "-fsanitize=address,undefined -g -D_GLIBCXX_ASSERTIONS")

# Aggiungi i flag globali
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SANITIZE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SANITIZE_FLAGS}")


# Aggiungi i file sorgenti (test)
set(SOURCES_TESTS
    src/../parameters.cpp
    src/../species.cpp 
    src/../unit_test.cpp    
    )

# Aggiungi i file sorgenti (species)
set(SOURCES_SPECIES
    src/../parameters.cpp
    src/../species.cpp 
    src/../input_interface.cpp
    src/../graphics.cpp
    src/../graphic_main.cpp   
    )

# Aggiungi i file sorgenti (data_analysis)
set(SOURCES_DATA_ANALYSIS
    src/../parameters.cpp
    src/../species.cpp 
    src/../input_interface.cpp
    src/../data_main.cpp
    )

#specifica che l'eseguibile binario va nella cartella executables 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/executables)

# Trova la libreria SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Crea l'eseguibile
add_executable(tests ${SOURCES_TESTS})
add_executable(species ${SOURCES_SPECIES})
add_executable(data_analysis ${SOURCES_DATA_ANALYSIS})

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

target_compile_options(species PRIVATE
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

target_compile_options(data_analysis PRIVATE
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

# Linka SFML
target_link_libraries(species sfml-graphics sfml-window sfml-system)
target_link_libraries(data_analysis sfml-system)

# Aggiunge un target personalizzato per eseguire il programma e generare il grafico
add_custom_target (graph
    COMMAND data_analysis                         # Esegue il programma per generare dati.txt
    COMMAND gnuplot ${CMAKE_SOURCE_DIR}/testplot.gp    # Esegue Gnuplot per creare il grafico
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR} )