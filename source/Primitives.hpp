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
    float vertexPosition[3];
    float vertexTextureCoord[3];
    float vertexNormalComponent[3];
};

struct Triangle{
    int vertexIndices[3];
    Triangle(int index0, int index1, int index2){
        vertexIndices[0] = index0;
        vertexIndices[1] = index1;
        vertexIndices[2] = index2;
    }
};

struct Quad{
    int vertexIndices[3];
    Quad(int index0, int index1, int index2, int index3){
        vertexIndices[0] = index0;
        vertexIndices[1] = index1;
        vertexIndices[2] = index2;
        vertexIndices[3] = index3;
    }
};


#endif // PRIMITIVES_HPP