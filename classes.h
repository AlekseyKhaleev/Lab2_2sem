#pragma once

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>


class SyntaxException : public ::std::runtime_error {
public:
    void description();
    explicit
    SyntaxException(const char* message, int type, int argc) : runtime_error{message} {
        this ->type=type;
        this ->argc=argc;
    }

private:
    int type;
    int argc;
};

