#include "Importer_OBJ.hpp"

Importer_OBJ::Importer_OBJ(std::shared_ptr<World> worldPointer):
    Importer{worldPointer}
    {}

Mesh Importer_OBJ::import(const std::string& filepath) {
    std::fstream fs;
    std::string inputLine;
    std::vector<PreMesh> preMeshes;
    preMeshes.push_back(PreMesh());

    fs.open(filepath, std::fstream::in);
    if(fs.is_open()){
        while(!fs.eof()){
            std::getline(fs, inputLine);
            handleInputLine(inputLine, preMeshes);
        }
        fs.close();
    }
}

void Importer_OBJ::handleInputLine(const std::string& inputLine, std::vector<PreMesh>& preMeshes){
    std::vector<std::string> splitLine;
    splitLine.reserve(5);
    int previousSpace = 0;
    int nextSpace = 0;
    int splitLineIndex = 0;
    int parameterCount = 0;
    for(int i = 0; i < inputLine.size(); i++){
        if(inputLine[i] == ' '){
            previousSpace = nextSpace;
            nextSpace = i;
            parameterCount++;
        }
        splitLine[splitLineIndex] = inputLine.substr(previousSpace + 1, nextSpace - previousSpace);
    }

    if(splitLine[0] == std::string("#")){
        return;
    }
    else if(splitLine[0] == std::string("v")){
        for(int j = 0; j < parameterCount; j++){
            preMeshes[preMeshes.size()].addVertexPosition(std::stof(splitLine[j + 1]));
        }
    }
    else if(splitLine[0] == std::string("vt")){
        for(int j = 0; j < parameterCount; j++){
            preMeshes[preMeshes.size()].addVertexTexturePosition(std::stof(splitLine[j + 1]));
        }
    }
    else if(splitLine[0] == std::string("vn")){
        for(int j = 0; j < parameterCount; j++){
            preMeshes[preMeshes.size()].addVertexNormalComponent(std::stof(splitLine[j + 1]));
        }
    }
    else if(splitLine[0] == std::string("f")){
        if(parameterCount == 3){
            preMeshes[preMeshes.size()].addTriangle(inputLine);
        }
        else if(parameterCount == 4){
            preMeshes[preMeshes.size()].addQuad(inputLine);
        }
    }
    else if(splitLine[0] == std::string("o")){
        preMeshes.push_back(PreMesh());
    }
    else{
        std::cout << "unsupported obj file" << std::endl;
        throw -1;
    }
}