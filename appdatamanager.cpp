//
// Created by ben on 14/11/21.
//

#include "appdatamanager.h"

AppDataManager *AppDataManagerInstance() {
    static AppDataManager instance;
    return &instance;
}

AppDataManager::AppDataManager() {
    std::ifstream jsonFile(getAssetPath("elements-data.json"));
    jsonFile >> mJsonRoot;
    for (auto &k : mJsonRoot["Table"]["Columns"]["Column"]) {
        mEntrySymbolInfoKeys.push_back(k.asString());
    }
    for (auto &row : mJsonRoot["Table"]["Row"]) {
        for (auto &cell : row) {
            EntrySymbolInfo symbolInfo;
            for (auto &e : cell) {
                symbolInfo.values.push_back(e.asString());
            }
            mEntries.emplace(cell[1].asString(), symbolInfo);
            //cout << cell;
        }
        //cout << endl;
    }
//    cout << mEntrySymbolInfoKeys;
    //const Json::Value rowEntries = root["Row"];
}

AppDataManager::EntryType AppDataManager::entries() {
    return mEntries;
}

const vector<string> &AppDataManager::entrySymbolInfoKeys() {
    return mEntrySymbolInfoKeys;
}

string AppDataManager::getValForElem(const string elem, const string key) {
    return mEntries.at(elem).values.at(
            find(mEntrySymbolInfoKeys.begin(), mEntrySymbolInfoKeys.end(), key) - mEntrySymbolInfoKeys.begin()
    );
}
