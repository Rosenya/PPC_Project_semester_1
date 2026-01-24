#include "include/menu_controller.h"
#include "include/book.h"
#include "include/library_state.h"
#include "include/reports.h"
#include <stdio.h>
#include <stdlib.h>

void menu_controller(Library_state* state) {
    int running = 1;
    printf("Witaj w systemie zarzadzania biblioteka!\n");

    while (running) {
        char buffer[32];
        int choice = -1;

        menu_msg();

        if (fgets(buffer, sizeof(buffer), stdin)) {
            choice = (int)strtol(buffer, NULL, 10);
        }

        switch (choice) {
            case 1: add_book(state); break;
            case 2: delete_book_by_id(state); break;
            case 3: edit_book_by_id(state); break;
            case 4: find_all_books(state); break;
            case 5: report_author_after_given_year(state); break;
            case 6: report_author_for_year_range(state); break;
            case 7: report_newest_books_of_given_amount(state); break;
            case 8: report_oldest_and_newest_books(state); break;
            case 0: running = 0; break;
            default: 
                printf("Nieprawidlowy wybor. Sprobuj ponownie.\n");
                break;
        }
    }

    
}

void menu_msg() {
        printf("\nMENU:\n");
        printf("1. Dodaj ksiazke\n");
        printf("2. Usun ksiazke\n");
        printf("3. Edytuj ksiazke\n");
        printf("4. Wyswietl wszystkie ksiazki\n");
        printf("5. Raport: autor po roku X\n");
        printf("6. Raport: autor w przedziale lat\n");
        printf("7. Raport: TOP N najnowszych\n");
        printf("8. Raport: najstarsza i najnowsza ksiazka\n");
        printf("0. Zakoncz\n");
        printf("Twoj wybor: ");
}