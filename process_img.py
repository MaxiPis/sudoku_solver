from PIL import Image

def main():
    img = Image.open("img/image.png")

    # Obtenemos el largo de la imagen
    x, y = img.width, img.height

    # Calculamos el largo de cada sub-imagen
    len_subgrid_x = x//9
    len_subgrid_y = y//9

    x_init = 0
    y_init = 0
    x_final = len_subgrid_x
    y_final = len_subgrid_y

    #  (left, top, right, bottom)
    area = (x_init, y_init, x_final, y_final)
    for x in range(9):
        for y in range(9):
            area = (x_init, y_init, x_final, y_final)
            x_init = x_final
            x_final += len_subgrid_x
            img_new = img.crop(area)
            name_img = f"img/i{x}_{y}.png"
            img_new.save(name_img)
        
        x_init = 0
        x_final = len_subgrid_x
        y_init = y_final
        y_final += len_subgrid_y

if __name__ == "__main__":
    main()