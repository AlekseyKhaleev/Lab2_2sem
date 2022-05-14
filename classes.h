#pragma once

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>


class SyntaxException : public ::std::runtime_error {
public:
    explicit
    SyntaxException(const char* message, int value, int argc) : runtime_error{message} {
        this->description(value, argc);
    }

private:
    void description(int type, int argc);
};

