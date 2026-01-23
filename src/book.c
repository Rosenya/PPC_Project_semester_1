#include "include/book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 50


Book* get_book_id(const Book* book) {
    return (Book*)book;
}

Book* get_title(Book* book) {
    return book;
}

Book* get_author(Book* book) {
    return book;
}

Book* get_year(Book* book) {
    return book;
}

void set_title(Book* book) {
    char buffer[BUFFER_SIZE];
    printf("Podaj tytul: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(book->title, buffer, sizeof(book->title)-1);
    book->title[sizeof(book->title)-1] = '\0';
}

void set_author(Book* book) {
    char buffer[BUFFER_SIZE];
    printf("Podaj autora: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(book->author, buffer, sizeof(book->author)-1);
    book->author[sizeof(book->author)-1] = '\0';
}

void set_year(Book* book) {
    char buffer[BUFFER_SIZE];
    printf("Podaj rok: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    sscanf(buffer, "%d", &book->year);
    
}

int get_book_id_from_user() {
    int book_id;
    char buffer[BUFFER_SIZE];
    printf("Podaj ID ksiazki: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    sscanf(buffer, "%d", &book_id);
    return book_id;
}

char* get_book_title_from_user() {
    char *title = (char*)malloc(BUFFER_SIZE * sizeof(char));
    printf("Podaj tytul ksiazki: ");
    fgets(title, BUFFER_SIZE, stdin);
    title[strcspn(title, "\n")] = '\0';
    printf("Szukany tytul: %s\n", title);
    return title;
}


char* get_book_author_from_user() {
    char *author = (char*)malloc(BUFFER_SIZE * sizeof(char));
    printf("Podaj autora ksiazki: ");
    fgets(author, BUFFER_SIZE, stdin);
    author[strcspn(author, "\n")] = '\0';
    return author;
}

int get_book_year_from_user() {
    int year;
    printf("Podaj rok: ");
    scanf("%d", &year);
    return year;
}

//dodac walidacje year > 0