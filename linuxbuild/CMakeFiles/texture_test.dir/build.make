# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /mnt/h/CS455/source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/h/CS455/linuxbuild

# Include any dependencies generated for this target.
include CMakeFiles/texture_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/texture_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/texture_test.dir/flags.make

CMakeFiles/texture_test.dir/texture_test.cpp.o: CMakeFiles/texture_test.dir/flags.make
CMakeFiles/texture_test.dir/texture_test.cpp.o: /mnt/h/CS455/source/texture_test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/h/CS455/linuxbuild/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/texture_test.dir/texture_test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/texture_test.dir/texture_test.cpp.o -c /mnt/h/CS455/source/texture_test.cpp

CMakeFiles/texture_test.dir/texture_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture_test.dir/texture_test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/h/CS455/source/texture_test.cpp > CMakeFiles/texture_test.dir/texture_test.cpp.i

CMakeFiles/texture_test.dir/texture_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture_test.dir/texture_test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/h/CS455/source/texture_test.cpp -o CMakeFiles/texture_test.dir/texture_test.cpp.s

CMakeFiles/texture_test.dir/texture_test.cpp.o.requires:
.PHONY : CMakeFiles/texture_test.dir/texture_test.cpp.o.requires

CMakeFiles/texture_test.dir/texture_test.cpp.o.provides: CMakeFiles/texture_test.dir/texture_test.cpp.o.requires
	$(MAKE) -f CMakeFiles/texture_test.dir/build.make CMakeFiles/texture_test.dir/texture_test.cpp.o.provides.build
.PHONY : CMakeFiles/texture_test.dir/texture_test.cpp.o.provides

CMakeFiles/texture_test.dir/texture_test.cpp.o.provides.build: CMakeFiles/texture_test.dir/texture_test.cpp.o

CMakeFiles/texture_test.dir/TextureRenderer.cpp.o: CMakeFiles/texture_test.dir/flags.make
CMakeFiles/texture_test.dir/TextureRenderer.cpp.o: /mnt/h/CS455/source/TextureRenderer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/h/CS455/linuxbuild/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/texture_test.dir/TextureRenderer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/texture_test.dir/TextureRenderer.cpp.o -c /mnt/h/CS455/source/TextureRenderer.cpp

CMakeFiles/texture_test.dir/TextureRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture_test.dir/TextureRenderer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/h/CS455/source/TextureRenderer.cpp > CMakeFiles/texture_test.dir/TextureRenderer.cpp.i

CMakeFiles/texture_test.dir/TextureRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture_test.dir/TextureRenderer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/h/CS455/source/TextureRenderer.cpp -o CMakeFiles/texture_test.dir/TextureRenderer.cpp.s

CMakeFiles/texture_test.dir/TextureRenderer.cpp.o.requires:
.PHONY : CMakeFiles/texture_test.dir/TextureRenderer.cpp.o.requires

CMakeFiles/texture_test.dir/TextureRenderer.cpp.o.provides: CMakeFiles/texture_test.dir/TextureRenderer.cpp.o.requires
	$(MAKE) -f CMakeFiles/texture_test.dir/build.make CMakeFiles/texture_test.dir/TextureRenderer.cpp.o.provides.build
.PHONY : CMakeFiles/texture_test.dir/TextureRenderer.cpp.o.provides

CMakeFiles/texture_test.dir/TextureRenderer.cpp.o.provides.build: CMakeFiles/texture_test.dir/TextureRenderer.cpp.o

CMakeFiles/texture_test.dir/glut_utilities.cpp.o: CMakeFiles/texture_test.dir/flags.make
CMakeFiles/texture_test.dir/glut_utilities.cpp.o: /mnt/h/CS455/source/glut_utilities.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/h/CS455/linuxbuild/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/texture_test.dir/glut_utilities.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/texture_test.dir/glut_utilities.cpp.o -c /mnt/h/CS455/source/glut_utilities.cpp

CMakeFiles/texture_test.dir/glut_utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture_test.dir/glut_utilities.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/h/CS455/source/glut_utilities.cpp > CMakeFiles/texture_test.dir/glut_utilities.cpp.i

