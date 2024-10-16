/*
 * example_3.c
 *
 * Opis:
 * Ten plik źródłowy bezpośrednio dołącza inny plik źródłowy `.c` za pomocą
 * dyrektywy `#include`.
 *
 * Struktura plików:
 * - `example_3.c`: Główny plik programu, który zawiera funkcję `main` i
 *                  bezpośrednio dołącza plik `example_3_dep.c`.
 * - `example_3_dep.c`: Plik zawierający funkcję `print_pi`.
 *
 * Kompilacja plików obiektowych:
 *    gcc -c example_3.c -o example_3.o
 *    gcc -c example_3_dep.c -o example_3_dep.o
 *
 * Kompilacja dynamiczna:
 *    gcc example_3.o -o example_3_dynamic_program
 *
 * Kompilacja statyczna:
 *    gcc -static example_3.o -o example_3_static_program
 * Oczekiwany wynik programu:
 * ```
 * Welcome to Super math app
 * The value of pi is approximately 3.141590
 * ```
 *
 * Błąd na etapie linkowania:
 *    gcc example_3.o example_3_dep.o -o example_3_dynamic_program_with_err
 *
 * Kontent błedu na etapie linkowania:
 * ```
 * /usr/bin/ld: example_3_dep.o: in function `print_pi':
 * example_3_dep.c:(.text+0x0): multiple definition of `print_pi';
 * example_3.o:example_3.c:(.text+0x0): first defined here /usr/bin/ld:
 * example_3_dep.o: in function `main': example_3_dep.c:(.text+0x20): multiple
 * definition of `main'; example_3.o:example_3.c:(.text+0x20): first defined
 * here collect2: error: ld returned 1 exit status
 * ```
 *
 * Na podstawie błędów możemy wyciągnąć dwa wnioski:
 *  1. W przypadku includowania plików `.c` błędy występują dopiero na etapie
 * linkowania.
 *  2. Błędy występują, jeśli próbujemy zlinkować plik `.c` wraz z plikiem
 * zawierającym `#include`. Gdyby plik `.c` nie zawierał symboli globalnych,
 * błąd by nie wystąpił.
 *
 * Analiza symboli:
 *    objdump -t example_3.o
 *    objdump -t example_3_dep.o
 *
 */

#include <stdio.h>

// Bezpośrednie dołączenie pliku źródłowego `.c`
#include "example_3_dep.c"

const char app_id[] = "Super math app";

int main() {
  printf("Welcome to %s\n", app_id);
  print_pi();
  return 0;
}
