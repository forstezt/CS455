#include <iostream>

#include "BaseRenderer.h"

namespace td {

/* ------------------------------------------------------------------------- */

BaseRenderer::BaseRenderer() {
	mouse_down = false;
}

/* ------------------------------------------------------------------------- */

BaseRenderer::~BaseRenderer() {
}

/* ------------------------------------------------------------------------- */

void BaseRenderer::OnDraw() {

  glViewport(0, 0, width, height);
  glClearColor(background_color[0], background_color[1], background_color[2], background_color[3]);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

/* ------------------------------------------------------------------------- */

void BaseRenderer::OnDraw(float delta_time) {

  glViewport(0, 0, width, height);
  glClearColor(background_color[0], background_color[1], background_color[2], background_color[3]);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

/* ------------------------------------------------------------------------- */

void BaseRenderer::OnInitialize() {

}

/* ------------------------------------------------------------------------- */

int BaseRenderer::GetWidth() const {
  return width;
}

/* ------------------------------------------------------------------------- */

int BaseRenderer::GetHeight() const {
  return height;
}

/* ------------------------------------------------------------------------- */

void BaseRenderer::OnSizeChanged(int width, int height) {
  this->width = width;
  this->height = height;
}

/* ------------------------------------------------------------------------- */

void BaseRenderer::SetBackgroundColor(float r, float g, float b, float a) {
  background_color[0] = r;
  background_color[1] = g;
  background_color[2] = b;
  background_color[3] = a;
}

/* ------------------------------------------------------------------------- */

void BaseRenderer::OnKey(td::Keys::key_t key) {

}

/* ------------------------------------------------------------------------- */

void BaseRenderer::OnLeftMouseDown(int x, int y) {

  mouse_down = true;

}

/* ------------------------------------------------------------------------- */

void BaseRenderer::OnLeftMouseUp(int x, int y) {

  mouse_down = false;
}

/* ------------------------------------------------------------------------- */

void BaseRenderer::OnLeftMouseDragged(int x, int y) {

}

/* ------------------------------------------------------------------------- */

void BaseRenderer::OnRightMouseDown(int x, int y) {

  mouse_down = true;
}

/* ------------------------------------------------------------------------- */

void BaseRenderer::OnRightMouseUp(int x, int y) {

  mouse_down = false;
}

/* ------------------------------------------------------------------------- */

void BaseRenderer::OnRightMouseDragged(int x, int y) {

}

/* ------------------------------------------------------------------------- */

void BaseRenderer::OnMiddleMouseDown(int x, int y) {

  mouse_down = true;
}

/* ------------------------------------------------------------------------- */

void BaseRenderer::OnMiddleMouseUp(int x, int y) {

  mouse_down = false;
}

/* ------------------------------------------------------------------------- */

void BaseRenderer::OnMiddleMouseDragged(int x, int y) {

}

/* ------------------------------------------------------------------------- */

float BaseRenderer::GetAspectRatio() const {
	return GetWidth() / (float)GetHeight();
}

/* ------------------------------------------------------------------------- */

void BaseRenderer::OnKeys(bool* key_states) {

}
}
