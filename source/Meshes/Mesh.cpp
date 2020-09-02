#include "Mesh.hpp"

Mesh::Mesh(){
    vertexPositionDimensions = 3;
    vertexNormalComponentCount = 3;
    vertexTextureCoordinateCount = 2;
}

void Mesh::render(){
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.7f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();
}