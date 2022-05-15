#pragma once

/* Подключение модулей */
#include "definitions.h"
#include <string>

void GetWinSize(int &width, int &height);

/* Изменение параметров терминала в для корректной работы программы в соответствии с заданием */
void CustomizeTerminal(const std::string& font, const std::string& back);

void ResetTerminal(int def_width, int def_height);

void DrawStartBlock();

void DrawMidBlock();

void DrawEndBlock();

void DrawFrame(int rows);

void DrawHead();

void DrawTable();