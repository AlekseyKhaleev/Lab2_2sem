
#pragma ones
#include <string>
#include "definitions.h"


struct PC{
    int row_number;
    char cpu_type[STRLEN];
    char cpu_freq[STRLEN];
    char memory[STRLEN];
    char storage[STRLEN];
    char display[STRLEN];
    void set(int current_row, int print_row);
    void out(int current_row);
};

