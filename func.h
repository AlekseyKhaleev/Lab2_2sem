/* Данный модуль содержит определения функций, необходимых для корректной работы программы Lab1 */

#pragma once

/* Подключение модулей */
#include "definitions.h"
#include <string>
#include <termios.h>
#include <array>


/* Формирование и вывод логотипа программы в окно терминала */
void PrintHeader(char* argv[]);

void PrintFooter(char* argv[], std::array<int, 2> rows = {0, 0}, std::string reason="text");

/* Вывод строки минимальной справки в зависимости от причины вызова */
void PrintQuickHelp(const std::string& reason);

/* Формирование и вывод справочного экрана в окно терминала */
void PrintHelpScreen(const std::string& reason);

/* Считывание кода нажатой клавиши в терминале без промежуточной буферизации */
int UserKey();

/* Аварийное завершение программы с предварительным выводом справочной информации */
void RaiseHelpScreen(const std::string& reason);

/* Функция вызова исключения связанного с выделением памяти для передачи в set_new_handler() */
void NewError();

int CorrectSyntax(int argc, char* argv[]);

void RaiseSyntaxError(int reason);

int CreateTable(char* argv[]);

void InitTable(char *argv[], struct PC ParkContent[], int rows);

void PrintTable(struct PC ParkContent[], int max, int current);

std::array<int, 2> ReadTableData(char *argv[]);

void ViewTable(char* argv[], int current_page = 0);

