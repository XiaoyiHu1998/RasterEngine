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

void RasterEngine::renderUI(){
    ImGui::NewFrame();
    ImGui::Begin("RasterEngine");
    ImGui::Text("%.1f FPS", ImGui::GetIO().Framerate);
    ImGui::Text("%.3f ms", 1000.0f / ImGui::GetIO().Framerate);
    if(ImGui::Button("import file")){
        importManager.import();
    }
    ImGui::End();

}