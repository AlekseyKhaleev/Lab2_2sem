#pragma once

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>


class SyntaxException : public ::std::runtime_error {
public:
    explicit
    SyntaxException(const char* message, int value) : runtime_error{message} {
        this->error_type=value;
        this->description(error_type);
    }

private:
    int error_type;
    void description(int type);
};

