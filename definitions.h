/* Данный модуль содержит макроопределения ESC-последовательностей, а также объявление необходимых констант */

#pragma once

/* Объявление констант */
const int SCREEN_WIDTH   = 112; // Ширина окна терминала
const int SCREEN_HEIGHT  = 42; // Высота окна терминала
const int LOGO_WIDTH     = 60; // Ширина логотипа программы (символов)
const int KEY_BUF_LEN    = 10; // Размер буфера для обработки ввода управляющих клавиш с клавиатуры
const int START_ROW      = 15;
const int START_COL      = 7;
const int MAX_ROWS       = 7;
const int START_ROW_FR   = 11;
const int START_COL_FR   = 6;
const int MAX_ROWS_FR    = 8;
const int START_ROW_HEAD = 12;
const int STEP_COL       = 17;
const int STEP_ROW       = 3;
const int BLOCK_WIDTH    = 18;
const int TABLE_COLS     = 6;
const int STRLEN         = 80;
const unsigned long CORRECT_BIT   = 1598745732109853234;


/* Определение кодов "горячих клавиш" для обработки ввода с клавиатуры */
#define Return 114 // соответствует коду клавиши 'r'
#define Help   104 // соответствует коду клавиши 'h'
#define Up     65  // соответствует коду клавиши 'Up'
#define Down   66  // соответствует коду клавиши 'Down'
#define Escape 27  // соответствует коду клавиши 'Esc'

/* Макроопределения ESC-последовательностей */
#define ESC                     "\x1B" // начало выражения
#define move_cursor(row, col)   std::cout << ESC "[" << (row) << ";" << (col) << "H"
#define move_up(n)              std::cout << ESC "[" << (n) << "A"
#define move_down(n)            std::cout << ESC "[" << (n) << "B"
#define move_right(n)           std::cout << ESC "[" << (n) << "C"
#define move_left(n)            std::cout << ESC "[" << (n) << "D"
#define move_start_down(n)      std::cout << ESC "[" << (n) << "E"

/* Установка размеров окна терминала (шириной x и высотой y) */
#define set_window_size(x, y)   std::cout << ESC "[\e[8;" << (y) << ";" << (x) << "t"

/* Переместить курсор в левый верхний угол */
#define home()                  std::cout << ESC "[0;0f"

/* Переместить курсор в начало последней строки */
#define to_end()                (std::cout << ESC "[" << SCREEN_HEIGHT - 1 << ";0f")

/* Переместить курсор в положение, соответствующее началу вывода содержимого файла */
#define file_home()             std::cout << ESC "[" << LOGO_LEN << ";0f"

/* Переместить курсор в левый верхний угол, очистить экран и буфер прокрутки, фон заполняется соответствующим цветом*/
#define clear_screen()          home(); std::cout << ESC "[2J" << ESC "[3J"

/* Сброс всех настроек терминала в значения по умолчанию */
#define reset_screen()          std::cout << ESC "c"

#define bright_on()                std::cout << ESC "[1m"
#define bright_on_text             "\x1B[1m\n"
#define bright_off()               std::cout << ESC "[22m"
#define bright_off_text            "\x1B[22m\n"

/* Установить цвета текста(f_color) и фона (b_color) */
#define set_display_atrib(f_color, b_color) std::cout << ESC "[" << (f_color) << ';' << (b_color) << "m"

/* Определения для цветов текста (RGB) */
#define F_GREY      "38;2;128;128;128" // Серый текст
#define F_WHITE     "38;2;252;252;252" // Белый текст
#define F_BLACK 	"38;2;0;0;0"       // Черный текст

/* Определения для цветов фона (RGB) */
#define B_WHITE     "48;2;252;252;252" // Белый фон
#define B_BLACK 	"48;2;0;0;0"       // Черный фон
