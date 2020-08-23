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
    ImGuiID mainWindowID = ImGui::GetID("main dockspace window");
    ImGui::DockSpace(mainWindowID);
    ImGui::End();

    ImGui::Begin("System");
    ImGui::SameLine();
    ImGui::Text("%.1f FPS", ImGui::GetIO().Framerate);
    ImGui::SameLine();
    ImGui::Text("%.3f ms", 1000.0f / ImGui::GetIO().Framerate);
    ImGui::SameLine();
    if(ImGui::Button("import file")){
        importManager.import();
    }
    ImGui::End();

    static bool showDemoWindow = true;
    ImGui::ShowDemoWindow(&showDemoWindow);
 
}