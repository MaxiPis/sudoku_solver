// main.c

#include <stdio.h>

int main()
{
    // Aqui estamos diciendo que a x asignamos el valor 4.

    int x = 4;
    // Aqui decimos que al puntero de tipo int le asignamos la
    // ubicacion en memoria de x.
    // & la direccion (address)
    // inmasdgadsg
    int *px = &x;
    // Cuando esta en el lado dereho, estamos diciendo
    // la cosa apuntada por el puntero
    int y = *px;

    printf("Hello from CMake project!\n");
    return 0;
}
// gcc functions.c -o functions
// ./functions