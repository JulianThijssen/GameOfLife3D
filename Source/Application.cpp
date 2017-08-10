#include "Application.h"

#include "Simulation.h"
#include "Renderer.h"

#include <iostream>

namespace Life
{
    Application::Application()
    {
        glfwInit();
        window = glfwCreateWindow(1024, 1024, "Game Of Life", NULL, NULL);
        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize OpenGL context" << std::endl;
        }

        simulation = std::make_unique<Simulation>();
        renderer = std::make_unique<Renderer>();
    }

    void Application::startGame()
    {
        simulation->init(scene);
        renderer->init(scene);

        while (glfwWindowShouldClose(window) == GLFW_FALSE)
        {
            glfwPollEvents();

            simulation->update(scene);
            renderer->update(scene);

            glfwSwapBuffers(window);
        }
    }
}

int main()
{
    Life::Application app;

    app.startGame();
    
    return 0;
}