CMakeFiles/texture_test.dir/glut_utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture_test.dir/glut_utilities.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/h/CS455/source/glut_utilities.cpp -o CMakeFiles/texture_test.dir/glut_utilities.cpp.s

CMakeFiles/texture_test.dir/glut_utilities.cpp.o.requires:
.PHONY : CMakeFiles/texture_test.dir/glut_utilities.cpp.o.requires

CMakeFiles/texture_test.dir/glut_utilities.cpp.o.provides: CMakeFiles/texture_test.dir/glut_utilities.cpp.o.requires
	$(MAKE) -f CMakeFiles/texture_test.dir/build.make CMakeFiles/texture_test.dir/glut_utilities.cpp.o.provides.build
.PHONY : CMakeFiles/texture_test.dir/glut_utilities.cpp.o.provides

CMakeFiles/texture_test.dir/glut_utilities.cpp.o.provides.build: CMakeFiles/texture_test.dir/glut_utilities.cpp.o

CMakeFiles/texture_test.dir/BaseRenderer.cpp.o: CMakeFiles/texture_test.dir/flags.make
CMakeFiles/texture_test.dir/BaseRenderer.cpp.o: /mnt/h/CS455/source/BaseRenderer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/h/CS455/linuxbuild/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/texture_test.dir/BaseRenderer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/texture_test.dir/BaseRenderer.cpp.o -c /mnt/h/CS455/source/BaseRenderer.cpp

CMakeFiles/texture_test.dir/BaseRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture_test.dir/BaseRenderer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/h/CS455/source/BaseRenderer.cpp > CMakeFiles/texture_test.dir/BaseRenderer.cpp.i

CMakeFiles/texture_test.dir/BaseRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture_test.dir/BaseRenderer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/h/CS455/source/BaseRenderer.cpp -o CMakeFiles/texture_test.dir/BaseRenderer.cpp.s

CMakeFiles/texture_test.dir/BaseRenderer.cpp.o.requires:
.PHONY : CMakeFiles/texture_test.dir/BaseRenderer.cpp.o.requires

CMakeFiles/texture_test.dir/BaseRenderer.cpp.o.provides: CMakeFiles/texture_test.dir/BaseRenderer.cpp.o.requires
	$(MAKE) -f CMakeFiles/texture_test.dir/build.make CMakeFiles/texture_test.dir/BaseRenderer.cpp.o.provides.build
.PHONY : CMakeFiles/texture_test.dir/BaseRenderer.cpp.o.provides

CMakeFiles/texture_test.dir/BaseRenderer.cpp.o.provides.build: CMakeFiles/texture_test.dir/BaseRenderer.cpp.o

CMakeFiles/texture_test.dir/Vector4.cpp.o: CMakeFiles/texture_test.dir/flags.make
CMakeFiles/texture_test.dir/Vector4.cpp.o: /mnt/h/CS455/source/Vector4.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/h/CS455/linuxbuild/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/texture_test.dir/Vector4.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/texture_test.dir/Vector4.cpp.o -c /mnt/h/CS455/source/Vector4.cpp

CMakeFiles/texture_test.dir/Vector4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture_test.dir/Vector4.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/h/CS455/source/Vector4.cpp > CMakeFiles/texture_test.dir/Vector4.cpp.i

CMakeFiles/texture_test.dir/Vector4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture_test.dir/Vector4.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/h/CS455/source/Vector4.cpp -o CMakeFiles/texture_test.dir/Vector4.cpp.s

CMakeFiles/texture_test.dir/Vector4.cpp.o.requires:
.PHONY : CMakeFiles/texture_test.dir/Vector4.cpp.o.requires

CMakeFiles/texture_test.dir/Vector4.cpp.o.provides: CMakeFiles/texture_test.dir/Vector4.cpp.o.requires
	$(MAKE) -f CMakeFiles/texture_test.dir/build.make CMakeFiles/texture_test.dir/Vector4.cpp.o.provides.build
