#ifndef MESH_HPP
#define MESH_HPP

#include "masterInclude.hpp"

class Mesh{
private:
    int vertexPositionDimensions;
    int vertexTextureCoordinateCount;
    int vertexNormalComponentCount;

    std::vector<float> vertexBuffer;
public:
    Mesh(){}
    void render(){}
};

class PreMesh{
private:
    int vertexPositionDimensions;
    int vertexTextureCoordinateCount;
    int vertexNormalComponentCount;
    
    std::vector<float> vertexPositions;
    std::vector<float> vertexTexturePositions;
    std::vector<float> vertexNormals;

    std::vector<Vertex> vertexArray;
    std::vector<Point> pointArray;
    std::vector<line> lineArray;
    std::vector<triangle> triangleArray;
    std::vector<quad> quadArray;
public:
    PreMesh();
    Mesh generateMesh();

    void addVertexPosition(float position);
    void addVertexTexturePosition(float coordinate);
    void addVertexNormalComponent(float normalComponent);

    void addPoint(const std::string& inputLine);
    void addLine(const std::string& inputLine);
    void addTriangle(const std::string& inputLine);
    void addQuad(const std::string& inputLine);
};

#endif //MESH_HPP