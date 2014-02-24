#ifndef BASERENDERER_H
#define BASERENDERER_H

#include "Keys.h"
#include "UtilitiesOpenGL.h"
#include "VertexArray.h"
#include <vector>

namespace td {

/* ------------------------------------------------------------------------- */

class BaseRenderer {
  public:
    BaseRenderer();
    ~BaseRenderer();

    int GetWidth() const;
    int GetHeight() const;
    float GetAspectRatio() const;

    virtual void OnSizeChanged(int width, int height);
    void SetBackgroundColor(float r, float g, float b, float a);
    virtual void OnInitialize();
    virtual void OnDraw();
	virtual void OnDraw(float delta_time);

    virtual void OnKey(td::Keys::key_t key);
	virtual void OnKeys(bool* key_states);
    virtual void OnLeftMouseDown(int x, int y);
    virtual void OnLeftMouseUp(int x, int y);
    virtual void OnLeftMouseDragged(int x, int y);
    virtual void OnRightMouseDown(int x, int y);
    virtual void OnRightMouseUp(int x, int y);
    virtual void OnRightMouseDragged(int x, int y);
    virtual void OnMiddleMouseDown(int x, int y);
    virtual void OnMiddleMouseUp(int x, int y);
    virtual void OnMiddleMouseDragged(int x, int y);

  private:
    float background_color[4];
	td::VertexAttributes* attributes;
	td::ShaderProgram* program;
	td::VertexArray* triangle;
	bool mouse_down;
	int width;
    int height;

};

/* ------------------------------------------------------------------------- */

}

#endif
