# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build

# Include any dependencies generated for this target.
include CMakeFiles/tme810.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tme810.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tme810.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tme810.dir/flags.make

moc_SaveCellDialog.cpp: /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/SaveCellDialog.hpp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating moc_SaveCellDialog.cpp"
	/usr/lib64/qt6/libexec/moc @/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/moc_SaveCellDialog.cpp_parameters

moc_CellWidget.cpp: /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/CellWidget.hpp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating moc_CellWidget.cpp"
	/usr/lib64/qt6/libexec/moc @/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/moc_CellWidget.cpp_parameters

moc_CellViewer.cpp: /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/CellViewer.hpp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating moc_CellViewer.cpp"
	/usr/lib64/qt6/libexec/moc @/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/moc_CellViewer.cpp_parameters

CMakeFiles/tme810.dir/Indentation.cpp.o: CMakeFiles/tme810.dir/flags.make
CMakeFiles/tme810.dir/Indentation.cpp.o: /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Indentation.cpp
CMakeFiles/tme810.dir/Indentation.cpp.o: CMakeFiles/tme810.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tme810.dir/Indentation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tme810.dir/Indentation.cpp.o -MF CMakeFiles/tme810.dir/Indentation.cpp.o.d -o CMakeFiles/tme810.dir/Indentation.cpp.o -c /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Indentation.cpp

CMakeFiles/tme810.dir/Indentation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tme810.dir/Indentation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Indentation.cpp > CMakeFiles/tme810.dir/Indentation.cpp.i

CMakeFiles/tme810.dir/Indentation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tme810.dir/Indentation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Indentation.cpp -o CMakeFiles/tme810.dir/Indentation.cpp.s

CMakeFiles/tme810.dir/XmlUtil.cpp.o: CMakeFiles/tme810.dir/flags.make
CMakeFiles/tme810.dir/XmlUtil.cpp.o: /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/XmlUtil.cpp
CMakeFiles/tme810.dir/XmlUtil.cpp.o: CMakeFiles/tme810.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tme810.dir/XmlUtil.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tme810.dir/XmlUtil.cpp.o -MF CMakeFiles/tme810.dir/XmlUtil.cpp.o.d -o CMakeFiles/tme810.dir/XmlUtil.cpp.o -c /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/XmlUtil.cpp

CMakeFiles/tme810.dir/XmlUtil.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tme810.dir/XmlUtil.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/XmlUtil.cpp > CMakeFiles/tme810.dir/XmlUtil.cpp.i

CMakeFiles/tme810.dir/XmlUtil.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tme810.dir/XmlUtil.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/XmlUtil.cpp -o CMakeFiles/tme810.dir/XmlUtil.cpp.s

CMakeFiles/tme810.dir/Point.cpp.o: CMakeFiles/tme810.dir/flags.make
CMakeFiles/tme810.dir/Point.cpp.o: /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Point.cpp
CMakeFiles/tme810.dir/Point.cpp.o: CMakeFiles/tme810.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/tme810.dir/Point.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tme810.dir/Point.cpp.o -MF CMakeFiles/tme810.dir/Point.cpp.o.d -o CMakeFiles/tme810.dir/Point.cpp.o -c /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Point.cpp

CMakeFiles/tme810.dir/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tme810.dir/Point.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Point.cpp > CMakeFiles/tme810.dir/Point.cpp.i

CMakeFiles/tme810.dir/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tme810.dir/Point.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Point.cpp -o CMakeFiles/tme810.dir/Point.cpp.s

CMakeFiles/tme810.dir/Box.cpp.o: CMakeFiles/tme810.dir/flags.make
CMakeFiles/tme810.dir/Box.cpp.o: /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Box.cpp
CMakeFiles/tme810.dir/Box.cpp.o: CMakeFiles/tme810.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/tme810.dir/Box.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tme810.dir/Box.cpp.o -MF CMakeFiles/tme810.dir/Box.cpp.o.d -o CMakeFiles/tme810.dir/Box.cpp.o -c /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Box.cpp

CMakeFiles/tme810.dir/Box.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tme810.dir/Box.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Box.cpp > CMakeFiles/tme810.dir/Box.cpp.i

CMakeFiles/tme810.dir/Box.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tme810.dir/Box.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Box.cpp -o CMakeFiles/tme810.dir/Box.cpp.s

