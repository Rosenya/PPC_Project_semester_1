#ifndef REPORTS_H
#define REPORTS_H
#include "library_state.h"
#include "book.h"

void report_author_after_given_year(Library_state* state);
void report_author_for_year_range(Library_state* state);
void report_newest_books_of_given_amount(Library_state* state);
void report_oldest_and_newest_books(Library_state* state);

#endif