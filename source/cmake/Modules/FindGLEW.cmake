#
# Try to find GLEW library and include path.
# Once done this will define
#
# GLEW_FOUND
# GLEW_INCLUDE_DIR
# GLEW_LIBRARY
# 

IF (WIN32)
  FIND_PATH( GLEW_INCLUDE_DIR GL/glew.h
    "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/include"
    $ENV{PROGRAMFILES}/GLEW/include
    ${PROJECT_SOURCE_DIR}/src/nvgl/glew/include
    DOC "The directory where GL/glew.h resides")
  FIND_LIBRARY( GLEW_LIBRARY
    NAMES glew GLEW glew32 glew32s
    PATHS
    "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/lib"
    $ENV{PROGRAMFILES}/GLEW/lib
    ${PROJECT_SOURCE_DIR}/src/nvgl/glew/bin
    ${PROJECT_SOURCE_DIR}/src/nvgl/glew/lib
    DOC "The GLEW library")
ELSE (WIN32)
  FIND_PATH( GLEW_INCLUDE_DIR GL/glew.h
    /usr/include
    /usr/local/include
    /sw/include
    /opt/local/include
    DOC "The directory where GL/glew.h resides")
  FIND_LIBRARY( GLEW_LIBRARY
    NAMES GLEW glew
    PATHS
    /usr/lib64
    /usr/lib
    /usr/local/lib64
    /usr/local/lib
    /sw/lib
    /opt/local/lib
    DOC "The GLEW library")
ENDIF (WIN32)

IF (GLEW_INCLUDE_DIR)
  SET( GLEW_FOUND 1 CACHE STRING "Set to 1 if GLEW is found, 0 otherwise")
ELSE (GLEW_INCLUDE_DIR)
  SET( GLEW_FOUND 0 CACHE STRING "Set to 1 if GLEW is found, 0 otherwise")
ENDIF (GLEW_INCLUDE_DIR)

MARK_AS_ADVANCED( GLEW_FOUND )

