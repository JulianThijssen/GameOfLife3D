#ifndef LIFE_SCENE_H
#define LIFE_SCENE_H

namespace Life
{
    class Scene
    {
    public:
        void init(unsigned int width, unsigned int height) {
            this->width = width;
            this->height = height;

            grid = new int*[width];
            for (int i = 0; i < height; i++) {
                grid[i] = new int[height];
            }

            for (int y = 0; y < height; y++) {
                for (int x = 0; x < width; x++) {
                    grid[x][y] = 0;
                }
            }
        }

        int** grid;

        unsigned int width, height;
    };
} // namespace Life

#endif LIFE_SCENE_H
