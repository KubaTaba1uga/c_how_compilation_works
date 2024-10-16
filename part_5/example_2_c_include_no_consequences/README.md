# Przykład 2: Manipulacja Zmienną `static` Bez Konsekwencji

## 1. Opis
Ten przykład ilustruje, że przy odpowiednim użyciu testów, można manipulować zmienną `static` bez wprowadzania niepożądanych konsekwencji. Pokazuje to, jak `static` ogranicza dostęp do zmiennych, zapewniając ich izolację między modułami.

## 2. Struktura Plików
```
example_2/
├── caller_module.c
├── dummy_module.c
├── dummy_module.h
├── test_dummy_module_manipulation.c
├── CMakeLists.txt
└── README.md
```

## 3. Pliki Źródłowe

### 3.1. `dummy_module.h`
```c
#ifndef DUMMY_MODULE_H
#define DUMMY_MODULE_H

// Funkcja do inkrementacji licznika
int increment_counter(void);

// Funkcja do ustawiania licznika
void set_counter(int value);

#endif // DUMMY_MODULE_H
```

### 3.2. `dummy_module.c`
```c
#include "dummy_module.h"

static int counter = 0;

int increment_counter(void) {
    return ++counter;
}

void set_counter(int value) {
    counter = value;
}
```

### 3.3. `caller_module.c`
```c
#include "dummy_module.h"
#include <stdio.h>

void call_increment(void) {
    int value = increment_counter();
    printf("Counter value after increment: %d\n", value);
}
```

### 3.4. `test_dummy_module_manipulation.c`
```c
#include "dummy_module.h"
#include "caller_module.c" // Prawidłowe dołączanie modułu wywołującego

#include <assert.h>

int main() {
    set_counter(10);
    assert(increment_counter() == 11);
    call_increment(); // Powinno wypisać "Counter value after increment: 12"
    set_counter(20);
    assert(increment_counter() == 21);
    printf("Test manipulation passed successfully.\n");
    return 0;
}
```

### 3.5. `CMakeLists.txt`
```cmake
cmake_minimum_required(VERSION 3.10)
project(Example2)

set(CMAKE_C_STANDARD 99)

add_executable(test_dummy_module_manipulation test_dummy_module_manipulation.c dummy_module.c caller_module.c)
```

## 4. Kompilacja i Uruchomienie

1. Klonowanie Repozytorium:
   ```bash
   git clone <link_do_repozytorium>
   cd <repozytorium>/example_2
   ```

2. Tworzenie Katalogu Budowania i Konfiguracja CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   ```

3. Budowanie Projektu:
   ```bash
   make
   ```

4. Uruchomienie Testu:
   ```bash
   ./test_dummy_module_manipulation
   ```

## 5. Oczekiwane Wyniki
Po uruchomieniu testu powinny pojawić się następujące komunikaty:
```
Counter value after increment: 12
Test manipulation passed successfully.
```

## 6. Wyjaśnienie
- Moduł `dummy_module`: Zawiera zmienną `static int counter` oraz funkcje `increment_counter` i `set_counter` do manipulacji tą zmienną.
- Moduł `caller_module`: Zawiera funkcję `call_increment`, która wywołuje `increment_counter` i wypisuje aktualną wartość `counter`.
- Test `test_dummy_module_manipulation.c`: Testuje możliwość manipulacji zmienną `counter` poprzez ustawianie jej wartości i inkrementację, zapewniając, że zmienna jest izolowana i nie wpływa negatywnie na inne moduły.

## 7. Wnioski
Ten przykład pokazuje, jak `static` zapewnia izolację zmiennych między modułami, umożliwiając kontrolowaną manipulację zmiennymi bez ryzyka konfliktów czy niepożądanych konsekwencji.
```

---

### Przykład 3: Duplikacja Symboli i Desynchronizacja Kodu Spowodowana Dołączaniem Plików `.c`

```markdown
# Przykład 3: Duplikacja Symboli i Desynchronizacja Kodu Spowodowana Dołączaniem Plików `.c`

## 1. Opis
Ten przykład przedstawia scenariusz, w którym dołączanie plików `.c` bezpośrednio za pomocą dyrektywy `#include` prowadzi do duplikacji symboli. W efekcie dochodzi do desynchronizacji kodu, gdzie jedna część testu nie jest poprawnie inkrementowana przez `caller_module`, podczas gdy druga część działa prawidłowo.

## 2. Struktura Plików
```
example_3/
├── caller_module.c
├── dummy_module.c
├── dummy_module.h
├── test_dummy_module_duplication.c
├── CMakeLists.txt
└── README.md
```

## 3. Pliki Źródłowe

