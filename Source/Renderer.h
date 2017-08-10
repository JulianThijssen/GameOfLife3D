#ifndef LIFE_RENDERER_H
#define LIFE_RENDERER_H

#include "Matrix4f.h"

namespace Life
{
    class Scene;

    class Renderer
    {
    public:
        void init(const Scene& scene);

        void update(const Scene& scene);
    private:
        int shader;

        unsigned int vao;
        unsigned int pbo;

        Matrix4f projMatrix;
        Matrix4f viewMatrix;
        Matrix4f modelMatrix;
    };
} // namespace Life

#endif LIFE_RENDERER_H
