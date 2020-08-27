#include "UIRenderer.hpp"

UIRenderer::UIRenderer(GLFWwindow* window, std::shared_ptr<ImportManager> importManagerPointer):
    window{window},
    importFile{false},
    systemInfo{false},
    sceneViewport{false},
    importManagerPointer{importManagerPointer}
    {}

void UIRenderer::drawWindows(unsigned int colorTexture){
    ImGui::NewFrame();

    static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;
    static bool dockspaceOpen = true;

    // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
    // because it would be confusing to have two docking targets within each others.
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    ImGuiViewport* viewport_ImGui = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport_ImGui->GetWorkPos());
    ImGui::SetNextWindowSize(viewport_ImGui->GetWorkSize());
    ImGui::SetNextWindowViewport(viewport_ImGui->ID);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    

    // When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
    // and handle the pass-thru hole, so we ask Begin() to not render a background.
    if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode){
        window_flags |= ImGuiWindowFlags_NoBackground;
    }

    // Important: note that we proceed even if Begin() returns false (aka window is collapsed).
    // This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
    // all active windows docked into it will lose their parent and become undocked.
    // We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
    // any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin("DockSpace Demo", &dockspaceOpen, window_flags);
    ImGui::PopStyleVar();

    ImGui::PopStyleVar(2);

    // DockSpace
    ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
    ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);

        if(ImGui::BeginMainMenuBar()){
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
            importManagerPointer->import();
        }
        if(systemInfo){
            ImGui::Begin("System");
            ImGui::Text("%.1f FPS", ImGui::GetIO().Framerate);
            ImGui::Text("%.3f ms", 1000.0f / ImGui::GetIO().Framerate);
            ImGui::End();
        }
        if(sceneViewport){
            draw3DViewport(colorTexture);
        }
        
    ImGui::End();
}

void UIRenderer::draw3DViewport(unsigned int colorTexture){
    ImGui::Begin("3D Viewport");
        ImGui::BeginChild("FrameBuffer");
        ImVec2 windowSizeVector = ImGui::GetWindowSize();
        ImGui::Image((ImTextureID)colorTexture, windowSizeVector, ImVec2(0, 1), ImVec2(1, 0));
        ImGui::EndChild();
    ImGui::End();
}

void UIRenderer::drawImGui(){
    //render imgui overlay
    ImGui::Render();
    ImGui::UpdatePlatformWindows();
    int display_w, display_h;
    glViewport(0, 0, display_w, display_h);
    glfwGetFramebufferSize(window, &display_w, &display_h);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}