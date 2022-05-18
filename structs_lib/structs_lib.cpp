/**********************************************************************************************************************
* Данный модуль содержит определения методов(функций) собственных структур, определенных в "structs.h"
**********************************************************************************************************************/

/* Подключение модулей */
#include "structs_lib.h"
#include <iostream>

void PC::set(int row_number, int row_to_print){
    /*****************************************************************************************************************
    * Цель: Инициализация элементов структуры значениями, считанными из потока STDIN с перемещением
    * курсора во время ввода в соответствующие ячейки таблицы.
    * Исходные данные:
    *   row_number   - порядковый номер строки таблицы
    *   row_to_print - строка таблицы, в которой должен осуществляться ввод
    * Результат: Элементы структуры инициализированы соответствующими значениями.
    * Вызываемые модули: <iostream>, "structs.h", "definitions.h"
    * Описание алгоритма:
    * 1) Переменная current_col, соответствующая позиции текущего столбца для ввода, инициализируется
    * начальным значением START_COL
    * 2) Для каждого элемента структуры:
    *   - курсор перемещается в очередную позицию (используются шаги сдвига курсора, определенные в definitions.h)
    *   - производится пользовательский ввод с клавиатуры очередного значения элемента структуры
    * Дата: 15 / 05 / 2022 Версия 1.01
    * Автор: Студент НГТУ ИРИТ, Халеев А. А. гр. 21-ИВТз
    * Исправления: нет
    *****************************************************************************************************************/

    int current_col = START_COL;
    move_cursor(START_ROW + row_to_print * STEP_ROW, START_COL);
    PC::number = row_number;
    std::cout << PC::number;
    move_cursor(START_ROW + row_to_print * STEP_ROW, current_col += STEP_COL);
    std::cin.getline(PC::cpu_type, MAX_CHARS);
    move_cursor(START_ROW + row_to_print * STEP_ROW, current_col += STEP_COL);
    std::cin.getline(PC::cpu_freq, MAX_CHARS);
    move_cursor(START_ROW + row_to_print * STEP_ROW, current_col += STEP_COL);
    std::cin.getline(PC::memory, MAX_CHARS);
    move_cursor(START_ROW + row_to_print * STEP_ROW, current_col += STEP_COL);
    std::cin.getline(PC::storage, MAX_CHARS);
    move_cursor(START_ROW + row_to_print * STEP_ROW, current_col += STEP_COL);
    std::cin.getline(PC::display, MAX_CHARS);
}
void PC::print(int row_to_print){
    /*****************************************************************************************************************
    * Цель: Вывод элементов структуры с перемещением курсора во время вывода в соответствующие ячейки таблицы.
    * Исходные данные:
    *   row_to_print - строка таблицы, в которой должен осуществляться вывод
    * Результат: Элементы структуры выведены в соответствующих ячейках таблицы.
    * Вызываемые модули: <iostream>, "structs.h", "definitions.h"
    * Описание алгоритма:
    * 1) Переменная current_col, соответствующая позиции текущего столбца для вывода, инициализируется
    * начальным значением START_COL
    * 2) Для каждого элемента структуры:
    *   - курсор перемещается в очередную позицию (используются шаги сдвига курсора, определенные в definitions.h)
    *   - производится вывод очередного значения элемента структуры
    * Дата: 15 / 05 / 2022 Версия 1.01
    * Автор: Студент НГТУ ИРИТ, Халеев А. А. гр. 21-ИВТз
    * Исправления: нет
    *****************************************************************************************************************/

    int current_col = START_COL;
    move_cursor(START_ROW + row_to_print * STEP_ROW, START_COL);
    std::cout << PC::number;
    move_cursor(START_ROW + row_to_print * STEP_ROW, current_col += STEP_COL);
    std::cout << PC::cpu_type;
    move_cursor(START_ROW + row_to_print * STEP_ROW, current_col += STEP_COL);
    std::cout << PC::cpu_freq;
    move_cursor(START_ROW + row_to_print * STEP_ROW, current_col += STEP_COL);
    std::cout << PC::memory;
    move_cursor(START_ROW + row_to_print * STEP_ROW, current_col += STEP_COL);
    std::cout << PC::storage;
    move_cursor(START_ROW + row_to_print * STEP_ROW, current_col += STEP_COL);
    std::cout << PC::display;
}

