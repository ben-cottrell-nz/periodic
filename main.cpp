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

    void resize();

    struct Entry {
        Rectf pos;
        string elemSymbol;
    };
    vector<Entry> entries;
    Font mFont;
    gl::TextureFontRef mTextureFont;
    float entryWidth, entryHeight;
    const int COLUMNS = 18;
    const int ROWS = 9;
};

static const vector<vector<string>> elemSymbols = {
        {"H", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "He"},
        {"Li", "Be", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "B", "C", "N", "O", "F", "Ne"},
        {"Na", "Mg", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "Al", "Si", "P", "S", "Cl", "Ar"},
        {"K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr"},
        {"Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe"},
        {"Cs", "Ba", "\t", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn"},
        {"Fr", "Ra", "\t", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"},
         {"\t", "\t", "\t", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu"},
         {"\t", "\t", "\t", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr"}
};

void SimpleViewerApp::setup() {

    ivec2 windowSize = getWindowSize();
    getWindow()->setTitle("Periodic");
    setWindowSize(1024,768);
    int y, x, index;
    entryWidth = windowSize.x / COLUMNS;
    entryHeight = windowSize.y / ROWS;
    for (y = 0; y < ROWS; ++y) {
        for (x = 0; x < COLUMNS; ++x) {
            index = floor((y * ROWS)) + x;
//            if (elemSymbols[index] != 0) {
//                entries.push_back(Entry{
//                        Rectf{x * entryWidth, y * entryHeight, (x * entryWidth) + entryWidth,
//                              (y * entryWidth) + entryHeight},
//                        elemSymbols[index]
//                });
//            }
        }
    }
    mFont = Font("", max(entryWidth,entryHeight)*0.5);
    mTextureFont = gl::TextureFont::create(mFont);

}

void SimpleViewerApp::mouseDown(MouseEvent event) {

}

void SimpleViewerApp::draw() {
    // clear out the window with black
    gl::clear(Color::hex(0x222222));
    gl::enableAlphaBlending();
    gl::setMatricesWindow(getWindowSize());
    vec2 offset = vec2(0);
    int y,x;
    const int padding = 15;
    for (y=0;y<ROWS;y++) {
        for (x=0;x<COLUMNS;x++) {
            if (elemSymbols[y][x][0] != '\t'){
                gl::color(0.698,0.875,0.859);
                gl::drawSolidRoundedRect(Rectf{entryWidth*x,entryHeight*y,entryWidth*x+entryWidth,entryHeight*y+entryHeight}, 5);
                gl::color(0.13,0.13,0.13);
                mTextureFont->drawString(elemSymbols[y][x],
                                         vec2{entryWidth * x, entryHeight * y + mTextureFont->getFont().getSize() * 2});
            }
        }
    }
//    mTextureFont->drawString(toString(floor(getAverageFps())) + " FPS",
//                             vec2(10, getWindowHeight() - mTextureFont->getDescent()) + offset);
}

void SimpleViewerApp::resize() {
    ivec2 windowSize = getWindowSize();
    entryWidth = windowSize.x / COLUMNS;
    entryHeight = windowSize.y / ROWS;
}


CINDER_APP(SimpleViewerApp, RendererGl)