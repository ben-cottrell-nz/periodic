//
// Created by ben on 14/11/21.
//

#ifndef PERIODIC_APPDATAMANAGER_H
#define PERIODIC_APPDATAMANAGER_H

#include "json/json.h"
#include <iostream>
#include <fstream>
#include "cinder/app/App.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class AppDataManager {
public:
    AppDataManager();
    struct EntrySymbolInfo {
        vector<string> values;
    };
    string getValForElem(const string elem, const string key);
    const vector<string>& entrySymbolInfoKeys();
    using EntryType = map<string,EntrySymbolInfo>;
    EntryType entries();
private:
    EntryType mEntries;
    vector<string> mEntrySymbolInfoKeys;
    Json::Value mJsonRoot;
};

AppDataManager* AppDataManagerInstance();

#endif //PERIODIC_APPDATAMANAGER_H
