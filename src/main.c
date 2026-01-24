#include "include/csv_io.h"
#include "include/library_state.h"
#include "include/reports.h"
#include "include/book.h"
#include "include/menu_controller.h"
#include <stdio.h>

int main(void){
    Library_state *library = NULL;
    create_file("library.csv");
    read_file("library.csv");
    library = create_library_state(10);
    menu_controller(library);
    free_library_state(library);


    return 0;
}   