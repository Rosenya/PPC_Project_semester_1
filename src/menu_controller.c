#include "include/book.h"
#include "include/csv_io.h"
#include "include/library_state.h"
#include "include/menu_controller.h"
#include "include/reports.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_controller(Library_state* state) {
    int running = 1;
    printf("Witaj w systemie zarzadzania biblioteka!\n");

    while (running) {
        char buffer[32];
        int choice = -1;

        menu_msg();

        if (fgets(buffer, sizeof(buffer), stdin)) {
            choice = (int)strtol(buffer, NULL, 10);

            size_t len = strlen(buffer);
            if (len > 0 && buffer[len - 1] != '\n') {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
        }

        switch (choice) {
            // Operacje na stanie biblioteki
            case 1: load_or_create_csv_file("library.csv", state); break;
            case 2: add_book(state); break;
            case 3: delete_book_by_id(state); break;
            case 4: edit_book_by_id(state); break;
            case 5: find_all_books(state); break;
            // Wyszukiwania
            case 6: find_book_by_id(state); break;
            case 7: find_books_by_title(state); break;
            case 8: find_books_by_author(state); break;
            case 9: find_books_by_year(state); break;
            // Raporty
            case 10: report_author_after_given_year(state); break;
            case 11: report_author_for_year_range(state); break;
            case 12: report_newest_books_of_given_amount(state); break;
            case 13: report_oldest_and_newest_books(state); break;
    
            case 0: running = 0; break;    
            default:     
            printf("Nieprawidlowy wybor. Sprobuj ponownie.\n");    
            break;
}

    }

    
}

void menu_msg() {
        printf("\nMENU:\n");
        printf("1. Wczytaj baze ksiazek z pliku CSV\n");
        printf("2. Dodaj ksiazke\n");
        printf("3. Usun ksiazke\n");
        printf("4. Edytuj ksiazke\n");
        printf("\nWyszukiwania:\n");
        printf("5. Wyswietl wszystkie ksiazki\n");
        printf("6. Znajdz ksiazke po ID\n");
        printf("7. Znajdz ksiazki po tytule\n");
        printf("8. Znajdz ksiazki po autorze\n");
        printf("9. Znajdz ksiazki z danego roku\n");
        printf("\nRaporty:\n");
        printf("10. Raport: autor po roku X\n");
        printf("11. Raport: autor w przedziale lat\n");
        printf("12. Raport: TOP N najnowszych\n");
        printf("13. Raport: najstarsza i najnowsza ksiazka\n");
        printf("Twoj wybor: ");
}