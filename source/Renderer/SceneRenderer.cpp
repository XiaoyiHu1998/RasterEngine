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
    GLCall(glGenFramebuffers(1, &frameBuffer));
    GLCall(glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer));

    //create and bind colorTexture
    GLCall(glGenTextures(1, &colorTexture));
    GLCall(glBindTexture(GL_TEXTURE_2D, colorTexture));
    GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, viewportHeight, viewportHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    GLCall(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorTexture, 0));

    //create and bind renderBuffer object
    GLCall(glGenRenderbuffers(1, &renderBuffer));
    GLCall(glBindRenderbuffer(GL_RENDERBUFFER, renderBuffer));
    GLCall(glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, viewportHeight, viewportHeight));
    GLCall(glBindRenderbuffer(GL_RENDERBUFFER, 0));
    GLCall(glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, renderBuffer));

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE){
        std::cout << "framebuffer status: " << glCheckFramebufferStatus(GL_FRAMEBUFFER) << std::endl;
    }
    GLCall(glBindFramebuffer(GL_FRAMEBUFFER, 0));
}

void SceneRenderer::bindFrameBuffer(){
    GLCall(glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer));
    GLCall(glViewport(0, 0, viewportHeight, viewportHeight));
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE){
        std::cout << "framebuffer status: " << glCheckFramebufferStatus(GL_FRAMEBUFFER) << std::endl;
    }
    if(clear_color.y < 0.80f){
        clear_color.y += 0.001f;
    }
    else{
        clear_color.y = 0.20f;
    }
    GLCall(glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w));
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void SceneRenderer::unbindFrameBuffer(){
    GLCall(glBindFramebuffer(GL_FRAMEBUFFER, 0));
}

void SceneRenderer::deleteFrameBuffer(){
    GLCall(glBindTexture(GL_TEXTURE_2D, 0));
    GLCall(glBindRenderbuffer(GL_RENDERBUFFER, 0));
    GLCall(glBindFramebuffer(GL_FRAMEBUFFER, 0));

    GLCall(glDeleteTextures(1, &colorTexture));
    GLCall(glDeleteRenderbuffers(1, &renderBuffer));
    GLCall(glDeleteFramebuffers(1, &frameBuffer));
}

unsigned int SceneRenderer::renderScene(){
    //render to right buffer
    if(viewportSizeChanged){
        deleteFrameBuffer();
        createFrameBuffer();
        viewportSizeChanged = false;
        bindFrameBuffer();
        scenePointer->render(viewportWidth, viewportHeight);
    }
    else{
        bindFrameBuffer();
        scenePointer->render();
    }

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