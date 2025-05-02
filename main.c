#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

bool backtracking_solver(int *grid[9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int n = 1; n < 10; n++)
            {
                int current_number = grid[i][j];
                if (current_number == 0)
                {
                    grid[i][j] = n;
                    if (partial_solution_check(grid))
                    {
                        bool check_return = backtracking_solver(grid);
                        if (check_return == false)
                            grid[i][j] = 0;
                    }
                    else

                        grid[i][j] = 0;
                }
            }
            if (grid[i][j] == 0)
                return false;
        }
    }

    return true;
}

void main()
{
    // Solicitamos memoria para la matriz de 9X9
    int rows = 9;
    int *grid[rows];
    int column = 9;

    for (int i = 0; i < rows; i++)
    {
        // Definimos que cada fila tenga 9 columnas
        grid[i] = malloc(column * sizeof(int));
    }

    // Importamos el .txt
    FILE *file;
    file = fopen("sudoku_grid.txt", "r");

    int num1;
    int num2;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < column; j++)
        {
            fscanf(file, "%d ", &grid[i][j]);
            // printf("%d ", grid[i][j]);
        }
    }
    backtracking_solver(grid);
    bool solution_bool = subgrid_check(grid);
    if (solution_bool)
        printf("Hay solucion \n");
    print_grid(grid);

    // for (int i = 0; i < 1000; i++)
    // {
    //     bool partial_solution_info;
    //     partial_solution_info = partial_solution_check(grid);

    //     printf("%d \n", i);
    // }
}