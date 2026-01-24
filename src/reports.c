#include "include/reports.h"
#include "include/library_state.h"
#include "include/book.h"
#include <stdio.h>
#include <stdlib.h> 

Book* find_newest_books_of_given_amount(Library_state* state) {
    if (state->count == 0) {
        printf("Biblioteka jest pusta.\n");
        return NULL;
    }

    size_t amount;
    char buffer[32];
    printf("Podaj ile najnowszych ksiazek chcesz zobaczyc: ");
    fgets(buffer, sizeof(buffer), stdin);
    amount = (size_t)strtoul(buffer, NULL, 10);

    if (amount == 0) {
        printf("Nie podano poprawnej liczby ksiazek.\n");
        return NULL;
    }

    size_t result_count = (amount < state->count) ? amount : state->count;

    Book* temp = malloc(sizeof(Book) * state->count);
    if (!temp) return NULL;
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

    Book* results = malloc(sizeof(Book) * result_count);
    if (!results) {
        free(temp);
        return NULL;
    }
    memcpy(results, temp, sizeof(Book) * result_count);
    free(temp);

    return results;
}

Book* find_oldest_and_newest_books(Library_state* state) {
    if (state->count == 0) {
        return NULL;
    }

    Book* oldest_newest = (Book*)malloc(sizeof(Book) * 2);
    oldest_newest[0] = state->book_list[0];
    oldest_newest[1] = state->book_list[0];

    for (size_t i = 1; i < state->count; i++) {
        if (state->book_list[i].year < oldest_newest[0].year) {
            oldest_newest[0] = state->book_list[i];
        }
        if (state->book_list[i].year > oldest_newest[1].year) {
            oldest_newest[1] = state->book_list[i];
        }
    }

    return oldest_newest;
}