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
            printf("Find by id. Znaleziono ksiazke: ID: %d, Tytul: %s, Autor: %s, Rok: %d\n",
                 state->book_list[i].book_id, state->book_list[i].title, state->book_list[i].author, state->book_list[i].year);
            return &state->book_list[i];
        } else {
            printf("Nie znaleziono ksiazki o podanym ID: %d\n", book_id);
        }
    }
    return NULL;
}

Book* find_books_by_title(Library_state* state) {
    char* title = get_book_title_from_user();
    Book* results = (Book*)malloc(sizeof(Book) * state->count);
    size_t result_count = 0;
    for (size_t i = 0; i < state->count; i++) {
        if (strcmp(state->book_list[i].title, title) == 0) {
            results[result_count++] = state->book_list[i];
            printf("Find by title. Znaleziono %zu rezultatow. ID: %d, Tytul: %s, Autor: %s, Rok: %d\n",
                    result_count,
                    state->book_list[i].book_id,
                    state->book_list[i].title,
                    state->book_list[i].author,
                    state->book_list[i].year);
        }
    }
    return results;
}

// Book* find_books_by_author(Library_state* state) {
//     Book* results = (Book*)malloc(sizeof(Book) * state->count);
//     size_t result_count = 0;
//     for (size_t i = 0; i < state->count; i++) {
//         if (strstr(state->book_list[i].author, author) != NULL) {
//             results[result_count++] = state->book_list[i];
//         }
//     }
//     return results;
// }

// Book* find_books_by_year(Library_state* state) {
//     Book* results = (Book*)malloc(sizeof(Book) * state->count);
//     size_t result_count = 0;
//     for (size_t i = 0; i < state->count; i++) {
//         if (state->book_list[i].year == year) {
//             results[result_count++] = state->book_list[i];
//         }
//     }
//     return results;
// }

// Book* delete_book_by_id(Library_state* state) {
//     Book* book = get_book_id_from_user();
//     int book_id = book->book_id;
//     for (size_t i = 0; i < state->count; i++) {
//         if (state->book_list[i].book_id == book_id) {
//             Book* deleted_book = (Book*)malloc(sizeof(Book));
//             *deleted_book = state->book_list[i];
//             for (size_t j = i; j < state->count - 1; j++) {
//                 state->book_list[j] = state->book_list[j + 1];
//             }
//             state->count--;
//             return deleted_book;
//         }
//     }
//     return NULL;
// }

// Book* edit_book_by_id(Library_state* state, int book_id, const char* new_title, const char* new_author, int new_year) {
//     Book* book = find_book_by_id(state, book_id);
//     if (book != NULL) {
//         strncpy(book->title, new_title, sizeof(book->title) - 1);
//         book->title[sizeof(book->title) - 1] = '\0';
//         strncpy(book->author, new_author, sizeof(book->author) - 1);
//         book->author[sizeof(book->author) - 1] = '\0';
//         book->year = new_year;
//         return book;
//     }
//     return NULL;
// }

// Book* find_newest_books_of_given_amount(Library_state* state, size_t amount) {
//     if (amount == 0 || state->count == 0) {
//         return NULL;
//     }

//     Book* sorted_books = (Book*)malloc(sizeof(Book) * state->count);
//     memcpy(sorted_books, state->book_list, sizeof(Book) * state->count);

//     for (size_t i = 0; i < state->count - 1; i++) {
//         for (size_t j = i + 1; j < state->count; j++) {
//             if (sorted_books[i].year < sorted_books[j].year) {
//                 Book temp = sorted_books[i];
//                 sorted_books[i] = sorted_books[j];
//                 sorted_books[j] = temp;
//             }
//         }
//     }

//     size_t result_count = (amount < state->count) ? amount : state->count;
//     Book* results = (Book*)malloc(sizeof(Book) * result_count);
//     memcpy(results, sorted_books, sizeof(Book) * result_count);
//     free(sorted_books);
//     return results;
// }

// Book* find_oldest_and_newest_books(Library_state* state) {
//     if (state->count == 0) {
//         return NULL;
//     }

//     Book* oldest_newest = (Book*)malloc(sizeof(Book) * 2);
//     oldest_newest[0] = state->book_list[0];
//     oldest_newest[1] = state->book_list[0];

//     for (size_t i = 1; i < state->count; i++) {
//         if (state->book_list[i].year < oldest_newest[0].year) {
//             oldest_newest[0] = state->book_list[i];
//         }
//         if (state->book_list[i].year > oldest_newest[1].year) {
//             oldest_newest[1] = state->book_list[i];
//         }
//     }

//     return oldest_newest;
// }

void free_library_state(Library_state* state) {
    if (state) {
        free(state->book_list);
        free(state);
    }
}

