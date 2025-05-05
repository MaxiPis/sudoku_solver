from crop_image import crop_image
from convert_to_bw import image_to_black_and_white
from recognize_number import recognize_number
import subprocess
import os

def main():
    # Recortamos la imagen 
    print("Recortando imagen...")
    crop_image()
    grid = []
    row = []
    # Iteramos por cada imagen
    print("Reconociendo cada imagen...")
    for i in range(9):
        for j in range(9):
            path = f"img/i{i}_{j}.png"
            # Convertimos en blanco y negro cada imagen
            image_to_black_and_white(path)
            # Reconocemos el numero y lo guardamos en la lista
            numero = recognize_number(path)
            row.append(numero)
        grid.append(row)
        
        row = []
    # print(grid)
    print("Guardando en formato .txt...")
    with open("sudoku_grid.txt", "w") as file:
        string_grid = ""
        for row in grid:
            counter = 0
            for column in row:
                string_grid += f"{column} "
                counter += 1
                if counter == 3:
                    string_grid += " "
                    counter = 0
            string_grid += "\n"
        string_grid = string_grid[:-1]
        file.write(string_grid)

    c_file = 'main.c'
    c_file_functions = 'functions.c'
    executable = 'main'

    print(f"Compilando {c_file, c_file_functions}...")
    subprocess.run(['gcc', c_file, c_file_functions,'-o', executable], check=True)

    # Ejecutar el programa C compilado
    print(f"Ejecutando el programa compilado {executable}...")
    subprocess.run(['./' + executable], check=True)



if __name__ == "__main__":
    main()