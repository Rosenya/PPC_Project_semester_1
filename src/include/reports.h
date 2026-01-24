#ifndef REPORTS_H
#define REPORTS_H
#include "library_state.h"
#include "book.h"

Book* find_newest_books_of_given_amount(Library_state* state);
Book* find_oldest_and_newest_books(Library_state* state);

#endif