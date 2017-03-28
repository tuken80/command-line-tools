//
//  SearchEngine.hpp
//  SearchStringIn
//
//  Created by Romain Duquesne on 27/03/2017.
//  Copyright © 2017 Romain Duquesne. All rights reserved.
//

#ifndef SearchEngine_hpp
#define SearchEngine_hpp

#include <string>
#include <vector>
#include <map>

class SearchEngine {
private:
    const std::string searchString;
    std::vector<std::string> results;
    std::map<std::string, std::vector<int>> lineNumberResults;
    
public:
    SearchEngine(std::string searchString);
    std::vector<std::string> getResults();
    std::map<std::string, std::vector<int>> getLineNumberResults();
    void searchInFile(std::string filePath);
    void searchInFolder(std::string folderPath);
};

#endif /* SearchEngine_hpp */
