import cv2

def image_to_black_and_white(path):
    # Leer imagen en escala de grises
    img = cv2.imread(path, cv2.IMREAD_GRAYSCALE)

    # Aplicar umbral binario: los píxeles > 128 serán blancos (255), los otros negros (0)
    _, bw = cv2.threshold(img, 128, 255, cv2.THRESH_BINARY)

    # Guardar y mostrar
    cv2.imwrite(path, bw)


if __name__ == "__main__":    
    path = "img/i8_4.png"
    image_to_black_and_white(path)
