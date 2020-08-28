#include "UIRenderer.hpp"

UIRenderer::UIRenderer(GLFWwindow* window, std::shared_ptr<ImportManager> importManagerPointer):
    window{window},
    importFile{false},
    sceneViewport{true},
    outliner{true},
    properties{true},
    performanceMetrics{true},
    importManagerPointer{importManagerPointer}
    {}

void UIRenderer::drawUI(unsigned int colorTexture){
    ImGui::NewFrame();

    static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;
    static bool dockspaceOpen = true;

    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    ImGuiViewport* viewport_ImGui = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport_ImGui->GetWorkPos());
    ImGui::SetNextWindowSize(viewport_ImGui->GetWorkSize());
    ImGui::SetNextWindowViewport(viewport_ImGui->ID);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    
    if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode){
        window_flags |= ImGuiWindowFlags_NoBackground;
    }

    // Important: keep maindockspace always open
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin("DockSpace Demo", &dockspaceOpen, window_flags);
    ImGui::PopStyleVar();
    ImGui::PopStyleVar(2);

    // Main dockspace, this is where all our windows are drawn
    ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
    ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);

        drawMainMenuBar();
        drawOpenWindows(colorTexture);

    ImGui::End();
}

void UIRenderer::drawMainMenuBar(){
    if(ImGui::BeginMenuBar()){
        if(ImGui::BeginMenu("File")){
            if(ImGui::MenuItem("import file")){
                importFile = true;
            }
            ImGui::EndMenu();
        }
        if(ImGui::BeginMenu("Windows")){
            if(ImGui::MenuItem("3D Viewport")){
                sceneViewport = !sceneViewport;
            }
            if(ImGui::MenuItem("Outliner")){
                outliner = !outliner;
            }
            if(ImGui::MenuItem("Properties")){
                properties = !properties;
            }
            ImGui::EndMenu();
        }
        if(ImGui::BeginMenu("Options")){
            if(sceneViewport){
                if(ImGui::MenuItem("Perfomance Overlay")){
                    performanceMetrics = !performanceMetrics;
                }
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
}

void UIRenderer::drawOpenWindows(unsigned int colorTexture){
    if(importFile){
        importFile = false;
        importManagerPointer->import();
    }
    if(sceneViewport){
        draw3DViewport(colorTexture);
    }
    if(outliner){
        ImGui::Begin("Outliner");
        ImGui::End();
    }
    if(properties){
        ImGui::Begin("Properties");
        ImGui::End();
    }
}

void UIRenderer::draw3DViewport(unsigned int colorTexture){
    ImGui::Begin("3D Viewport");
        ImGui::BeginChild("FrameBuffer");
            viewportSize = ImGui::GetWindowSize();
            ImGui::Image((ImTextureID)colorTexture, viewportSize, ImVec2(0, 1), ImVec2(1, 0));

            if(performanceMetrics){
                ImGui::SetCursorPos(ImVec2(8, 5));
                ImGui::Text("%.1f fps", ImGui::GetIO().Framerate);
                ImGui::SetCursorPos(ImVec2(8, 15));
                ImGui::Text("%.3f ms", 1000.0f / ImGui::GetIO().Framerate);
            }
        ImGui::EndChild();
        
    ImGui::End();
}

void UIRenderer::drawToScreen(){
    //render imgui overlay to glfw window
    ImGui::Render();
    ImGui::UpdatePlatformWindows();
    int display_w, display_h;
    glViewport(0, 0, display_w, display_h);
    glfwGetFramebufferSize(window, &display_w, &display_h);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

ImVec2 UIRenderer::getViewportSize(){
    return viewportSize;
}