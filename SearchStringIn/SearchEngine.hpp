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

class SearchEngine {
private:
    std::string searchString;
    std::vector<std::string> results;
    
public:
    SearchEngine(std::string searchString);
    std::vector<std::string> getResults();
    void searchInFile(std::string filePath);
    void searchInFolder(std::string folderPath);
};

#endif /* SearchEngine_hpp */
