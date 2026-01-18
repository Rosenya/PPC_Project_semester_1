#include "book.h"
typedef struct{
    Book *book_list;
    size_t count;
    size_t capacity;
    int next_id;
}Library_state;
