//
// Created by ben on 14/11/21.
//

#ifndef PERIODIC_TABLE_H
#define PERIODIC_TABLE_H
#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Table {
public:
    void draw();
    bool isVisible();
    void setVisible(bool);
    void resize();
    void setup();
    struct Entry {
        Rectf pos;
        string elemSymbol;
    };
    void mouseDown(MouseEvent& event, function<void(Entry*)> handler);
private:
    Entry* mSelectedEntry;
    gl::TextureFontRef mTextureFont;
    bool mVisible;
    vector<Entry> mEntries;
    Font mFont;
};


#endif //PERIODIC_TABLE_H
