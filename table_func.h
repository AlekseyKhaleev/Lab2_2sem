#pragma once

#include <array>
#include <fstream>

/* Функция вызова исключения связанного с выделением памяти для передачи в set_new_handler() */
void NewError();

int CreateTable(char *argv[], std::fstream &table_out, int rows_request);

void PrintTable(struct PC ParkContent[], int rows_request, int row_number);

void ViewTable(char *argv[], std::fstream &table_in, int rows_request, int row_number=0);

void GenerateTablePage(struct PC ParkContent[], char* argv[], int rows_to_print, int real_rows, int row_number);
