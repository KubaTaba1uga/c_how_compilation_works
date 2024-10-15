/*
 * example_2.c
 *
 * Opis:
 * Ten przykład demonstruje, jak preprocesor języka C przetwarza dyrektywy
 * `#include` dla plików nagłówkowych zdefiniowanych przez użytkownika.
 *
 * Plik `example_2.c` zawiera dyrektywę `#include "example_2_dep.h"`, która
 * wstawia zawartość pliku nagłówkowego podczas preprocessingu.
 *
 * Aby zobaczyć wynik preprocessingu, użyj komendy:
 *   gcc -E example_2.c -o example_2.i
 *
 * Plik `example_2.i` zawiera wynik działania preprocesora.
 * Otwórz ten plik w edytorze tekstu, aby zobaczyć, jak zawartość pliku
 * `example_2_dep.h` została wstawiona do `example_2.c`.
 */

#include "example_2_dep.h"

int main() {
  print_pi();
  return 0;
}
