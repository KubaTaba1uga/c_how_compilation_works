### **Plan prezentacji: Kompilowanie w C na przykładzie biblioteki Baresip**

---

**1. Wprowadzenie do spotkania**
   - **Cel spotkania**: Przedstawienie procesu kompilacji w C na przykładzie biblioteki Baresip, z naciskiem na zrozumienie różnic między kompilacją statyczną a dynamiczną oraz wpływu użycia `static` na widoczność funkcji i zmiennych. Po prezentacji planujemy omówić strategie testowania aplikacji w kontekście zdobytej wiedzy.
   - **Plan prezentacji**:
     - Omówienie procesu kompilacji w C: preprocessing, kompilacja, linkowanie.
     - Różnice między kompilacją statyczną a dynamiczną.
     - Wpływ słowa kluczowego `static` na widoczność funkcji i zmiennych.
     - Dobre praktyki w zakresie importowania plików `.c` i `.h`.
     - Omówienie strategii kompilacji i wyboru między kompilacją statyczną a dynamiczną w projekcie Baresip.
     - **Inspekcja kompilacji repozytorium Baresip**: Analiza testów wykonywalnych i plików obiektowych.
     - Sesja Q&A i omówienie zadań do dalszej dyskusji.
   - **Uczestnicy**: Zespół odpowiedzialny za rozwój i testowanie Baresip.
   - **Czas trwania**: 1 godzina, z możliwością wydłużenia o 15 minut na pytania.

---

**2. Proces kompilacji w C: preprocessing, kompilacja, linkowanie**
   - **Opis procesu**:
     - **Preprocessing**: Omówienie, jak działa `#include`, `#define`, makra i ich wpływ na kod przed kompilacją.
     - **Kompilacja**: Tłumaczenie kodu na kod maszynowy i tworzenie plików obiektowych (`.o`).
     - **Linkowanie**: Łączenie plików obiektowych w plik wykonywalny lub bibliotekę.
   - **Przykład 1: Preprocessing w praktyce**
     - Prezentacja prostego programu C z użyciem `#include` i `#define`.
     - Przedstawienie wyniku preprocessingu przy użyciu `gcc -E` i omówienie rezultatów.
   - **Przykład 2: Tworzenie pliku obiektowego**
     - Kompilacja pliku `main.c` do pliku obiektowego (`main.o`) przy użyciu `gcc -c`.
     - Omówienie zawartości pliku `.o` i jego znaczenia w procesie linkowania.
   - **Przykład 3: Linkowanie**
     - Przykład użycia `gcc` do połączenia plików obiektowych w plik wykonywalny.
     - Omówienie komendy `ld` i analizy powstałego pliku wykonywalnego.

---

**3. Różnice między kompilacją statyczną a dynamiczną**
   - **Definicje i różnice**:
     - Kompilacja statyczna: Biblioteki są dołączane bezpośrednio do pliku wykonywalnego.
     - Kompilacja dynamiczna: Biblioteki są ładowane podczas uruchamiania programu, co zmniejsza rozmiar pliku wykonywalnego, ale wymaga obecności bibliotek na systemie.
   - **Przykład 4: Kompilacja statyczna vs. dynamiczna z Baresip**
     - Przykład kompilacji aplikacji z użyciem biblioteki Baresip w sposób statyczny (`gcc -static`) i dynamiczny (`gcc` bez opcji `-static`).
     - **Analiza rozmiaru plików wynikowych**: Porównanie wielkości pliku `.exe` oraz wpływu na wydajność.
     - **Analiza symboli**: Użycie `nm` i `objdump` do analizy symboli w obu przypadkach.
     - **Wnioski**: Kiedy warto stosować każdą metodę, zależnie od potrzeb aplikacji i środowiska docelowego.

---

