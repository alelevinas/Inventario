# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nicomoccagatta/git/Inventario

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nicomoccagatta/git/Inventario/build

# Include any dependencies generated for this target.
include CMakeFiles/Admin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Admin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Admin.dir/flags.make

CMakeFiles/Admin.dir/Administrador/Administrador.cpp.o: CMakeFiles/Admin.dir/flags.make
CMakeFiles/Admin.dir/Administrador/Administrador.cpp.o: ../Administrador/Administrador.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nicomoccagatta/git/Inventario/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Admin.dir/Administrador/Administrador.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Admin.dir/Administrador/Administrador.cpp.o -c /home/nicomoccagatta/git/Inventario/Administrador/Administrador.cpp

CMakeFiles/Admin.dir/Administrador/Administrador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Admin.dir/Administrador/Administrador.cpp.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CXX_CREATE_PREPROCESSED_SOURCE

CMakeFiles/Admin.dir/Administrador/Administrador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Admin.dir/Administrador/Administrador.cpp.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CXX_CREATE_ASSEMBLY_SOURCE

CMakeFiles/Admin.dir/Administrador/Administrador.cpp.o.requires:
.PHONY : CMakeFiles/Admin.dir/Administrador/Administrador.cpp.o.requires

CMakeFiles/Admin.dir/Administrador/Administrador.cpp.o.provides: CMakeFiles/Admin.dir/Administrador/Administrador.cpp.o.requires
	$(MAKE) -f CMakeFiles/Admin.dir/build.make CMakeFiles/Admin.dir/Administrador/Administrador.cpp.o.provides.build
.PHONY : CMakeFiles/Admin.dir/Administrador/Administrador.cpp.o.provides

CMakeFiles/Admin.dir/Administrador/Administrador.cpp.o.provides.build: CMakeFiles/Admin.dir/Administrador/Administrador.cpp.o

# Object files for target Admin
Admin_OBJECTS = \
"CMakeFiles/Admin.dir/Administrador/Administrador.cpp.o"

# External object files for target Admin
Admin_EXTERNAL_OBJECTS =

Admin: CMakeFiles/Admin.dir/Administrador/Administrador.cpp.o
Admin: CMakeFiles/Admin.dir/build.make
Admin: CMakeFiles/Admin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Admin"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Admin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Admin.dir/build: Admin
.PHONY : CMakeFiles/Admin.dir/build

CMakeFiles/Admin.dir/requires: CMakeFiles/Admin.dir/Administrador/Administrador.cpp.o.requires
.PHONY : CMakeFiles/Admin.dir/requires

CMakeFiles/Admin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Admin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Admin.dir/clean

CMakeFiles/Admin.dir/depend:
	cd /home/nicomoccagatta/git/Inventario/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nicomoccagatta/git/Inventario /home/nicomoccagatta/git/Inventario /home/nicomoccagatta/git/Inventario/build /home/nicomoccagatta/git/Inventario/build /home/nicomoccagatta/git/Inventario/build/CMakeFiles/Admin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Admin.dir/depend
