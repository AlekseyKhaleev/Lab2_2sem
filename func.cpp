/* Данный модуль содержит описания функций, необходимых для корректной работы программы Lab1 */

/* Подключение модулей */
#include "struct.h"
#include "definitions.h"
#include "func.h"
#include "draw_func.h"
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
#include <array>


void PrintHeader(char *argv[]) {
    // Цель: Формирование и вывод логотипа программы в окно терминала.
    // Исходные данные:
    //      file_name - строка, содержащая имя файла, открытого в программе
    // Результат: В окно терминала выведен логотип программы.
    // Вызываемые модули: <string>
    /* Описание алгоритма:
    * 1) Объявляется массив строк logo и инициализируется строками, соответствующими логотипу программы
    * 2) Применяются требуемые настройки цветового оформления терминала.
    * 3) Курсор переводится в левый верхний угол. Осуществляется очистка окна терминала, очистка буфера прокрутки
    * и заполнение фона терминала.
    * 4) С помощью обхода массива logo в цикле осуществляется вывод справочной информации по центру.
    * 5) Восстанавливаются программные настройки цветовой палитры терминала, завершение работы модуля.
    // Дата: 2022 / 03 / 09 Версия 1.01
    // Автор: Студент НГТУ ИРИТ, Халеев А. А. гр. 21-ИВТз
    // Исправления: нет
    /***********************************************************************************************************/

    /* Массив строк соответствующих содержимому логотипа программы */
    std::string logo[LOGO_LEN] = {
            "\n",
            "***********************************************************\n",
            "* Nizhniy Novgorod Technical University                   *\n",
            "* Study work number 2. Task number 8. Semester number 2.  *\n",
            "* Performed student 21-IVTz Khaleev Aleksey               *\n",
            "***********************************************************\n",
            "\n"};

    size_t left_bord = (SCREEN_WIDTH - LOGO_WIDTH) / 2.;   // Вычисление левой границы выводимого текста
    for (auto &i: logo) {                         // Обход массива строк логотипа программы
        std::cout << std::setw(left_bord) << "";           // Центрирование вывода
        std::cout << i;                                    // Вывод очередной строки логотипа программы
    }
    move_start_down(1);
    if (std::string(argv[1]) == "-r") {
        std::cout << std::setw(left_bord) << "";           // Центрирование вывода
        std::cout << "The data of the PC-park in the \"" + std::string(argv[3]) + "\" table: \n";
    }
    if (std::string(argv[1]) == "-c") {
        std::cout << std::setw(left_bord) << "";           // Центрирование вывода
        std::cout << "Please enter the data of the PC-park in the \"" + std::string(argv[3]) + "\" table: \n";
    }
}

void PrintFooter(char *argv[], std::array<int, 2> rows, std::string reason) {
    // Цель: Формирование и вывод логотипа программы в окно терминала.
    // Исходные данные:
    //      file_name - строка, содержащая имя файла, открытого в программе
    // Результат: В окно терминала выведен логотип программы.
    // Вызываемые модули: <string>
    /* Описание алгоритма:
    * 1) Объявляется массив строк logo и инициализируется строками, соответствующими логотипу программы
    * 2) Применяются требуемые настройки цветового оформления терминала.
    * 3) Курсор переводится в левый верхний угол. Осуществляется очистка окна терминала, очистка буфера прокрутки
    * и заполнение фона терминала.
    * 4) С помощью обхода массива logo в цикле осуществляется вывод справочной информации по центру.
    * 5) Восстанавливаются программные настройки цветовой палитры терминала, завершение работы модуля.
    // Дата: 2022 / 03 / 09 Версия 1.01
    // Автор: Студент НГТУ ИРИТ, Халеев А. А. гр. 21-ИВТз
    // Исправления: нет
    /***********************************************************************************************************/

    size_t left_bord = (SCREEN_WIDTH - LOGO_WIDTH) / 2.;   // Вычисление левой границы выводимого текста
    move_start_down(2);
    if (std::string(argv[1]) == "-r") {
        std::cout << std::setw(left_bord) << "";           // Центрирование вывода
        std::cout << "The PC-park table was initialized successfully.\n\n";
        std::cout << std::setw(left_bord) << "";
        std::cout << "Loaded " + std::to_string(rows[0]) + " of " + std::to_string(rows[1]) + " lines\n\n";
    }
    if (std::string(argv[1]) == "-c") {
        std::cout << std::setw(left_bord) << "";           // Центрирование вывода
        std::cout << "The creation of the PC-park table is now complete.\n\n";
    }
    to_end();
    std::cout << std::setw(left_bord) << "";           // Центрирование вывода
    PrintQuickHelp(reason);      // Вывод очередной строки логотипа программы
}

