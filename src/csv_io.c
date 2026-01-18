#include "include\\csv_io.h"
#include "include\\library_state.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void save_library_to_csv(const char *filename, Library_state *library) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Nie można otworzyć pliku");
        return;
    }

    fprintf(file, "book_id;title;author;year\n");

    for (size_t i = 0; i < library->count; i++) {
        save_library_to_csv("library.csv", library);
    }

    fclose(file);
}

int read_file(const char *filename){
    FILE *fptr;
    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Nie udalo się otworzyć pliku.\n");
    }

    fclose(fptr);
    printf("Plik istnieje i został otwarty.\n");
    return 1;
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