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

#endif 