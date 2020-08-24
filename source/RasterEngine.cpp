#include "RasterEngine.hpp"

RasterEngine::RasterEngine():
    world{World()},
    importManager{ImportManager(std::make_shared<World>(world))},
    importFile{false},
    systemInfo{false},
    viewport{false}
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

    // ImGui::Begin("RasterEngine");
    // ImGuiID mainWindowID = ImGui::GetID("main dockspace window");
    // ImGui::DockSpace(mainWindowID);
    // ImGui::End();

    // ImGui::Begin("System");
    // ImGui::SameLine();
    // ImGui::Text("%.1f FPS", ImGui::GetIO().Framerate);
    // ImGui::SameLine();
    // ImGui::Text("%.3f ms", 1000.0f / ImGui::GetIO().Framerate);
    // ImGui::SameLine();
    // ImGui::End();

    // static bool showDemoWindow = true;
    // ImGui::ShowDemoWindow(&showDemoWindow);

    if(ImGui::BeginMainMenuBar()){
        if(ImGui::BeginMenu("File")){
            if(ImGui::MenuItem("import file")){
                importFile = true;
            }
            ImGui::EndMenu();
        }
        if(ImGui::BeginMenu("Windows")){
            if(ImGui::MenuItem("3D Viewport")){
                viewport = !viewport;
            }
            ImGui::EndMenu();
        }
        if(ImGui::BeginMenu("System")){
            if(ImGui::MenuItem("System Info")){
                systemInfo = !systemInfo;
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }

    if(importFile){
        importFile = false;
        importManager.import();
    }
    if(systemInfo){
        ImGui::Begin("System");
        ImGui::Text("%.1f FPS", ImGui::GetIO().Framerate);
        ImGui::Text("%.3f ms", 1000.0f / ImGui::GetIO().Framerate);
        ImGui::End();
    }
    if(viewport){
        ImGui::Begin("3D Viewport");
        ImGui::End();
    }
 
}