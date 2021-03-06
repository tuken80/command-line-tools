//
//  ReplaceEngine.hpp
//  ReplaceStringIn
//
//  Created by Romain Duquesne on 01/04/2017.
//  Copyright © 2017 Romain Duquesne. All rights reserved.
//

#ifndef ReplaceEngine_hpp
#define ReplaceEngine_hpp

#include <string>
#include <vector>
#include <map>

class SearchEngine {
private:
    const std::string searchString;
    std::vector<std::string> results;
    std::map<std::string, std::vector<int> > lineNumberResults;
    
public:
    SearchEngine(std::string searchString);
    std::vector<std::string> getResults();
    std::map<std::string, std::vector<int> > getLineNumberResults();
    void searchInFile(std::string filePath);
    void searchInFolder(std::string folderPath);
};

#endif /* ReplaceEngine_hpp */
