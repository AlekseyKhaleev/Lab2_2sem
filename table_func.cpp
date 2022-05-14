#include "table_func.h"
#include "definitions.h"
#include "struct.h"
#include "print_func.h"
#include "draw_func.h"
#include <iostream>
#include <map>

/* Функция вызова исключения связанного с выделением памяти для передачи в set_new_handler() */
void NewError() {
    throw std::bad_alloc();
}

void PrintTable(struct PC ParkContent[], int rows_request, int row_number) {
    int rows = rows_request > MAX_ROWS ? MAX_ROWS : rows_request;
    for (int i = 0, j = row_number; i < rows; i++, j++) {
        ParkContent[j].out(i);
    }
}

int CreateTable(char *argv[], std::fstream &table_out, int rows_request) {
    CustomizeTerminal(F_BLACK, B_WHITE);
    PrintHeader(argv);
    DrawTable();
    errno = 0;  // Переменная модуля errno.h, хранящая целочисленный код последней ошибки. 0 - отсутствие ошибок
    std::set_new_handler(NewError); // Назначение функции, которая будет вызвана при получении ошибки выделения памяти
    int row_number = 1;
    try {
        table_out.write((char *) &CORRECT_BIT, sizeof(CORRECT_BIT));
        table_out.write((char *) &rows_request, sizeof(int));
        auto ParkUpdate = new PC[rows_request];
        for (int i = 0; i < rows_request; i++) {
            if (i < MAX_ROWS) {
                ParkUpdate[i].set(i+1, i);
                table_out.write((char *) &ParkUpdate[i], sizeof(struct PC));
            } else {
                DrawTable();
                PrintTable(ParkUpdate, i - 1, row_number);
                ParkUpdate[i].set(i, MAX_ROWS - 1);
                table_out.write((char *) &ParkUpdate[i], sizeof(struct PC));
                row_number++;
            }
        }
        std::cout << std::endl;
        delete[] ParkUpdate;
    } catch (std::exception &e) { // Обработка исключения, связанного с выделением динамической памяти
        perror("Memory allocation error");
    }
    row_number--;
    table_out.seekg(std::ios::beg);
    return row_number;
}

void ViewTable(char *argv[], std::fstream &table_in, int rows_request, int row_number) {
    errno = 0;  // Переменная модуля errno.h, хранящая целочисленный код последней ошибки. 0 - отсутствие ошибок
    std::set_new_handler(NewError); // Назначение функции, которая будет вызвана при получении ошибки выделения памяти
    try {
        /* последовательный контейнер из двух элементов, соответствующих количеству прочитанных строк в файле
         * и действительному количеству строк в файле*/

        /* Действительное количество строк */
        int real_rows;
        table_in.read((char *) &real_rows, sizeof(real_rows));
        int rows_to_print = rows_request < real_rows? rows_request:real_rows;
        auto *ParkContent = new PC[rows_to_print];
        for (int i = 0; i < rows_to_print; i++) {
            table_in.read((char *) &ParkContent[i], sizeof(struct PC));
        }
        GenerateTablePage(ParkContent,argv,rows_to_print,real_rows,row_number);
        int mark = true; // флаг-индикатор продолжения/завершения программы
        while (mark) { // бесконечный цикл считывания клавиш
            switch (UserKey()) { // считывание кода клавиши введенной пользователем в режиме "реального времени"
                /* Клавиша ESC завершит цикл считывания клавиш */
                case Escape: {
                    mark = false;
                    break;
                }
                case Up: {
                    if (row_number > 0) {
                        row_number--;
                        GenerateTablePage(ParkContent,argv,rows_to_print,real_rows,row_number);
                    }
                    break;
                }
                case Down: {
                    if ((row_number <= rows_to_print - MAX_ROWS_FR) && (rows_to_print > MAX_ROWS_FR)) {
                        row_number++;
                        GenerateTablePage(ParkContent,argv,rows_to_print,real_rows,row_number);
                    }
                    break;
                }
                case Help: {
                    PrintHelpScreen("help_prog"); // Вывод справочного экрана
                    int h_mark = true; // флаг-индикатор продолжения/завершения показа справочного экрана
                    while (h_mark) { // бесконечный цикл считывания клавиш
                        switch (UserKey()) { // считывание кода клавиши введенной пользователем в режиме "реального времени"
                            /* Клавиша ESC завершит цикл считывания клавиш как в режиме справки, так и в основном цикле
                             * и приведет в последствии к завершению программы*/
                            case Escape: {
                                h_mark = false;
                                mark = false;
                                break;
                            }
                                /* Клавиша r завершит цикл считывания клавиш в режиме справки, просмотр текста продолжится
                                 * с экрана на котором была вызвана справка */
                            case Return: {
                                GenerateTablePage(ParkContent,argv,rows_to_print,real_rows,row_number);
                                h_mark = false;
                                break;
                            }
                            default:
                                break;  // игнорирование любых клавиш, поведение которых неопределено
                        }
                    }
                    break;
                }
            }
        }
        delete[] ParkContent;
    } catch (std::exception &e) { // Обработка исключения, связанного с выделением динамической памяти
        perror("Memory allocation error");
    }
}

void GenerateTablePage(struct PC ParkContent[], char* argv[], int rows_to_print, int real_rows, int row_number){
    CustomizeTerminal(F_BLACK, B_WHITE);
    PrintHeader(argv);
    DrawTable();
    PrintTable(ParkContent, rows_to_print, row_number);
    PrintFooter(argv, rows_to_print,real_rows);
}

