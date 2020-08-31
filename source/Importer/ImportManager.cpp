#include "ImportManager.hpp"

ImportManager::ImportManager(std::shared_ptr<Scene> scenePointer):
    importer_obj{Importer_OBJ(scenePointer)}
    {}

std::string ImportManager::getFilePath(){
    char filepath_charArray[MAX_PATH];
        OPENFILENAME toOpenFileName;
        ZeroMemory(&filepath_charArray, sizeof(filepath_charArray));
        ZeroMemory(&toOpenFileName, sizeof(toOpenFileName));
        toOpenFileName.lStructSize  = sizeof(toOpenFileName);
        toOpenFileName.lpstrFile    = filepath_charArray;
        toOpenFileName.nMaxFile     = MAX_PATH;
        toOpenFileName.hwndOwner    = NULL; // TODO: add handle of the rasterEngine window later.
        toOpenFileName.lpstrTitle   = "Choose a file to Import.";
        toOpenFileName.lpstrFilter  = "Obj Files\0*.obj\0Text Files\0*.txt\0Any File\0*.*\0";
        toOpenFileName.Flags        = OFN_FILEMUSTEXIST | OFN_DONTADDTORECENT;

        if(!GetOpenFileName(&toOpenFileName)){
            switch(CommDlgExtendedError()){
                case CDERR_DIALOGFAILURE   : std::cout << "CDERR_DIALOGFAILURE\n";   break;
                case CDERR_FINDRESFAILURE  : std::cout << "CDERR_FINDRESFAILURE\n";  break;
                case CDERR_INITIALIZATION  : std::cout << "CDERR_INITIALIZATION\n";  break;
                case CDERR_LOADRESFAILURE  : std::cout << "CDERR_LOADRESFAILURE\n";  break;
                case CDERR_LOADSTRFAILURE  : std::cout << "CDERR_LOADSTRFAILURE\n";  break;
                case CDERR_LOCKRESFAILURE  : std::cout << "CDERR_LOCKRESFAILURE\n";  break;
                case CDERR_MEMALLOCFAILURE : std::cout << "CDERR_MEMALLOCFAILURE\n"; break;
                case CDERR_MEMLOCKFAILURE  : std::cout << "CDERR_MEMLOCKFAILURE\n";  break;
                case CDERR_NOHINSTANCE     : std::cout << "CDERR_NOHINSTANCE\n";     break;
                case CDERR_NOHOOK          : std::cout << "CDERR_NOHOOK\n";          break;
                case CDERR_NOTEMPLATE      : std::cout << "CDERR_NOTEMPLATE\n";      break;
                case CDERR_STRUCTSIZE      : std::cout << "CDERR_STRUCTSIZE\n";      break;
                case FNERR_BUFFERTOOSMALL  : std::cout << "FNERR_BUFFERTOOSMALL\n";  break;
                case FNERR_INVALIDFILENAME : std::cout << "FNERR_INVALIDFILENAME\n"; break;
                case FNERR_SUBCLASSFAILURE : std::cout << "FNERR_SUBCLASSFAILURE\n"; break;
                default                    : std::cout << "User cancelled opening file.\n";
            }
            return std::string("ERROR");
        }
        else{
            return std::string(filepath_charArray);
        }
}

void ImportManager::import(){
    std::string error = "ERROR";
    std::string filepath = getFilePath();

    if(filepath != std::string("ERROR")){
        std::string extension = filepath.substr(filepath.size() - 4, 4);
        std::cout << "path: " << filepath << std::endl;
        std::cout << "file extension: " << extension << std::endl;
        if(extension == std::string(".obj")){
            importer_obj.import(filepath);
        }
        else{
            std::cout << "unsupported filetype selected." << std::endl;
        }
    }
}