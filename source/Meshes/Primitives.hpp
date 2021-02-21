#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

struct vector2f{
    float x, y;
    vector2f(float x = 0, float y = 0){
        x = x;
        y = y;
    }
};

struct vector2i{
    int x, y;
    vector2i(int x = 0, int y = 0){
        x = x;
        y = y;
    }
};

struct vector3f{
    float x, y, z;
    vector3f(float x = 0, float y = 0, float z = 0){
        x = x;
        y = y;
        z = z;
    }
};

struct vector3i{
    int x, y, z;
    vector3i(int x = 0, int y = 0, int z = 0){
        x = x;
        y = y;
        z = z;
    }
};

struct Vertex{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec3 vertColor;
    glm::vec2 texCoord;
    Vertex(glm::vec3 position = glm::vec3(-1), glm::vec3 normal = glm::vec3(-1), glm::vec3 vertColor = glm::vec3(-1), glm::vec3 textureCoordinate = glm::vec3(-1)):
        position{position},
        normal{normal},
        vertColor{vertColor},
        texCoord{texCoord}
        {}
    void setNormals(){}
    void setColors(){}
    void setTexCoord(){}
};

struct Point{
    Vertex vertex;
    Point(Vertex vertex){
        vertex = vertex;
    }
};

struct Line{
    Vertex vertices[2];
    line(Vertex vert0, Vertex vert1){
        vertices[0] = vert0;
        vertices[2] = vert1;
    }
};

struct Triangle{
    Vertex vertices[3];
    triangle(Vertex vert0, Vertex vert1, Vertex vert2){
        vertices[0] = vert0;
        vertices[1] = vert1;
        vertices[2] = vert2;
    }
};

struct Quad{
    Vertex vertices[4];
    quad(Vertex vert0, Vertex vert1, Vertex vert2, Vertex vert3){
        vertices[0] = vert0;
        vertices[1] = vert1;
        vertices[2] = vert2;
        vertices[3] = vert3;
    }
};


#endif // PRIMITIVES_HPP