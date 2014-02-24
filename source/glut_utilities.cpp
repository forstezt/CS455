#include <cstring>
#include <iostream>

#include "glut_utilities.h"
#include "Keys.h"
#include "KeyIndices.h"
#include "MessagedException.h"
#include "UtilitiesOpenGL.h"

#include <GL/glut.h>

/* ------------------------------------------------------------------------- */

td::BaseRenderer *renderer = NULL;

bool key_states[10];

enum mouse_button_t {
  MOUSE_LEFT,
  MOUSE_RIGHT,
  MOUSE_MIDDLE,
  MOUSE_NONE
};

mouse_button_t mouse_button;

/* ------------------------------------------------------------------------- */
/* FUNCTION PROTOTYPES                                                       */
/* ------------------------------------------------------------------------- */

void on_cleanup();
void on_mouse(int button,
              int state,
              int x,
              int y);
void on_mouse_dragged(int x,
                      int y);
void on_key(unsigned char key,
            int x,
            int y);
void on_special_key(int key,
                    int x,
                    int y);
void on_mouse(int button,
              int x,
              int y);
void on_size_changed(int width,
                     int height);
void on_draw();


void on_keys(unsigned char key,
            int x,
            int y);
void on_keys_up(unsigned char key,
            int x,
            int y);

void on_special_keys(int key,
                    int x,
                    int y);
void on_special_keys_up(int key,
                    int x,
                    int y);

int then;

/* ------------------------------------------------------------------------- */

void glut_render(td::BaseRenderer *given_renderer) {

  for(int i = 0; i < 10; i++) {
	  key_states[i] = false;
  }

  renderer = given_renderer;
  atexit(on_cleanup);

  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowSize(512, 512);
  glutInitWindowPosition(50, 50);

  int argc = 1;
  char *argv[1];
  argv[0] = (char *) malloc(20 * sizeof(char));
  strcpy(argv[0], "cs455.exe");
  glutInit(&argc, argv);

  then = glutGet(GLUT_ELAPSED_TIME);

  glutCreateWindow("...");
  glutDisplayFunc(on_draw);
  glutIdleFunc(on_draw);
  glutReshapeFunc(on_size_changed);


  glutIgnoreKeyRepeat(1);

  //glutKeyboardFunc(on_key);
  //glutSpecialFunc(on_special_key);

  glutKeyboardFunc(on_keys);
  glutKeyboardUpFunc(on_keys_up);
  glutSpecialFunc(on_special_keys);
  glutSpecialUpFunc(on_special_keys_up);


  glutMouseFunc(on_mouse);
  glutMotionFunc(on_mouse_dragged);

  try {
    td::OpenGL::SetupGLEW();
    renderer->OnInitialize();
    glutMainLoop();
  } catch (td::MessagedException e) {
    std::cerr << "EXCEPTION: " << e.what() << std::endl;
  }
}

/* ------------------------------------------------------------------------- */

void on_cleanup() {
  delete renderer;
}

/* ------------------------------------------------------------------------- */

void on_draw() {
  int now = glutGet(GLUT_ELAPSED_TIME);
  renderer->OnKeys(key_states);
  //renderer->OnDraw();
  renderer->OnDraw((now - then) / 1000.0f);
  then = now;
  glutSwapBuffers();
}

/* ------------------------------------------------------------------------- */

void on_size_changed(int width,
                     int height) {
  renderer->OnSizeChanged(width, height);
  glutPostRedisplay();
}

/* ------------------------------------------------------------------------- */

void on_mouse(int button,
              int state,
              int x,
              int y) {
  y = renderer->GetHeight() - y;
  if (state == GLUT_DOWN) {
    if (button == GLUT_LEFT_BUTTON) {
      renderer->OnLeftMouseDown(x, y);
      mouse_button = MOUSE_LEFT;
    } else if (button == GLUT_RIGHT_BUTTON) {
      renderer->OnRightMouseDown(x, y);
      mouse_button = MOUSE_RIGHT;
    } else if (button == GLUT_MIDDLE_BUTTON) {
      renderer->OnMiddleMouseDown(x, y);
      mouse_button = MOUSE_MIDDLE;
    }
  } else if (state == GLUT_UP) {
    if (button == GLUT_LEFT_BUTTON) {
      renderer->OnLeftMouseUp(x, y);
    } else if (button == GLUT_RIGHT_BUTTON) {
      renderer->OnRightMouseUp(x, y);
    } else if (button == GLUT_MIDDLE_BUTTON) {
      renderer->OnMiddleMouseUp(x, y);
    }
    mouse_button = MOUSE_NONE;
  }

  glutPostRedisplay();
}

