#ifndef CSV_WRITER_H
#define CSV_WRITER_H

#include "book.h"
#include "library_state.h"

void save_book_to_csv(FILE *file, Book *book);

void save_library_to_csv(const char *filename, Library_state *library);

#endif