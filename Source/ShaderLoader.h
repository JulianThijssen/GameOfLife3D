#ifndef LIFE_SHADER_LOADER_H
#define LIFE_SHADER_LOADER_H

#include <string>

namespace Life
{
    class ShaderLoader
    {
    public:
        static int loadShaders(std::string vertPath, std::string fragPath);

    private:
        static int loadShader(std::string path, int type);
    };
}

#endif // LIFE_SHADER_LOADER_H
