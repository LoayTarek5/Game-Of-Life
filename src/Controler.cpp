#include "Controler.h"

void Controler::update_cell_stat()
{
    if(game_running) {
        grid.update_cell_stat();
    }
}

void Controler::clear()
{
    if(!game_stat())
    {
        grid.clear();
    }
}

void Controler::fill_random_cell()
{
    if(!game_stat())
    {
        grid.fill_random_cell();
    }
}

void Controler::toggle_cell_stat(int row, int column)
{
    if(!game_stat())
    {
        grid.toggle_cell_stat(row, column);
    }
}


