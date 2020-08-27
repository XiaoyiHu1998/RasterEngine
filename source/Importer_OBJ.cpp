#include "Importer_OBJ.hpp"

Importer_OBJ::Importer_OBJ(std::shared_ptr<World> worldPointer):
    Importer{worldPointer}
    {}

Mesh Importer_OBJ::import(const std::string& filepath) {
    std::fstream fs;
    std::string inputLine;
    std::vector<PreMesh> preMeshes;
    preMeshes.push_back(PreMesh());
    mtlPresentForCurrentFile = false;
    mtlFilePath = "";
    materialName = "";

    std::cout << "opening file" << std::endl;
    fs.open(filepath, std::fstream::in);
    if(fs.is_open()){
        std::cout << "file opened" << std::endl;
        while(!fs.eof()){
            // std::cout << "getting line" << std::endl;
            std::getline(fs, inputLine);
            if(inputLine != std::string("")){
                handleInputLine(inputLine, preMeshes);
            }
        }
        std::cout << "closing file" << std::endl;
        fs.close();
    }
    std::cout << "import finished" << std::endl;
}

void Importer_OBJ::handleInputLine(const std::string& inputLine, std::vector<PreMesh>& preMeshes){
    std::vector<std::string> splitLine;
    splitLine.push_back(std::string("")); 
    int parameterCount = 0;
    // std::cout << "current line in file: " << inputLine << std::endl;
    // std::cout << "<==== Split ====>" << std::endl;
    for(int i = 0; i < inputLine.size(); i++){
        if(inputLine[i] == ' '){
            parameterCount++;
            splitLine.push_back(std::string(""));
        }
        else{
            splitLine[splitLine.size() - 1] += inputLine[i];
        };
    }
    // for(int i = 0; i < splitLine.size(); i++){
    //     std::cout << splitLine[i] << std::endl;
    // }
    // std::cout << "====> split <====" << std::endl;

    #define CURRENT_PREMESH preMeshes[preMeshes.size() - 1]
    if(splitLine[0] == std::string("#")){
        return;
    }
    else if(splitLine[0] == std::string("v")){
        for(int j = 0; j < parameterCount; j++){
            CURRENT_PREMESH.addVertexPosition(std::stof(splitLine[j + 1]));
        }
    }
    else if(splitLine[0] == std::string("vt")){
        for(int j = 0; j < parameterCount; j++){
            CURRENT_PREMESH.addVertexTexturePosition(std::stof(splitLine[j + 1]));
        }
    }
    else if(splitLine[0] == std::string("vn")){
        for(int j = 0; j < parameterCount; j++){
            CURRENT_PREMESH.addVertexNormalComponent(std::stof(splitLine[j + 1]));
        }
    }
    else if(splitLine[0] == std::string("p")){
        CURRENT_PREMESH.addPoint(inputLine);
    }
    else if(splitLine[0] == std::string("l")){
        CURRENT_PREMESH.addLine(inputLine);
    }
    else if(splitLine[0] == std::string("f")){
        if(parameterCount == 3){
            CURRENT_PREMESH.addTriangle(inputLine);
        }
        else if(parameterCount == 4){
            CURRENT_PREMESH.addQuad(inputLine);
        }
    }
    else if(splitLine[0] == std::string("mtllib")){
        mtlPresentForCurrentFile = true;
        mtlFilePath = splitLine[1];
    }
    else if(splitLine[0] == std::string("usemtl")){
        materialName = splitLine[1];
    }
    else if(splitLine[0] == std::string("o")){
        preMeshes.push_back(PreMesh());
    }
    else if(splitLine[0] == std::string("s")){ 
        if(splitLine[1] == std::string("off")){
            // TODO: no smoothinggroups
        }
        else{
            // TODO: smoothinggroups
        }
    }
    else{
        std::cout << "unsupported obj file" << std::endl;
    }

    #undef CURRENT_PREMESH
}