void PrintHelpScreen(const std::string &reason) {
    // Цель: Формирование и вывод справочного экрана в окно терминала.
    // Исходные данные:
    //      reason - строка, ключ для передачи в качестве аргумента в модуль PrintHelp() для вывода короткой справки
    // Результат: Сформирован и выведен в терминал справочный экран
    // Вызываемые модули: <string>, PrintQuickHelp()
    /* Описание алгоритма:
    * 1) Объявляется массив строк help_screen и инициализируется строками, содержащими справочную информацию о программе
    * 2) Применяются требуемые настройки цветового оформления терминала.
    * 3) Курсор переводится в левый верхний угол. Осуществляется очистка окна терминала, очистка буфера прокрутки
    * и заполнение фона терминала.
    * 4) С помощью обхода массива help_screen в цикле осуществляется вывод справочной информации по центру.
    * 5) Курсор переводится в начало последней строки.
    * 6) Выводится строка минимальной справки, в зависимости от причины вызова справки
    * (аргумент reason функции PrintHelp())
    * 7) Применяются программные настройки цветовой палитры терминала, завершение работы модуля.
    // Дата: 2022 / 03 / 09 Версия 1.01
    // Автор: Студент НГТУ ИРИТ, Халеев А. А. гр. 21-ИВТз
    // Исправления: нет
    /***********************************************************************************************************/

    /* Массив строк, содержащих справочную информацию о работе программы */
    std::string help_screen[] =
            {"\n",
             "Lab2 is a table reader/constructor, made by Khaleev Aleksey\n\n",
             "This app will help you create and view tables containing\n",
             "the characteristics of your fleet of PC's\n\n",
             "Correct arguments for run this app must be like:\n\n",
             "        --help or -h : help mode\n",
             "        -с [N] [file_name] : create spreadsheet mode\n",
             "        -r [N] [file_name] : read spreadsheet mode\n\n",
             "N – the number of records;\n",
             "file_name – file path to save/read the table;\n\n",
             "Example1: /home/username/Lab1   -h\n",
             "Example2: /home/username/Lab1   --help\n",
             "Example3: /home/username/Lab1   -c 10 my_table\n",
             "Example4: /home/username/Lab1   -r 5 my_table\n\n",
             "                             IMPORTANT!\n",
             " Keep in mind that to start the program correctly in create or read mode\n",
             "you must correctly specify the number of rows of the future table:\n",
             "- if the specified number of rows is not positive ( N <= 0),\n",
             "the program will not start\n",
             "- if the number of rows specified in the read mode is less than the number\n",
             "contained in the specified file, the first rows will be displayed according\n",
             "to the query;\n",
             "- if the specified number of lines in read mode is more than contained\n",
             "in the specified file, all lines contained in the file will be shown. \n\n",
             "This program conclude few hot-keys for control application in -c/-r mode:\n\n",
             "Esc      - exit program\n",
             "h        - view help page\n",
             "r        - return to program interface\n\n"};
    set_display_atrib(F_BLACK, B_WHITE);                    // Изменение настроек цветовой палитры терминала

    /* Перевод курсора в верхний левый угол, очистка экрана, очистка буфера прокрутки и заполнение фона */
    clear_screen();

    size_t left_bord = (SCREEN_WIDTH - LOGO_WIDTH) / 2.;    // Вычисление левой границы выводимого текста
    for (auto &i: help_screen) {                    // Обход массива строк со справочной информацией
        std::cout << std::setw(left_bord) << "";            // Центрирование вывода
        std::cout << i;                                     // Вывод очередной справочной строки
    }
    to_end();                                               // Перевод курсора в начало последней строки
    std::cout << std::setw(left_bord) << "";// Центрирование вывода
    PrintQuickHelp(reason); // Вывод минимальной справки о возможных действиях
    set_display_atrib(F_GREY, B_BLACK);                     // Применение программных настроек цветовой палитры
}

