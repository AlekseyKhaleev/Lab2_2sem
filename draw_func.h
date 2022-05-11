#pragma once

/* Подключение модулей */
#include "definitions.h"
#include <string>

/* Изменение параметров терминала в для корректной работы программы в соответствии с заданием */
void CustomizeTerminal(std::string font, std::string back);

void DrawHead();

void DrawStartBlock();

void DrawMidBlock();

void DrawEndBlock();

void DrawFrame(int rows);
