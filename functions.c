#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

void print_grid(int *grid[9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", grid[i][j]);
            if (j == 2 || j == 5)
                printf(" ");
        }

        if (i == 2 || i == 5)
            printf("\n");

        printf("\n");
    }
}

bool horizontal_check(int *grid[9])
{
    // Creamos un arreglo para almacenar los números repetidos
    int *repeated_numbers;
    repeated_numbers = calloc(9, sizeof(int));

    int current_number;

    // Revisamos si hay elementos repeitdos en cada fila
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            current_number = grid[i][j];
            if (current_number != 0)
            {
                if (repeated_numbers[current_number - 1] == 0)
                    repeated_numbers[current_number - 1] = 1;
                else
                {
                    free(repeated_numbers);
                    return false;
                }
            }
        }
        free(repeated_numbers);
        repeated_numbers = calloc(9, sizeof(int));
    }
    free(repeated_numbers);
    return true;
}

bool vertical_check(int *grid[9])
{
    int *repeated_numbers;
    repeated_numbers = calloc(9, sizeof(int));
    int current_number;
    for (int j = 0; j < 9; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            current_number = grid[i][j];
            if (current_number != 0)
            {
                if (repeated_numbers[current_number - 1] == 0)
                    repeated_numbers[current_number - 1] = 1;
                else
                {
                    free(repeated_numbers);
                    return false;
                }
            }
        }
        free(repeated_numbers);
        repeated_numbers = calloc(9, sizeof(int));
    }
    free(repeated_numbers);
    return true;
}

bool subgrid_check(int *grid[9])
{
    int *repeated_numbers;
    repeated_numbers = calloc(9, sizeof(int));
    int current_number;

    for (int k = 0; k < 3; k++)
    {
        int row = k * 3;
        for (int c = 0; c < 3; c++)
        {
            int column = c * 3;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    current_number = grid[row + i][column + j];
                    if (current_number != 0)
                    {
                        if (repeated_numbers[current_number - 1] == 0)
                            repeated_numbers[current_number - 1] = 1;
                        else
                        {
                            free(repeated_numbers);
                            return false;
                        }
                    }
                }
            }
            free(repeated_numbers);
            repeated_numbers = calloc(9, sizeof(int));
        }
    }
    free(repeated_numbers);
    return true;
}

bool partial_solution_check(int *grid[9])
{

    bool horizontal_info = horizontal_check(grid);
    if (horizontal_info == false)
        return false;

    bool vertical_info = vertical_check(grid);
    if (vertical_info == false)
        return false;

    bool subgrid_info = subgrid_check(grid);
    if (subgrid_info == false)
        return false;
    // En cualquier otro caso, cumple con las restricciones
    return true;
}
