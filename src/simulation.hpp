#pragma once
#include "grid.hpp"

class Simulation
{
public:
    Simulation(int width, int height, int cell_size)
        : grid(width, height, cell_size), temp_grid(width, height, cell_size) { grid.FillRandom(); };
    void Draw();
    void SetCellValue(int row, int column, int value);
    int CountLiveNeighbors(int row, int column);
    void Update();

private:
    Grid grid;
    Grid temp_grid;
};