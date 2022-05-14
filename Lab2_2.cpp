// Lab2_2.cpp: Листинг программы для Задания 1, 2-й лабораторной работы 2-го семестра
// Вариант 8
//*********************************************************************************
// Имя файла: Lab2_2.cpp
// Резюме: Пример программы написанной на языке программирования С++
// Описание:
// Программа позволяет создавать и просматривать таблицы парка ПК,
// получать справку и прокручивать экран. Таблица сохраняется в бинарном файле.
// Каждый бинарный файл содержит:
// 1) уникальный числовой идентификатор программы
// 2) количество записей в таблице
// 3) непосредственно записи таблице, организованные с помощью структур.
// - для корректного вызова программы требуется указать серию аргументов:
// --help или -h      : режим справки
// -с [N] [file_name] : режим создания таблицы
// -r [N] [file_name] : режим чтения таблицы
// где:
//    N – число записей для ввода/вывода;
//    file_name – асболютный или относительный путь к файлу;
// В программе организована обработка аргументов командной строки,
// при некорректных параметрах выводятся соответствующие сообщения
//  Программа поддерживает некоторые горячие клавиши:
// - Up, Down - прокрутка текста;
// - h - вызов справки;
// - r - возврат к текстовому файлу;
// - ESC - завершение программы;
// Дата создания: 2022 / 05 / 11
// Автор : Студент НГТУ ИРИТ, Халеев А.А., гр. 21-ИВТз
// Платформа : OS Ubuntu 22.04, Jet Brains Clion IDE (Study)
// *********************************************************************************

/* Подключение модулей */

#include "print_func.h"
#include "draw_func.h"
#include "table_func.h"
#include "struct.h"
#include "classes.h"
#include <iostream>
#include <string>
#include <map>


/* Для корректной работы программы необходимо передать путь к текстовому файлу в качестве аргумента командной строки */
int main(int argc, char **argv) {
    try {
        switch (argc) {
            case 2: {
                if (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help") {
                    RaiseHelpScreen("help_arg"); // Запуск программы в режиме справки
                }
                break;
            }
            case 4: {
                int rows_request;
                try {
                    rows_request = std::stoi(argv[2]);
                } catch (std::invalid_argument &stoi_err) {
                    throw SyntaxException(" The specified number of lines must be an integer", 1);
                }
                if (rows_request < 0) {
                    /* Пользователь захотел ввести/прочитать 0 строк */
                    throw SyntaxException(
                            " The specified number of lines can't be less than or equal to zero", 2);
                }
                if (argv[2] != std::to_string(rows_request)) {
                    /* Пользователь захотел ввести/прочитать не целое количество строк */
                    throw SyntaxException(
                            " It is not possible to use a floating point number to specify the number of lines\n"
                            " You should also use only digits for an integer", 3);
                } else
                    /* если количество строк целое и больше нуля */
                {
                    std::map<std::string, int> choice_map{
                            /* Строка справки для экрана, формируемого в случае некорректного запуска программы */
                            {"-r", 1},
                            /* Строка справки для экрана, формируемого в режиме прокрутки содержимого файла */
                            {"-c", 2}
                    };
                    switch (choice_map[argv[1]]) {
                        case 1: { // читаем
                            std::fstream table_in(argv[3], std::ios::in | std::ios::binary);
                            if (!table_in.is_open()) {
                                throw SyntaxException(
                                        " Unable to open or create specified file"
                                        "\n  Check that the specified file exists", 4);
                            } else
                                /* Если файл открыт успешно, продолжаем работу с его содержимым */
                            {
                                unsigned long file_bit;
                                table_in.seekg(0, std::ios::end);
                                long file_size = table_in.tellg();
                                if (file_size == 0) {  // если файл пустой
                                    throw SyntaxException(" The specified file is empty", 5);
                                } else {
                                    table_in.seekg(std::ios::beg);
                                    table_in.read((char *) &file_bit, sizeof(CORRECT_BIT));
                                    if (file_bit == CORRECT_BIT) {    //создан ли файл в этой проге
                                        ViewTable(argv, table_in, rows_request);
                                    } else {
                                        throw SyntaxException(
                                                " The specified file was not created in this program", 6);
                                    }
                                }
                                table_in.close();
                                if (table_in.is_open()) {
                                    throw SyntaxException(" Unable to close specified file", 7);
                                }
                            }
                            break;
                        }
                        case 2: { //пишем
                            std::fstream table_out(argv[3], std::ios::in | std::ios::out | std::ios::binary);
                            /* Если файл открыт успешно, продолжаем работу с его содержимым */
                            if (!table_out.is_open()) {
                                throw SyntaxException(
                                        " Unable to open or create specified file"
                                        "  Check that the specified file exists", 4);
                            } else {
                                int row_number = CreateTable(argv, table_out, rows_request);
                                ViewTable(argv, table_out, rows_request, row_number);

                                table_out.close();
                                if (table_out.is_open()) {
                                    throw SyntaxException(" Unable to close specified file", 7);

                                }
                                break; // конец записи
                            }
                        }
                        default: {
                            throw SyntaxException(
                                    " First argument is wrong. Among other things, check your keyboard layout", 8);
                        }
                    }
                    break; // конец обработки режима запуска (первый аргумент)
                }
                default: {
                    throw SyntaxException(
                            " Wrong number of arguments", 9);
                    break; // конец обработки количества полученных аргументов
                }
            }
        }
    } catch (SyntaxException &ex) {
        return 1;
    }
    reset_screen();
    return 0; // Завершение программы с кодом 0.
}
