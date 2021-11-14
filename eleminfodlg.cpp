//
// Created by ben on 14/11/21.
//

#include "eleminfodlg.h"
#include "appdatamanager.h"

void ElemInfoDlg::draw() {
    gl::color(Color::white());
    AppDataManager::EntrySymbolInfo entry = AppDataManagerInstance()->entries().at(mText);
    string text;
    auto v = AppDataManagerInstance()->entrySymbolInfoKeys();
    int y = 1;
    for (int i = 0; i < v.size(); i++) {
        text.clear();
        text += v[i] + ": ";
        text += entry.values[i];
        gl::drawString(text, {0, mFont.getAscent() * 1.2 * y}, Color::white(), mFont);
        y += 1;
    }

}

bool ElemInfoDlg::isVisible() {
    return mVisible;
}

void ElemInfoDlg::resize() {

}

void ElemInfoDlg::setup() {
    mFont = Font("", 27);
}

void ElemInfoDlg::mouseDown(MouseEvent &event) {
    setVisible(false);
}

void ElemInfoDlg::setVisible(bool v) {
    mVisible = v;
}

void ElemInfoDlg::setText(string &text) {
    mText = text;
}
