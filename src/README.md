# PPC_Project_semester_1
# Program: System zarządzania prywatną biblioteką

## Cel
Celem programu jest stworzenie konsolowego systemu do zarządzania
prywatną biblioteką książek. Program umożliwia dodawanie, usuwanie,
edycję, wyszukiwanie książek oraz generowanie raportów na podstawie
danych przechowywanych w pliku CSV.

Projekt został wykonany w języku C w celu nauki pracy z:
- strukturami,
- wskaźnikami,
- dynamiczną alokacją pamięci,
- plikami tekstowymi,
- menu konsolowym.

## Pliki projektu
- `book.h / book.c` – struktura Book oraz wprowadzanie danych od użytkownika
- `library_state.h / library_state.c` – przechowywanie i obsługa stanu biblioteki
- `csv_io.h / csv_io.c` – zapis i odczyt danych z pliku CSV
- `reports.h / reports.c` – generowanie raportów na podstawie danych
- `menu_controller.h / menu_controller.c` – obsługa menu użytkownika
- `main.c` – punkt wejścia programu
- `library.csv` – plik z danymi książek
- `README.md` – opis projektu

## Struktura programu
1. Program uruchamia się w trybie konsolowym.
2. Tworzona jest struktura `Library_state`, która przechowuje dynamiczną
   tablicę książek.
3. Użytkownik porusza się po menu za pomocą wyborów liczbowych.
4. Dostępne operacje:
   - wczytanie danych z pliku CSV,
   - dodanie nowej książki,
   - usunięcie książki po ID,
   - edycja książki,
   - wyświetlenie wszystkich książek,
   - wyszukiwanie książek po ID, tytule, autorze i roku,
   - generowanie raportów.
5. Raporty nie modyfikują danych biblioteki – jedynie je analizują.
6. Po zakończeniu programu dane są zapisywane do pliku `library.csv`.
7. Przed zakończeniem działania programu zwalniana jest cała
   dynamicznie zaalokowana pamięć.

## Raporty
Program umożliwia generowanie następujących raportów:
- lista autorów książek wydanych po podanym roku,
- lista autorów książek w zadanym przedziale lat,
- lista N najnowszych książek,
- najstarsza i najnowsza książka w bibliotece.

## Instrukcja uruchomienia
1. Kompilacja programu:
   gcc -Wall -Wextra main.c csv_io.c library_state.c book.c reports.c menu_controller.c -o main.exe
2. Uruchomienie programu:
   .\main.exe
3. Obsługa programu odbywa się poprzez menu konsolowe.

## Przykład działania
Stan biblioteki zostal utworzony poprawnie.
Witaj w systemie zarzadzania biblioteka!   

MENU:
1. Wczytaj baze ksiazek z pliku CSV        
2. Dodaj ksiazke
3. Usun ksiazke
4. Edytuj ksiazke

Wyszukiwania:
5. Wyswietl wszystkie ksiazki  
6. Znajdz ksiazke po ID        
7. Znajdz ksiazki po tytule    
8. Znajdz ksiazki po autorze   
9. Znajdz ksiazki z danego roku

Raporty:
10. Raport: autor po roku X
11. Raport: autor w przedziale lat
12. Raport: TOP N najnowszych
13. Raport: najstarsza i najnowsza ksiazka

Twoj wybor: 5
Brak ksiazek w bibliotece.

Twoj wybor: 1
Plik 'library.csv' zostal wczytany. Liczba ksiazek w pamieci: 6

Twoj wybor: 5
Find all books. ID: 1, Tytul: straznik, Autor: p.hendel, Rok: 2014
Find all books. ID: 2, Tytul: tropiciel, Autor: p.hendel, Rok: 2014
Find all books. ID: 3, Tytul: lowca, Autor: p.hendel, Rok: 2014
Find all books. ID: 4, Tytul: wyslannik, Autor: p.hendel, Rok: 2020
Find all books. ID: 5, Tytul: demon, Autor: p.hendel, Rok: 2022
Find all books. ID: 6, Tytul: szeptucha, Autor: k.b.miszczuk, Rok: 2016

Twoj wybor: 2
Podaj tytul: koralina  
Podaj autora: n.gaiman
Podaj rok: 2003

Twoj wybor: 5
Find all books. ID: 1, Tytul: straznik, Autor: p.hendel, Rok: 2014
Find all books. ID: 2, Tytul: tropiciel, Autor: p.hendel, Rok: 2014
Find all books. ID: 3, Tytul: lowca, Autor: p.hendel, Rok: 2014
Find all books. ID: 4, Tytul: wyslannik, Autor: p.hendel, Rok: 2020
Find all books. ID: 5, Tytul: demon, Autor: p.hendel, Rok: 2022
Find all books. ID: 6, Tytul: szeptucha, Autor: k.b.miszczuk, Rok: 2016
Find all books. ID: 7, Tytul: koralina, Autor: n.gaiman, Rok: 2003

Twoj wybor: 4
Podaj ID ksiazki: 7
Podaj ID ksiazki do edycji: Podaj nowe dane ksiazki:
Podaj tytul: karolina
Podaj autora: n.gaiman
Podaj rok: 2003
Ksiazka o ID 7 zostala zaktualizowana.

