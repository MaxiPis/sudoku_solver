from PIL import Image

def crop_image():
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
    diminishing = 25
    for x in range(9):
        for y in range(9):
            # Area sin recorte
            # area = (x_init, y_init, x_final, y_final)
            # Area con recorte
            left_less = diminishing + 5
            top_less = diminishing
            right_less = diminishing + 5
            bottom_less = diminishing
            area = (x_init + left_less, y_init + top_less, x_final - right_less, y_final - bottom_less) 

            x_init = x_final
            x_final += len_subgrid_x
            img_new = img.crop(area)
            # img_new = img_new.convert("1")
            name_img = f"img/i{x}_{y}.png"
            img_new.save(name_img)
        
        x_init = 0
        x_final = len_subgrid_x
        y_init = y_final
        y_final += len_subgrid_y

if __name__ == "__main__":
     crop_image()