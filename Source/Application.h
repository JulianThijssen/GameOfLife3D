#ifndef LIFE_APPLICATION_H
#define LIFE_APPLICATION_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Scene.h"

#include <memory>

namespace Life
{
    class Simulation;
    class Renderer;

    class Application
    {
    public:
        Application();

        void startGame();

    private:
        GLFWwindow* window;

        Scene scene;
        std::unique_ptr<Simulation> simulation;
        std::unique_ptr<Renderer> renderer;
    };
} // namespace Life

#endif LIFE_APPLICATION_H
