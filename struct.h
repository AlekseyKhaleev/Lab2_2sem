
#pragma ones

#include <string>
#include "definitions.h"


struct PC{
    int number;
    char cpu_type[STRLEN];
    char cpu_freq[STRLEN];
    char memory[STRLEN];
    char storage[STRLEN];
    char display[STRLEN];
    void set(int row_number, int row_to_print);
    void out(int row_to_print);
};

