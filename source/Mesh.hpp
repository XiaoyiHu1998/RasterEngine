#ifndef MESH_HPP
#define MESH_HPP

#include "masterInclude.hpp"

class PreMesh{
private:
    int vertexPositionDimensions;
    int vertexTextureCoordinateCount;
    int vertexNormalComponentCount;
    
    std::vector<float> vertexPositions;
    std::vector<float> vertexTexturePositions;
    std::vector<float> vertexNormals;

    std::vector<Vertex> vertexArray;
    std::vector<Triangle> triangleArray;
    std::vector<Quad> quadArray;
public:
    PreMesh();
    void setVertexPositionDimensions(int count);
    void setVertexTextureCoordinateCount(int count);
    void setVertexNormalComponentCount(int count);
    void addVertexPosition(float position);
    void addVertexTexturePosition(float position);
    void addVertexNormalComponent(float position);
};

class Mesh{
private:
    int vertexPositionDimensions;
    int vertexTextureCoordinateCount;
    int vertexNormalComponentCount;

    std::vector<float> vertexPositions;
    std::vector<float> vertexTexturePositions;
    std::vector<float> vertexNormals;

    std::vector<Vertex> vertexArray;
    std::vector<Triangle> triangleArray;
    std::vector<Quad> quadArray;
public:
    Mesh();
    void setVertexPositionDimensions(int count);
    void setVertexTextureCoordinateCount(int count);
    void setVertexNormalComponentCount(int count);
    void addVertexPosition(float position);
    void addVertexTexturePosition(float position);
    void addVertexNormalComponent(float position);
};

#endif //MESH_HPP