void PrintQuickHelp(const std::string& reason){
    // Цель: Вывод строки минимальной справки в зависимости от причины вызова.
    // Исходные данные:
    //      reason - строка-ключ для передачи в качестве аргумента в модуль PrintHelp() для вывода короткой справки
    // Результат: В окно терминала выведена строка с минимальной справочной информацией.
    // Вызываемые модули: <string>, <map>
    /* Описание алгоритма:
    * Справочная строка может отличаться в зависимости от текущего содержимого в окне терминала.
    * 1) С помощью ассоциативного контейнера choice_map задаются пары ключ-значение типов string-string. Каждый ключ
    * обозначает одно из условий вызова справки, получаемое с помощью аргумента reason. Ключу ставится в соответствие
    * строка, которая будет выведена на экран.
    * 2) Производится проверка корректности аргумента, переданного в переменную reason.
    * 3) Если ключ reason присутствует в choice_map:
    *   - изменяются параметры цветового оформления терминала
    *   - выводится значение choice_map, соответствующее ключу reason
    *   - восстанавливаются программные настройки цветового оформления терминала
    * 4) Если ключ reason отсутствует в choice_map выводится сообщение об отсутствии ключа reason.
    // Дата: 2022 / 03 / 09 Версия 1.01
    // Автор: Студент НГТУ ИРИТ, Халеев А. А. гр. 21-ИВТз
    // Исправления: нет
    /***********************************************************************************************************/

    /* Инициализация ассоциативного контейнера choice_map */
    std::map <std::string, std::string> choice_map{
            /* Строка справки для экрана, формируемого в случае некорректного запуска программы */
            {"help_arg", "                 Press Esc for exit"},
            /* Строка справки для экрана, формируемого в режиме прокрутки содержимого файла */
            {"text", "            Press Esc for exit or h for help"},
            /* Строка справки для экрана, формируемого в режиме отображения справочного экрана */
            {"help_prog", "            Press Esc for exit or r for return to text"}
    };
    if (choice_map.find(reason) != choice_map.end()){ // Если в переменную reason передан корректный аргумент
        set_display_atrib(F_BLACK, B_WHITE);             // Изменение цветовых параметров терминала
        std::cout << choice_map[reason];                 // Вывод минимальной справочной информации
        set_display_atrib(F_GREY, B_BLACK);              // Восстановление программных цветовых параметров терминала
    } else
        std::cout << "PrintHelp() error. Key '" << reason << "' not found."; // Вывод сообщения о некорректном аргументе
}

