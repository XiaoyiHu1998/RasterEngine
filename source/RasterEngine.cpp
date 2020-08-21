#include "RasterEngine.hpp"

RasterEngine::RasterEngine():
    world{World()},
    importManager{ImportManager(std::make_shared<World>(world))},
    importFile{false}
    {}

void RasterEngine::reset(){

}

void RasterEngine::tick(){

}

void RasterEngine::update(){

}

void RasterEngine::render(){
    
}

void RasterEngine::importWindow(){
    ImGui::Begin("importer");
    if(ImGui::Button("import file")){
        importManager.import();
    }
    ImGui::End();

}