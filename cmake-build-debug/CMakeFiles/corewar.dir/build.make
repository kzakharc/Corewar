# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nfs/2016/v/vpoltave/CLionProjects/repocorewar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/2016/v/vpoltave/CLionProjects/repocorewar/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/corewar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/corewar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/corewar.dir/flags.make

CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.o: ../vp_virtual_machine/vp_virtual_main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/v/vpoltave/CLionProjects/repocorewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.o   -c /nfs/2016/v/vpoltave/CLionProjects/repocorewar/vp_virtual_machine/vp_virtual_main.c

CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/v/vpoltave/CLionProjects/repocorewar/vp_virtual_machine/vp_virtual_main.c > CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.i

CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/v/vpoltave/CLionProjects/repocorewar/vp_virtual_machine/vp_virtual_main.c -o CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.s

CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.o.requires:

.PHONY : CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.o.requires

CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.o.provides: CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.o.requires
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.o.provides.build
.PHONY : CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.o.provides

CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.o.provides.build: CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.o


CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.o: ../vp_virtual_machine/vp_err_u.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/v/vpoltave/CLionProjects/repocorewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.o   -c /nfs/2016/v/vpoltave/CLionProjects/repocorewar/vp_virtual_machine/vp_err_u.c

CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/v/vpoltave/CLionProjects/repocorewar/vp_virtual_machine/vp_err_u.c > CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.i

CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/v/vpoltave/CLionProjects/repocorewar/vp_virtual_machine/vp_err_u.c -o CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.s

CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.o.requires:

.PHONY : CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.o.requires

CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.o.provides: CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.o.requires
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.o.provides.build
.PHONY : CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.o.provides

CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.o.provides.build: CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.o


CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.o: CMakeFiles/corewar.dir/flags.make
CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.o: ../vp_virtual_machine/vp_basic.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/2016/v/vpoltave/CLionProjects/repocorewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.o   -c /nfs/2016/v/vpoltave/CLionProjects/repocorewar/vp_virtual_machine/vp_basic.c

CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/2016/v/vpoltave/CLionProjects/repocorewar/vp_virtual_machine/vp_basic.c > CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.i

CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/2016/v/vpoltave/CLionProjects/repocorewar/vp_virtual_machine/vp_basic.c -o CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.s

CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.o.requires:

.PHONY : CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.o.requires

CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.o.provides: CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.o.requires
	$(MAKE) -f CMakeFiles/corewar.dir/build.make CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.o.provides.build
.PHONY : CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.o.provides

CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.o.provides.build: CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.o


# Object files for target corewar
corewar_OBJECTS = \
"CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.o" \
"CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.o" \
"CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.o"

# External object files for target corewar
corewar_EXTERNAL_OBJECTS =

corewar: CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.o
corewar: CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.o
corewar: CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.o
corewar: CMakeFiles/corewar.dir/build.make
corewar: ../libft/libft.a
corewar: CMakeFiles/corewar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/2016/v/vpoltave/CLionProjects/repocorewar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable corewar"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/corewar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/corewar.dir/build: corewar

.PHONY : CMakeFiles/corewar.dir/build

CMakeFiles/corewar.dir/requires: CMakeFiles/corewar.dir/vp_virtual_machine/vp_virtual_main.c.o.requires
CMakeFiles/corewar.dir/requires: CMakeFiles/corewar.dir/vp_virtual_machine/vp_err_u.c.o.requires
CMakeFiles/corewar.dir/requires: CMakeFiles/corewar.dir/vp_virtual_machine/vp_basic.c.o.requires

.PHONY : CMakeFiles/corewar.dir/requires

CMakeFiles/corewar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/corewar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/corewar.dir/clean

CMakeFiles/corewar.dir/depend:
	cd /nfs/2016/v/vpoltave/CLionProjects/repocorewar/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/2016/v/vpoltave/CLionProjects/repocorewar /nfs/2016/v/vpoltave/CLionProjects/repocorewar /nfs/2016/v/vpoltave/CLionProjects/repocorewar/cmake-build-debug /nfs/2016/v/vpoltave/CLionProjects/repocorewar/cmake-build-debug /nfs/2016/v/vpoltave/CLionProjects/repocorewar/cmake-build-debug/CMakeFiles/corewar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/corewar.dir/depend