int UserKey() {
    // Цель: Считывание кода нажатой клавиши в терминале без промежуточной буферизации
    // Исходные данные:
    // Результат: функция возвращает целое число соответствующее коду нажатой клавиши
    // Вызываемые модули: <termios.h>, <unistd.h>
    /* Описание алгоритма:
    * 1) С помощью модуля termios.h объявляются структуры для хранения состояния терминала:
    *       - oldt до считывания нажатия клавиши
    *       - newt во время считывания нажатия клавиши
    * 2) Объявляются целочисленные переменные и массив:
    *   - key_buffer целочисленный массив для хранения кода считанной клавиши (из-за привязки к ESC-последовательностям
    *   управляющие клавиши могут возвращать не единственное целое число (код символа), а серию таких чисел).
    *   Размер массива равен 10, чтобы обеспечить "запас" и избежать обращения по несуществующему индексу.
    *   - buffer_index вспомогательная переменная для обхода массива key_buffer в цикле.
    *   - key_code переменная для хранения обработанного кода считанной клавиши.
    * 3) В структуру oldt записывается текущее состояние терминала, это позволит восстановить исходное состояние
    * терминала после завершения необходимых операций, также состояние дублируется в структуру newt.
    * 4) В структуре newt отключаются флаги "каноничный" и "эхо", это необходимо для обеспечения неканоничного ввода
    * (без буферизации, редактирования).
    * 5) С помощью структуры newt применяется новый режим (состояние) терминала.
    * 6) C помощью функции getchar() считывается нажатие клавиши клавиатуры, результат приводится к типу int
    * и записывается в массив key_buffer под индексом 0.
    * 7) Производится обработка полученного значения:
    *   - если полученное целое значение равно 27, то возможны 2 варианта:
    *     1. Считана клавиша ESC, значение записано в массив.
    *     2. Считана управляющая клавиша, первое число из серии возвращаемых значений записано в массив.
    *   Для определения нажатой клавиши с помощью цикла производится попытка считать все оставшиеся числа серии
    *   и записать их в массив key_buffer. Для продвижения по массиву в цикле используется переменная-индекс
    *   buffer_index, начальное значение которого равно 1. Отличие от 1 индекса после завершения цикла является
    *   маркером считывания управляющей клавиши. В данной программе используются только 2 управляющие клавиши,
    *   не считая ESC: Up и Down, серии возвращаемых значений которых отличаются третьими элементами, равными
    *   соответственно 65 и 66. В связи с этим свойством, в случае отличия от 1 индекса buffer_index в переменную
    *   key_code записывается значение элемента key_buffer с индексом 2. В противном случае записывается значение
    *   элемента key_buffer с индексом 0.
    * 8) С помощью сохраненного в структуре oldt состояния терминала восстанавливаются исходные параметры.
    * 9) Функция возвращает обработанный целочисленный код клавиши, сохраненный в переменной key_code.
    // Дата: 2022 / 03 / 09 Версия 1.01
    // Автор: Студент НГТУ ИРИТ, Халеев А. А. гр. 21-ИВТз
    // Исправления: нет
    /***********************************************************************************************************/
    struct termios oldt{}, newt{};                          // структуры для хранения состояния терминала
    int key_code, buffer_index{1}, key_buffer[KEY_BUF_LEN]; // Переменные и массив, необходимые для работы модуля
    tcgetattr(STDIN_FILENO, &oldt);          // Сохранение исходного состояния терминала
    newt = oldt;                                            // Копирование состояния терминала для дальнейшей работы
    newt.c_lflag &= ~(ICANON | ECHO);                     // Отключение флагов "каноничный" и "эхо"
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Применение новых параметров терминала
    key_buffer[0] = getchar(); // Считывание нажатия клавиши клавиатуры

    // Блок обработки, проверка на получение управляющей клавиши, сохранение целочисленного кода нажатой клавиши
    if (key_buffer[0] == 27) {
        newt.c_cc[VMIN] = 0;
        tcsetattr(0, TCSANOW, &newt);
        while ((key_buffer[buffer_index] = getchar()) > 0) {
            ++buffer_index;
            if (buffer_index >= KEY_BUF_LEN) break;
        }
        clearerr(stdin);
    }
    if (buffer_index > 1) {
        key_code = key_buffer[2];
    } else
        key_code = key_buffer[0];

    /* Восстановление исходных параметров терминала */
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return key_code; // Возвращение целочисленного кода нажатой клавиши, завершение работы модуля
}

