cmake_minimum_required(VERSION 2.8)

project(CS455)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/" ${CMAKE_MODULE_PATH})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_C_FLAGS "-g -pedantic -Wall -std=c99")
  set(CMAKE_CXX_FLAGS "-g -pedantic -Wall -std=c++0x")
endif(CMAKE_COMPILER_IS_GNUCXX)

include_directories(libtwodee)

set(COMMON
  glut_utilities.cpp
  BaseRenderer.cpp
  Field3.h
  Vector4.cpp
  Matrix4.cpp
  Camera.cpp
  Image.cpp
  ObjUtilities.cpp
  Heightmap.cpp
  libtwodee/Log.cpp
  libtwodee/MessagedException.cpp
  libtwodee/ShaderProgram.cpp
  libtwodee/Utilities.cpp
  libtwodee/UtilitiesOpenGL.cpp
  libtwodee/VertexArray.cpp
  libtwodee/VertexAttributes.cpp
)

add_definitions(-DSHADERS_DIR="${CMAKE_CURRENT_SOURCE_DIR}/shaders")
add_definitions(-DOBJECTS_DIR="${CMAKE_CURRENT_SOURCE_DIR}/../Objects")

#add_executable(model_test model_test.cpp ModelRenderer.cpp ${COMMON})
#target_link_libraries(model_test ${GLUT_LIBRARIES} ${GLEW_LIBRARY} ${OPENGL_LIBRARIES})

#add_executable(spotlight_test spotlight_test.cpp SpotlightRenderer.cpp ${COMMON})
#target_link_libraries(spotlight_test ${GLUT_LIBRARIES} ${GLEW_LIBRARY} ${OPENGL_LIBRARIES})

#add_executable(circle_test circle_test.cpp CircleRenderer.cpp ${COMMON})
#target_link_libraries(circle_test ${GLUT_LIBRARIES} ${GLEW_LIBRARY} ${OPENGL_LIBRARIES})

#add_executable(spiral_test spiral_test.cpp ${COMMON})
#target_link_libraries(spiral_test ${GLUT_LIBRARIES} ${GLEW_LIBRARY} ${OPENGL_LIBRARIES})

add_executable(project_test project_test.cpp ProjectRenderer.cpp ${COMMON})
target_link_libraries(project_test ${GLUT_LIBRARIES} ${GLEW_LIBRARY} ${OPENGL_LIBRARIES})

#add_executable(trackball_test trackball_test.cpp TrackballRenderer.cpp ${COMMON})
#target_link_libraries(trackball_test ${GLUT_LIBRARIES} ${GLEW_LIBRARY} ${OPENGL_LIBRARIES})

#add_executable(texture_test texture_test.cpp TextureRenderer.cpp ${COMMON})
#target_link_libraries(texture_test ${GLUT_LIBRARIES} ${GLEW_LIBRARY} ${OPENGL_LIBRARIES})
