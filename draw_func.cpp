
#include "draw_func.h"
#include "definitions.h"
#include <string>
#include <iostream>


void CustomizeTerminal(std::string font, std::string back){
    // Цель: Изменить параметры терминала в для корректной работы программы в соответствии с заданием.
    // Исходные данные:
    // Результат: Терминал готов к работе программы с новыми параметрами.
    // Вызываемые модули: <definitions.h>
    /* Описание алгоритма:
    * Для изменения необходимых настроек терминала используются макроопределения, описанные в модуле definitions.h
    * 1) С помощью константных значений, соответствующих требованиям к работе программы (ширина = 80), изменяется
    * размер окна терминала.
    * 2) Отключается перенос по словам.
    * 3) Применяются новые настройки цветовой палитры терминала:
    *   - серый текст
    *   - черный фон
    * 4) Курсор перемещается в левый верхний угол, производится очистка экрана и буфера с заполнением фона с учетом
    * новых настроек цветовой палитры.
    // Дата: 2022 / 03 / 09 Версия 1.01
    // Автор: Студент НГТУ ИРИТ, Халеев А. А. гр. 21-ИВТз
    // Исправления: нет
    /***********************************************************************************************************/
    set_window_size(SCREEN_WIDTH, SCREEN_HEIGHT);
    //cut();
    set_display_atrib(font, back);
    clear_screen();
}

void DrawHead(){
    std::string head[] = {"N","CPU Type","CPU Freq. (MHz)","Memory (MB)","Storage (GB)",
                          "Display"};
    for(int i=START_COL, j=0; i < (BLOCK_WIDTH-1)*TABLE_COLS+START_COL; i+=(STEP_COL), j++){
        move_cursor(13, i);
        std::cout << head[j];
    }
}

void DrawStartBlock(){
    std::cout << "┌────────────────┐";
    move_left(BLOCK_WIDTH);
    move_down(1);
    std::cout << "│                │";
    move_left(BLOCK_WIDTH);
    move_down(1);
    std::cout << "└────────────────┘";
    move_up(2);
    move_left(1);
}

void DrawMidBlock(){
    std::cout << "┬────────────────┬";
    move_left(BLOCK_WIDTH);
    move_down(1);
    std::cout << "│                │";
    move_left(BLOCK_WIDTH);
    move_down(1);
    std::cout << "┴────────────────┴";
    move_up(2);
    move_left(1);
}

void DrawEndBlock(){
    std::cout << "┬────────────────┐";
    move_left(BLOCK_WIDTH);
    move_down(1);
    std::cout << "│                │";
    move_left(BLOCK_WIDTH);
    move_down(1);
    std::cout << "┴────────────────┘";
    move_up(2);
    move_left(1);
}

void DrawFrame(int rows){
    move_cursor(START_ROW_FR, START_COL_FR);
    for (int i=0; i < rows; i++){
        for (int j=0; j < TABLE_COLS; j++){
            switch(j){
                case 0: DrawStartBlock(); break;
                case (TABLE_COLS - 1): DrawEndBlock(); break;
                default: DrawMidBlock(); break;
            }
        }
        move_start_down(3);
        move_right(5);
    }
}