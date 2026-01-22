#include "include/csv_io.h"
#include "include/library_state.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void save_library_to_csv(const char *filename, Library_state *library) {
    FILE *fptr = fopen(filename, "a");
    if (fptr == NULL) {
        fprintf(stderr, "Nie można otworzyć pliku");
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

void read_file(const char *filename){
    FILE *fptr;
    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Nie udalo się otworzyć pliku.\n");
    }

    fclose(fptr);
    printf("Plik istnieje i zostal otwarty.\n");
}

void load_csv_file(const char *filename, Library_state *state) {
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Nie udało się otworzyć pliku %s\n", filename);
        return;
    }

    printf("Plik został otwarty.\n");

    char line[256];
    fgets(line, sizeof(line), fptr);

    while (fgets(line, sizeof(line), fptr) != NULL) {
        int id, year;
        char title[50], author[50];
        if (sscanf(line, "%d;%49[^;];%49[^;];%d", &id, title, author, &year) == 4) {
            if (state->count == state->capacity) {
                state->capacity *= 2;
                state->book_list = realloc(state->book_list, sizeof(Book) * state->capacity);
            }
            Book *b = &state->book_list[state->count++];
            b->book_id = id;
            strcpy(b->title, title);
            strcpy(b->author, author);
            b->year = year;

            if (id >= state->next_id) state->next_id = id + 1;
        }
    }

    fclose(fptr);
    printf("Plik został wczytany. Liczba książek w pamięci: %zu\n", state->count);
}

int create_file(const char *filename){
    fprintf(stderr, "wejscie ok: %s\n", filename);
    FILE *fptr;
    fptr = fopen(filename, "w");
    if (fptr == NULL) {
        fprintf(stderr, "Nie udało się utworzyć pliku");
    }

    fclose(fptr);

    printf("Plik '%s' zostal utworzony lub istnieje.\n", filename);
    return 0;
}