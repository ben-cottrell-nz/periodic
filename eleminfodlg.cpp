//
// Created by ben on 14/11/21.
//

#include "eleminfodlg.h"
#include "appdatamanager.h"
#include "cinder/gl/Shader.h"
#include "cinder/Timeline.h"

void ElemInfoDlg::draw() {
    gl::color(1, 1, 1, 0);
    AppDataManager::EntrySymbolInfo entry = AppDataManagerInstance()->entries().at(mText);
    string text;
    auto v = AppDataManagerInstance()->entrySymbolInfoKeys();
    int y = 1;
    for (int i = 0; i < v.size(); i++) {
        text.clear();
        text += v[i] + ": ";
        text += entry.values[i];
        gl::drawString(text, {0, mFont.getAscent() * 1.2 * y},
                       ColorA(1, 1, 1, mAlpha), mFont);
        y += 1;
    }

}

bool ElemInfoDlg::isVisible() {
    return mVisible;
}

void ElemInfoDlg::resize() {

}

void ElemInfoDlg::setup() {
    mAlpha = 0;
    mFont = Font(loadAsset("Lato-Bold.ttf"), 27);
    //mBatch = gl::Batch(geom::Sphere(), gl::getStockShader())
}

void ElemInfoDlg::mouseDown(MouseEvent &event) {
    transitionLeave();
}

void ElemInfoDlg::setVisible(bool v) {
    mVisible = v;
}

void ElemInfoDlg::setText(string &text) {
    mText = text;
}

void ElemInfoDlg::transitionEnter() {
    mAlpha = 0;
    timeline().apply(&mAlpha, 12.f, 0.6, EaseInCubic());
}

void ElemInfoDlg::transitionLeave() {
    timeline().apply(&mAlpha, 0.f, 0.6, EaseOutCubic()).finishFn([this](){
        mVisible = false;
    });
}
