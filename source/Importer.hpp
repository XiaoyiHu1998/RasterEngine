#ifndef IMPORTER_HPP
#define IMPORTER_HPP

#include "masterInclude.hpp"
#include "World.hpp"
#include "Mesh.hpp"

class Importer{
private:
    std::shared_ptr<World>  worldPointer;
    
    virtual void handleInputLine();
public:
    Importer(){}
    virtual Mesh import(const std::string& filepath) = 0;  
};

#endif //IMPORTER_HPP