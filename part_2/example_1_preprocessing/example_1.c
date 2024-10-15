/*
 * example_1.c
 *
 * Aby zobaczyć wynik preprocessingu, użyj komendy:
 * gcc -E example_1.c -o example_1.i
 *
 * Plik `example_1.i` zawiera wynik działania preprocesora.
 * Otwórz ten plik w edytorze tekstu.
 *
 * Kiedy w swoim kodzie używasz dyrektywy #include <stdio.h>,
 * prosisz preprocesor o wstawienie całej zawartości pliku
 * stdio.h w miejsce tej dyrektywy.
 * Plik stdio.h może z kolei zawierać dyrektywy #include do
 * innych plików nagłówkowych, takich jak stdarg.h, stddef.h,
 * czy bits/types.h.
 */

#include <stdio.h>

#define PI 3.14159

void print_pi(void) { printf("Wartość PI to: %f\n", PI); }

int main() {
  print_pi();
  return 0;
}
