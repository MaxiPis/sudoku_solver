import cv2
import pytesseract

def recognize_number(path):
    # Cargar la imagen
    imagen = cv2.imread(path)
    if imagen is None:
        print("No se pudo cargar la imagen.")
        return 0

    # Convertir a escala de grises
    gris = cv2.cvtColor(imagen, cv2.COLOR_BGR2GRAY)

    # Opcional: umbral para mejorar el OCR
    _, binaria = cv2.threshold(gris, 150, 255, cv2.THRESH_BINARY_INV)

    # Configurar Tesseract para detectar solo dígitos
    config = r'--oem 3 --psm 6 outputbase digits'

    texto = pytesseract.image_to_string(binaria, config=config).strip()

    # Filtrar texto para dejar solo dígitos
    digitos = ''.join(filter(str.isdigit, texto))

    # Si no hay dígitos, devolvemos 0
    return int(digitos) if digitos else 0


if __name__ == "__main__": 
    path = f"img/i0_2.png"
    numero = recognize_number(path)

# ruta_imagen = 'img/i5_4.png'  # Cambia esto por tu imagen

