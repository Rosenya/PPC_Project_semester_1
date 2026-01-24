#include "include/csv_io.h"
#include "include/library_state.h"
#include "include/reports.h"
#include "include/book.h"
#include "include/menu_controller.h"
#include <stdio.h>

int main(void){
    Library_state *library = create_library_state(10);
    menu_controller(library);
    save_library_to_csv("library.csv", library);
    free_library_state(library);
    return 0;
}   