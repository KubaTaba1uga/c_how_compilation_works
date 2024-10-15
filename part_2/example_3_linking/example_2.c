/*
 * example_2.c
 *
 * Opis:
 * Ten plik źródłowy w języku C jest głównym plikiem programu, który demonstruje
 * prawidłowe użycie plików nagłówkowych (.h) oraz osobnych plików źródłowych
 * (.c) do tworzenia modularnego i łatwo utrzymywalnego projektu.
 *
 * Struktura plików:
 * - `example_2.c`: Główny plik źródłowy, który zawiera funkcję `main`.
 * - `example_2_dep.c`: Plik źródłowy zawierający definicje funkcji `print_pi`.
 * - `example_2_dep.h`: Plik nagłówkowy deklarujący funkcje `print_pi`.
 *
 * Proces kompilacji:
 * 1. Kompilacja `example_2.c` do `example2.o`:
 *    gcc -c example_2.c -o example_2.o
 *
 * 2. Kompilacja `example_2_dep.c` do `example2_dep.o`:
 *    gcc -c example_2_dep.c -o example_2_dep.o
 *
 * 3. Linkowanie plików obiektowych za pomocą `ld` w celu utworzenia programu
 *    wykonywalnego:
 *    - Dla linkowania dynamicznego:
 *      ld -dynamic-linker /lib64/ld-linux-x86-64.so.2   \
          /usr/lib/x86_64-linux-gnu/crt1.o              \
          /usr/lib/x86_64-linux-gnu/crti.o              \
          /usr/lib/x86_64-linux-gnu/crtn.o              \
          -lc example_2.o example_2_dep.o               \
          -o example_2_dynamic_program
 *
 *    - Dla linkowania statycznego:
 *      ld -static                          \
          /usr/lib/x86_64-linux-gnu/crt1.o \
          /usr/lib/x86_64-linux-gnu/crti.o \
          /usr/lib/x86_64-linux-gnu/crtn.o \
          -lc example_2.o example_2_dep.o  \
          -o example_2_static_program
 *
 * Uruchomienie Programów:
 *
 * - Dynamiczny:
 *   Upewnij się, że biblioteka dynamiczna jest w ścieżce:
 *   export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
 *   ./example2_dynamic_program
 *
 * - Statyczny:
 *   ./example2_static_program
 *
 * Oczekiwany Wynik po Uruchomieniu Programów:
 *
 * ```
 * Welcome to Awesome App

 * ```
 *
 * Analiza Symboli za pomocą `ldd` i `objdump`:
 *
 * ```sh
 * ldd example2_dynamic_program
 * objdump -T example2_dynamic_program
 * ldd example2_static_program
 * objdump -t example2_static_program
 * ```
 *
 * Dlaczego używanie `ld` wymaga ręcznego dołączania plików startowych i
 * bibliotek:
 *
 * Kiedy używasz `ld` bezpośrednio, bierzesz na siebie odpowiedzialność za
 * dołączenie wszystkich niezbędnych plików startowych oraz bibliotek. `ld`
 * jest niskopoziomowym narzędziem do linkowania, które nie posiada wbudowanej
 * wiedzy o tym, które pliki są potrzebne do prawidłowego uruchomienia
 * programu. Dlatego musisz ręcznie określić pliki startowe i biblioteki.
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
 * wejścia, co spowoduje błędy podczas linkowania lub uruchamiania.
 * Więcej informacji tutaj: https://wiki.osdev.org/Creating_a_C_Library
 */

#include "example_2_dep.h"
#include <stdio.h>

const char app_id[] = "Awesome Math App";

int main() {
  printf("Welcome to %s\n", app_id);
  print_pi();
  return 0;
}
