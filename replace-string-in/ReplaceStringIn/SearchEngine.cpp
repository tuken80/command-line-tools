//
//  SearchEngine.cpp
//  ReplaceStringIn
//
//  Created by Romain Duquesne on 01/04/2017.
//  Copyright © 2017 Romain Duquesne. All rights reserved.
//

#include "SearchEngine.hpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <boost/filesystem.hpp>

using std::string;
using std::vector;
using std::map;
using std::find;
using std::ifstream;
using boost::filesystem::directory_entry;
using boost::filesystem::directory_iterator;
using boost::filesystem::is_directory;
using boost::filesystem::is_regular_file;

SearchEngine::SearchEngine(string searchString): searchString(searchString) {}

vector<string> SearchEngine::getResults() {
    return results;
}

map<string, vector<int> > SearchEngine::getLineNumberResults() {
    return lineNumberResults;
}

void SearchEngine::searchInFile(string filePath) {
    int currentLineNumber(0);
    string line;
    bool findInFile(false);
    ifstream file(filePath);
    
    if (file.is_open()) {
        while (getline(file,line)) {
            ++currentLineNumber;
            
            if (line.find(searchString) != string::npos) {
                findInFile = true;
                lineNumberResults[filePath].push_back(currentLineNumber);
            }
        }
        file.close();
    }
    
    if (findInFile && find(results.begin(), results.end(), filePath) != results.end() == 0)
        results.push_back(filePath);
}

void SearchEngine::searchInFolder(string folderPath) {
    for (directory_entry & entry : directory_iterator(folderPath)) {
        string path = entry.path().string();
        
        if (is_directory(path))
            searchInFolder(path);
        else if (is_regular_file(path))
            searchInFile(path);
    }
}
