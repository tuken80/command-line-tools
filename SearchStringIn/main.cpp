//
//  main.cpp
//  SearchStringIn
//
//  Created by Romain Duquesne on 27/03/2017.
//  Copyright © 2017 Romain Duquesne. All rights reserved.
//


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <boost/filesystem.hpp>
#include "SearchEngine.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using boost::filesystem::is_directory;
using boost::filesystem::is_regular_file;
using boost::filesystem::exists;
using boost::filesystem::filesystem_error;

int main(int argc, const char * argv[]) {
    vector<string> fileFolderNames;
    bool help(false);
    
    for (int i=1; i<argc; ++i) {
        if (strncmp ("help", argv[i], 4) == 0 || strncmp ("--help", argv[i], 6) == 0)
            help = true;
        
        if (i != 1)
            fileFolderNames.push_back(argv[i]);
    }
    
    if (help) {
        cout << "This tool allows searching string occurences in file or folder's files." << endl << "Usage: " << argv[0] << " <string> <file|folder> [<file|folder>] [<file|folder>] ..." << endl << "Example: " << argv[0] << " \"#include <iostream>\" /home/user/projects/project/main.cpp /home/user/projects/projet" << endl;
        
        return 0;
    }
    
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " <string> <file|folder> [<file|folder>] [<file|folder>] ..." << endl << "You can get an example by running the command: " << argv[0] << " help" << endl;
        return 1;
    }
    
    const string strToFind(argv[1]);
    SearchEngine se(strToFind);
    
    for (string & path : fileFolderNames) {
        try {
            if (exists(path)) {
                if (is_directory(path))
                    se.searchInFolder(path);
                else if (is_regular_file(path))
                    se.searchInFile(path);
                else
                    cout << path << " exists, but is not a regular file or directory." << endl;
            } else
                cout << path << " does not exists." << endl;
        } catch (const filesystem_error & ex) {
            cout << ex.what() << endl;
        }
    }
    
    vector<string> results(se.getResults());
    map<string, vector<int>> lineNumberResults(se.getLineNumberResults());
    
    for (string & result : results) {
        cout << "Find in: " << result << "." << " Line(s): ";
        
        for (int & line : lineNumberResults[result]) {
            if (&line - &lineNumberResults[result][0] != 0)
                cout << ", ";
            cout << line;
        }
        
        cout << "." << endl;
    }
    
    return 0;
}
