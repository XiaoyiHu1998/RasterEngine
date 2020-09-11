#include "SceneRenderer.hpp"

SceneRenderer::SceneRenderer(std::shared_ptr<Scene> scenePointer):
    scenePointer{scenePointer},
    viewportWidth{1920},
    viewportHeight{1080},
    viewportSizeChanged{true},
    clear_color{ImVec4(0.35f, 0.55f, 0.45f, 1.00f)}
    {}


void SceneRenderer::createFrameBuffer(){
    //create buffer and bind framebuffer
    glGenFramebuffers(1, &frameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);

    //create and bind colorTexture
    glGenTextures(1, &colorTexture);
    glBindTexture(GL_TEXTURE_2D, colorTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, viewportHeight, viewportHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorTexture, 0);

    //create and bind renderBuffer object
    glGenRenderbuffers(1, &renderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, renderBuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, viewportHeight, viewportHeight);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, renderBuffer);

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE){
        std::cout << "framebuffer status: " << glCheckFramebufferStatus(GL_FRAMEBUFFER) << std::endl;
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void SceneRenderer::bindFrameBuffer(){
    glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
    glViewport(0, 0, viewportHeight, viewportHeight);
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE){
        std::cout << "framebuffer status: " << glCheckFramebufferStatus(GL_FRAMEBUFFER) << std::endl;
    }
    if(clear_color.y < 0.80f){
        clear_color.y += 0.001f;
    }
    else{
        clear_color.y = 0.20f;
    }
    glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
}

void SceneRenderer::unbindFrameBuffer(){
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void SceneRenderer::deleteFrameBuffer(){
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    glDeleteTextures(1, &colorTexture);
    glDeleteRenderbuffers(1, &renderBuffer);
    glDeleteFramebuffers(1, &frameBuffer);
}

unsigned int SceneRenderer::renderScene(const Camera& camera){
    //render to right buffer
    if(viewportSizeChanged){
        deleteFrameBuffer();
        createFrameBuffer();
        viewportSizeChanged = false;
    }
    bindFrameBuffer();

    //rendering scene
    // glBegin(GL_TRIANGLES);
    // glVertex2f(0.0f, 0.7f);
    // glVertex2f(-0.5f, -0.5f);
    // glVertex2f(0.5f, -0.5f);
    // glEnd();

    scenePointer->render();

    //return colorTexture
    unbindFrameBuffer();
    return colorTexture;
}

void SceneRenderer::setRenderResolution(ImVec2 viewportSize){
    if(viewportWidth != viewportSize.x && viewportHeight != viewportSize.y){
        viewportSizeChanged = true;
        viewportHeight = viewportSize.x;
        viewportHeight = viewportSize.y;
    }
}

