/*
 * example_3.c
 *
 * Opis:
 * Ten przykład demonstruje, co się dzieje, gdy plik źródłowy `.c` jest
 * dołączany bezpośrednio za pomocą dyrektywy `#include`. Plik `example_3_dep.c`
 * jest włączany, a funkcja `print_pi` jest wywoływana w funkcji `main`.
 *
 * Aby zobaczyć wynik preprocessingu, użyj komendy:
 *   gcc -E example_3.c -o example.i
 *
 * Uwaga:
 * Dołączanie plików `.c` za pomocą `#include` jest ogólnie uważane za złą
 * praktykę. Zamiast tego zaleca się kompilowanie plików `.c` oddzielnie i
 * linkowanie ich. Ten przykład służy do ilustracji wpływu takiego podejścia
 * na kod zrodlowy w etapie preprocessingu.
 */

#include "example_3_dep.c"

int main() {
  print_pi();
  return 0;
}
