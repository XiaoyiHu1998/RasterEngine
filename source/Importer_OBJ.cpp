#include "Importer_OBJ.hpp"

Importer_OBJ::Importer_OBJ(std::shared_ptr<World> worldPointer):
    base{worldPointer}
    {}

Mesh Importer_OBJ::import() override {
    std::fstream fs;
    std::string inputLine;
    Mesh newMesh();

    fs.open(filepath, std::fstream::in);
    if(fs.is_open()){
        while(!fs.eof()){
            std::getline(fs, inputLine);
            handleInputLine(const std::string& inputLine, Mesh& mesh);
        }
        fs.close();
    }
}

void Importer_OBJ::handleInputLine(const std::string& inputLine, PreMesh& preMesh){
    std::vector<string> splitLine;
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
        splitLine[splitlineIndex] = inputLine.substr(previousSpace + 1, nextSpace - previousSpace);
    }

    switch(splitLine){
        case splitLine[0] == "#": //Comments
            break;
        case splitLine[0] == "v": //VertexPosition
            mesh.setVertexPositionDimensions(parameterCount);
            for(int j = 0; j < parameterCount; j++){
                mesh.addVertexPosition(std::stof(splitLine[i + 1]));
            }
            break;
        case splitLine[0] == "vt": // vertexTextureCoordinates
            mesh.setVertexTextureCoordinateCount(parameterCount);
            for(int j = 0; j < parameterCount; j++){
                mesh.addVertexTexturePosition(std::stof(splitLine[i + 1]));
            }
            break;
        case splitLine[0] == "vn": // vertexNormalCoordinates
            mesh.setVertexNormalComponentCount(parameterCount);
            for(int j = 0; j < parameterCount; j++){
                mesh.addVertexNormalComponent(std::stof(splitLine[i + 1]));
            }
            break;
        case splitLine[0] == "f":
            if(parameterCount == 3){
                for(int j = 0; j < 3; j++){
                    parseVertexIndices(splitLine[j + 1], preMesh);
                }
            }
            else if(paramter_count == 4){

            }
        case default:
            std::cout << "unsupporterd obj file." << std::endl;
            throw;
            break;
    }
}

std::vector<int> parseVertexIndices(const string& indices, PreMehs& preMesh){
    std::vector 
}
