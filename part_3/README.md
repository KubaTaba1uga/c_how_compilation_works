## Kompilacja statyczna:
Kompilacja statyczna oznacza, że wszystkie potrzebne biblioteki są dołączane bezpośrednio do pliku wykonywalnego programu. Oznacza to, że powstały plik binarny zawiera wszystko, co jest potrzebne do jego uruchomienia, niezależnie od konfiguracji systemu, na którym jest uruchamiany. Zalety takiego podejścia to:
1. Program może działać na każdym systemie bez konieczności instalowania dodatkowych bibliotek.
2. Brak problemów z niezgodnością wersji bibliotek, ponieważ wszystko jest zawarte w pliku wykonywalnym.

Jednak kompilacja statyczna ma również pewne wady:
1. Zwiększa rozmiar pliku wykonywalnego, ponieważ wszystkie biblioteki są w nim zawarte.
2. Modyfikacja czy aktualizacja bibliotek wymaga ponownej kompilacji całego programu.


## Kompilacja dynamiczna:
W przypadku kompilacji dynamicznej biblioteki nie są dołączane bezpośrednio do pliku wykonywalnego, lecz są ładowane podczas uruchamiania programu. Pozwala to na zmniejszenie rozmiaru pliku binarnego oraz na łatwiejszą aktualizację bibliotek bez potrzeby rekompilacji programu.

Zalety kompilacji dynamicznej to:
1. Mniejszy rozmiar pliku wykonywalnego.
2. Łatwość aktualizacji bibliotek – wystarczy zaktualizować bibliotekę w systemie, aby program korzystał z nowej wersji.

Wady tego podejścia to:
1. Wymaga obecności odpowiednich wersji bibliotek na systemie, na którym program jest uruchamiany.
2. Może prowadzić do problemów z niezgodnością wersji bibliotek (tzw. „dependency hell”).
