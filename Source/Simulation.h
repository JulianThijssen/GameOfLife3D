#ifndef LIFE_SIMULATION_H
#define LIFE_SIMULATION_H

namespace Life
{
    class Scene;

    class Simulation
    {
    public:
        void init(Scene& scene);

        void update(Scene& scene);
    private:
        const int GRID_WIDTH = 512;
        const int GRID_HEIGHT = 512;

    };
} // namespace Life

#endif LIFE_SIMULATION_H