CMakeFiles/tme810.dir/Term.cpp.o: CMakeFiles/tme810.dir/flags.make
CMakeFiles/tme810.dir/Term.cpp.o: /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Term.cpp
CMakeFiles/tme810.dir/Term.cpp.o: CMakeFiles/tme810.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/tme810.dir/Term.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tme810.dir/Term.cpp.o -MF CMakeFiles/tme810.dir/Term.cpp.o.d -o CMakeFiles/tme810.dir/Term.cpp.o -c /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Term.cpp

CMakeFiles/tme810.dir/Term.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tme810.dir/Term.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Term.cpp > CMakeFiles/tme810.dir/Term.cpp.i

CMakeFiles/tme810.dir/Term.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tme810.dir/Term.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Term.cpp -o CMakeFiles/tme810.dir/Term.cpp.s

CMakeFiles/tme810.dir/Net.cpp.o: CMakeFiles/tme810.dir/flags.make
CMakeFiles/tme810.dir/Net.cpp.o: /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Net.cpp
CMakeFiles/tme810.dir/Net.cpp.o: CMakeFiles/tme810.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/tme810.dir/Net.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tme810.dir/Net.cpp.o -MF CMakeFiles/tme810.dir/Net.cpp.o.d -o CMakeFiles/tme810.dir/Net.cpp.o -c /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Net.cpp

CMakeFiles/tme810.dir/Net.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tme810.dir/Net.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Net.cpp > CMakeFiles/tme810.dir/Net.cpp.i

CMakeFiles/tme810.dir/Net.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tme810.dir/Net.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Net.cpp -o CMakeFiles/tme810.dir/Net.cpp.s

CMakeFiles/tme810.dir/Instance.cpp.o: CMakeFiles/tme810.dir/flags.make
CMakeFiles/tme810.dir/Instance.cpp.o: /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Instance.cpp
CMakeFiles/tme810.dir/Instance.cpp.o: CMakeFiles/tme810.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/tme810.dir/Instance.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tme810.dir/Instance.cpp.o -MF CMakeFiles/tme810.dir/Instance.cpp.o.d -o CMakeFiles/tme810.dir/Instance.cpp.o -c /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Instance.cpp

CMakeFiles/tme810.dir/Instance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tme810.dir/Instance.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Instance.cpp > CMakeFiles/tme810.dir/Instance.cpp.i

CMakeFiles/tme810.dir/Instance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tme810.dir/Instance.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Instance.cpp -o CMakeFiles/tme810.dir/Instance.cpp.s

CMakeFiles/tme810.dir/Node.cpp.o: CMakeFiles/tme810.dir/flags.make
CMakeFiles/tme810.dir/Node.cpp.o: /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Node.cpp
CMakeFiles/tme810.dir/Node.cpp.o: CMakeFiles/tme810.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/tme810.dir/Node.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tme810.dir/Node.cpp.o -MF CMakeFiles/tme810.dir/Node.cpp.o.d -o CMakeFiles/tme810.dir/Node.cpp.o -c /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Node.cpp

CMakeFiles/tme810.dir/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tme810.dir/Node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Node.cpp > CMakeFiles/tme810.dir/Node.cpp.i

CMakeFiles/tme810.dir/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tme810.dir/Node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Node.cpp -o CMakeFiles/tme810.dir/Node.cpp.s

CMakeFiles/tme810.dir/Line.cpp.o: CMakeFiles/tme810.dir/flags.make
CMakeFiles/tme810.dir/Line.cpp.o: /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Line.cpp
CMakeFiles/tme810.dir/Line.cpp.o: CMakeFiles/tme810.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/tme810.dir/Line.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tme810.dir/Line.cpp.o -MF CMakeFiles/tme810.dir/Line.cpp.o.d -o CMakeFiles/tme810.dir/Line.cpp.o -c /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Line.cpp

CMakeFiles/tme810.dir/Line.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tme810.dir/Line.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Line.cpp > CMakeFiles/tme810.dir/Line.cpp.i

CMakeFiles/tme810.dir/Line.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tme810.dir/Line.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Line.cpp -o CMakeFiles/tme810.dir/Line.cpp.s

CMakeFiles/tme810.dir/Shape.cpp.o: CMakeFiles/tme810.dir/flags.make
CMakeFiles/tme810.dir/Shape.cpp.o: /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Shape.cpp
CMakeFiles/tme810.dir/Shape.cpp.o: CMakeFiles/tme810.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/tme810.dir/Shape.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tme810.dir/Shape.cpp.o -MF CMakeFiles/tme810.dir/Shape.cpp.o.d -o CMakeFiles/tme810.dir/Shape.cpp.o -c /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Shape.cpp

