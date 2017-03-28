//
//  SearchEngine.cpp
//  SearchStringIn
//
//  Created by Romain Duquesne on 27/03/2017.
//  Copyright © 2017 Romain Duquesne. All rights reserved.
//

#include "SearchEngine.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <boost/filesystem.hpp>

using std::string;
using std::vector;
using std::find;
using std::ifstream;
using boost::filesystem::directory_entry;
using boost::filesystem::directory_iterator;
using boost::filesystem::is_directory;
using boost::filesystem::is_regular_file;

SearchEngine::SearchEngine(string searchString) {
    this->searchString = searchString;
}

vector<string> SearchEngine::getResults() {
    return results;
}

void SearchEngine::searchInFile(string filePath) {
    string line;
    bool findInFile(false);
    ifstream file(filePath);
    
    if (file.is_open()) {
        while (getline(file,line)) {
            if (line.find(searchString) != std::string::npos) {
                findInFile = true;
            }
        }
        file.close();
    }
    
    if (findInFile && find(results.begin(), results.end(), filePath) != results.end() == 0) {
        results.push_back(filePath);
    }
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
