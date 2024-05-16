#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PALABRAS 1000
#define MAX_LONGITUD 50

int main() {s
  char texto[MAX_PALABRAS * MAX_LONGITUD];
  int palabras[MAX_LONGITUD] = {0};
  int longitudTexto, i, longitudPalabra;

  // Leer el texto del usuario
  printf("Ingrese el texto: ");
  fgets(texto, sizeof(texto), stdin);

  // Eliminar el caracter de nueva línea al final del texto
  longitudTexto = strlen(texto);
  if (texto[longitudTexto - 1] == '\n') {
    texto[longitudTexto - 1] = '\0';
    longitudTexto--;
  }

  // Contar las palabras y su longitud
  i = 0;
  longitudPalabra = 0;
  for (int j = 0; j < longitudTexto; j++) {
    if (texto[j] == ' ' || texto[j] == '\0') {
      if (longitudPalabra > 0) {
        palabras[longitudPalabra - 1]++;
        longitudPalabra = 0;
      }
      i++;
    } else {
      longitudPalabra++;
    }
  }

  // Imprimir el histograma
  printf("\nHistograma de la cantidad de palabras:\n");
  for (int j = 0; j < MAX_LONGITUD; j++) {
    if (palabras[j] > 0) {
      printf("Palabras de longitud %d: %d\n", j + 1, palabras[j]);
    }
  }

  return 0;
}
