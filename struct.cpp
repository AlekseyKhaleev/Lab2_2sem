
#include "struct.h"
#include <iostream>
#include "definitions.h"
namespace structs{
    void PC::set(int current_row){
        int current_col = START_COL;
        move_cursor(START_ROW + current_row * STEP_ROW, START_COL);
        std::cout << current_row + 1;
        move_cursor(START_ROW + current_row * STEP_ROW, current_col += STEP_COL);
        std::cin.getline(PC::cpu_type, STRLEN);
        move_cursor(START_ROW + current_row * STEP_ROW, current_col += STEP_COL);
        std::cin.getline(PC::cpu_freq, STRLEN);
        move_cursor(START_ROW + current_row * STEP_ROW, current_col += STEP_COL);
        std::cin.getline(PC::memory, STRLEN);
        move_cursor(START_ROW + current_row * STEP_ROW, current_col += STEP_COL);
        std::cin.getline(PC::storage, STRLEN);
        move_cursor(START_ROW + current_row * STEP_ROW, current_col += STEP_COL);
        std::cin.getline(PC::display, STRLEN);
    }
    void PC::out(int current_row){
        int current_col = START_COL;
        move_cursor(START_ROW + current_row * STEP_ROW, START_COL);
        std::cout << current_row + 1;
        move_cursor(START_ROW + current_row * STEP_ROW, current_col += STEP_COL);
        std::cout << PC::cpu_type;
        move_cursor(START_ROW + current_row * STEP_ROW, current_col += STEP_COL);
        std::cout << PC::cpu_freq;
        move_cursor(START_ROW + current_row * STEP_ROW, current_col += STEP_COL);
        std::cout << PC::memory;
        move_cursor(START_ROW + current_row * STEP_ROW, current_col += STEP_COL);
        std::cout << PC::storage;
        move_cursor(START_ROW + current_row * STEP_ROW, current_col += STEP_COL);
        std::cout << PC::display;
    }
}
