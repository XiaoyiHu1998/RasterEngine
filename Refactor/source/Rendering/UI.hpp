#ifndef UI_HPP
#define UI_HPP

#include "namespace.hpp"

namespace UI{

    void drawMainMenuBar(){
        if(ImGui::BeginMenuBar()){
            if(ImGui::BeginMenu("File")){
                if(ImGui::MenuItem("import file")){
                    Engine::UI::importFile = true;
                }
                ImGui::EndMenu();
            }
            if(ImGui::BeginMenu("Windows")){
                if(ImGui::MenuItem("3D Viewport")){
                    Engine::UI::sceneViewport = !Engine::UI::sceneViewport;
                }
                if(ImGui::MenuItem("Outliner")){
                    Engine::UI::outliner = !Engine::UI::outliner;
                }
                if(ImGui::MenuItem("Properties")){
                    Engine::UI::properties = !Engine::UI::properties;
                }
                if(ImGui::MenuItem("ImGui Demo")){
                    Engine::UI::demoWindow = !Engine::UI::demoWindow;
                }
                ImGui::EndMenu();
            }
            if(ImGui::BeginMenu("Options")){
                if(Engine::UI::sceneViewport){
                    if(ImGui::MenuItem("Perfomance Overlay")){
                        Engine::UI::performanceMetrics = !Engine::UI::performanceMetrics;
                    }
                }
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }
    }

    void draw3DViewport(){
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
        ImGui::Begin("3D Viewport");
            ImGui::BeginChild("FrameBuffer");
                Engine::UI::viewportSize = ImVec2(ImGui::GetWindowContentRegionMax().x - ImGui::GetWindowContentRegionMin().x, ImGui::GetWindowContentRegionMax().y - ImGui::GetWindowContentRegionMin().y);
                ImGui::Image((ImTextureID)Engine::Viewport::renderTexture, Engine::UI::viewportSize, ImVec2(0, 1), ImVec2(1, 0));

                if(Engine::UI::performanceMetrics){
                    ImGui::SetCursorPos(ImVec2(8, 5));
                    ImGui::Text("%.1f fps", ImGui::GetIO().Framerate);
                    ImGui::SetCursorPos(ImVec2(8, 15));
                    ImGui::Text("%.3f ms", 1000.0f / ImGui::GetIO().Framerate);
                    ImGui::SetCursorPos(ImVec2(8, 25));
                    ImGui::Text("%dx%d", (int)(ImGui::GetWindowContentRegionMax().x - ImGui::GetWindowContentRegionMin().x), (int)(ImGui::GetWindowContentRegionMax().y - ImGui::GetWindowContentRegionMin().y));
                }
            ImGui::EndChild();
        ImGui::End();
        ImGui::PopStyleVar();
    }

    void drawOpenWindows(unsigned int colorTexture){
        if(Engine::UI::importFile){
            Engine::UI::importFile = false;
            RE_STUB("implement importer call when import pressed");
        }
        if(Engine::UI::sceneViewport){
            draw3DViewport();
        }
        if(Engine::UI::outliner){
            ImGui::Begin("Outliner");
            ImGui::End();
        }
        if(Engine::UI::properties){
            ImGui::Begin("Properties");
            ImGui::End();
        }
        if(Engine::UI::demoWindow){
            ImGui::ShowDemoWindow(&Engine::UI::demoWindow);
        }
    }

    void drawToScreen(){
        //render imgui overlay to glfw window
        ImGui::Render();
        ImGui::UpdatePlatformWindows();
        int display_w, display_h;
        glfwGetFramebufferSize(Engine::window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
    
    void drawUI(){
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
            drawOpenWindows(Engine::Viewport::renderTexture);
        ImGui::End();
    }
};



#endif //UI_HPP