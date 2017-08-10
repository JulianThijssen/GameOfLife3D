#include "Simulation.h"

#include "Scene.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>

namespace Life {
    void Simulation::init(Scene& scene) {
        scene.init(GRID_WIDTH, GRID_HEIGHT);

        //scene.grid[9][7] = 1;
        //scene.grid[8][8] = 1;
        //scene.grid[9][8] = 1;
        //scene.grid[10][8] = 1;

        for (int y = 0; y < scene.height; y++) {
            for (int x = 0; x < scene.width; x++) {
                int alive = rand() % 2;
                scene.grid[x][y] = alive;
            }
        }
    }

    void Simulation::update(Scene& scene) {
        int** newGrid = new int*[scene.width];
        for (int i = 0; i < scene.height; i++) {
            newGrid[i] = new int[scene.height];
        }

        std::cout << "Performing simulation: " << scene.width << " " << scene.height << std::endl;
        for (int y = 0; y < scene.height; y++) {
            for (int x = 0; x < scene.width; x++) {
                int alive = scene.grid[x][y];
                int aliveNeighbours = 0;

                bool N, W, S, E, NW, SW, SE, NE;
                N = W = S = E = NW = SW = SE = NE = true;

                if (y >= scene.height - 1) { N = NW = NE = false; }
                if (y <= 0) { S = SW = SE = false; }
                if (x >= scene.width - 1) { E = NE = SE = false; }
                if (x <= 0) { W = NW = SW = false; }

                

                if (N) aliveNeighbours += scene.grid[x][y+1];
                if (W) aliveNeighbours += scene.grid[x-1][y];
                if (S) aliveNeighbours += scene.grid[x][y-1];
                if (E) aliveNeighbours += scene.grid[x+1][y];
                if (NW) aliveNeighbours += scene.grid[x-1][y+1];
                if (SW) aliveNeighbours += scene.grid[x-1][y-1];
                if (SE) aliveNeighbours += scene.grid[x+1][y-1];
                if (NE) aliveNeighbours += scene.grid[x+1][y+1];

                newGrid[x][y] = alive;
                if (alive) {
                    //std::cout << x << " " << y << " " << aliveNeighbours << std::endl;
                    //printf("N: %d, W: %d, S: %d, E: %d, NW: %d, SW: %d, SE: %d, NE: %d\n", scene.grid[x][y + 1], scene.grid[x - 1][y], scene.grid[x][y - 1], scene.grid[x + 1][y], scene.grid[x - 1][y + 1], scene.grid[x - 1][y - 1], scene.grid[x + 1][y - 1], scene.grid[x + 1][y + 1]);
                    if (aliveNeighbours < 2 || aliveNeighbours > 3) {
                        newGrid[x][y] = 0;
                    }
                }
                else {
                    if (aliveNeighbours == 3) {
                        newGrid[x][y] = 1;
                    }
                }
            }
        }
        std::cout << "Done simulation" << std::endl;

        for (int y = 0; y < scene.height; y++) {
            for (int x = 0; x < scene.width; x++) {
                scene.grid[x][y] = newGrid[x][y];
            }
        }
    }
}