void RaiseHelpScreen(const std::string &reason) {
    // Цель: Аварийное завершение программы с предварительным выводом справочной информации.
    // Исходные данные:
    // Результат: Пользователь ознакомлен со справочной информацией, программа завершена с кодом 1
    // Вызываемые модули: <stdlib.h>, PrintHelpScreen(), UserKey(), EndScreen()
    /* Описание алгоритма:
    * 1) В окно терминала выводится справочная информация с помощью функции PrintHelpScreen() c аргументом "error".
    * 2) Модуль поддерживает одну "горячую" клавишу - Esc для завершения программы.
    * 3) После получения команды завершения производится очистка экрана и восстановление исходных параметров цветовой
    * палитры терминала с помощью функции EndScreen().
    * 4) Программа завершается с кодом 1 с помощью вызова функции exit(1).
    // Дата: 2022 / 03 / 09 Версия 1.01
    // Автор: Студент НГТУ ИРИТ, Халеев А. А. гр. 21-ИВТз
    // Исправления: нет
    /***********************************************************************************************************/
    CustomizeTerminal(F_BLACK, B_WHITE);
    PrintHelpScreen(reason);
    bool mark = true;
    while (mark) {
        switch (UserKey()) {
            case Escape:
                mark = false;
                break;
            default:
                break;
        }
    }
    reset_screen();
    exit(1);
}

/* Функция вызова исключения связанного с выделением памяти для передачи в set_new_handler() */
void NewError() {
    throw std::bad_alloc();
}

int CorrectSyntax(int argc, char *argv[]) {
    int correct = -1;
    switch (argc) {
        case 2: {
            if (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help") {
                correct = 0;
            }
            break;
        };
        case 4: {
            std::map<std::string, int> choice_map{
                    /* Строка справки для экрана, формируемого в случае некорректного запуска программы */
                    {"-r", 1},
                    /* Строка справки для экрана, формируемого в режиме прокрутки содержимого файла */
                    {"-c", 2}
            };
            int n = std::stoi(argv[2]);
            if (argv[2] == std::to_string(n) && n > 0) { //если количество строк целое и больше нуля
                switch (choice_map[argv[1]]) {
                    case 1: { // читаем
                        std::ifstream data(argv[3], std::ios::in | std::ios::binary);
                        /* Если файл открыт успешно, продолжаем работу с его содержимым */
                        if (data.is_open()) {
                            long file_size;
                            unsigned long file_bit;
                            data.seekg(0, std::ios::end);
                            file_size = data.tellg();
                            if (file_size == 0) {
                                correct = 1; // если файл пустой
                            } else {
                                data.seekg(std::ios::beg);
                                data.read((char *) &file_bit, sizeof(CORRECT_BIT));
                                if (file_bit == CORRECT_BIT) {    //создан ли файл в этой проге
                                    correct = 0;
                                } else correct = 2;
                            }
                        } else correct = 4;
                        data.close();
                        if (data.is_open() != 0) {
                            std::cout
                                    << "Ошибка закрытия файла\n"; // Если файл не закрыт корректно выводим сообщение ошибке и
                            exit(1);                          // завершаем программу с кодом 1
                        }
                        break;
                    }
                    case 2: { //пишем
                        std::ofstream data(argv[3], std::ios::out | std::ios::binary);
                        /* Если файл открыт успешно, продолжаем работу с его содержимым */
                        if (data.is_open()) {
                            correct = 0;
                        } else correct = 4;
                        data.close();
                        if (data.is_open() != 0) {
                            std::cout
                                    << "Ошибка закрытия файла\n"; // Если файл не закрыт корректно выводим сообщение ошибке и
                            exit(1);                          // завершаем программу с кодом 1
                        }
                        break;
                    }
                }
            } else correct = 3; // пользователь захотел ввести/прочитать 0 строк
            break;
        }
        default:
            break;
    }
    return correct;
}

