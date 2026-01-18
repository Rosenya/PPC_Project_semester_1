#ifndef CSV_WRITER_H
#define CSV_WRITER_H

#include "library_state.h"

void save_library_to_csv(const char *filename, Library_state *library);

void read_file(const char *filename);

void load_csv_file(const char *filename, Library_state *state);
void create_file(const char *filename);

#endif