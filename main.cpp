#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/svg/Svg.h"
#include "cinder/ip/Fill.h"
#include "cinder/Text.h"
#include "cinder/cairo/Cairo.h"
#include <optional>

using namespace ci;
using namespace ci::app;
using namespace std;

class SimpleViewerApp : public App {
public:
    void setup();

    void mouseDown(MouseEvent event);

    void draw();
    void render();

    void resize();

    struct Entry {
        Rectf pos;
        string elemSymbol;
    };
    vector<Entry> entries;
    Font mFont;
    gl::TextureRef mTextTexture;
    float entryWidth, entryHeight;
    const int COLUMNS = 18;
    const int ROWS = 9;
};

static const char* elemSymbols[] = {
        "H", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "He",
        "Li", "Be", "", "", "", "", "", "", "", "", "", "", "B", "C", "N", "O", "F", "Ne",
        "Na", "Mg", "", "", "", "", "", "", "", "", "", "", "Al", "Si", "P", "S", "Cl", "Ar",
        "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr",
        "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe",
        "Cs", "Ba", "", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn",
        "Fr", "Ra", "", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og",
        "", "", "", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu",
        "", "", "", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr"
};

void SimpleViewerApp::setup() {

    ivec2 windowSize = getWindowSize();
    int y, x, index;
    entryWidth = windowSize.x / COLUMNS;
    entryHeight = windowSize.y / ROWS;
    for (y = 0; y < ROWS; ++y) {
        for (x = 0; x < COLUMNS; ++x) {
            index = (y * ROWS) + x;
            if (elemSymbols[index] != 0) {
                entries.push_back(Entry{
                        Rectf{x * entryWidth, y * entryHeight, (x * entryWidth) + entryWidth,
                              (y * entryWidth) + entryHeight},
                          elemSymbols[index]
                });
            }
        }
    }

}

void SimpleViewerApp::mouseDown(MouseEvent event) {

}

void SimpleViewerApp::draw() {
    // clear out the window with black
    gl::clear(Color::gray(0.5f));
    gl::enableAlphaBlending();
    gl::setMatricesWindow(getWindowSize());

//    for (auto &e : entries) {
//        //gl::drawSolidRect(e.pos, e.pos.getUpperLeft(), e.pos.getLowerRight());
//        gl::drawString(e.elemSymbol, e.pos.getCenter(), ColorA(1, 1, 1, 1), ft);
//    }

}

void SimpleViewerApp::resize() {
    ivec2 windowSize = getWindowSize();
    entryWidth = windowSize.x / COLUMNS;
    entryHeight = windowSize.y / ROWS;
}

void SimpleViewerApp::render() {
    TextBox tbox = TextBox().alignment(TextBox::LEFT).font(mFont).size(
            getWindowSize()).text("periodic table");
    mTextTexture = gl::Texture2d::create(tbox.render());
}


CINDER_APP(SimpleViewerApp, RendererGl)