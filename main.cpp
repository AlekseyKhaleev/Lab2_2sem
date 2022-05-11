#include "func.h"
#include "draw_func.h"
#include "struct.h"
#include <iostream>
#include <string>
#include <array>

int main(int argc, char **argv) {
    int UserInput = CorrectSyntax(argc, argv);
    if (!UserInput) {
        if (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help") {
            RaiseHelpScreen("help_arg");
        } else {
            if (std::string(argv[1]) == "-c") {
                int current_page = CreateTable(argv);
                ViewTable(argv, current_page);
            }
            if (std::string(argv[1]) == "-r") {
                ViewTable(argv);
            }
        }
        reset_screen();
    } else {
        RaiseSyntaxError(UserInput);
    }
    return 0;
}