.PHONY : CMakeFiles/texture_test.dir/Vector4.cpp.o.provides

CMakeFiles/texture_test.dir/Vector4.cpp.o.provides.build: CMakeFiles/texture_test.dir/Vector4.cpp.o

CMakeFiles/texture_test.dir/Matrix4.cpp.o: CMakeFiles/texture_test.dir/flags.make
CMakeFiles/texture_test.dir/Matrix4.cpp.o: /mnt/h/CS455/source/Matrix4.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/h/CS455/linuxbuild/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/texture_test.dir/Matrix4.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/texture_test.dir/Matrix4.cpp.o -c /mnt/h/CS455/source/Matrix4.cpp

CMakeFiles/texture_test.dir/Matrix4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture_test.dir/Matrix4.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/h/CS455/source/Matrix4.cpp > CMakeFiles/texture_test.dir/Matrix4.cpp.i

CMakeFiles/texture_test.dir/Matrix4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture_test.dir/Matrix4.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/h/CS455/source/Matrix4.cpp -o CMakeFiles/texture_test.dir/Matrix4.cpp.s

CMakeFiles/texture_test.dir/Matrix4.cpp.o.requires:
.PHONY : CMakeFiles/texture_test.dir/Matrix4.cpp.o.requires

CMakeFiles/texture_test.dir/Matrix4.cpp.o.provides: CMakeFiles/texture_test.dir/Matrix4.cpp.o.requires
	$(MAKE) -f CMakeFiles/texture_test.dir/build.make CMakeFiles/texture_test.dir/Matrix4.cpp.o.provides.build
.PHONY : CMakeFiles/texture_test.dir/Matrix4.cpp.o.provides

CMakeFiles/texture_test.dir/Matrix4.cpp.o.provides.build: CMakeFiles/texture_test.dir/Matrix4.cpp.o

CMakeFiles/texture_test.dir/Camera.cpp.o: CMakeFiles/texture_test.dir/flags.make
CMakeFiles/texture_test.dir/Camera.cpp.o: /mnt/h/CS455/source/Camera.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/h/CS455/linuxbuild/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/texture_test.dir/Camera.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/texture_test.dir/Camera.cpp.o -c /mnt/h/CS455/source/Camera.cpp

CMakeFiles/texture_test.dir/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture_test.dir/Camera.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/h/CS455/source/Camera.cpp > CMakeFiles/texture_test.dir/Camera.cpp.i

CMakeFiles/texture_test.dir/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture_test.dir/Camera.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/h/CS455/source/Camera.cpp -o CMakeFiles/texture_test.dir/Camera.cpp.s

CMakeFiles/texture_test.dir/Camera.cpp.o.requires:
.PHONY : CMakeFiles/texture_test.dir/Camera.cpp.o.requires

CMakeFiles/texture_test.dir/Camera.cpp.o.provides: CMakeFiles/texture_test.dir/Camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/texture_test.dir/build.make CMakeFiles/texture_test.dir/Camera.cpp.o.provides.build
.PHONY : CMakeFiles/texture_test.dir/Camera.cpp.o.provides

CMakeFiles/texture_test.dir/Camera.cpp.o.provides.build: CMakeFiles/texture_test.dir/Camera.cpp.o

CMakeFiles/texture_test.dir/Image.cpp.o: CMakeFiles/texture_test.dir/flags.make
CMakeFiles/texture_test.dir/Image.cpp.o: /mnt/h/CS455/source/Image.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/h/CS455/linuxbuild/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/texture_test.dir/Image.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/texture_test.dir/Image.cpp.o -c /mnt/h/CS455/source/Image.cpp

CMakeFiles/texture_test.dir/Image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture_test.dir/Image.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/h/CS455/source/Image.cpp > CMakeFiles/texture_test.dir/Image.cpp.i

CMakeFiles/texture_test.dir/Image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture_test.dir/Image.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/h/CS455/source/Image.cpp -o CMakeFiles/texture_test.dir/Image.cpp.s

