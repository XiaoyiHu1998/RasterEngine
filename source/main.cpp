#include "masterInclude.hpp"
#include "RasterEngine.hpp"

int main(){
    //glfw init
    if(!glfwInit()){
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWwindow* window = glfwCreateWindow(WINDOW_RES_X, WINDOW_RES_Y, "RasterEngine.exe", NULL, NULL);
    if(!window){
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //glew init
    if(glewInit() != GLEW_OK){
        return -1;
    }

    //imgui init
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
    // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;      // Enable Viewports outside of main window
    ImGui::StyleColorsDark();

    const char* glsl_version = "#version 130";
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    bool show_demo_window = true;

    //main program init
    RasterEngine rasterEngine(window);

    //main loop
    std::cout << glGetString(GL_VERSION) << std::endl;
    while(!glfwWindowShouldClose(window)){

        
        //imgui systemInfo
        glClearColor(0,0,0,0);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        rasterEngine.drawSceneToTexture();
        rasterEngine.draw();

        glBegin(GL_TRIANGLES);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.0f, 0.05f);
        glVertex2f(0.0f, -0.05f);
        glEnd();

        //swap buffers
        glfwSwapBuffers(window);

        //event check and handling
        glfwPollEvents();
    }

    //Terminate
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}