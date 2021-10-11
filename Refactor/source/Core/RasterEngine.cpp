#include "RasterEngine.hpp"

RasterEngine::RasterEngine(GLFWwindow* window):
    scene{Scene()}
    {
        // rendererManager.init();
        //setting initial values for Engine namespace members;
        Engine::window = window;
        Engine::scene = Scene();

        //viewport members
        initViewport(window);
        Viewport::createFrameBuffer();

        //ui members
        initUI();

    }

void RasterEngine::initViewport(GLFWwindow* window){
    Engine::Viewport::clearColor = ImVec4(0.35f, 0.55f, 0.45f, 1.00f);
    Engine::Viewport::width = 1920;
    Engine::Viewport::height = 1080;
    Engine::Viewport::sizeChanged = true;
}

void RasterEngine::initUI(){
    Engine::UI::viewportSize = ImVec2(ImGui::GetWindowContentRegionMax().x - ImGui::GetWindowContentRegionMin().x, 
                                      ImGui::GetWindowContentRegionMax().y - ImGui::GetWindowContentRegionMin().y
                                     );
    Engine::UI::importFile = false;
    Engine::UI::sceneViewport = true;
    Engine::UI::outliner = true;
    Engine::UI::properties = true;
    Engine::UI::performanceMetrics = true;
    Engine::UI::demoWindow = false;
}

void RasterEngine::draw(){
    // rendererManager.renderProgramWindow();

    //draw scene
    Viewport::renderScene();

    //draw UI
    UI::drawUI();
    UI::drawToScreen();

    Viewport::setRenderResolution();
}