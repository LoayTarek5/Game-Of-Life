#pragma once
#ifndef CONTROLER_H
#define CONTROLER_H
#include <raylib.h>
#include "Grid.h"

class Controler {
protected:
    Grid grid;
    bool game_running;
    // vector<int> directions_8_x = {1, 1, 0, -1, -1, -1, 0, 1};
    // vector<int> directions_8_y = {0, 1, 1, 1, 0, -1, -1, -1};
public:
    Controler(int width, int height, int sz)
    : grid(width, height, sz), game_running(false)
    {
    };
    bool game_stat() {return  game_running;};
    // int count_cell_neighbors(int row, int col);
    void update_cell_stat();
    void stop(){game_running = false;};
    void run(){game_running = true;};
    void draw() { grid.draw(); };
    void set_cell(int row, int column, int stat) { grid.set_cell(row, column, stat); }
    void clear();
    void fill_random_cell();
    void toggle_cell_stat(int row, int column);

};



#endif //CONTROLER_H
