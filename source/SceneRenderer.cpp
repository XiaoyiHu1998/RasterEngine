#include "SceneRenderer.hpp"

SceneRenderer::SceneRenderer(std::shared_ptr<World> worldPointer):
    worldPointer{worldPointer}
    {}


void SceneRenderer::init(){
    glGenFramebuffers(1, &frameBuffer);
    glGenTextures(1, &colorTexture);
    glGenRenderbuffers(1, &renderBuffer);

    //bind frameBuffer
    glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);

    //create and bind colorTexture
    glBindTexture(GL_TEXTURE_2D, colorTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, renderResolution.x, renderResolution.y, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorTexture, 0);

    //create and bind renderBuffer object
    glBindRenderbuffer(GL_RENDERBUFFER, renderBuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, renderResolution.x, renderResolution.y);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, renderBuffer);

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE){
        std::cout << "error: framebuffer not initialized properly" << std::endl;
    }
}

void SceneRenderer::setRenderResolution(ImVec2 viewportSize){
    renderResolution.x = (int)viewportSize.x;
    renderResolution.y = (int) viewportSize.y;
}


unsigned int SceneRenderer::renderScene(){
    //render if framebuffer complete
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE){
        std::cout << "framebuffer status: " << glCheckFramebufferStatus(GL_FRAMEBUFFER);
    }
    else{
        // worldPointer.renderObjects();
        std::cout << "rendering openGl triangle" << std::endl;
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glBegin(GL_TRIANGLES);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(-1.0f, 1.0f);
        glVertex2f(1.0f, 1.0f);
        glEnd();
    }

    return colorTexture;
}