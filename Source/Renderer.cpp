#include "Renderer.h"

#include "Scene.h"
#include "ShaderLoader.h"

#include <glad/glad.h>
#include <iostream>

///
#include "Cube.h"
#include <vector>


namespace Life
{
    void Renderer::init(const Scene& scene)
    {
        shader = ShaderLoader::loadShaders("quad.vert", "color.frag");

        if (shader == -1)
        {
            std::cout << "Failed to load shaders" << std::endl;
        }

        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        unsigned int vbo;
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        Cube cube;
        std::vector<Vector3f> vertices;
        vertices.resize(36);
        for (int i = 0; i < vertices.size(); i++)
        {
            vertices[i] = cube.vertices[cube.indices[i]];
        }

        glBufferData(GL_ARRAY_BUFFER, vertices.size() * 3 * 4, vertices.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(0);

        glGenBuffers(1, &pbo);
        glBindBuffer(GL_ARRAY_BUFFER, pbo);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(1);
        glVertexAttribDivisor(1, 1);

        projMatrix.setIdentity();
        float aspect = 1.0;
        float fovy = 90;
        float zNear = 0.1f, zFar = 1000.0f;
        projMatrix[0] = (1.0f / tan(fovy / 2)) / aspect;
        projMatrix[5] = (1.0f / tan(fovy / 2));
        projMatrix[10] = (zNear + zFar) / (zNear - zFar);
        projMatrix[11] = -1;
        projMatrix[14] = (2 * zNear * zFar) / (zNear - zFar);
        projMatrix[15] = 0;
        //float left = -128;
        //float right = 128;
        //float top = 128;
        //float bottom = -128;
        //float zNear = -100;
        //float zFar = 100;
        //projMatrix[0] = 2 / (right - left);
        //projMatrix[5] = 2 / (top - bottom);
        //projMatrix[10] = -2 / (zFar - zNear);
        //projMatrix[12] = (-right - left) / (right - left);
        //projMatrix[13] = (-top - bottom) / (top - bottom);
        //projMatrix[14] = (-zFar - zNear) / (zFar - zNear);

        glEnable(GL_DEPTH_TEST);
    }

    float t = 0;

    void Renderer::update(const Scene& scene)
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shader);

        ///
        glBindBuffer(GL_ARRAY_BUFFER, pbo);

        std::vector<Vector3f> positions;
        int xOffset = scene.width / 2, yOffset = scene.height / 2;
        for (int y = 0; y < scene.height; y++) {
            for (int x = 0; x < scene.width; x++) {
                int alive = scene.grid[x][y];
                if (alive)
                    positions.push_back(Vector3f(x - xOffset, y - yOffset, 0));
            }
        }

        glBufferData(GL_ARRAY_BUFFER, positions.size() * 3 * 4, positions.data(), GL_STATIC_DRAW);
        ///
        t += 0.4f;
        viewMatrix.setIdentity();
        viewMatrix.translate(Vector3f(0, 0, -200));
        viewMatrix.rotate(t, 0, 1, 0);

        modelMatrix.setIdentity();

        int projLocation = glGetUniformLocation(shader, "projMatrix");
        glUniformMatrix4fv(projLocation, 1, false, projMatrix.toArray());

        int viewLocation = glGetUniformLocation(shader, "viewMatrix");
        glUniformMatrix4fv(viewLocation, 1, false, viewMatrix.toArray());

        int modelLocation = glGetUniformLocation(shader, "modelMatrix");
        glUniformMatrix4fv(modelLocation, 1, false, modelMatrix.toArray());

        glBindVertexArray(vao);

        glDrawArraysInstanced(GL_TRIANGLES, 0, 36, positions.size());
    }
}
