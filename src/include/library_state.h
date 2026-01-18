#ifndef LIBRARY_STATE_H
#define LIBRARY_STATE_H

#include "book.h"
#include <stddef.h>

typedef struct {
    Book *book_list;
    size_t count;
    size_t capacity;
    int next_id;
} Library_state;

Library_state* create_library_state(size_t initial_capacity);
Library_state* add_book(Library_state* state, const char* title, const char* author, int year);
Book* find_all_books(Library_state* state);
Book* find_book_by_id(Library_state* state, int book_id);
Book* find_books_by_title(Library_state* state, const char* title);
Book* find_books_by_author(Library_state* state, const char* author);
Book* find_books_by_year(Library_state* state, int year);
Book* find_newest_books_of_given_amount(Library_state* state, size_t amount);
Book* find_oldest_and_newest_books(Library_state* state);
Book* delete_book_by_id(Library_state* state, int book_id);
Book* edit_book_by_id(Library_state* state, int book_id, const char* new_title, const char* new_author, int new_year);
#endif 