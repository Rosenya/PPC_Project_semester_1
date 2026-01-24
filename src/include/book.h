#ifndef BOOK_H
#define BOOK_H
#define MAX_ARRAY_SIZE 50

typedef struct {
    int book_id;
    char title[MAX_ARRAY_SIZE];
    char author[MAX_ARRAY_SIZE];
    int year;
} Book;

void set_title(Book* book);
void set_author(Book* book);
void set_year(Book* book);
int get_book_id_from_user();
char* get_book_title_from_user();
char* get_book_author_from_user();
int get_book_year_from_user();

#endif