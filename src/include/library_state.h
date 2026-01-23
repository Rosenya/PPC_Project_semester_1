#ifndef LIBRARY_STATE_H
#define LIBRARY_STATE_H

#include "book.h"
#include <stddef.h>
/* Użycie biblioteki stddef.h dla typu size_t. Size_t reprezentuje liczby całkowite nieujemne i jest używany podczas pracy z pamięcią.
Zdecydowałam się na jego użycie, ze wględu na jego lepszą stabilność i elastyczność przy użyciu w różnych systemach operacyjnych.
Uznałam, że dzięki temu mój kod będzie mniej narażony na błędy.*/

typedef struct {
    Book *book_list;
    size_t count;
    size_t capacity;
    int next_id;
} Library_state;

Library_state* create_library_state(size_t initial_capacity);
Library_state* add_book(Library_state* state);
Book* find_all_books(Library_state* state);
Book* find_book_by_id(Library_state* state);
Book* find_books_by_title(Library_state* state);
Book* find_books_by_author(Library_state* state);
Book* find_books_by_year(Library_state* state);
Book* find_newest_books_of_given_amount(Library_state* state);
Book* find_oldest_and_newest_books(Library_state* state);
Book* delete_book_by_id(Library_state* state);
Book* edit_book_by_id(Library_state* state);
void free_library_state(Library_state* state);
#endif 