CMakeFiles/texture_test.dir/Image.cpp.o.requires:
.PHONY : CMakeFiles/texture_test.dir/Image.cpp.o.requires

CMakeFiles/texture_test.dir/Image.cpp.o.provides: CMakeFiles/texture_test.dir/Image.cpp.o.requires
	$(MAKE) -f CMakeFiles/texture_test.dir/build.make CMakeFiles/texture_test.dir/Image.cpp.o.provides.build
.PHONY : CMakeFiles/texture_test.dir/Image.cpp.o.provides

CMakeFiles/texture_test.dir/Image.cpp.o.provides.build: CMakeFiles/texture_test.dir/Image.cpp.o

CMakeFiles/texture_test.dir/ObjUtilities.cpp.o: CMakeFiles/texture_test.dir/flags.make
CMakeFiles/texture_test.dir/ObjUtilities.cpp.o: /mnt/h/CS455/source/ObjUtilities.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/h/CS455/linuxbuild/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/texture_test.dir/ObjUtilities.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/texture_test.dir/ObjUtilities.cpp.o -c /mnt/h/CS455/source/ObjUtilities.cpp

CMakeFiles/texture_test.dir/ObjUtilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture_test.dir/ObjUtilities.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/h/CS455/source/ObjUtilities.cpp > CMakeFiles/texture_test.dir/ObjUtilities.cpp.i

CMakeFiles/texture_test.dir/ObjUtilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture_test.dir/ObjUtilities.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/h/CS455/source/ObjUtilities.cpp -o CMakeFiles/texture_test.dir/ObjUtilities.cpp.s

CMakeFiles/texture_test.dir/ObjUtilities.cpp.o.requires:
.PHONY : CMakeFiles/texture_test.dir/ObjUtilities.cpp.o.requires

CMakeFiles/texture_test.dir/ObjUtilities.cpp.o.provides: CMakeFiles/texture_test.dir/ObjUtilities.cpp.o.requires
	$(MAKE) -f CMakeFiles/texture_test.dir/build.make CMakeFiles/texture_test.dir/ObjUtilities.cpp.o.provides.build
.PHONY : CMakeFiles/texture_test.dir/ObjUtilities.cpp.o.provides

CMakeFiles/texture_test.dir/ObjUtilities.cpp.o.provides.build: CMakeFiles/texture_test.dir/ObjUtilities.cpp.o

CMakeFiles/texture_test.dir/Heightmap.cpp.o: CMakeFiles/texture_test.dir/flags.make
CMakeFiles/texture_test.dir/Heightmap.cpp.o: /mnt/h/CS455/source/Heightmap.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/h/CS455/linuxbuild/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/texture_test.dir/Heightmap.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/texture_test.dir/Heightmap.cpp.o -c /mnt/h/CS455/source/Heightmap.cpp

CMakeFiles/texture_test.dir/Heightmap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture_test.dir/Heightmap.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/h/CS455/source/Heightmap.cpp > CMakeFiles/texture_test.dir/Heightmap.cpp.i

CMakeFiles/texture_test.dir/Heightmap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture_test.dir/Heightmap.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/h/CS455/source/Heightmap.cpp -o CMakeFiles/texture_test.dir/Heightmap.cpp.s

CMakeFiles/texture_test.dir/Heightmap.cpp.o.requires:
.PHONY : CMakeFiles/texture_test.dir/Heightmap.cpp.o.requires

CMakeFiles/texture_test.dir/Heightmap.cpp.o.provides: CMakeFiles/texture_test.dir/Heightmap.cpp.o.requires
	$(MAKE) -f CMakeFiles/texture_test.dir/build.make CMakeFiles/texture_test.dir/Heightmap.cpp.o.provides.build
.PHONY : CMakeFiles/texture_test.dir/Heightmap.cpp.o.provides

CMakeFiles/texture_test.dir/Heightmap.cpp.o.provides.build: CMakeFiles/texture_test.dir/Heightmap.cpp.o

