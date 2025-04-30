#include <stdio.h>
#include <stdlib.h>

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

    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < column; j++)
    //     {
    //         printf("%d", grid[i][j]);
    //     }
    // }
    print_grid(grid);
}