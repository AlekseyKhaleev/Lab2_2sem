/**********************************************************************************************************************
* Данный модуль содержит определения методов собственных классов, определенных в "classes.h"
**********************************************************************************************************************/

/* Подключение модулей */
#include "classes.h"
#include <string>
#include <iostream>

void SyntaxException::description(){
    /*****************************************************************************************************************
    * Цель: Вывести в STDOUT сообщение с описанием полученной ошибки аргументов и краткую справку.
    * Исходные данные:
     *  type - закрытая переменная класса SyntaxException
     *  argc - закрытая переменная класса SyntaxException
    * Результат: В поток вывода выведено сообщение об ошибке.
    * Вызываемые модули: <string>, "classes.h"
    * Описание алгоритма:
    * 1) Определяется массив string[], содержащий общую информацию о корректных аргументах
    * 2) Выводится сообщение, в котором:
     * type - тип ошибки
     * argc - количество полученных аргументов
     * what() - возвращенное описание ошибки
    * 3) В цикле по строчно выводится базовое сообщение
    * Дата: 15 / 05 / 2022 Версия 1.01
    * Автор: Студент НГТУ ИРИТ, Халеев А. А. гр. 21-ИВТз
    * Исправления: нет
    *****************************************************************************************************************/
    std::string error_msg[] = {
            "Correct arguments for run this app:\n\n",
            "--help or -h : help mode\n",
            "-с [N] [file_name] : create spreadsheet mode\n",
            "-r [N] [file_name] : read spreadsheet mode\n\n",
            "N – the number of records;\n",
            "file_name – file name or full path to save/read the table;\n\n"
    };
    std::cout << "\nSyntax Exception Type " << type << " : " << argc - 1 << " arguments given.\n" << what() << "\n\n";
    for (auto &i: error_msg) {
        std::cout << i;
    }
}
