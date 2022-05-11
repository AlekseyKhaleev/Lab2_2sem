#include "func.h"
#include "draw_func.h"
#include "struct.h"
#include <iostream>
#include <string>
#include <array>

int main(int argc, char **argv) {
    int UserInput = CorrectSyntax(argc, argv);
    if (!UserInput) {
        if (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help") {
            RaiseHelpScreen("help_arg");
        } else {
            if (std::string(argv[1]) == "-c") {
                CustomizeTerminal(F_BLACK,B_WHITE);
                PrintHeader(argv);
                CreateTable(argv);
                PrintFooter(argv);
                int mark = true; // флаг-индикатор продолжения/завершения программы
                while(mark) { // бесконечный цикл считывания клавиш
                    switch (UserKey()) { // считывание кода клавиши введенной пользователем в режиме "реального времени"
                        /* Клавиша ESC завершит цикл считывания клавиш */
                        case Escape: {
                            mark = false;
                            break;
                        }
                        case Help: {
                            PrintHelpScreen("help_prog"); // Вывод справочного экрана
                            int h_mark = true; // флаг-индикатор продолжения/завершения показа справочного экрана
                            while (h_mark){ // бесконечный цикл считывания клавиш
                                switch(UserKey()){ // считывание кода клавиши введенной пользователем в режиме "реального времени"

                                    /* Клавиша ESC завершит цикл считывания клавиш как в режиме справки, так и в основном цикле
                                     * и приведет в последствии к завершению программы*/
                                    case Escape:{
                                        h_mark = false;
                                        mark = false;
                                        break;
                                    }
                                        /* Клавиша r завершит цикл считывания клавиш в режиме справки, просмотр текста продолжится
                                         * с экрана на котором была вызвана справка */
                                    case Return:{
                                        CustomizeTerminal(F_BLACK,B_WHITE);
                                        PrintHeader(argv);
                                        PrintTable(argv);
                                        PrintFooter(argv);
                                        h_mark = false;
                                        break;
                                    }
                                    default: break;  // игнорирование любых клавиш, поведение которых неопределено
                                }
                            }
                            break;
                        }
                    }
                }
            }
            if (std::string(argv[1]) == "-r") {
                CustomizeTerminal(F_BLACK,B_WHITE);
                PrintHeader(argv);
                std::array<int, 2> printed_rows = PrintTable(argv);
                PrintFooter(argv,printed_rows);
                int mark = true; // флаг-индикатор продолжения/завершения программы
                while(mark) { // бесконечный цикл считывания клавиш
                    switch (UserKey()) { // считывание кода клавиши введенной пользователем в режиме "реального времени"
                        /* Клавиша ESC завершит цикл считывания клавиш */
                        case Escape: {
                            mark = false;
                            break;
                        }
                        case Help: {
                            PrintHelpScreen("help_prog"); // Вывод справочного экрана
                            int h_mark = true; // флаг-индикатор продолжения/завершения показа справочного экрана
                            while (h_mark){ // бесконечный цикл считывания клавиш
                                switch(UserKey()){ // считывание кода клавиши введенной пользователем в режиме "реального времени"

                                    /* Клавиша ESC завершит цикл считывания клавиш как в режиме справки, так и в основном цикле
                                     * и приведет в последствии к завершению программы*/
                                    case Escape:{
                                        h_mark = false;
                                        mark = false;
                                        break;
                                    }
                                        /* Клавиша r завершит цикл считывания клавиш в режиме справки, просмотр текста продолжится
                                         * с экрана на котором была вызвана справка */
                                    case Return:{
                                        CustomizeTerminal(F_BLACK,B_WHITE);
                                        PrintHeader(argv);
                                        PrintTable(argv);
                                        PrintFooter(argv, printed_rows);
                                        h_mark = false;
                                        break;
                                    }
                                    default: break;  // игнорирование любых клавиш, поведение которых неопределено
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }
        reset_screen();
    } else {
        RaiseSyntaxError(UserInput);
    }
    return 0;
}
