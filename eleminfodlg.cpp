//
// Created by ben on 14/11/21.
//

#include "eleminfodlg.h"

void ElemInfoDlg::draw() {
    gl::color(Color::white());
    gl::drawString(mText, {0, mFont.getAscent()*2});
}

bool ElemInfoDlg::isVisible() {
    return mVisible;
}

void ElemInfoDlg::resize() {

}

void ElemInfoDlg::setup() {
    mFont = Font("",27);
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
