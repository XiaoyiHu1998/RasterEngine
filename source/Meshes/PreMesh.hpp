#ifndef PRE_MESH_HPP
#define PRE_MESH_HPP

#include "Mesh.hpp"

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
    std::vector<Line> lineArray;
    std::vector<Triangle> triangleArray;
    std::vector<Quad> quadArray;
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

#endif //PRE_MESH_HPP