CMakeFiles/tme810.dir/Shape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tme810.dir/Shape.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Shape.cpp > CMakeFiles/tme810.dir/Shape.cpp.i

CMakeFiles/tme810.dir/Shape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tme810.dir/Shape.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Shape.cpp -o CMakeFiles/tme810.dir/Shape.cpp.s

CMakeFiles/tme810.dir/Symbol.cpp.o: CMakeFiles/tme810.dir/flags.make
CMakeFiles/tme810.dir/Symbol.cpp.o: /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Symbol.cpp
CMakeFiles/tme810.dir/Symbol.cpp.o: CMakeFiles/tme810.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/tme810.dir/Symbol.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tme810.dir/Symbol.cpp.o -MF CMakeFiles/tme810.dir/Symbol.cpp.o.d -o CMakeFiles/tme810.dir/Symbol.cpp.o -c /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Symbol.cpp

CMakeFiles/tme810.dir/Symbol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tme810.dir/Symbol.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Symbol.cpp > CMakeFiles/tme810.dir/Symbol.cpp.i

CMakeFiles/tme810.dir/Symbol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tme810.dir/Symbol.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Symbol.cpp -o CMakeFiles/tme810.dir/Symbol.cpp.s

CMakeFiles/tme810.dir/Cell.cpp.o: CMakeFiles/tme810.dir/flags.make
CMakeFiles/tme810.dir/Cell.cpp.o: /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Cell.cpp
CMakeFiles/tme810.dir/Cell.cpp.o: CMakeFiles/tme810.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/tme810.dir/Cell.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tme810.dir/Cell.cpp.o -MF CMakeFiles/tme810.dir/Cell.cpp.o.d -o CMakeFiles/tme810.dir/Cell.cpp.o -c /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Cell.cpp

CMakeFiles/tme810.dir/Cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tme810.dir/Cell.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Cell.cpp > CMakeFiles/tme810.dir/Cell.cpp.i

CMakeFiles/tme810.dir/Cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tme810.dir/Cell.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Cell.cpp -o CMakeFiles/tme810.dir/Cell.cpp.s

CMakeFiles/tme810.dir/SaveCellDialog.cpp.o: CMakeFiles/tme810.dir/flags.make
CMakeFiles/tme810.dir/SaveCellDialog.cpp.o: /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/SaveCellDialog.cpp
CMakeFiles/tme810.dir/SaveCellDialog.cpp.o: CMakeFiles/tme810.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/tme810.dir/SaveCellDialog.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tme810.dir/SaveCellDialog.cpp.o -MF CMakeFiles/tme810.dir/SaveCellDialog.cpp.o.d -o CMakeFiles/tme810.dir/SaveCellDialog.cpp.o -c /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/SaveCellDialog.cpp

CMakeFiles/tme810.dir/SaveCellDialog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tme810.dir/SaveCellDialog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/SaveCellDialog.cpp > CMakeFiles/tme810.dir/SaveCellDialog.cpp.i

CMakeFiles/tme810.dir/SaveCellDialog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tme810.dir/SaveCellDialog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/SaveCellDialog.cpp -o CMakeFiles/tme810.dir/SaveCellDialog.cpp.s

CMakeFiles/tme810.dir/CellWidget.cpp.o: CMakeFiles/tme810.dir/flags.make
CMakeFiles/tme810.dir/CellWidget.cpp.o: /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/CellWidget.cpp
CMakeFiles/tme810.dir/CellWidget.cpp.o: CMakeFiles/tme810.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/tme810.dir/CellWidget.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tme810.dir/CellWidget.cpp.o -MF CMakeFiles/tme810.dir/CellWidget.cpp.o.d -o CMakeFiles/tme810.dir/CellWidget.cpp.o -c /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/CellWidget.cpp

CMakeFiles/tme810.dir/CellWidget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tme810.dir/CellWidget.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/CellWidget.cpp > CMakeFiles/tme810.dir/CellWidget.cpp.i

CMakeFiles/tme810.dir/CellWidget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tme810.dir/CellWidget.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/CellWidget.cpp -o CMakeFiles/tme810.dir/CellWidget.cpp.s