CMakeFiles/texture_test.dir/libtwodee/Log.cpp.o: CMakeFiles/texture_test.dir/flags.make
CMakeFiles/texture_test.dir/libtwodee/Log.cpp.o: /mnt/h/CS455/source/libtwodee/Log.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/h/CS455/linuxbuild/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/texture_test.dir/libtwodee/Log.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/texture_test.dir/libtwodee/Log.cpp.o -c /mnt/h/CS455/source/libtwodee/Log.cpp

CMakeFiles/texture_test.dir/libtwodee/Log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture_test.dir/libtwodee/Log.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/h/CS455/source/libtwodee/Log.cpp > CMakeFiles/texture_test.dir/libtwodee/Log.cpp.i

CMakeFiles/texture_test.dir/libtwodee/Log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture_test.dir/libtwodee/Log.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/h/CS455/source/libtwodee/Log.cpp -o CMakeFiles/texture_test.dir/libtwodee/Log.cpp.s

CMakeFiles/texture_test.dir/libtwodee/Log.cpp.o.requires:
.PHONY : CMakeFiles/texture_test.dir/libtwodee/Log.cpp.o.requires

CMakeFiles/texture_test.dir/libtwodee/Log.cpp.o.provides: CMakeFiles/texture_test.dir/libtwodee/Log.cpp.o.requires
	$(MAKE) -f CMakeFiles/texture_test.dir/build.make CMakeFiles/texture_test.dir/libtwodee/Log.cpp.o.provides.build
.PHONY : CMakeFiles/texture_test.dir/libtwodee/Log.cpp.o.provides

CMakeFiles/texture_test.dir/libtwodee/Log.cpp.o.provides.build: CMakeFiles/texture_test.dir/libtwodee/Log.cpp.o

CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.o: CMakeFiles/texture_test.dir/flags.make
CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.o: /mnt/h/CS455/source/libtwodee/MessagedException.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/h/CS455/linuxbuild/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.o -c /mnt/h/CS455/source/libtwodee/MessagedException.cpp

CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/h/CS455/source/libtwodee/MessagedException.cpp > CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.i

CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/h/CS455/source/libtwodee/MessagedException.cpp -o CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.s

CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.o.requires:
.PHONY : CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.o.requires

CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.o.provides: CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.o.requires
	$(MAKE) -f CMakeFiles/texture_test.dir/build.make CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.o.provides.build
.PHONY : CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.o.provides

CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.o.provides.build: CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.o

CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.o: CMakeFiles/texture_test.dir/flags.make
CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.o: /mnt/h/CS455/source/libtwodee/ShaderProgram.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/h/CS455/linuxbuild/CMakeFiles $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.o -c /mnt/h/CS455/source/libtwodee/ShaderProgram.cpp

CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/h/CS455/source/libtwodee/ShaderProgram.cpp > CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.i

CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/h/CS455/source/libtwodee/ShaderProgram.cpp -o CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.s

CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.o.requires:
.PHONY : CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.o.requires

CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.o.provides: CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.o.requires
	$(MAKE) -f CMakeFiles/texture_test.dir/build.make CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.o.provides.build
.PHONY : CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.o.provides

CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.o.provides.build: CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.o

CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.o: CMakeFiles/texture_test.dir/flags.make
CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.o: /mnt/h/CS455/source/libtwodee/Utilities.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/h/CS455/linuxbuild/CMakeFiles $(CMAKE_PROGRESS_14)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.o -c /mnt/h/CS455/source/libtwodee/Utilities.cpp

CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/h/CS455/source/libtwodee/Utilities.cpp > CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.i

CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/h/CS455/source/libtwodee/Utilities.cpp -o CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.s

CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.o.requires:
.PHONY : CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.o.requires

CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.o.provides: CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.o.requires
	$(MAKE) -f CMakeFiles/texture_test.dir/build.make CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.o.provides.build
.PHONY : CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.o.provides

CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.o.provides.build: CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.o

CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.o: CMakeFiles/texture_test.dir/flags.make
CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.o: /mnt/h/CS455/source/libtwodee/UtilitiesOpenGL.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/h/CS455/linuxbuild/CMakeFiles $(CMAKE_PROGRESS_15)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.o -c /mnt/h/CS455/source/libtwodee/UtilitiesOpenGL.cpp

CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/h/CS455/source/libtwodee/UtilitiesOpenGL.cpp > CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.i

CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/h/CS455/source/libtwodee/UtilitiesOpenGL.cpp -o CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.s

CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.o.requires:
.PHONY : CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.o.requires

CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.o.provides: CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.o.requires
	$(MAKE) -f CMakeFiles/texture_test.dir/build.make CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.o.provides.build
.PHONY : CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.o.provides

CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.o.provides.build: CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.o

CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.o: CMakeFiles/texture_test.dir/flags.make
CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.o: /mnt/h/CS455/source/libtwodee/VertexArray.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/h/CS455/linuxbuild/CMakeFiles $(CMAKE_PROGRESS_16)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.o -c /mnt/h/CS455/source/libtwodee/VertexArray.cpp

CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/h/CS455/source/libtwodee/VertexArray.cpp > CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.i

CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/h/CS455/source/libtwodee/VertexArray.cpp -o CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.s

CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.o.requires:
.PHONY : CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.o.requires

CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.o.provides: CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.o.requires
	$(MAKE) -f CMakeFiles/texture_test.dir/build.make CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.o.provides.build
.PHONY : CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.o.provides

CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.o.provides.build: CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.o

CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.o: CMakeFiles/texture_test.dir/flags.make
CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.o: /mnt/h/CS455/source/libtwodee/VertexAttributes.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/h/CS455/linuxbuild/CMakeFiles $(CMAKE_PROGRESS_17)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.o -c /mnt/h/CS455/source/libtwodee/VertexAttributes.cpp

CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/h/CS455/source/libtwodee/VertexAttributes.cpp > CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.i

CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/h/CS455/source/libtwodee/VertexAttributes.cpp -o CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.s

CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.o.requires:
.PHONY : CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.o.requires

CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.o.provides: CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.o.requires
	$(MAKE) -f CMakeFiles/texture_test.dir/build.make CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.o.provides.build
.PHONY : CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.o.provides

CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.o.provides.build: CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.o

# Object files for target texture_test
texture_test_OBJECTS = \
"CMakeFiles/texture_test.dir/texture_test.cpp.o" \
"CMakeFiles/texture_test.dir/TextureRenderer.cpp.o" \
"CMakeFiles/texture_test.dir/glut_utilities.cpp.o" \
"CMakeFiles/texture_test.dir/BaseRenderer.cpp.o" \
"CMakeFiles/texture_test.dir/Vector4.cpp.o" \
"CMakeFiles/texture_test.dir/Matrix4.cpp.o" \
"CMakeFiles/texture_test.dir/Camera.cpp.o" \
"CMakeFiles/texture_test.dir/Image.cpp.o" \
"CMakeFiles/texture_test.dir/ObjUtilities.cpp.o" \
"CMakeFiles/texture_test.dir/Heightmap.cpp.o" \
"CMakeFiles/texture_test.dir/libtwodee/Log.cpp.o" \
"CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.o" \
"CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.o" \
"CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.o" \
"CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.o" \
"CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.o" \
"CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.o"

# External object files for target texture_test
texture_test_EXTERNAL_OBJECTS =

