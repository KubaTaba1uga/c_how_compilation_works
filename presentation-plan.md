### **Plan Prezentacji: Kompilowanie w C na Przykładzie Biblioteki Baresip**

---

#### **1. Wprowadzenie**
   - **Cel Prezentacji:**
     - Przedstawienie procesu kompilacji w języku C.
     - Zrozumienie różnic między kompilacją statyczną a dynamiczną.
     - Analiza wpływu słowa kluczowego `static` na widoczność funkcji i zmiennych.
     - Omówienie dobrych praktyk w organizacji kodu źródłowego.
   - **Agenda:**
     1. Proces kompilacji w C
     2. Kompilacja statyczna vs dynamiczna
     3. Rola słowa kluczowego `static`
     4. Praktyczne przykłady z Baresip
     5. Strategie testowania i najlepsze praktyki
     6. Sesja pytań i odpowiedzi

---

#### **2. Proces Kompilacji w C: Preprocessing, Kompilacja, Linkowanie**
   - **Etapy Kompilacji:**
     - **Preprocessing:**
       - Działanie dyrektyw preprocesora (`#include`, `#define`, makra).
       - Przykład: Analiza pliku `example_1.c` z dyrektywami `#include` i `#define`.
       - Demonstracja wyniku preprocessingu (`gcc -E example_1.c -o example_1.i`).
     - **Kompilacja:**
       - Tłumaczenie kodu źródłowego na kod maszynowy.
       - Tworzenie plików obiektowych (`.o`).
       - Przykład kompilacji: `gcc -c example_1.c -o example_1.o`.
     - **Linkowanie:**
       - Łączenie plików obiektowych w jeden plik wykonywalny lub bibliotekę.
       - Omówienie komendy `ld` i jej roli w procesie linkowania.
       - Przykład linkowania: `gcc example1.o example1_dep.o -o example1_program`.

---

#### **3. Kompilacja Statyczna vs Dynamiczna**
   - **Kompilacja Statyczna:**
     - **Definicja:** Wszystkie niezbędne biblioteki są dołączane bezpośrednio do pliku wykonywalnego.
     - **Zalety:**
       1. Program może działać na każdym systemie bez dodatkowych zależności.
       2. Uniknięcie problemów z niezgodnością wersji bibliotek.
     - **Wady:**
       1. Większy rozmiar pliku wykonywalnego.
       2. Konieczność ponownej kompilacji przy aktualizacji bibliotek.
     - **Przykład:** Kompilacja z użyciem flagi `-static`.
   - **Kompilacja Dynamiczna:**
     - **Definicja:** Biblioteki są ładowane podczas uruchamiania programu.
     - **Zalety:**
       1. Mniejszy rozmiar pliku wykonywalnego.
       2. Łatwiejsza aktualizacja bibliotek bez rekompilacji programu.
     - **Wady:**
       1. Wymaga obecności odpowiednich wersji bibliotek na systemie docelowym.
       2. Możliwość wystąpienia problemów z zależnościami (dependency hell).
     - **Przykład:** Standardowa kompilacja bez flagi `-static`.

---

#### **4. Rola Słowa Kluczowego `static` w C**
   - **Znaczenie `static`:**
     - Ograniczenie widoczności funkcji i zmiennych do danego pliku źródłowego.
     - Zapobieganie konfliktom nazw w różnych plikach.
   - **Zastosowanie `static` dla Funkcji:**
     - Definicja funkcji `static` w pliku `example_1_dep.c`.
     - Przykład braku konfliktów przy wielokrotnych definicjach funkcji `print_message`.
   - **Zastosowanie `static` dla Zmiennych:**
     - Rola `static` w utrzymaniu stanu zmiennych między wywołaniami funkcji.
     - Przykład zmiennych `static` w `example_1.c` i `example_1_dep.c`.
   - **Praktyczne Przykłady:**
     - Analiza plików `example_1.c`, `example_1_dep.c`, `example_2.c`.
     - Rozwiązywanie problemów z wielokrotnymi definicjami symboli.
   - **Najlepsze Praktyki:**
     - Kiedy używać `static` dla funkcji i zmiennych.
     - Unikanie konfliktów nazw poprzez odpowiednią organizację kodu.

---

#### **5. Praktyczne Przykłady z Biblioteką Baresip**
   - **Struktura Projektu Baresip:**
     - Omówienie kluczowych plików i ich roli (np. `compile_baresip.sh`, `dummy_module.c`).
   - **Analiza Skryptów Budujących:**
     - Przegląd skryptów `compile_baresip.sh`, `compile_re.sh`, `download.sh`.
     - Automatyzacja procesu kompilacji i instalacji.
   - **Moduły i Testy:**
     - Omówienie modułu `dummy_module` i jego funkcji.
     - Analiza testów w `test_something.c` i ich roli w weryfikacji funkcjonalności.
   - **Inspekcja Symboli:**
     - Użycie narzędzia `objdump` do analizy symboli w plikach obiektowych.
     - Przykłady analiz dla różnych scenariuszy kompilacji.
   - **Rozwiązywanie Problemów:**
     - Przykłady błędów kompilacji i linkowania.
     - Metody debugowania i naprawy problemów z widocznością symboli.

---

### **Materiały Dodatkowe**
   - **Repozytorium Kodów Źródłowych:**
     - Dostępne na: [Link do Repozytorium](https://github.com/KubaTaba1uga/c_how_compilation_works)
   - **Dokumentacja Baresip:**
     - [Baresip Documentation](https://github.com/baresip/baresip/wiki)
   - **Narzędzia do Analizy Symboli:**
     - `objdump` – [Instrukcja Użycia](https://linux.die.net/man/1/objdump)








