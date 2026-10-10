#include <vector>
#include <utility>
#include "simulation.hpp"

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value)
{
    grid.SetValue(row, column, value);
}

int Simulation::CountLiveNeighbors(int row, int column)
{
    int live_neighbors = 0;
    std::vector<std::pair<int, int>> neighbor_offsets =
        {
            {-1, 0},  // Directly above
            {1, 0},   // Directly below
            {0, -1},  // To the left
            {0, 1},   // To the right
            {-1, -1}, // Diagonal upper left
            {-1, 1},  // Diagonal upper right
            {1, -1},  // Diagonal lower left
            {1, 1}    // Diagonal lower right
    };

    for (const auto &offset : neighbor_offsets)
    {
        int neighbor_row = (row + offset.first + grid.GetRows()) % grid.GetRows();
        int neighbor_column = (column + offset.second + grid.GetColumns()) % grid.GetColumns();

        live_neighbors += grid.GetValue(neighbor_row, neighbor_column);
    }

    return live_neighbors;
}