/* ------------------------------------------------------------------------- */

void on_mouse_dragged(int x,
                      int y) {
  y = renderer->GetHeight() - y;

  if (mouse_button == MOUSE_LEFT) {
    renderer->OnLeftMouseDragged(x, y);
  } else if (mouse_button == MOUSE_RIGHT) {
    renderer->OnRightMouseDragged(x, y);
  } else if (mouse_button == MOUSE_MIDDLE) {
    renderer->OnMiddleMouseDragged(x, y);
  }

  glutPostRedisplay();
}

/* ------------------------------------------------------------------------- */

void on_key(unsigned char key,
            int x,
            int y) {
  if (key == 27) {
    exit(0);
  } else {
    renderer->OnKey((td::Keys::key_t) key);
    glutPostRedisplay();
  }
}


void on_keys(unsigned char key,
            int x,
            int y) {
  if (key == 27) {
    exit(0);
  } else if (key == 'w') {
	  key_states[td::KeyStates::key_w] = true;
  } else if (key == 's') {
	  key_states[td::KeyStates::key_s] = true;
  } else if (key == 'a') {
	  key_states[td::KeyStates::key_a] = true;
  } else if (key == 'd') {
	  key_states[td::KeyStates::key_d] = true;
  } else if (key == 'f') {
	  key_states[td::KeyStates::key_f] = true;
  } else if (key == 'F') {
	  key_states[td::KeyStates::key_F] = true;
  }

  //renderer->OnKeys(key_states);
  glutPostRedisplay();
}

void on_keys_up(unsigned char key,
            int x,
            int y) {
  if (key == 27) {
    exit(0);
  } else if (key == 'w') {
	  key_states[td::KeyStates::key_w] = false;
  } else if (key == 's') {
	  key_states[td::KeyStates::key_s] = false;
  } else if (key == 'a') {
	  key_states[td::KeyStates::key_a] = false;
  } else if (key == 'd') {
	  key_states[td::KeyStates::key_d] = false;
  } else if (key == 'f') {
	  key_states[td::KeyStates::key_f] = false;
  } else if (key == 'F') {
	  key_states[td::KeyStates::key_F] = false;
  }

  //renderer->OnKeys(key_states);
  glutPostRedisplay();
}
/* ------------------------------------------------------------------------- */

void on_special_key(int glut_key,
                    int x,
                    int y) {
  td::Keys::key_t key;

  if (glut_key == GLUT_KEY_PAGE_UP) {
	  key = td::Keys::PAGEUP;
  } else if(glut_key == GLUT_KEY_LEFT) {
	  key = td::Keys::LEFT;
  } else if(glut_key == GLUT_KEY_RIGHT) {
	  key = td::Keys::RIGHT;
  } else if(glut_key == GLUT_KEY_UP) {
	key = td::Keys::UP;
  } else if(glut_key == GLUT_KEY_DOWN) {
	key = td::Keys::DOWN;
  }
  // TODO: handle other keys

  renderer->OnKey(key);

  glutPostRedisplay();
}


void on_special_keys(int glut_key,
                    int x,
                    int y) {
  if(glut_key == GLUT_KEY_LEFT) {
	  key_states[td::KeyStates::key_left] = true;
  } else if(glut_key == GLUT_KEY_RIGHT) {
	  key_states[td::KeyStates::key_right] = true;
  } else if(glut_key == GLUT_KEY_UP) {
	  key_states[td::KeyStates::key_up] = true;
  } else if(glut_key == GLUT_KEY_DOWN) {
	  key_states[td::KeyStates::key_down] = true;
  }
  // TODO: handle other keys

  //renderer->OnKeys(key_states);

  glutPostRedisplay();
}

void on_special_keys_up(int glut_key,
                    int x,
                    int y) {
  if(glut_key == GLUT_KEY_LEFT) {
	  key_states[td::KeyStates::key_left] = false;
  } else if(glut_key == GLUT_KEY_RIGHT) {
	  key_states[td::KeyStates::key_right] = false;
  } else if(glut_key == GLUT_KEY_UP) {
	  key_states[td::KeyStates::key_up] = false;
  } else if(glut_key == GLUT_KEY_DOWN) {
	  key_states[td::KeyStates::key_down] = false;
  }
  // TODO: handle other keys

  //renderer->OnKeys(key_states);

  glutPostRedisplay();
}

/* ------------------------------------------------------------------------- */
