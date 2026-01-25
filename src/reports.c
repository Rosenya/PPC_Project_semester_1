#include "include/reports.h"
#include "include/library_state.h"
#include "include/book.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

void report_author_after_given_year(Library_state* state) {
    if (state->count == 0) {
        printf("Biblioteka jest pusta.\n");
        return;
    }

    char buffer[32];
    long year;
    char *endptr;

    printf("Podaj rok: ");
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        printf("Blad odczytu.\n");
        return;
    }

    year = strtol(buffer, &endptr, 10); //strtol konwertuje string na long z walidacja
    if (endptr == buffer || *endptr != '\n') {
        printf("Nieprawidlowe dane. Podaj liczbe calkowita.\n");
        return;
    }

    int found = 0;
    printf("Autorzy ksiazek wydanych po roku %ld:\n", year);
    for (size_t i = 0; i < state->count; i++) {
        if (state->book_list[i].year >= year) {
            printf("- %s\n", state->book_list[i].author);
            found = 1;
        }
    }

    if (!found) {
        printf("Nie znaleziono ksiazek wydanych po roku %ld.\n", year);
    }
}

void report_author_for_year_range(Library_state* state) {
    if (state->count == 0) {
        printf("Biblioteka jest pusta.\n");
        return;
    }

    char buffer[32];
    long start_year, end_year;
    char *endptr;

    printf("Podaj rok poczatkowy: ");
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        printf("Blad odczytu.\n");
        return;
    }
    start_year = strtol(buffer, &endptr, 10);
    if (endptr == buffer || (*endptr != '\n' && *endptr != '\0')) {
        printf("Nieprawidlowe dane. Podaj liczbe calkowita.\n");
        return;
    }

    printf("Podaj rok koncowy: ");
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        printf("Blad odczytu.\n");
        return;
    }
    end_year = strtol(buffer, &endptr, 10);
    if (endptr == buffer || (*endptr != '\n' && *endptr != '\0')) {
        printf("Nieprawidlowe dane. Podaj liczbe calkowita.\n");
        return;
    }

    if (start_year > end_year) {
        printf("Niepoprawny przedzial lat: poczatek wiekszy od konca.\n");
        return;
    }

    int found = 0;
    printf("Autorzy ksiazek wydanych w latach %ld - %ld:\n", start_year, end_year);
    for (size_t i = 0; i < state->count; i++) {
        int year = state->book_list[i].year;
        if (year >= start_year && year <= end_year) {
            printf("- %s\n", state->book_list[i].author);
            found = 1;
        }
    }

    if (!found) {
        printf("Nie znaleziono ksiazek w zadanym przedziale lat.\n");
    }
}

void report_newest_books_of_given_amount(Library_state* state) {
    if (state->count == 0) {
        printf("Biblioteka jest pusta.\n");
        return;
    }

    size_t amount;
    char buffer[32];
    printf("Podaj ile najnowszych ksiazek chcesz zobaczyc: ");
    fgets(buffer, sizeof(buffer), stdin);
    amount = (size_t)strtoul(buffer, NULL, 10);

    if (amount == 0) {
        printf("Nie podano poprawnej liczby ksiazek.\n");
        return;
    }

    size_t result_count = (amount < state->count) ? amount : state->count;

    Book* temp = malloc(sizeof(Book) * state->count);
    if (!temp) return;
    memcpy(temp, state->book_list, sizeof(Book) * state->count);

    for (size_t i = 0; i < state->count - 1; i++) {
        for (size_t j = i + 1; j < state->count; j++) {
            if (temp[i].year < temp[j].year) {
                Book t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    printf("TOP %zu najnowszych ksiazek:\n", result_count);
    for (size_t i = 0; i < result_count; i++) {
        printf("ID: %d, Tytul: %s, Autor: %s, Rok: %d\n",
               temp[i].book_id, temp[i].title, temp[i].author, temp[i].year);
    }

    free(temp);
}

void report_oldest_and_newest_books(Library_state* state) {
    if (state->count == 0) {
        printf("Biblioteka jest pusta.\n");
        return;
    }

    Book oldest = state->book_list[0];
    Book newest = state->book_list[0];

    for (size_t i = 1; i < state->count; i++) {
        if (state->book_list[i].year < oldest.year) {
            oldest = state->book_list[i];
        }
        if (state->book_list[i].year > newest.year) {
            newest = state->book_list[i];
        }
    }

    printf("Najstarsza ksiazka: ID %d, Tytul: %s, Autor: %s, Rok: %d\n",
           oldest.book_id, oldest.title, oldest.author, oldest.year);
    printf("Najnowsza ksiazka: ID %d, Tytul: %s, Autor: %s, Rok: %d\n",
           newest.book_id, newest.title, newest.author, newest.year);
}