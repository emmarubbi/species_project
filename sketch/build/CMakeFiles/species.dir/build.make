# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/emmarubbi/species_project/sketch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/emmarubbi/species_project/sketch/build

# Include any dependencies generated for this target.
include CMakeFiles/species.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/species.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/species.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/species.dir/flags.make

CMakeFiles/species.dir/parameters.cpp.o: CMakeFiles/species.dir/flags.make
CMakeFiles/species.dir/parameters.cpp.o: /home/emmarubbi/species_project/sketch/parameters.cpp
CMakeFiles/species.dir/parameters.cpp.o: CMakeFiles/species.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/emmarubbi/species_project/sketch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/species.dir/parameters.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/species.dir/parameters.cpp.o -MF CMakeFiles/species.dir/parameters.cpp.o.d -o CMakeFiles/species.dir/parameters.cpp.o -c /home/emmarubbi/species_project/sketch/parameters.cpp

CMakeFiles/species.dir/parameters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/species.dir/parameters.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emmarubbi/species_project/sketch/parameters.cpp > CMakeFiles/species.dir/parameters.cpp.i

CMakeFiles/species.dir/parameters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/species.dir/parameters.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emmarubbi/species_project/sketch/parameters.cpp -o CMakeFiles/species.dir/parameters.cpp.s

CMakeFiles/species.dir/species.cpp.o: CMakeFiles/species.dir/flags.make
CMakeFiles/species.dir/species.cpp.o: /home/emmarubbi/species_project/sketch/species.cpp
CMakeFiles/species.dir/species.cpp.o: CMakeFiles/species.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/emmarubbi/species_project/sketch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/species.dir/species.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/species.dir/species.cpp.o -MF CMakeFiles/species.dir/species.cpp.o.d -o CMakeFiles/species.dir/species.cpp.o -c /home/emmarubbi/species_project/sketch/species.cpp

CMakeFiles/species.dir/species.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/species.dir/species.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emmarubbi/species_project/sketch/species.cpp > CMakeFiles/species.dir/species.cpp.i

CMakeFiles/species.dir/species.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/species.dir/species.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emmarubbi/species_project/sketch/species.cpp -o CMakeFiles/species.dir/species.cpp.s

CMakeFiles/species.dir/input_interface.cpp.o: CMakeFiles/species.dir/flags.make
CMakeFiles/species.dir/input_interface.cpp.o: /home/emmarubbi/species_project/sketch/input_interface.cpp
CMakeFiles/species.dir/input_interface.cpp.o: CMakeFiles/species.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/emmarubbi/species_project/sketch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/species.dir/input_interface.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/species.dir/input_interface.cpp.o -MF CMakeFiles/species.dir/input_interface.cpp.o.d -o CMakeFiles/species.dir/input_interface.cpp.o -c /home/emmarubbi/species_project/sketch/input_interface.cpp

CMakeFiles/species.dir/input_interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/species.dir/input_interface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emmarubbi/species_project/sketch/input_interface.cpp > CMakeFiles/species.dir/input_interface.cpp.i

CMakeFiles/species.dir/input_interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/species.dir/input_interface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emmarubbi/species_project/sketch/input_interface.cpp -o CMakeFiles/species.dir/input_interface.cpp.s

CMakeFiles/species.dir/graphics.cpp.o: CMakeFiles/species.dir/flags.make
CMakeFiles/species.dir/graphics.cpp.o: /home/emmarubbi/species_project/sketch/graphics.cpp
CMakeFiles/species.dir/graphics.cpp.o: CMakeFiles/species.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/emmarubbi/species_project/sketch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/species.dir/graphics.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/species.dir/graphics.cpp.o -MF CMakeFiles/species.dir/graphics.cpp.o.d -o CMakeFiles/species.dir/graphics.cpp.o -c /home/emmarubbi/species_project/sketch/graphics.cpp

CMakeFiles/species.dir/graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/species.dir/graphics.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emmarubbi/species_project/sketch/graphics.cpp > CMakeFiles/species.dir/graphics.cpp.i

CMakeFiles/species.dir/graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/species.dir/graphics.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emmarubbi/species_project/sketch/graphics.cpp -o CMakeFiles/species.dir/graphics.cpp.s

CMakeFiles/species.dir/graphic_main.cpp.o: CMakeFiles/species.dir/flags.make
CMakeFiles/species.dir/graphic_main.cpp.o: /home/emmarubbi/species_project/sketch/graphic_main.cpp
CMakeFiles/species.dir/graphic_main.cpp.o: CMakeFiles/species.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/emmarubbi/species_project/sketch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/species.dir/graphic_main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/species.dir/graphic_main.cpp.o -MF CMakeFiles/species.dir/graphic_main.cpp.o.d -o CMakeFiles/species.dir/graphic_main.cpp.o -c /home/emmarubbi/species_project/sketch/graphic_main.cpp

CMakeFiles/species.dir/graphic_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/species.dir/graphic_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emmarubbi/species_project/sketch/graphic_main.cpp > CMakeFiles/species.dir/graphic_main.cpp.i

CMakeFiles/species.dir/graphic_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/species.dir/graphic_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emmarubbi/species_project/sketch/graphic_main.cpp -o CMakeFiles/species.dir/graphic_main.cpp.s

# Object files for target species
species_OBJECTS = \
"CMakeFiles/species.dir/parameters.cpp.o" \
"CMakeFiles/species.dir/species.cpp.o" \
"CMakeFiles/species.dir/input_interface.cpp.o" \
"CMakeFiles/species.dir/graphics.cpp.o" \
"CMakeFiles/species.dir/graphic_main.cpp.o"

# External object files for target species
species_EXTERNAL_OBJECTS =

executables/species: CMakeFiles/species.dir/parameters.cpp.o
executables/species: CMakeFiles/species.dir/species.cpp.o
executables/species: CMakeFiles/species.dir/input_interface.cpp.o
executables/species: CMakeFiles/species.dir/graphics.cpp.o
executables/species: CMakeFiles/species.dir/graphic_main.cpp.o
executables/species: CMakeFiles/species.dir/build.make
executables/species: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.6.1
executables/species: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.6.1
executables/species: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.6.1
executables/species: CMakeFiles/species.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/emmarubbi/species_project/sketch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable executables/species"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/species.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/species.dir/build: executables/species
.PHONY : CMakeFiles/species.dir/build

CMakeFiles/species.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/species.dir/cmake_clean.cmake
.PHONY : CMakeFiles/species.dir/clean

CMakeFiles/species.dir/depend:
	cd /home/emmarubbi/species_project/sketch/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emmarubbi/species_project/sketch /home/emmarubbi/species_project/sketch /home/emmarubbi/species_project/sketch/build /home/emmarubbi/species_project/sketch/build /home/emmarubbi/species_project/sketch/build/CMakeFiles/species.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/species.dir/depend