CMakeFiles/tme810.dir/CellViewer.cpp.o: CMakeFiles/tme810.dir/flags.make
CMakeFiles/tme810.dir/CellViewer.cpp.o: /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/CellViewer.cpp
CMakeFiles/tme810.dir/CellViewer.cpp.o: CMakeFiles/tme810.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/tme810.dir/CellViewer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tme810.dir/CellViewer.cpp.o -MF CMakeFiles/tme810.dir/CellViewer.cpp.o.d -o CMakeFiles/tme810.dir/CellViewer.cpp.o -c /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/CellViewer.cpp

CMakeFiles/tme810.dir/CellViewer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tme810.dir/CellViewer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/CellViewer.cpp > CMakeFiles/tme810.dir/CellViewer.cpp.i

CMakeFiles/tme810.dir/CellViewer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tme810.dir/CellViewer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/CellViewer.cpp -o CMakeFiles/tme810.dir/CellViewer.cpp.s

CMakeFiles/tme810.dir/Main.cpp.o: CMakeFiles/tme810.dir/flags.make
CMakeFiles/tme810.dir/Main.cpp.o: /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Main.cpp
CMakeFiles/tme810.dir/Main.cpp.o: CMakeFiles/tme810.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/tme810.dir/Main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tme810.dir/Main.cpp.o -MF CMakeFiles/tme810.dir/Main.cpp.o.d -o CMakeFiles/tme810.dir/Main.cpp.o -c /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Main.cpp

CMakeFiles/tme810.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tme810.dir/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Main.cpp > CMakeFiles/tme810.dir/Main.cpp.i

CMakeFiles/tme810.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tme810.dir/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src/Main.cpp -o CMakeFiles/tme810.dir/Main.cpp.s

CMakeFiles/tme810.dir/moc_SaveCellDialog.cpp.o: CMakeFiles/tme810.dir/flags.make
CMakeFiles/tme810.dir/moc_SaveCellDialog.cpp.o: moc_SaveCellDialog.cpp
CMakeFiles/tme810.dir/moc_SaveCellDialog.cpp.o: CMakeFiles/tme810.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/tme810.dir/moc_SaveCellDialog.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tme810.dir/moc_SaveCellDialog.cpp.o -MF CMakeFiles/tme810.dir/moc_SaveCellDialog.cpp.o.d -o CMakeFiles/tme810.dir/moc_SaveCellDialog.cpp.o -c /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/moc_SaveCellDialog.cpp

CMakeFiles/tme810.dir/moc_SaveCellDialog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tme810.dir/moc_SaveCellDialog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/moc_SaveCellDialog.cpp > CMakeFiles/tme810.dir/moc_SaveCellDialog.cpp.i

CMakeFiles/tme810.dir/moc_SaveCellDialog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tme810.dir/moc_SaveCellDialog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/moc_SaveCellDialog.cpp -o CMakeFiles/tme810.dir/moc_SaveCellDialog.cpp.s

CMakeFiles/tme810.dir/moc_CellWidget.cpp.o: CMakeFiles/tme810.dir/flags.make
CMakeFiles/tme810.dir/moc_CellWidget.cpp.o: moc_CellWidget.cpp
CMakeFiles/tme810.dir/moc_CellWidget.cpp.o: CMakeFiles/tme810.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building CXX object CMakeFiles/tme810.dir/moc_CellWidget.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tme810.dir/moc_CellWidget.cpp.o -MF CMakeFiles/tme810.dir/moc_CellWidget.cpp.o.d -o CMakeFiles/tme810.dir/moc_CellWidget.cpp.o -c /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/moc_CellWidget.cpp

CMakeFiles/tme810.dir/moc_CellWidget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tme810.dir/moc_CellWidget.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/moc_CellWidget.cpp > CMakeFiles/tme810.dir/moc_CellWidget.cpp.i

CMakeFiles/tme810.dir/moc_CellWidget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tme810.dir/moc_CellWidget.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/moc_CellWidget.cpp -o CMakeFiles/tme810.dir/moc_CellWidget.cpp.s

CMakeFiles/tme810.dir/moc_CellViewer.cpp.o: CMakeFiles/tme810.dir/flags.make
CMakeFiles/tme810.dir/moc_CellViewer.cpp.o: moc_CellViewer.cpp
CMakeFiles/tme810.dir/moc_CellViewer.cpp.o: CMakeFiles/tme810.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Building CXX object CMakeFiles/tme810.dir/moc_CellViewer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tme810.dir/moc_CellViewer.cpp.o -MF CMakeFiles/tme810.dir/moc_CellViewer.cpp.o.d -o CMakeFiles/tme810.dir/moc_CellViewer.cpp.o -c /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/moc_CellViewer.cpp

