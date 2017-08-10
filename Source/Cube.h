#ifndef LIFE_CUBE_H
#define LIFE_CUBE_H

#include "Vector3f.h"

#include <vector>

namespace Life
{
    class Cube
    {
    public:
        Cube()
        {
            vertices.resize(8);
            vertices[0] = Vector3f(-0.5f, -0.5f,  0.5f);
            vertices[1] = Vector3f( 0.5f, -0.5f,  0.5f);
            vertices[2] = Vector3f(-0.5f,  0.5f,  0.5f);
            vertices[3] = Vector3f( 0.5f,  0.5f,  0.5f);
            vertices[4] = Vector3f(-0.5f, -0.5f, -0.5f);
            vertices[5] = Vector3f( 0.5f, -0.5f, -0.5f);
            vertices[6] = Vector3f(-0.5f,  0.5f, -0.5f);
            vertices[7] = Vector3f( 0.5f,  0.5f, -0.5f);

            indices = {
                0, 1, 2, 2, 1, 3,
                1, 5, 3, 3, 5, 7,
                5, 4, 7, 7, 4, 6,
                4, 0, 6, 6, 0, 2,
                2, 3, 6, 6, 3, 7,
                4, 5, 0, 0, 5, 1
            };
        }
    
        std::vector<Vector3f> vertices;
        std::vector<unsigned int> indices;
    };
}

#endif // LIFE_CUBE_H
