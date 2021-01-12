#ifndef IMPORT_MANAGER_HPP
#define IMPORT_MANAGER_HPP

#include "masterInclude.hpp"

#include "Importer_OBJ.hpp"

class ImportManager{
private:
    Importer_OBJ importer_obj;

    std::string getFilePath();
public:
    ImportManager(std::shared_ptr<Scene> scenePointer);
    void import();
};


#endif //IMPORT_MANAGER_HPP