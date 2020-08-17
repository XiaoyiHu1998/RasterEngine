#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "World.hpp"

class Renderer{
private:
    std::unique_ptr<World> world;

    void clear();
    void renderFrame();
public:
    Renderer();
    void render();
};

#endif //RENDERER_HPP