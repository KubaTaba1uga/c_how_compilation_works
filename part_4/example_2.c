/*
 * example_2.c
 *
 * Opis:
 * Ten plik źródłowy demonstruje użycie funkcji i zmiennych statycznych w języku
 * C. Zawiera funkcję `print_message()`, która jest ograniczona widocznością
 * tylko do tego pliku, oraz funkcję `main()`, która wywołuje funkcje z tego
 * pliku oraz z pliku zależnego (`example_1_dep.c`).
 *
 * Zmienna `counter` jest statyczna, co oznacza, że jej wartość jest zachowywana
 * między wywołaniami, ale dostęp do niej jest ograniczony tylko do tego pliku.
 *
 * Funkcje:
 * - `print_message()`: Wyświetla wartość zmiennej `counter`.
 * - `main()`: Wywołuje `print_message()` oraz funkcję `print_counter()` z pliku
 * `example_1_dep.c`.
 *
 * Struktura plików:
 * - `example_2.c`: Plik główny zawierający funkcję `main()` oraz funkcję
 * `print_message()`.
 * - `example_1_dep.c`: Zawiera funkcję `print_counter()` oraz lokalną funkcję
 * `print_message()`.
 *
 * Oczekiwane błędy:
 * - Kompilator wyświetli błąd wielokrotnej definicji zmiennej `counter`,
 *   ponieważ zarówno `example_2.c`, jak i `example_1_dep.c` definiują zmienną
 *   statyczną o tej samej nazwie.
 * - Podobnie wystąpi błąd wielokrotnej definicji funkcji `print_message()`,
 *   ponieważ obie funkcje w obu plikach mają tę samą sygnaturę.
 *
 * Kompilacja:
 *    gcc example_2.c -o example_2_program
 *
 * Oczekiwane błędy kompilacji:
 * ```
 * example_2.c:41:12: error: redefinition of ‘counter’
 *    41 | static int counter = 0;
 *       |            ^~~~~~~
 * In file included from example_2.c:35:
 * example_1_dep.c:5:12: note: previous definition of ‘counter’ with type ‘int’
 *    5 | static int counter = 0;
 *       |            ^~~~~~~
 * example_2.c:57:6: error: redefinition of ‘print_message’
 *    57 | void print_message(void) {
 *       |      ^~~~~~~~~~~~~
 * example_1_dep.c:15:6: note: previous definition of ‘print_message’ with type
 * ‘void(void)’
 *    15 | void print_message(void) { printf("Hello from example 1 dep: "); };
 *       |      ^~~~~~~~~~~~~
 * ```
 *
 * Wnioski:
 *  1. Słowo kluczowe `static` nie rozwiązuje wszystkich konfliktów symboli
 *     jeśli używamy inkludowania plików `.c`. Rozwiązuje tylko niektóre z nich.
 */

#include <stdio.h>

#include "example_1_dep.c" // Importowanie pliku z wielokrotną definicją

// Deklaracja funkcji statycznej `print_message`
static void print_message(void);

// Zmienna statyczna `counter`, widoczna tylko w tym pliku
static int counter = 0;

// Funkcja `main`, która wywołuje funkcje z tego i zależnego pliku
int main() {
  printf("Welcome to the static function test.\n");

  // Wywołanie lokalnej funkcji `print_message`
  print_message();

  // Wywołanie funkcji `print_counter` z pliku example_1_dep.c
  print_counter();

  return 0;
}

// Definicja funkcji `print_message`, która wyświetla wartość `counter`
void print_message(void) {
  printf("Hello from example 1: counter = %d\n", counter);
}
