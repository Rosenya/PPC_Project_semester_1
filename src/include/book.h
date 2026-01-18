#ifndef BOOK_H
#define BOOK_H

typedef struct {
    int book_id;
    char title[50];
    char author[50];
    int year;
} Book;

#endif