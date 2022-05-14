
#include "classes.h"
#include <string>
#include <map>

void SyntaxException::description(int type){
    std::string error_msg[] = {
            "Correct arguments for run this app:\n\n",
            "--help or -h : help mode\n",
            "-с [N] [file_name] : create spreadsheet mode\n",
            "-r [N] [file_name] : read spreadsheet mode\n\n",
            "N – the number of records;\n",
            "file_name – file name or full path to save/read the table;\n\n"
    };
    std::cout << "\nSyntax Exception Type " << type << " :\n" << what() << "\n\n";
    for (auto &i: error_msg) {
        std::cout << i;
    }
}
