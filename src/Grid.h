#pragma once
#ifndef GRID_H
#define GRID_H
#include <raylib.h>
#include <vector>
using namespace std;

class Grid
{
protected:
    int rows;
    int cols;
    int cell_size;
    vector<vector<int>> status;
    vector<int> directions_8_x = {1, 1, 0, -1, -1, -1, 0, 1};
    vector<int> directions_8_y = {0, 1, 1, 1, 0, -1, -1, -1};

public:
    Grid(const int width, const int height, const int sz)
    : rows(height/sz), cols(width/sz), cell_size(sz), status(rows, std::vector<int>(cols, 0)) {};
    void resize(const int width, const int height, const int sz) {
        rows = height/sz;
        cols = width/sz;
        cell_size = sz;

        // Reinitialize status with new dimensions
        status.clear();
        status.resize(rows, std::vector<int>(cols, 0));
    }
    void draw() const;
    void set_cell(int row,int col, int stat);
    bool check_bounds(int row, int col) const;
    void fill_random_cell();
    void clear();
    void toggle_cell_stat(int row, int col);
    int get_cell_status(int row, int col);
    int get_rows() {return rows;}
    int get_cols() {return cols;}
    int count_cell_neighbors(int row, int col);
    void update_cell_stat();
};



#endif //GRID_H
