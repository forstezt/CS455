#include <iostream>

#include "Log.h"
#include "Utilities.h"
#include "UtilitiesOpenGL.h"

namespace td {

bool OpenGL::is_glew_initialized = false;

/* ------------------------------------------------------------------------- */

GLuint OpenGL::CompileGLSLFile(GLenum shader_type, const char *path) {
  char *code = Utilities::FileToString(std::string(path));
  GLuint sid = CompileGLSL(shader_type, code);
  delete[] code;
  return sid;
}

/* ------------------------------------------------------------------------- */

GLuint OpenGL::CompileGLSL(GLenum shader_type, const char *src) {
  GLint succeeded;
  GLuint sid;

#if 0
  std::string glsl_version = std::string((const char *) glGetString(GL_SHADING_LANGUAGE_VERSION));
  glsl_version = glsl_version.substr(0, glsl_version.find_first_of(" "));

  std::string older_src;
  if (glsl_version == "1.30") {
    older_src = src;

    // Replace #version line with #version 130
    size_t i = older_src.find_first_of("\n");
    older_src = older_src.replace(0, i, "#version 130");

    src = older_src.c_str();
    std::cout << "src: " << src << std::endl;
  }
#endif

  sid = glCreateShader(shader_type);
  // TODO why need a cast?
#ifdef ANDROID
  glShaderSource(sid, 1, &src, NULL);
#else
  glShaderSource(sid, 1, (const GLchar **) &src, NULL);
#endif
  glCompileShader(sid);
  glGetShaderiv(sid, GL_COMPILE_STATUS, &succeeded);

  GLint log_length;
  glGetShaderiv(sid, GL_INFO_LOG_LENGTH, &log_length);

  if (log_length > 1) {
    char *log = new char[log_length];
    GLint chars_written;
    glGetShaderInfoLog(sid, log_length, &chars_written, log);
    std::cerr << log << std::endl;
    delete[] log;
  }

  if (succeeded != GL_TRUE) {
    Log::Error(src);
    Log::Error("Something went wrong with the shader.");
  }

  return sid;  
}

/* ------------------------------------------------------------------------- */

void OpenGL::LinkGLSL(GLuint pid, GLuint vertex_sid, GLuint fragment_sid, GLuint geo_sid) {
  glAttachShader(pid, vertex_sid);
  if (geo_sid) {
    glAttachShader(pid, geo_sid);
  }
  glAttachShader(pid, fragment_sid);
  glLinkProgram(pid);

  GLint succeeded;
  glGetProgramiv(pid, GL_LINK_STATUS, &succeeded);
  if (succeeded != GL_TRUE) {
    GLint log_length;
    glGetProgramiv(pid, GL_INFO_LOG_LENGTH, &log_length);

    if (log_length) {
      char *log = new char[log_length];
      GLint chars_written;
      glGetProgramInfoLog(pid, log_length, &chars_written, log);
      Log::Error(log);
      delete[] log;
    } else {
      Log::Error("Something went wrong with the shader.");
    }
  }
}

/* ------------------------------------------------------------------------- */

void OpenGL::CheckError(const std::string& label) {
  for (GLint error = glGetError(); error; error = glGetError()) {
    Log::Error("%s: %x", label.c_str(), error);
  }  
}

/* ------------------------------------------------------------------------- */

void OpenGL::SetupGLEW() {
  if (is_glew_initialized) {
    return;
  }

  glewExperimental = GL_TRUE;
  GLenum err = glewInit();
  if (GLEW_OK != err) {
     std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
  } else {
    is_glew_initialized = true;
  }
}

/* ------------------------------------------------------------------------- */

}
