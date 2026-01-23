#include "include/csv_io.h"
#include "include/library_state.h"
#include "include/book.h"
#include <stdio.h>

int main(void){
    Library_state *library = NULL;
    create_file("library.csv");
    read_file("library.csv");
    library = create_library_state(10);

    library = add_book(library);
    library = add_book(library);
    
    find_book_by_id(library);
    find_books_by_title(library);
    find_books_by_author(library);
    find_books_by_year(library);
    find_all_books(library);

    return 0;
}   