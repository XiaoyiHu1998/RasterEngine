#ifndef IMPORTER_OBJ_HPP
#define IMPORTER_OBJ_HPP

#include "Importer.hpp"

class Importer_OBJ : public Importer{
private:
    void handleInputLine(const std::string& inputLine, std::vector<PreMesh>& preMeshes) override;
public:
    Importer_OBJ(std::shared_ptr<World> worldPointer);
    Mesh import(const std::string& filepath) override;
};

#endif //IMPORTER_OBJ_HPP