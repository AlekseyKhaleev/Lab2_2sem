
#pragma ones
#include <string>
#include "definitions.h"

namespace structs{
    struct PC{
        char cpu_type[STRLEN];
        char cpu_freq[STRLEN];
        char memory[STRLEN];
        char storage[STRLEN];
        char display[STRLEN];
        void set(int current_row);
        void out(int current_row);
    };
}