void RaiseSyntaxError(int reason) {
    std::map <int, std::string> choice_map{
            /* Строка справки для экрана, формируемого в случае некорректного запуска программы */
            {-1, "\n Wrong number or type of arguments.\nAmong other things, check your keyboard layout\n"},
            /* Строка справки для экрана, формируемого в режиме отображения справочного экрана */
            {1,"\n The specified file is empty\n"},
            {2,"\n The specified file was not created in this program\n"},
            {3,"\n The specified number of lines cannot be less than or equal to zero\n"},
            {4,"\n Unable to open or create specified file\nCheck that the specified file exists\n"}
    };
    std::cout << choice_map[reason] << std::endl;
    std::string error_msg[] = {
            "Correct arguments for run this app must be like:\n\n",
            "--help or -h : help mode\n",
            "-с [N] [file_name] : create spreadsheet mode\n",
            "-r [N] [file_name] : read spreadsheet mode\n\n",
            "N – the number of records;\n",
            "file_name – file path to save/read the table;\n\n",
            "Example1: /home/username/Lab1   -h\n\n",
            "Example2: /home/username/Lab1   --help\n\n",
            "Example3: /home/username/Lab1   -c 10 my_table\n\n",
            "Example4: /home/username/Lab1   -r 5 my_table\n\n",
            "",
    };
    for (auto &i: error_msg) {
        std::cout << i;
    }
}

void CreateTable(char *argv[]) {
    errno = 0;  // Переменная модуля errno.h, хранящая целочисленный код последней ошибки. 0 - отсутствие ошибок
    std::set_new_handler(
            NewError); // Назначение функции, которая будет вызвана при получении ошибки выделения памяти
    try {
        std::ofstream table_out(argv[3], std::ios::out | std::ios::binary);
        if (table_out.is_open()) {
            int n = std::stoi(argv[2]);
            table_out.write((char *) &CORRECT_BIT, sizeof(CORRECT_BIT));
            table_out.write((char *) &n, sizeof(int));
            auto ParkUpdate = new structs::PC[n];
            DrawFrame(n + 1);
            DrawHead();
            for (int i = 0; i < n; i++) {
                ParkUpdate[i].set(i);
                table_out.write((char *) &ParkUpdate[i], sizeof(struct structs::PC));
            }
            std::cout << std::endl;
            delete[] ParkUpdate;
        } else {
            std::cout << "Cannot open file\n";
            exit(1);
        }
        table_out.close();
        if (table_out.is_open() != 0) {
            std::cout << "Cannot close file\n";            // Если файл не закрыт корректно выводим сообщение ошибке и
            exit(1);                                    // завершаем программу с кодом 1
        }
    } catch (std::exception e) { // Обработка исключения, связанного с выделением динамической памяти
        perror("Memory allocation error");
    }
}

std::array<int, 2> PrintTable(char *argv[]) {
    std::array<int, 2> n{std::stoi(argv[2]),-1};
    errno = 0;  // Переменная модуля errno.h, хранящая целочисленный код последней ошибки. 0 - отсутствие ошибок
    std::set_new_handler(
            NewError); // Назначение функции, которая будет вызвана при получении ошибки выделения памяти
    try {
        std::ifstream table_in(argv[3], std::ios::in | std::ios::binary);
        if (table_in.is_open()) {
            table_in.seekg(sizeof(CORRECT_BIT));
            table_in.read((char *) &n[1], sizeof(int));
            if (n[0] > n[1]) n[0] = n[1];
            auto ParkContent = new structs::PC[n[0]];
            DrawFrame(n[0] + 1);
            DrawHead();
            for (int i = 0; i < n[0]; i++) {
                table_in.read((char *) &ParkContent[i], sizeof(struct structs::PC));
                ParkContent[i].out(i);
            }
            std::cout << std::endl;
            delete[] ParkContent;
            table_in.close();
            if (table_in.is_open() != 0) {
                std::cout
                        << "Cannot close file\n";            // Если файл не закрыт корректно выводим сообщение ошибке и
                exit(1);                                    // завершаем программу с кодом 1
            }
        } else {
            std::cout << "Cannot open file.\n";
            exit(1);
        }
    } catch (std::exception e) { // Обработка исключения, связанного с выделением динамической памяти
        perror("Memory allocation error");
    }
    return n;
}
