/*
 * example_1.c
 *
 * Opis:
 * Ten plik źródłowy w języku C jest głównym plikiem programu, który demonstruje
 * prawidłowe użycie plików nagłówkowych (.h) oraz osobnych plików źródłowych
 * (.c) do tworzenia modularnego i łatwo utrzymywalnego projektu.
 *
 * Program wyświetla powitanie zawierające identyfikator aplikacji oraz wartość
 * stałej PI, wykorzystując funkcję `print_pi` zdefiniowaną w pliku
 * `example_1_dep.c`.
 *
 * Struktura plików:
 * - `example_1.c`: Główny plik źródłowy, który zawiera funkcję `main`.
 * - `example_1_dep.c`: Plik źródłowy zawierający definicję funkcji `print_pi`.
 * - `example_1_dep.h`: Plik nagłówkowy deklarujący funkcję `print_pi`.
 *
 * Proces kompilacji:
 * 1. Kompilacja `example_1.c` do `example1.o`:
 *    gcc -c example_1.c -o example1.o
 *
 * 2. Kompilacja `example_1_dep.c` do `example1_dep.o`:
 *    gcc -c example_1_dep.c -o example1_dep.o
 *
 * 3. Linkowanie plików obiektowych za pomocą `ld` w celu utworzenia programu
 * wykonywalnego:
 *    ld -dynamic-linker /lib64/ld-linux-x86-64.so.2   \
         /usr/lib/x86_64-linux-gnu/crt1.o	       \
         /usr/lib/x86_64-linux-gnu/crti.o              \
         /usr/lib/x86_64-linux-gnu/crtn.o              \
         /usr/lib/x86_64-linux-gnu/crtn.o              \
         example1.o example1_dep.o -lc -o example1_program
 *
 * Oczekiwany Wynik po Uruchomieniu Programu:
 *
 * ```
 * Welcome in Super math app
 * The value of pi is approximately 3.141590
 * ```
 *
 * Analiza Symboli za pomocą `objdump`:
 *
 * ```sh
 * objdump -t example1.o
 * objdump -t example1_dep.o
 * objdump -t example1_program
 * ```
 *
 * Kiedy używasz `ld` bezpośrednio, bierzesz na siebie odpowiedzialność za
 *  dołączenie wszystkich niezbędnych plików startowych oraz bibliotek. `ld`
 *  jest niskopoziomowym narzędziem do linkowania, które nie posiada wbudowanej
 *  wiedzy o tym, które pliki są potrzebne do prawidłowego uruchomienia
 *  programu. Dlatego musisz ręcznie określić pliki startowe i biblioteki.
 *
 * Pliki Startowe:
 * - `crt1.o`
 * - `crti.o`
 * - `crtn.o`
 *
 * Biblioteki:
 * - `libc.a` lub `libc.so`
 *
 * Bez dołączenia tych plików, program nie będzie miał poprawnego punktu
 *  wejścia, co spowoduje błędy podczas linkowania lub uruchamiania.
 *  Wiecej informacji tutaj: https://wiki.osdev.org/Creating_a_C_Library
 */

#include <stdio.h>

#include "example_1_dep.h"

const char app_id[] = "Super math app";

int main() {
  printf("Welcome in %s\n", app_id);
  print_pi();
  return 0;
}