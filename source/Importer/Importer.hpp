#ifndef IMPORTER_HPP
#define IMPORTER_HPP

#include "masterInclude.hpp"
#include "Scene.hpp"
#include "PreMesh.hpp"
#include "Mesh.hpp"

class Importer{
private:
    std::shared_ptr<Scene> scenePointer;
    
    virtual void handleInputLine(const std::string& inputLine, std::vector<PreMesh>& preMeshes) = 0;
    
public:
    Importer(std::shared_ptr<Scene> scenePointer){
        scenePointer = scenePointer;
    }

    virtual Mesh import(const std::string& filepath) = 0;
};

#endif //IMPORTER_HPP