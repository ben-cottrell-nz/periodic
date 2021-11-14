//
// Created by ben on 14/11/21.
//

#include "table.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace ci;
using namespace ci::app;

static const vector<vector<string>> elemSymbols = {
        {"H",  "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "He"},
        {"Li", "Be", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "B",  "C",  "N",  "O",  "F",  "Ne"},
        {"Na", "Mg", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "Al", "Si", "P",  "S",  "Cl", "Ar"},
        {"K",  "Ca", "Sc", "Ti", "V",  "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr"},
        {"Rb", "Sr", "Y",  "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I",  "Xe"},
        {"Cs", "Ba", "\t", "Hf", "Ta", "W",  "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn"},
        {"Fr", "Ra", "\t", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"},
        {"\t", "\t", "\t", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu"},
        {"\t", "\t", "\t", "Ac", "Th", "Pa", "U",  "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr"}
};
const int ROWS = 9;
const int COLUMNS = 18;
float entryWidth, entryHeight;

void Table::draw() {
    vec2 offset = vec2(0);
    int y, x;
    const int padding = 15;
    int index = 0;
    gl::color(Color::white());
    for (y = 0; y < ROWS; y++) {
        for (x = 0; x < COLUMNS; x++) {
            if (elemSymbols[y][x][0] != '\t') {
                gl::color(0.698, 0.875, 0.859);
                Entry &e = mEntries[index++];
                gl::drawSolidRoundedRect(e.pos, 5);
                gl::color(0.13, 0.13, 0.13);
                mTextureFont->drawString(elemSymbols[y][x],
                                         vec2{entryWidth * x, entryHeight * y + mTextureFont->getFont().getSize() * 2});
            }
        }
    }
}

bool Table::isVisible() {
    return mVisible;
}

void Table::mouseDown(MouseEvent &event, function<void(Entry*)> handler) {
    for (auto &e : mEntries) {
        if (e.pos.contains(event.getPos())) {
            mSelectedEntry = &e;
            handler(mSelectedEntry);
            //showElemInfoDialog();
        }
    }
}

void Table::resize() {
    ivec2 windowSize = getWindowSize();
    entryWidth = windowSize.x / COLUMNS;
    entryHeight = windowSize.y / ROWS;
    int y, x, index = 0;
    for (y = 0; y < ROWS; ++y) {
        for (x = 0; x < COLUMNS; ++x) {
            if (elemSymbols[y][x][0] != '\t') {
                mEntries[index++].pos = Rectf{entryWidth * x, entryHeight * y, entryWidth * x + entryWidth,
                                              entryHeight * y + entryHeight};
            }
        }
    }
}

void Table::setup() {
    ivec2 windowSize = getWindowSize();
    getWindow()->setTitle("Periodic");
    setWindowSize(1024, 768);
    int y, x, index;
    entryWidth = windowSize.x / COLUMNS;
    entryHeight = windowSize.y / ROWS;
    for (y = 0; y < ROWS; ++y) {
        for (x = 0; x < COLUMNS; ++x) {
            if (elemSymbols[y][x][0] != '\t') {
                mEntries.push_back(Entry{
                        Rectf{entryWidth * x, entryHeight * y, entryWidth * x + entryWidth,
                              entryHeight * y + entryHeight},
                        elemSymbols[y][x]
                });
            }
        }
    }
    mFont = Font("", max(entryWidth, entryHeight) * 0.5);
    mTextureFont = gl::TextureFont::create(mFont);
}

void Table::setVisible(bool v) {
    mVisible = v;
}
