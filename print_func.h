/* Данный модуль содержит определения функций, необходимых для корректной работы программы Lab1 */

#pragma once

/* Подключение модулей */
#include <string>


/* Формирование и вывод логотипа программы в окно терминала */
void PrintHeader(char* argv[]);

void PrintFooter(char *argv[], int rows_request, int real_rows, const std::string& reason="text");

/* Вывод строки минимальной справки в зависимости от причины вызова */
void PrintQuickHelp(const std::string& reason);

/* Формирование и вывод справочного экрана в окно терминала */
void PrintHelpScreen(const std::string& reason);

/* Аварийное завершение программы с предварительным выводом справочной информации */
void RaiseHelpScreen(const std::string& reason);

/* Считывание кода нажатой клавиши в терминале без промежуточной буферизации */
int UserKey();





