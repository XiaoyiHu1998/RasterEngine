#ifndef MESH_HPP
#define MESH_HPP

#include "masterInclude.hpp"

class Mesh{
private:
    int vertexPositionDimensions;
    int vertexTextureCoordinateCount;
    int vertexNormalComponentCount;
public:
    Mesh();
    void render();
};

#endif //MESH_HPP