CMakeFiles/tme810.dir/moc_CellViewer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tme810.dir/moc_CellViewer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/moc_CellViewer.cpp > CMakeFiles/tme810.dir/moc_CellViewer.cpp.i

CMakeFiles/tme810.dir/moc_CellViewer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tme810.dir/moc_CellViewer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/moc_CellViewer.cpp -o CMakeFiles/tme810.dir/moc_CellViewer.cpp.s

# Object files for target tme810
tme810_OBJECTS = \
"CMakeFiles/tme810.dir/Indentation.cpp.o" \
"CMakeFiles/tme810.dir/XmlUtil.cpp.o" \
"CMakeFiles/tme810.dir/Point.cpp.o" \
"CMakeFiles/tme810.dir/Box.cpp.o" \
"CMakeFiles/tme810.dir/Term.cpp.o" \
"CMakeFiles/tme810.dir/Net.cpp.o" \
"CMakeFiles/tme810.dir/Instance.cpp.o" \
"CMakeFiles/tme810.dir/Node.cpp.o" \
"CMakeFiles/tme810.dir/Line.cpp.o" \
"CMakeFiles/tme810.dir/Shape.cpp.o" \
"CMakeFiles/tme810.dir/Symbol.cpp.o" \
"CMakeFiles/tme810.dir/Cell.cpp.o" \
"CMakeFiles/tme810.dir/SaveCellDialog.cpp.o" \
"CMakeFiles/tme810.dir/CellWidget.cpp.o" \
"CMakeFiles/tme810.dir/CellViewer.cpp.o" \
"CMakeFiles/tme810.dir/Main.cpp.o" \
"CMakeFiles/tme810.dir/moc_SaveCellDialog.cpp.o" \
"CMakeFiles/tme810.dir/moc_CellWidget.cpp.o" \
"CMakeFiles/tme810.dir/moc_CellViewer.cpp.o"

# External object files for target tme810
tme810_EXTERNAL_OBJECTS =

tme810: CMakeFiles/tme810.dir/Indentation.cpp.o
tme810: CMakeFiles/tme810.dir/XmlUtil.cpp.o
tme810: CMakeFiles/tme810.dir/Point.cpp.o
tme810: CMakeFiles/tme810.dir/Box.cpp.o
tme810: CMakeFiles/tme810.dir/Term.cpp.o
tme810: CMakeFiles/tme810.dir/Net.cpp.o
tme810: CMakeFiles/tme810.dir/Instance.cpp.o
tme810: CMakeFiles/tme810.dir/Node.cpp.o
tme810: CMakeFiles/tme810.dir/Line.cpp.o
tme810: CMakeFiles/tme810.dir/Shape.cpp.o
tme810: CMakeFiles/tme810.dir/Symbol.cpp.o
tme810: CMakeFiles/tme810.dir/Cell.cpp.o
tme810: CMakeFiles/tme810.dir/SaveCellDialog.cpp.o
tme810: CMakeFiles/tme810.dir/CellWidget.cpp.o
tme810: CMakeFiles/tme810.dir/CellViewer.cpp.o
tme810: CMakeFiles/tme810.dir/Main.cpp.o
tme810: CMakeFiles/tme810.dir/moc_SaveCellDialog.cpp.o
tme810: CMakeFiles/tme810.dir/moc_CellWidget.cpp.o
tme810: CMakeFiles/tme810.dir/moc_CellViewer.cpp.o
tme810: CMakeFiles/tme810.dir/build.make
tme810: /usr/lib/libQt6Gui.so.6.7.2
tme810: /usr/lib/libxml2.so
tme810: /usr/lib/libQt6Core.so.6.7.2
tme810: /usr/lib/libGLX.so
tme810: /usr/lib/libOpenGL.so
tme810: CMakeFiles/tme810.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_23) "Linking CXX executable tme810"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tme810.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tme810.dir/build: tme810
.PHONY : CMakeFiles/tme810.dir/build

CMakeFiles/tme810.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tme810.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tme810.dir/clean

CMakeFiles/tme810.dir/depend: moc_CellViewer.cpp
CMakeFiles/tme810.dir/depend: moc_CellWidget.cpp
CMakeFiles/tme810.dir/depend: moc_SaveCellDialog.cpp
	cd /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/src /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build /home/ivan/Shortcuts/m1/mobj/tme/tme8-10/build/CMakeFiles/tme810.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/tme810.dir/depend

