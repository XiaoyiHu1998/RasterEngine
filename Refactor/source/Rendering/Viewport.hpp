#ifndef VIEWPORT_HPP
#define VIEWPORT_HPP

#include "namespace.hpp"

namespace Viewport{
    void createFrameBuffer(){
        //create buffer and bind framebuffer
        GLCall(glGenFramebuffers(1, &Engine::Viewport::frameBuffer));
        GLCall(glBindFramebuffer(GL_FRAMEBUFFER, Engine::Viewport::frameBuffer));

        //create and bind renderTexture
        GLCall(glGenTextures(1, &Engine::Viewport::renderTexture));
        GLCall(glBindTexture(GL_TEXTURE_2D, Engine::Viewport::renderTexture));
        GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Engine::Viewport::height, Engine::Viewport::height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL));
        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
        GLCall(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, Engine::Viewport::renderTexture, 0));

        //create and bind renderBuffer object
        GLCall(glGenRenderbuffers(1, &Engine::Viewport::renderBuffer));
        GLCall(glBindRenderbuffer(GL_RENDERBUFFER, Engine::Viewport::renderBuffer));
        GLCall(glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, Engine::Viewport::height, Engine::Viewport::height));
        GLCall(glBindRenderbuffer(GL_RENDERBUFFER, 0));
        GLCall(glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, Engine::Viewport::renderBuffer));

        if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE){
            std::cout << "framebuffer status: " << glCheckFramebufferStatus(GL_FRAMEBUFFER) << std::endl;
        }
        GLCall(glBindFramebuffer(GL_FRAMEBUFFER, 0));
    }

    void deleteFrameBuffer(){
        GLCall(glBindTexture(GL_TEXTURE_2D, 0));
        GLCall(glBindRenderbuffer(GL_RENDERBUFFER, 0));
        GLCall(glBindFramebuffer(GL_FRAMEBUFFER, 0));

        GLCall(glDeleteTextures(1, &Engine::Viewport::renderTexture));
        GLCall(glDeleteRenderbuffers(1, &Engine::Viewport::renderBuffer));
        GLCall(glDeleteFramebuffers(1, &Engine::Viewport::frameBuffer));
    }

    void bindFrameBuffer(){
        GLCall(glBindFramebuffer(GL_FRAMEBUFFER, Engine::Viewport::frameBuffer));
        GLCall(glViewport(0, 0, Engine::Viewport::height, Engine::Viewport::height));
        if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE){
            std::cout << "framebuffer status: " << glCheckFramebufferStatus(GL_FRAMEBUFFER) << std::endl;
        }
        if(Engine::Viewport::clearColor.y < 0.80f){
            Engine::Viewport::clearColor.y += 0.001f;
        }
        else{
            Engine::Viewport::clearColor.y = 0.20f;
        }
        GLCall(glClearColor(Engine::Viewport::clearColor.x, Engine::Viewport::clearColor.y, Engine::Viewport::clearColor.z, Engine::Viewport::clearColor.w));
        GLCall(glClear(GL_COLOR_BUFFER_BIT));
    }

    void unbindFrameBuffer(){
        GLCall(glBindFramebuffer(GL_FRAMEBUFFER, 0));
    }

    void setRenderResolution(){
        if(Engine::Viewport::width != Engine::UI::viewportSize.x || Engine::Viewport::height != Engine::UI::viewportSize.y){
            Engine::Viewport::sizeChanged = true;
            Engine::Viewport::width = Engine::UI::viewportSize.x;
            Engine::Viewport::height = Engine::UI::viewportSize.y;
        }
    }

    void renderScene(){
        //render to right buffer
        if(Engine::Viewport::sizeChanged){
            Engine::Viewport::sizeChanged = false;
            deleteFrameBuffer();
            createFrameBuffer();
            bindFrameBuffer();
            // scenePointer->render(Engine::Viewport::width, Engine::Viewport::height);
        }
        else{
            bindFrameBuffer();
            // scenePointer->render();
        }

        //return colorTexture
        unbindFrameBuffer();
    }
};


#endif //VIEWPORT_HPP