Twoj wybor: 5
Find all books. ID: 1, Tytul: straznik, Autor: p.hendel, Rok: 2014
Find all books. ID: 2, Tytul: tropiciel, Autor: p.hendel, Rok: 2014
Find all books. ID: 3, Tytul: lowca, Autor: p.hendel, Rok: 2014
Find all books. ID: 4, Tytul: wyslannik, Autor: p.hendel, Rok: 2020
Find all books. ID: 5, Tytul: demon, Autor: p.hendel, Rok: 2022
Find all books. ID: 6, Tytul: szeptucha, Autor: k.b.miszczuk, Rok: 2016
Find all books. ID: 7, Tytul: karolina, Autor: n.gaiman, Rok: 2003

Twoj wybor: 3
Podaj ID ksiazki: 7
Ksiazka o ID 7 zostala usunieta pomyslnie.

Twoj wybor: 4
Podaj ID ksiazki: 7
Podaj ID ksiazki do edycji: Nie znaleziono ksiazki o ID 7.

Twoj wybor: 2
Podaj tytul: koralina
Podaj autora: n.gaiman
Podaj rok: 2003

Twoj wybor: 56
Nieprawidlowy wybor. Sprobuj ponownie.

Twoj wybor: 5
Find all books. ID: 1, Tytul: straznik, Autor: p.hendel, Rok: 2014
Find all books. ID: 2, Tytul: tropiciel, Autor: p.hendel, Rok: 2014
Find all books. ID: 3, Tytul: lowca, Autor: p.hendel, Rok: 2014
Find all books. ID: 4, Tytul: wyslannik, Autor: p.hendel, Rok: 2020
Find all books. ID: 5, Tytul: demon, Autor: p.hendel, Rok: 2022
Find all books. ID: 6, Tytul: szeptucha, Autor: k.b.miszczuk, Rok: 2016
Find all books. ID: 8, Tytul: koralina, Autor: n.gaiman, Rok: 2003

Twoj wybor: 6
Podaj ID ksiazki: 7
Nie znaleziono ksiazki o podanym ID: 7

Twoj wybor: 6
Podaj ID ksiazki: 2
Find by id. Znaleziono ksiazke: ID: 2, Tytul: tropiciel, Autor: p.hendel, Rok: 2014

Twoj wybor: 7
Podaj tytul ksiazki: koralina
Szukany tytul: koralina
Find by title. Znaleziono 1 rezultatow.
ID: 8, Tytul: koralina, Autor: n.gaiman, Rok: 2003

Twoj wybor: 7
Podaj tytul ksiazki: karolina
Szukany tytul: karolina
Nie znaleziono ksiazki o podanym tytule: karolina

Twoj wybor: 8
Podaj autora ksiazki: p.hendel 
Find by author. Znaleziono 5 rezultatow.
ID: 1, Tytul: straznik, Autor: p.hendel, Rok: 2014
ID: 2, Tytul: tropiciel, Autor: p.hendel, Rok: 2014
ID: 3, Tytul: lowca, Autor: p.hendel, Rok: 2014
ID: 4, Tytul: wyslannik, Autor: p.hendel, Rok: 2020
ID: 5, Tytul: demon, Autor: p.hendel, Rok: 2022

Twoj wybor: 8
Podaj autora ksiazki: n.gaiman
Find by author. Znaleziono 1 rezultatow.
ID: 8, Tytul: koralina, Autor: n.gaiman, Rok: 2003

Twoj wybor: 8
Podaj autora ksiazki: hendel
Nie znaleziono ksiazki tego autora: hendel

Twoj wybor: 9
Podaj rok: 2005 
Nie znaleziono ksiazki z podanego roku: 2005

Twoj wybor: 9
Podaj rok: 2022
Find by year. Znaleziono 1 rezultatow.
ID: 5, Tytul: demon, Autor: p.hendel, Rok: 2022

Twoj wybor: 9
Podaj rok: 2014
Find by year. Znaleziono 3 rezultatow.
ID: 1, Tytul: straznik, Autor: p.hendel, Rok: 2014
ID: 2, Tytul: tropiciel, Autor: p.hendel, Rok: 2014
ID: 3, Tytul: lowca, Autor: p.hendel, Rok: 2014

Twoj wybor: 2
Podaj tytul: gniewa
Podaj autora: k.b.miszczuk
Podaj rok: 2022

Twoj wybor: 10
Podaj rok: 2018
Autorzy ksiazek wydanych po roku 2018:
- p.hendel
- p.hendel
- k.b.miszczuk

Twoj wybor: 10
Podaj rok: 2023
Autorzy ksiazek wydanych po roku 2023:
Nie znaleziono ksiazek wydanych po roku 2023.

Twoj wybor: 11
Podaj rok poczatkowy: 2015
Podaj rok koncowy: 2025
Autorzy ksiazek wydanych w latach 2015 - 2025:
- p.hendel
- p.hendel
- k.b.miszczuk
- k.b.miszczuk

Twoj wybor: 11
Podaj rok poczatkowy: 2023
Podaj rok koncowy: 2025
Autorzy ksiazek wydanych w latach 2023 - 2025:

Twoj wybor: 12
Podaj ile najnowszych ksiazek chcesz zobaczyc: 3
TOP 3 najnowszych ksiazek:
ID: 5, Tytul: demon, Autor: p.hendel, Rok: 2022
ID: 9, Tytul: gniewa, Autor: k.b.miszczuk, Rok: 2022
ID: 4, Tytul: wyslannik, Autor: p.hendel, Rok: 2020

Twoj wybor: 13
Najstarsza ksiazka: ID 8, Tytul: koralina, Autor: n.gaiman, Rok: 2003
Najnowsza ksiazka: ID 5, Tytul: demon, Autor: p.hendel, Rok: 2022