**4. Wpływ słowa kluczowego `static` na widoczność funkcji i zmiennych**
   - **Wyjaśnienie działania `static` w C**:
     - Rola `static` w ograniczaniu widoczności funkcji i zmiennych do danego pliku źródłowego.
     - Zastosowanie `static` dla zmiennych globalnych i funkcji.
   - **Przykład 5: Funkcje `static` i zwykłe w różnych plikach**
     - Analiza, co się dzieje, gdy dwa pliki `.c` zawierają funkcje o tych samych nazwach:
       - Dwa pliki z funkcjami `print_message()`.
       - Dwa pliki z funkcjami `static_message()` z użyciem `static`.
     - Omówienie wyników kompilacji:
       - **W przypadku funkcji zwykłych**: Błąd "multiple definition".
       - **W przypadku `static`**: Brak konfliktów dzięki ograniczeniu widoczności.
   - **Przykład 6: Zmienne `static` i importowanie plików `.c`**
     - Co się dzieje, gdy plik `file1.c` zawiera zmienną `int counter` i `static int static_counter`, a `file2.c` używa `#include "file1.c"`.
     - Omówienie widoczności zmiennych oraz potencjalnych błędów związanych z ich wielokrotnym definiowaniem.
   - **Wnioski**: Zalety i zagrożenia związane z używaniem `static` oraz jak to może pomóc w ograniczeniu zakresu symboli.

---

**5. Inspekcja kompilacji repozytorium Baresip**
   - **Sprawdzenie plików obiektowych**:
     - Analiza plików `.o`, które powstały podczas kompilacji, przy pomocy narzędzi takich jak `nm`, `objdump`.
     - Przegląd funkcji i symboli znajdujących się w obiektach oraz ich relacje w procesie linkowania.
   - **Testy wykonywalne**:
     - Omówienie procesu kompilacji pliku testowego w repozytorium Baresip.
     - Sprawdzenie, jakie obiekty i funkcje są używane przez testy.
     - Analiza, czy są testowane wszystkie kluczowe ścieżki i funkcjonalności aplikacji.

---

**6. Omówienie strategii kompilacji w projekcie Baresip**
   - **Dyskusja nad wyborem między kompilacją statyczną a dynamiczną w projekcie Baresip**:
     - Zalety i wady obu podejść w kontekście projektu.
     - Jakie czynniki powinny wpływać na wybór strategii (np. wielkość pliku, potrzeba dystrybucji, możliwość aktualizacji).
   - **Propozycje zadań do dalszej pracy**:
     - Utworzenie zadań w backlogu dotyczących przetestowania obu metod kompilacji na przykładzie aplikacji korzystającej z Baresip.
     - Określenie testów jednostkowych i integracyjnych dla aplikacji Baresip po przeanalizowaniu wpływu `static`.
     - Omówienie wpięcia tych zadań do najbliższego sprintu z priorytetem normalnym.

---

**7. Podsumowanie i sesja Q&A**
   - **Podsumowanie kluczowych punktów**:
     - Proces kompilacji w C, różnice między kompilacją statyczną i dynamiczną, znaczenie `static`.
     - Dobre praktyki w zakresie organizacji kodu i importowania plików.
   - **Sesja Q&A**: Odpowiedzi na pytania i rozwianie wątpliwości uczestników.
   - **Omówienie zadania do dalszej dyskusji**:
     - Zdefiniowanie następnych kroków i dalszych działań zespołu.
   - **Podziękowania**: Spotkanie zakończone wspólną kawą.

---

### **Materiały dodatkowe:**
   - **Repozytorium kodu**: Przykłady kodu są dostępne w repozytorium (link do repozytorium).
   - **Dokumentacja Baresip**: `https://baresip.org/documentation.html`
   - **Narzędzia do analizy symboli**: `nm`, `objdump` - instrukcje użycia dostępne w repozytorium.

---

### **Kryteria akceptacji - Sprawdzenie:**
- Prezentacja zawiera dokładne omówienie procesu kompilacji w C z przykładami oraz wyjaśnieniem wszystkich kluczowych zagadnień.
- Przykłady kodu są dostępne w repozytorium, działają poprawnie i są zgodne z biblioteką Baresip.
- Zespół lepiej rozumie różnice między kompilacją statyczną a dynamiczną, wpływ `static

` i sposób organizacji plików `.c` i `.h`.
- Zostały zdefiniowane zadania do dyskusji w zakresie wyboru strategii testowania i kompilacji w projekcie Baresip.