### 3.1. `dummy_module.h`
```c
#ifndef DUMMY_MODULE_H
#define DUMMY_MODULE_H

// Funkcja do inkrementacji licznika
int increment_counter(void);

#endif // DUMMY_MODULE_H
```

### 3.2. `dummy_module.c`
```c
#include "dummy_module.h"

static int counter = 0;

int increment_counter(void) {
    return ++counter;
}
```

### 3.3. `caller_module.c`
```c
#include "dummy_module.h"
#include <stdio.h>

void call_increment(void) {
    int value = increment_counter();
    printf("Counter value after increment: %d\n", value);
}
```

### 3.4. `test_dummy_module_duplication.c`
```c
#include "dummy_module.h"
#include "caller_module.c" // Nieprawidłowe dołączanie pliku `.c`, powoduje duplikację symboli
#include "dummy_module.c"  // Duplikacja modułu

#include <assert.h>

int main() {
    assert(increment_counter() == 1);
    call_increment(); // Powinno wypisać "Counter value after increment: 2"
    assert(increment_counter() == 3);
    printf("Test duplication failed to synchronize counters.\n");
    return 0;
}
```

### 3.5. `CMakeLists.txt`
```cmake
cmake_minimum_required(VERSION 3.10)
project(Example3)

set(CMAKE_C_STANDARD 99)

add_executable(test_dummy_module_duplication test_dummy_module_duplication.c dummy_module.c caller_module.c)
```

## 4. Kompilacja i Uruchomienie

1. Klonowanie Repozytorium:
   ```bash
   git clone <link_do_repozytorium>
   cd <repozytorium>/example_3
   ```

2. Tworzenie Katalogu Budowania i Konfiguracja CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   ```

3. Budowanie Projektu:
   ```bash
   make
   ```

4. Uruchomienie Testu:
   ```bash
   ./test_dummy_module_duplication
   ```

## 5. Oczekiwane Wyniki
Podczas kompilacji powinna wystąpić następująca wiadomość o błędzie:
```
/usr/bin/ld: duplicate symbol 'increment_counter' in:
    test_dummy_module_duplication.o
    dummy_module.o
/usr/bin/ld: duplicate symbol 'counter' in:
    test_dummy_module_duplication.o
    dummy_module.o
collect2: error: ld returned 1 exit status
```

## 6. Wyjaśnienie
- Problem Duplikacji Symboli:
  - Dołączanie plików `.c` bezpośrednio za pomocą `#include` powoduje, że kompilator traktuje zawartość tych plików jako część pliku testowego.
  - W rezultacie, symbole takie jak `increment_counter` i `counter` są definiowane wielokrotnie, co prowadzi do konfliktów podczas linkowania.
  
- Desynchronizacja Kodu:
  - Nawet jeśli uda się skompilować, zmienne `counter` będą miały oddzielne instancje w różnych częściach programu, prowadząc do niespójnych wyników.

- Rozwiązanie:
  - Unikanie dołączania plików `.c` bezpośrednio za pomocą `#include`.
  - Używanie plików nagłówkowych (`.h`) do deklaracji funkcji i zmiennych.
  - Stosowanie słowa kluczowego `static` dla zmiennych i funkcji, które mają być ograniczone do danego pliku źródłowego.

## 7. Poprawka Problemu
Aby naprawić problem, należy:
1. Usunięcie Dołączania Plików `.c`:
   - W pliku `test_dummy_module_duplication.c` usuń linie:
     ```c
     #include "caller_module.c"
     #include "dummy_module.c"
     ```
   - Zamiast tego, upewnij się, że pliki `.c` są kompilowane oddzielnie i linkowane razem.

2. Stosowanie `static` dla Zmiennych i Funkcji:
   - W module `dummy_module.c` upewnij się, że zarówno funkcje, jak i zmienne, które nie powinny być widoczne poza modułem, są oznaczone jako `static`.

3. Poprawny Proces Budowania:
   - Skonfiguruj CMake tak, aby kompilował wszystkie pliki `.c` oddzielnie i linkował je razem, unikając bezpośredniego dołączania plików `.c` w kodzie źródłowym.

## 8. Wnioski
Ten przykład pokazuje, jak nieprawidłowe dołączanie plików `.c` może prowadzić do poważnych problemów z duplikacją symboli i desynchronizacją kodu. Stosowanie `static` oraz prawidłowa organizacja procesu kompilacji są kluczowe dla uniknięcia takich problemów.

---

Mam nadzieję, że te pliki `README.md` pomogą w dokumentacji każdego z trzech przykładów. Jeśli potrzebujesz dodatkowych modyfikacji lub masz inne wymagania, daj znać!