texture_test: CMakeFiles/texture_test.dir/texture_test.cpp.o
texture_test: CMakeFiles/texture_test.dir/TextureRenderer.cpp.o
texture_test: CMakeFiles/texture_test.dir/glut_utilities.cpp.o
texture_test: CMakeFiles/texture_test.dir/BaseRenderer.cpp.o
texture_test: CMakeFiles/texture_test.dir/Vector4.cpp.o
texture_test: CMakeFiles/texture_test.dir/Matrix4.cpp.o
texture_test: CMakeFiles/texture_test.dir/Camera.cpp.o
texture_test: CMakeFiles/texture_test.dir/Image.cpp.o
texture_test: CMakeFiles/texture_test.dir/ObjUtilities.cpp.o
texture_test: CMakeFiles/texture_test.dir/Heightmap.cpp.o
texture_test: CMakeFiles/texture_test.dir/libtwodee/Log.cpp.o
texture_test: CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.o
texture_test: CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.o
texture_test: CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.o
texture_test: CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.o
texture_test: CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.o
texture_test: CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.o
texture_test: CMakeFiles/texture_test.dir/build.make
texture_test: /usr/lib/x86_64-linux-gnu/libglut.so
texture_test: /usr/lib/x86_64-linux-gnu/libXmu.so
texture_test: /usr/lib/x86_64-linux-gnu/libXi.so
texture_test: /usr/lib/x86_64-linux-gnu/libGLEW.so
texture_test: /usr/lib/x86_64-linux-gnu/libGLU.so
texture_test: /usr/lib/x86_64-linux-gnu/libGL.so
texture_test: /usr/lib/x86_64-linux-gnu/libSM.so
texture_test: /usr/lib/x86_64-linux-gnu/libICE.so
texture_test: /usr/lib/x86_64-linux-gnu/libX11.so
texture_test: /usr/lib/x86_64-linux-gnu/libXext.so
texture_test: CMakeFiles/texture_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable texture_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/texture_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/texture_test.dir/build: texture_test
.PHONY : CMakeFiles/texture_test.dir/build

CMakeFiles/texture_test.dir/requires: CMakeFiles/texture_test.dir/texture_test.cpp.o.requires
CMakeFiles/texture_test.dir/requires: CMakeFiles/texture_test.dir/TextureRenderer.cpp.o.requires
CMakeFiles/texture_test.dir/requires: CMakeFiles/texture_test.dir/glut_utilities.cpp.o.requires
CMakeFiles/texture_test.dir/requires: CMakeFiles/texture_test.dir/BaseRenderer.cpp.o.requires
CMakeFiles/texture_test.dir/requires: CMakeFiles/texture_test.dir/Vector4.cpp.o.requires
CMakeFiles/texture_test.dir/requires: CMakeFiles/texture_test.dir/Matrix4.cpp.o.requires
CMakeFiles/texture_test.dir/requires: CMakeFiles/texture_test.dir/Camera.cpp.o.requires
CMakeFiles/texture_test.dir/requires: CMakeFiles/texture_test.dir/Image.cpp.o.requires
CMakeFiles/texture_test.dir/requires: CMakeFiles/texture_test.dir/ObjUtilities.cpp.o.requires
CMakeFiles/texture_test.dir/requires: CMakeFiles/texture_test.dir/Heightmap.cpp.o.requires
CMakeFiles/texture_test.dir/requires: CMakeFiles/texture_test.dir/libtwodee/Log.cpp.o.requires
CMakeFiles/texture_test.dir/requires: CMakeFiles/texture_test.dir/libtwodee/MessagedException.cpp.o.requires
CMakeFiles/texture_test.dir/requires: CMakeFiles/texture_test.dir/libtwodee/ShaderProgram.cpp.o.requires
CMakeFiles/texture_test.dir/requires: CMakeFiles/texture_test.dir/libtwodee/Utilities.cpp.o.requires
CMakeFiles/texture_test.dir/requires: CMakeFiles/texture_test.dir/libtwodee/UtilitiesOpenGL.cpp.o.requires
CMakeFiles/texture_test.dir/requires: CMakeFiles/texture_test.dir/libtwodee/VertexArray.cpp.o.requires
CMakeFiles/texture_test.dir/requires: CMakeFiles/texture_test.dir/libtwodee/VertexAttributes.cpp.o.requires
.PHONY : CMakeFiles/texture_test.dir/requires

CMakeFiles/texture_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/texture_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/texture_test.dir/clean

CMakeFiles/texture_test.dir/depend:
	cd /mnt/h/CS455/linuxbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/h/CS455/source /mnt/h/CS455/source /mnt/h/CS455/linuxbuild /mnt/h/CS455/linuxbuild /mnt/h/CS455/linuxbuild/CMakeFiles/texture_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/texture_test.dir/depend

