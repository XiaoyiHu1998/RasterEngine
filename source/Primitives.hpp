#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

struct vector2f{
    float x, y;
    vector2f(float x, float y){
        x = x;
        y = y;
    }
};

struct vector2i{
    int x, y;
    vector2i(int x, int y){
        x = x;
        y = y;
    }
};

struct vector3f{
    float x, y, z;
    vector3f(float x, float y, float z){
        x = x;
        y = y;
        z = z;
    }
};

struct vector3i{
    int x, y, z;
    vector3i(int x, int y, int z){
        x = x;
        y = y;
        z = z;
    }
};

struct Vertex{
    int position;
    int textureCoordinate;
    int normal;
    Vertex(int position = -1, int textureCoordinate = -1, int normal = -1){
        position = position;
        textureCoordinate = textureCoordinate;
        normal = normal;
    }
};

struct Point{
    Vertex vertex;
    Point(Vertex vertex){
        vertex = vertex;
    }
};

struct line{
    Vertex vertices[2];
    line(Vertex vert0, Vertex vert1){
        vertices[0] = vert0;
        vertices[2] = vert1;
    }
};

struct triangle{
    Vertex vertices[3];
    triangle(Vertex vert0, Vertex vert1, Vertex vert2){
        vertices[0] = vert0;
        vertices[1] = vert1;
        vertices[2] = vert2;
    }
};

struct quad{
    Vertex vertices[4];
    quad(Vertex vert0, Vertex vert1, Vertex vert2, Vertex vert3){
        vertices[0] = vert0;
        vertices[1] = vert1;
        vertices[2] = vert2;
        vertices[3] = vert3;
    }
};


#endif // PRIMITIVES_HPP