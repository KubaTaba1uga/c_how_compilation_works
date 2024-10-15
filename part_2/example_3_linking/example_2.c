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
 * 1. Kompilacja `example_2.c` do `example_2.o`:
 *    gcc -c example_2.c -o example_2.o
 *
 * 2. Kompilacja `example_2_dep.c` do `example_2_dep.o`:
 *    gcc -c example_2_dep.c -o example_2_dep.o
 *
 * 3. Linkowanie plików obiektowych za pomocą `ld` w celu utworzenia programu
 *    wykonywalnego:
 *    - Dla linkowania dynamicznego:
 *      ld -dynamic-linker /lib64/ld-linux-x86-64.so.2  \
          /usr/lib/x86_64-linux-gnu/crt1.o              \
          /usr/lib/x86_64-linux-gnu/crti.o              \
          /usr/lib/x86_64-linux-gnu/crtn.o              \
          -lc example_2.o example_2_dep.o               \
          -o example_2_dynamic_program
 *
 *    - Dla linkowania statycznego:
 *      ld -static \
          /usr/lib/x86_64-linux-gnu/crt1.o \
          /usr/lib/x86_64-linux-gnu/crti.o \
          /usr/lib/x86_64-linux-gnu/crtn.o \
          example_2.o			     \
          example_2_dep.o \
          --start-group \
              /usr/lib/gcc/x86_64-linux-gnu/12/libgcc.a \
              /usr/lib/gcc/x86_64-linux-gnu/12/libgcc_eh.a \
              /usr/lib/x86_64-linux-gnu/libc.a \
          --end-group \
          -o example_2_static_program
 *
 * Uruchomienie Programów:
 *
 * - Dynamiczny:
 *   Upewnij się, że biblioteka dynamiczna jest w ścieżce:
 *   export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
 *   ./example_2_dynamic_program
 *
 * - Statyczny:
 *   ./example_2_static_program
 *
 * Oczekiwany Wynik po Uruchomieniu Programów:
 *
 * ```
 * Welcome in Super math app
 * The value of pi is approximately 3.141590
 * ```
 *
 * Analiza Symboli za pomocą `ldd` i `objdump`:
 *    ldd example_2_dynamic_program
 *    objdump -T example_2_dynamic_program
 *    ldd example_2_static_program
 *    objdump -t example_2_static_program
 *
 * Wyjaśnienie wyniku `ldd`:
 * Kiedy uruchamiasz `ldd example_2_dynamic_program`, zobaczysz następujący
 wynik:
 *
 * ```
 * linux-vdso.so.1 (0x00007ffd073ef000)
 * libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007d5e29de9000)
 * /lib64/ld-linux-x86-64.so.2 (0x00007d5e29fe1000)
 * ```
 *
 * Wyjaśnienie:
 * 1. `linux-vdso.so.1`:
 *    - Virtual Dynamic Shared Object (VDSO) to specjalna biblioteka dostarczana
 *         przez kernel w celu optymalizacji wywołań systemowych.
 *    - Jest mapowana bezpośrednio do przestrzeni adresowej procesu w celu
 *         szybszego wykonywania niektórych wywołań systemowych.
 *
 * 2. `libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6`:
 *    - Jest to biblioteka GNU C (glibc), która dostarcza standardowe funkcje
 *         języka C, takie jak `printf` i `scanf`.
 *    - Jest wymagana przez większość programów w języku C i jest dynamicznie
 *         ładowana podczas uruchamiania programu.
 *
 * 3. `/lib64/ld-linux-x86-64.so.2`:
 *    - Jest to dynamiczny linker/loader odpowiedzialny za ładowanie i
 *         linkowanie bibliotek dynamicznych podczas uruchamiania programu.
 *    - Rozwiązuje zależności bibliotek i mapuje je do przestrzeni pamięci
 *         procesu.
 *
 * Używaj polecenia `ldd`, aby zobaczyć, jakie biblioteki współdzielone są
 *    wymagane przez programy linkowane dynamicznie i zweryfikować, czy
 *    wszystkie zależności są poprawnie rozwiązane.
 *
 */
#include <stdio.h>

#include "example_2_dep.h"

const char app_id[] = "Super math app";

int main() {
  printf("Welcome to %s\n", app_id);
  print_pi();
  return 0;
}
