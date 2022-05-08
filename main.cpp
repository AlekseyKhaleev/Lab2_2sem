#include "func.h"
#include "struct.h"
#include <cerrno>
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {
    if (CorrectSyntax(argc,argv)){
        errno = 0;  // Переменная модуля errno.h, хранящая целочисленный код последней ошибки. 0 - отсутствие ошибок
        std::set_new_handler(NewError); // Назначение функции, которая будет вызвана при получении ошибки выделения памяти
        try {
            if (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help") {
                RaiseHelpScreen("error");
            } else{
                if (std::string(argv[1]) == "-c") {
                    std::ofstream table_out(argv[3], std::ios::out | std::ios::binary );
                    if(!table_out) {
                        std::cout << "Cannot open file.\n";
                        return 1;
                    }
                    int n = std::stoi(argv[2]);
                    if (n > 0) {
                        table_out.write((char *) &n, sizeof(int));
                        auto ParkUpdate = new structs::PC[n];
                        DrawFrame(n + 1);
                        DrawHead();
                        for (int i = 0; i < n; i++) {
                            ParkUpdate[i].set(i);
                            table_out.write((char *) &ParkUpdate[i], sizeof(struct structs::PC));
                        }
                        std::cin.get();
                        table_out.close();
                        if (table_out.is_open() != 0) {
                            std::cout
                                    << "Ошибка закрытия файла\n";            // Если файл не закрыт корректно выводим сообщение ошибке и
                            exit(1);                                    // завершаем программу с кодом 1
                        }
                        delete[] ParkUpdate;
                    }
                }
                if (std::string(argv[1]) == "-r") {
                    std::ifstream table_in(argv[3], std::ios::in | std::ios::binary);
                    if (!table_in) {
                        std::cout << "Cannot open file.\n";
                        return 1;
                    }
                    int n = std::stoi(argv[2]);
                    int n_content;
                    long file_size;
                    table_in.seekg(0, std::ios::end);
                    file_size = table_in.tellg();
                    if (file_size != 0 && n != 0) {
                        table_in.seekg(std::ios::beg);
                        table_in.read((char *) &n_content, sizeof(int));
                        if (n > n_content) n = n_content;
                        auto ParkContent = new structs::PC[n];
                        DrawFrame(n + 1);
                        DrawHead();
                        for (int i = 0; i < n; i++) {
                            table_in.read((char *) &ParkContent[i], sizeof(struct structs::PC));
                            ParkContent[i].out(i);
                        }
                        std::cin.get();
                        table_in.close();
                        if (table_in.is_open() != 0) {
                            std::cout
                                    << "Ошибка закрытия файла\n";            // Если файл не закрыт корректно выводим сообщение ошибке и
                            exit(1);                                    // завершаем программу с кодом 1
                        }
                        delete[] ParkContent;
                    }
                }
            }
        }
        catch (std::exception e) { // Обработка исключения, связанного с выделением динамической памяти
            perror("Memory allocation error");
        }
    } else
    {
        std::string error_msg[] = {
                "Correct arguments for run this app must be like:\n\n",
                "--help or -h : help mode\n",
                "-с [N] [file_name] - create spreadsheet mode\n",
                "-r [N] [file_name] - read spreadsheet mode\n\n",
                "N – the number of records;\n",
                "file_name – file path to save/read the table;\n\n",
                "Example1: /home/username/Lab1   -h\n\n",
                "Example2: /home/username/Lab1   --help\n\n",
                "Example3: /home/username/Lab1   -c 10 my_table\n\n",
                "Example4: /home/username/Lab1   -r 5 my_table\n\n",
        };
        for (auto & i : error_msg){
            std::cout << i;
        }
    };
    return 0;
}
