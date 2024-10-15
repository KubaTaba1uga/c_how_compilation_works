/*
 * example_2.c
 *
 * Opis:
 * Ten plik źródłowy w języku C demonstruje, co się dzieje, gdy zamiast
 * dołączać plik nagłówkowy (.h), dołączamy bezpośrednio plik źródłowy (.c)
 * za pomocą dyrektywy `#include`. Taka praktyka jest **niepoprawna** i
 * może prowadzić do błędów kompilacji, takich jak podwójne definicje symboli.
 *
 * Struktura plików:
 * - `example_2.c`: Główny plik źródłowy, który dołącza `example_2_dep.c`.
 * - `example_2_dep.c`: Plik źródłowy zawierający definicję funkcji `print_pi`.
 *
 * Aby skompilować ten plik do pliku obiektowego, użyjemy komendy:
 *   gcc -c example_1.c -o example_2.o
 *
 * Aby wyświetlić listę symboli w pliku obiektowym, użyj komendy:
 *   objdump -t example_2.o
 *
 * Porownaj tablice symboli example_1.o i example_2.o.
 */

#include <stdio.h>

#include "example_2_dep.c" // Niepoprawne dołączanie pliku .c

const char app_id[] = "Super math app";

int main() {
  printf("Welcome in %s\n", app_id);
  print_pi();
  return 0;
}
