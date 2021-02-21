#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

struct Vertex{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec3 vertColor;
    glm::vec2 texCoord;
    Vertex(const glm::vec3& position = glm::vec3(-1), const glm::vec3& normal = glm::vec3(-1), const glm::vec3& vertColor = glm::vec3(-1), const glm::vec3& textureCoordinate = glm::vec3(-1)):
        position{position},
        normal{normal},
        vertColor{vertColor},
        texCoord{texCoord}
        {}
    void setNormals(const glm::vec3& normalIndices)     { normal = normalIndices;       }
    void setColors(const glm::vec3& colorIndices)       { vertColor = colorIndices;     }
    void setTexCoords(const glm::vec3& texCoordIndices) { texCoord = texCoordIndices;   }
};

struct Point{
    int vertex;
    Point(int vertIndex){
        vertex = vertIndex;
    }
};

struct Line{
    glm::vec2 vertices;
    Line(const glm::vec2& vertIndices){
        vertices = vertIndices;
    }
};

struct Triangle{
    glm::vec3 vertices;
    Triangle(const glm::vec3& vertIndices){
        vertices = vertIndices;
    }
};

struct Quad{
    glm::vec4 vertices;
    Quad(const glm::vec4& vertIndices){
        vertices = vertIndices;
    }
};


#endif // PRIMITIVES_HPP