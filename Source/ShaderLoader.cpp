#include "ShaderLoader.h"

#include <glad/glad.h>

#include <fstream>
#include <iostream>

namespace Life
{
    int ShaderLoader::loadShaders(std::string vertPath, std::string fragPath)
    {
        int vertexShader = loadShader(vertPath, GL_VERTEX_SHADER);
        int fragmentShader = loadShader(fragPath, GL_FRAGMENT_SHADER);

        int program = glCreateProgram();

        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);

        glLinkProgram(program);

        GLint status = 0;
        glGetProgramiv(program, GL_LINK_STATUS, &status);
        if (status == GL_FALSE)
        {
            std::cout << "Failed to link shader program" << std::endl;
            return -1;
        }

        glValidateProgram(program);

        return program;
    }

    int ShaderLoader::loadShader(std::string path, int type)
    {
        int shader = 0;

        std::ifstream file(path);
        if (file.fail() || !file.is_open())
        {
            std::cout << "No such file: " << path << std::endl;
        }

        std::string source;
        std::string line;
        while (getline(file, line))
        {
            source.append(line + "\n");
        }

        const char* csource = source.c_str();

        shader = glCreateShader(type);
        glShaderSource(shader, 1, &csource, NULL);
        glCompileShader(shader);

        char log[1024];
        GLint status;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
        if (status == GL_FALSE)
        {
            glGetShaderInfoLog(shader, 1024, nullptr, log);
            std::cout << log << std::endl;
            return -1;
        }
        return shader;
    }
}
