//
// Created by ben on 14/11/21.
//

#ifndef PERIODIC_ELEMINFODLG_H
#define PERIODIC_ELEMINFODLG_H
#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/Timeline.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class ElemInfoDlg {
public:
    void draw();
    bool isVisible();
    void setText(string& text);
    void setVisible(bool);
    void resize();
    void setup();
    void mouseDown(MouseEvent& event);
    void transitionEnter();
    void transitionLeave();
private:
    Anim<float> mAlpha;
    bool mVisible;
    string mText;
    Font mFont;
    gl::BatchRef mBatch;
};


#endif //PERIODIC_ELEMINFODLG_H
