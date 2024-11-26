#include "Grid.h"

#include <stdlib.h>

void Grid::draw() const
{
    for(int row = 0; row < rows; row ++)
    {
        for(int column = 0; column < cols; column++)
        {
            Color color = status[row][column] ? Color{255, 255, 0, 255} : Color{55, 55, 55, 255};
            DrawRectangle(column * cell_size, row * cell_size, cell_size, cell_size, color);
            DrawRectangleLines(column * cell_size, row * cell_size, cell_size, cell_size, BLACK); // Optional: Add borders

        }
    }
}

void Grid::set_cell(int row, int col, int stat)
{
    if(check_bounds(row, col))
    {
        status[row][col] = stat;
    }
}

bool Grid::check_bounds(const int row, const int col) const
{
    if(row < 0 || row >= rows || col < 0 || col >= cols) return false;
    return true;
}

void Grid::fill_random_cell()
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            int randomValue = GetRandomValue(0, 1);
            set_cell(i, j, randomValue);
        }
    }
}

void Grid::clear()
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            set_cell(i, j, 0);
        }
    }
}

void Grid::toggle_cell_stat(int row, int col)
{
    if(check_bounds(row, col))
    {
        status[row][col] = !status[row][col];
    }
}

int Grid::get_cell_status(int row, int col)
{
    if(check_bounds(row, col))
    {
        return status[row][col];
    }
    return 0;
}

int Grid::count_cell_neighbors(int row, int col)
{
    int count_neighbors = 0;
    int num_rows = rows;
    int num_cols = cols;

    for(int i = 0; i < 8; i++)
    {
        int x = (row + directions_8_x[i] + num_rows) % num_rows;
        int y = (col + directions_8_y[i] + num_cols) % num_cols;
        count_neighbors += get_cell_status(x, y);
    }
    return count_neighbors;
}

void Grid::update_cell_stat()
{
    Grid next_grid = *this;

    for(int row = 0; row < rows; row++)
    {
        for(int column = 0; column < cols; column++)
        {
            int count_neighbors = count_cell_neighbors(row, column);
            int cellValue = get_cell_status(row, column);

            if(cellValue == 1)
            {
                if(count_neighbors > 3 || count_neighbors < 2)
                {
                    next_grid.set_cell(row, column, 0);
                }
                else
                {
                    next_grid.set_cell(row, column, 1);
                }
            }
            else
            {
                if(count_neighbors == 3)
                {
                    next_grid.set_cell(row, column, 1);
                }
                else
                {
                    next_grid.set_cell(row, column, 0);
                }
            }
        }
    }
    *this = next_grid;
}



