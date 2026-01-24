#include "include/csv_io.h"
#include "include/library_state.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void load_or_create_csv_file(const char *filename, Library_state *library) {
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        fptr = fopen(filename, "w");
        if (!fptr) {
            fprintf(stderr, "Nie mozna utworzyc pliku: %s\n", filename);
            return;
        }
        printf("Plik '%s' zostal utworzony.\n", filename);
        fclose(fptr);
    }

    char line[256];
    while (fgets(line, sizeof(line), fptr)) {
        int id, year;
        char title[50], author[50];
        if (sscanf(line, "%d;%49[^;];%49[^;];%d", &id, title, author, &year) == 4) {
            if (library->count == library->capacity) {
                library->capacity *= 2;
                library->book_list = realloc(library->book_list, sizeof(Book) * library->capacity);
            }
            Book *b = &library->book_list[library->count++];
            b->book_id = id;
            strcpy(b->title, title);
            strcpy(b->author, author);
            b->year = year;
            if (id >= library->next_id) library->next_id = id + 1;
        }
    }

    fclose(fptr);
    printf("Plik '%s' zostal wczytany. Liczba ksiazek w pamieci: %zu\n", filename, library->count);
}


void save_library_to_csv(const char *filename, Library_state *library) {
    FILE *fptr = fopen(filename, "w");
    if (fptr == NULL) {
        fprintf(stderr, "Nie mozna otworzyć pliku");
        return;
    }

    for (size_t i = 0; i < library->count; i++) {
        fprintf(fptr, "%d;%s;%s;%d\n",
                library->book_list[i].book_id,
                library->book_list[i].title,
                library->book_list[i].author,
                library->book_list[i].year);
    }

    fclose(fptr);
}