#include "include/library_state.h"
#include "include/book.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Library_state* create_library_state(size_t initial_capacity) {
    if(initial_capacity ==0){
        initial_capacity = 10;
    }    
    Library_state* state = (Library_state*)malloc(sizeof(Library_state));
    state->book_list = (Book*)malloc(sizeof(Book) * initial_capacity);
    state->count = 0;
    state->capacity = initial_capacity;
    state->next_id = 1;   
    printf("Stan biblioteki zostal utworzony poprawnie.\n");
    return state;
}

Library_state* add_book(Library_state* state) {
    if (state->count == state->capacity) {
        state->capacity *= 2;
        state->book_list = (Book*)realloc(state->book_list, sizeof(Book) * state->capacity);
    }
    Book* new_book;
    new_book = &state->book_list[state->count++];
    new_book->book_id = state->next_id++;
    set_title(new_book);
    set_author(new_book);
    set_year(new_book);
    return state;
}

Book* find_all_books(Library_state* state) {
    if(state->count == 0){
        printf("Brak ksiazek w bibliotece.\n");
    }
    for (size_t i = 0; i < state->count; i++) {
        printf("Find all books. ID: %d, Tytul: %s, Autor: %s, Rok: %d\n", 
            state->book_list[i].book_id, state->book_list[i].title, state->book_list[i].author, state->book_list[i].year);
    }
    return state->book_list;
}

Book* find_book_by_id(Library_state* state) {
    int book_id = get_book_id_from_user();
    for (size_t i = 0; i < state->count; i++) {
        if (state->book_list[i].book_id == book_id) {
            printf(
                "Find by id. Znaleziono ksiazke: "
                "ID: %d, Tytul: %s, Autor: %s, Rok: %d\n",
                state->book_list[i].book_id,
                state->book_list[i].title,
                state->book_list[i].author,
                state->book_list[i].year
            );
            return &state->book_list[i];
        }
    }

    printf("Nie znaleziono ksiazki o podanym ID: %d\n", book_id);
    return NULL;
}

Book* find_books_by_title(Library_state* state) {
    char* title = get_book_title_from_user();
    Book* results = (Book*)malloc(sizeof(Book) * state->count);
    size_t result_count = 0;
    for (size_t i = 0; i < state->count; i++) {
        if (strcmp(state->book_list[i].title, title) == 0) {
            results[result_count++] = state->book_list[i];
        }
    }
    if (result_count == 0) {
        printf("Nie znaleziono ksiazki o podanym tytule: %s\n", title);
        free(results);
        return NULL;
    }
    printf("Find by title. Znaleziono %zu rezultatow.\n", result_count);
    for (size_t i = 0; i < result_count; i++) {
        printf("ID: %d, Tytul: %s, Autor: %s, Rok: %d\n",
               results[i].book_id,
               results[i].title,
               results[i].author,
               results[i].year);
    }
    return results;
}

Book* find_books_by_author(Library_state* state) {
    char* author = get_book_author_from_user();
    Book* results = (Book*)malloc(sizeof(Book) * state->count);
    size_t result_count = 0;
    for (size_t i = 0; i < state->count; i++) {
        if (strcmp(state->book_list[i].author, author) == 0) {
            results[result_count++] = state->book_list[i];
        }
    }
    if (result_count == 0) {
        printf("Nie znaleziono ksiazki tego autora: %s\n", author);
        free(results);
        return NULL;
    }
    printf("Find by author. Znaleziono %zu rezultatow.\n", result_count);
    for (size_t i = 0; i < result_count; i++) {
        printf("ID: %d, Tytul: %s, Autor: %s, Rok: %d\n",
               results[i].book_id,
               results[i].title,
               results[i].author,
               results[i].year);
    }
    return results;
}

Book* find_books_by_year(Library_state* state) {
    int year = get_book_year_from_user();
    Book* results = (Book*)malloc(sizeof(Book) * state->count);
    size_t result_count = 0;
    for (size_t i = 0; i < state->count; i++) {
        if (state->book_list[i].year == year) {
            results[result_count++] = state->book_list[i];
        }
    }
    if (result_count == 0) {
        printf("Nie znaleziono ksiazki z podanego roku: %d\n", year);
        free(results);
        return NULL;
    }
    printf("Find by year. Znaleziono %zu rezultatow.\n", result_count);
    for (size_t i = 0; i < result_count; i++) {
        printf("ID: %d, Tytul: %s, Autor: %s, Rok: %d\n",
               results[i].book_id,
               results[i].title,
               results[i].author,
               results[i].year);
    }
    return results;
}

Book* delete_book_by_id(Library_state* state) {
    int book_id = get_book_id_from_user();
    for (size_t i = 0; i < state->count; i++) {
        if (state->book_list[i].book_id == book_id) {

            Book* deleted_book = malloc(sizeof(Book));
            if (!deleted_book) return NULL;

            *deleted_book = state->book_list[i];

            for (size_t j = i; j < state->count - 1; j++) {
                state->book_list[j] = state->book_list[j + 1];
            }

            state->count--;
            printf("Ksiazka o ID %d zostala usunieta pomyslnie.\n", book_id);
            return deleted_book;
        }
    }
    printf("Nie znaleziono ksiazki o ID %d.\n", book_id);
    return NULL;
}

Book* edit_book_by_id(Library_state* state) {
    int book_id = get_book_id_from_user();
    printf("Podaj ID ksiazki do edycji: ");
    Book* book = NULL;
    for (size_t i = 0; i < state->count; i++) {
        if (state->book_list[i].book_id == book_id) {
            book = &state->book_list[i];
            break;
        }
    }
    if (!book) {
        printf("Nie znaleziono ksiazki o ID %d.\n", book_id);
        return NULL;
    }
    printf("Podaj nowe dane ksiazki:\n");
    set_title(book);
    set_author(book);
    set_year(book);

    printf("Ksiazka o ID %d zostala zaktualizowana.\n", book_id);
    return book;
}



void free_library_state(Library_state* state) {
    if (state) {
        free(state->book_list);
        free(state);
    }
}

