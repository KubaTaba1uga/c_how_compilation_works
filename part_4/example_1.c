/*
 * example_1.c
 *
 * Opis:
 * Ten plik źródłowy demonstruje wpływ słowa kluczowego `static` na widoczność
 * funkcji i zmiennych w języku C. W tym przykładzie korzystamy z dwóch plików
 * źródłowych: `example_1.c` i `example_1_dep.c`. Plik `example_1.c` zawiera
 * funkcje globalne oraz funkcje statyczne, które są widoczne tylko w obrębie
 * swojego pliku.
 *
 * Rola `static`:
 * - Funkcje i zmienne oznaczone jako `static` są ograniczone tylko do pliku
 * źródłowego, w którym zostały zdefiniowane.
 * - Funkcje i zmienne bez `static` są widoczne globalnie w całym programie i
 * mogą prowadzić do konfliktów nazw, jeśli nie zostaną odpowiednio
 * zorganizowane.
 *
 * Struktura plików:
 * - `example_1.c`: Główny plik programu zawierający funkcję `main` i globalną
 * funkcję `print_message`.
 * - `example_1_dep.c`: Plik pomocniczy zawierający funkcję o tej samej nazwie
 * `print_message` oraz funkcję statyczną `static_message`.
 *
 * Kompilowanie i Linkowanie plików obiektowych (program dynamiczny):
 *    gcc example_1.c example_1_dep.c -o example_1_program
 *
 * Oczekiwany błąd na etapie linkowania:
 * ```
 * /usr/bin/ld: example_1_dep.o: in function `print_message':
 * example_1_dep.c:(.text+0x0): multiple definition of `print_message';
 * example_1.o: first defined here collect2: error: ld returned 1 exit status
 * ```
 *
 * Wyniki:
 * - Funkcje globalne zdefiniowane w dwóch plikach `.c` powodują błąd
 * linkowania, ponieważ mają tę samą nazwę.
 * - Funkcje `static` są ograniczone do pliku źródłowego, co zapobiega
 * konfliktom nazw w różnych plikach.
 *
 * Analiza symboli:
 *    objdump -t example_1.o
 *    objdump -t example_1_dep.o
 *
 * Napraw blad wprowadzajac slowo kluczowe `static` do  example_1_dep.c.
 *
 * Oczekiwany wynik programu:\
 * ```
 * Welcome to the static function test.
 * Hello from example 1: counter = 0
 * Hello from example 1 dep: counter = 1
 * Hello from static function in file2
 * ```
 */
#include <stdio.h>

#include "example_1_dep.h"

// Deklaracja funkcji (funkcja bez `static`)
void print_message(void);

// Globalna zmienna
int counter = 0;

// Funkcja `main`, która wywołuje funkcje z plików zależnych
int main() {
  printf("Welcome to the static function test.\n");

  print_message(); // Funkcja z example_1.c lub example_1_dep.c (w zależności od
                   // kolejności linkowania)

  print_counter();
  // Próba wywołania funkcji `static_message` spowoduje błąd kompilacji,
  // ponieważ funkcja statyczna jest niewidoczna poza swoim plikiem.
  // static_message(); // Błąd: nie można znaleźć definicji tej funkcji

  return 0;
}

void print_message(void) {
  printf("Hello from example 1: counter = %d\n", counter);
}
