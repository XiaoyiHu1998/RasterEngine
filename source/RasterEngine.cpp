#include "RasterEngine.hpp"

RasterEngine::RasterEngine():
    world{World()},
    importManager{ImportManager(std::make_shared<World>(world))}
    {}

void RasterEngine::reset(){

}

void RasterEngine::tick(){

}

void RasterEngine::update(){

}

void RasterEngine::render(){
    
}