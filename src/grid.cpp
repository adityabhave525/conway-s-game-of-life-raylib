#include "grid.hpp"
#include <raylib.h>

void Grid::Draw()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            Color color = cells[row][column] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
            DrawRectangle(column * cell_size, row * cell_size, cell_size - 1, cell_size - 1, color);
        }
    }
}

void Grid::SetValue(int row, int column, int value)
{
    if (row >= 0 && row < rows && column >= 0 && column < columns)
    {
        cells[row][column] = value;
    }
}
