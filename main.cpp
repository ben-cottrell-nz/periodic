#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/svg/Svg.h"
#include "cinder/ip/Fill.h"
#include "cinder/Text.h"
#include "cinder/Timeline.h"
#include "json/json.h"
#include "table.h"
#include "eleminfodlg.h"
#include "appdatamanager.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class PeriodicApp : public App {
public:
    void setup();
    void mouseDown(MouseEvent event);
    void draw();
    void resize();
    struct Entry {
        Rectf pos;
        string elemSymbol;
    };
private:
    Table mTable;
    ElemInfoDlg mElemInfoDlg;
    Json::Value mJsonRoot;
};

void PeriodicApp::setup() {
    AppDataManagerInstance();
    mTable.setup();
    mTable.setVisible(true);
    mTable.transitionEnter();
    mElemInfoDlg.setup();
    mElemInfoDlg.setVisible(false);
}

void PeriodicApp::mouseDown(MouseEvent event) {
    cout << event.getPos();
    if (mElemInfoDlg.isVisible()) {
        mElemInfoDlg.mouseDown(event);
        mTable.transitionEnter();
        //mElemInfoDlg.setVisible(false);
    } else if (mTable.isVisible()) {
        mTable.mouseDown(event, [&](Table::Entry* entry){
            mTable.transitionLeave();
            mElemInfoDlg.setVisible(true);
            mElemInfoDlg.transitionEnter();
            mElemInfoDlg.setText(entry->elemSymbol);
        });
    }
}
//Font font("Times New Roman",72);
void PeriodicApp::draw() {
    gl::clear(Color::hex(0x222222));
    gl::enableAlphaBlending();
    gl::setMatricesWindow(getWindowSize());
    if (mElemInfoDlg.isVisible()) {
        mElemInfoDlg.draw();
    } else if (mTable.isVisible()) {
        mTable.draw();
    }
    /*gl::drawString(toString(floor(getAverageFps())) + " FPS",
                             vec2(10, getWindowHeight() - font.getDescent()));*/
}

void PeriodicApp::resize() {
    if (!mElemInfoDlg.isVisible()) {
        mTable.resize();
    }
}


CINDER_APP(PeriodicApp, RendererGl)