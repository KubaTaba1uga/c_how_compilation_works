/*
 * example_1.c
 *
 * Opis:
 * Ten plik źródłowy zawiera prosty program w języku C, który demonstruje
 * podstawowe elementy programowania, takie jak użycie funkcji `printf`, makr,
 * deklaracji funkcji poprzez plik nagłówkowy oraz zmiennych globalnych i
 * statycznych.
 *
 * Aby skompilować ten plik do pliku obiektowego, użyjemy komendy:
 *   gcc -c example_1.c -o example_1.o
 *   gcc -c example_1_dep.c -o example_1_dep.o
 *
 * Plik `example_1.o` będzie zawierał skompilowany kod maszynowy, który można
 * analizować za pomocą narzędzia `objdump`.
 *
 * Aby wyświetlić listę symboli w pliku obiektowym, użyj komendy:
 *   objdump -t example_1.o
 *   objdump -t example_dep.o
 *
 * Obok poszczególnych symboli zobaczysz oznaczenia takie jak:
 *   - **g**: Symbol globalny (Global symbol)
 *     - **Globalny** oznacza, że symbol jest widoczny i dostępny z innych
 * plików obiektowych oraz bibliotek. Może być używany do łączenia różnych
 * modułów programu.
 *   - **l**: Symbol lokalny (Local symbol)
 *     - **Lokalny** oznacza, że symbol jest widoczny tylko w obrębie pliku
 * obiektowego, w którym jest zdefiniowany. Nie jest dostępny z innych modułów
 * programu.
 *   - **w**: Słaby symbol (Weak symbol)
 *     - **Słaby** symbol umożliwia zdefiniowanie symbolu, który może być
 * zastąpiony przez symbol o tej samej nazwie, ale o wyższym priorytecie (np.
 * globalny) podczas procesu linkowania. Słabe symbole są użyteczne do
 * definiowania domyślnych wartości, które mogą być nadpisane przez użytkownika.
 *   - **U**: Niezdefiniowany symbol (Undefined symbol)
 *     - **Niezdefiniowany** symbol oznacza, że symbol jest zadeklarowany, ale
 * nie zdefiniowany w analizowanym pliku obiektowym. Oczekuje się, że zostanie
 * zdefiniowany w innym pliku obiektowym lub bibliotece podczas linkowania.
 *   - **F**: Funkcja (Function)
 *     - **Funkcja** oznacza, że symbol reprezentuje kod wykonywalny, czyli
 * funkcję.
 *   - **O**: Obiekt (Object)
 *     - **Obiekt** oznacza, że symbol reprezentuje dane, takie jak zmienne lub
 * tablice.
 *   - **C**: Symbol common (Common symbol)
 *     - **Symbol common** to symbol, który rezerwuje przestrzeń dla zmiennych
 * nieinicjalizowanych. Jeśli podczas linkowania znajdą się inne definicje tego
 * symbolu, przestrzeń zostanie dostosowana.
 *   - **A**: Symbol absolutny (Absolute symbol)
 *     - **Symbol absolutny** ma stałą wartość i nie jest powiązany z żadną
 * sekcją. Jest używany do definiowania wartości, które nie mogą być
 * modyfikowane.
 *
 * Flagi mogą być łączone, aby dokładniej określić właściwości symbolu. Na
 * przykład:
 *   - **gw**: Globalny i słaby symbol
 *     - Oznacza, że symbol jest globalny, ale jego definicja może być
 * zastąpiona przez inną definicję podczas linkowania.
 *   - **lF**: Lokalna funkcja
 *     - Oznacza, że symbol jest lokalny i reprezentuje funkcję.
 *
 * Obiekty i funkcje oznaczone slowem `static` beda mialy symbol localny obok
 * siebie.
 */
#include <stdio.h>

#include "example_1_dep.h"

const char app_id[] = "Super math app";

int main() {
  printf("Welcome in %s\n", app_id);
  print_pi();
  return 0;
}
