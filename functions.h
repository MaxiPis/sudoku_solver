#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void print_grid(int *grid[9]);
bool horizontal_check(int *grid[9]);
bool vertical_check(int *grid[9]);
bool subgrid_check(int *grid[9]);
bool partial_solution_check(int *grid[9]);

#endif