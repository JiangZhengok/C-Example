# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_SOURCE_DIR = /media/jiang/DATA/00MyDocuments/PublicDocument/C++/Example/CmakeProject/BuyTicket

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/jiang/DATA/00MyDocuments/PublicDocument/C++/Example/CmakeProject/BuyTicket/build

# Include any dependencies generated for this target.
include CMakeFiles/BuyTicket.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BuyTicket.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BuyTicket.dir/flags.make

CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.o: CMakeFiles/BuyTicket.dir/flags.make
CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.o: ../src/BuyTicket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jiang/DATA/00MyDocuments/PublicDocument/C++/Example/CmakeProject/BuyTicket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.o -c /media/jiang/DATA/00MyDocuments/PublicDocument/C++/Example/CmakeProject/BuyTicket/src/BuyTicket.cpp

CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/jiang/DATA/00MyDocuments/PublicDocument/C++/Example/CmakeProject/BuyTicket/src/BuyTicket.cpp > CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.i

CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/jiang/DATA/00MyDocuments/PublicDocument/C++/Example/CmakeProject/BuyTicket/src/BuyTicket.cpp -o CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.s

CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.o.requires:

.PHONY : CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.o.requires

CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.o.provides: CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.o.requires
	$(MAKE) -f CMakeFiles/BuyTicket.dir/build.make CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.o.provides.build
.PHONY : CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.o.provides

CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.o.provides.build: CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.o


CMakeFiles/BuyTicket.dir/src/main.cpp.o: CMakeFiles/BuyTicket.dir/flags.make
CMakeFiles/BuyTicket.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jiang/DATA/00MyDocuments/PublicDocument/C++/Example/CmakeProject/BuyTicket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BuyTicket.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BuyTicket.dir/src/main.cpp.o -c /media/jiang/DATA/00MyDocuments/PublicDocument/C++/Example/CmakeProject/BuyTicket/src/main.cpp

CMakeFiles/BuyTicket.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BuyTicket.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/jiang/DATA/00MyDocuments/PublicDocument/C++/Example/CmakeProject/BuyTicket/src/main.cpp > CMakeFiles/BuyTicket.dir/src/main.cpp.i

CMakeFiles/BuyTicket.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BuyTicket.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/jiang/DATA/00MyDocuments/PublicDocument/C++/Example/CmakeProject/BuyTicket/src/main.cpp -o CMakeFiles/BuyTicket.dir/src/main.cpp.s

CMakeFiles/BuyTicket.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/BuyTicket.dir/src/main.cpp.o.requires

CMakeFiles/BuyTicket.dir/src/main.cpp.o.provides: CMakeFiles/BuyTicket.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/BuyTicket.dir/build.make CMakeFiles/BuyTicket.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/BuyTicket.dir/src/main.cpp.o.provides

CMakeFiles/BuyTicket.dir/src/main.cpp.o.provides.build: CMakeFiles/BuyTicket.dir/src/main.cpp.o


# Object files for target BuyTicket
BuyTicket_OBJECTS = \
"CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.o" \
"CMakeFiles/BuyTicket.dir/src/main.cpp.o"

# External object files for target BuyTicket
BuyTicket_EXTERNAL_OBJECTS =

BuyTicket: CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.o
BuyTicket: CMakeFiles/BuyTicket.dir/src/main.cpp.o
BuyTicket: CMakeFiles/BuyTicket.dir/build.make
BuyTicket: CMakeFiles/BuyTicket.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/jiang/DATA/00MyDocuments/PublicDocument/C++/Example/CmakeProject/BuyTicket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable BuyTicket"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BuyTicket.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BuyTicket.dir/build: BuyTicket

.PHONY : CMakeFiles/BuyTicket.dir/build

CMakeFiles/BuyTicket.dir/requires: CMakeFiles/BuyTicket.dir/src/BuyTicket.cpp.o.requires
CMakeFiles/BuyTicket.dir/requires: CMakeFiles/BuyTicket.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/BuyTicket.dir/requires

CMakeFiles/BuyTicket.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BuyTicket.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BuyTicket.dir/clean

CMakeFiles/BuyTicket.dir/depend:
	cd /media/jiang/DATA/00MyDocuments/PublicDocument/C++/Example/CmakeProject/BuyTicket/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/jiang/DATA/00MyDocuments/PublicDocument/C++/Example/CmakeProject/BuyTicket /media/jiang/DATA/00MyDocuments/PublicDocument/C++/Example/CmakeProject/BuyTicket /media/jiang/DATA/00MyDocuments/PublicDocument/C++/Example/CmakeProject/BuyTicket/build /media/jiang/DATA/00MyDocuments/PublicDocument/C++/Example/CmakeProject/BuyTicket/build /media/jiang/DATA/00MyDocuments/PublicDocument/C++/Example/CmakeProject/BuyTicket/build/CMakeFiles/BuyTicket.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BuyTicket.dir/depend
