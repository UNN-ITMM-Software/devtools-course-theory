// Copyright 2013 K.Nikolaev

#include "library/NumConverter_application.h"

#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>

NumConverterApplication::NumConverterApplication() : mess_("") {}

void NumConverterApplication::Help(const char* appname) {
    mess_ += std::string("This is a number converter application.\n")
         + "Please provide arguments in the following format:\n\n"
         + "  $ " + appname + " <numsystem> <number>\n\n"
         + "Where <numsys> is one of 'bin', 'oct', 'dec' or 'hex', "
         + "and <number> is unsigned integer in selected notation.\n";
}

std::string ParseNumber(const char* num, NumSystem numsys);
std::string ParseNumber(const char* num, NumSystem numsys) {
    std::string s(num);
    if (numsys == bin) {
        if (s.length() > 31)
            throw "Wrong number format";
        for (unsigned int i = 0; i < s.length(); i++) {
            if (s[i] < 48 || s[i] > 49)
                throw "Wrong number format";
        }
    } else if (numsys == oct) {
        if (s.length() > 10)
            throw "Wrong number format";
        for (unsigned int i = 0; i < s.length(); i++) {
            if (s[i] < 48 || s[i] > 55)
                throw "Wrong number format";
        }
    } else if (numsys == dec) {
        if (s.length() > 9)
            throw "Wrong number format";
        for (unsigned int i = 0; i < s.length(); i++) {
            if (s[i] < 48 || s[i] > 57)
                throw "Wrong number format";
        }
    } else if (numsys == hex) {
        if (s.length() > 7)
            throw "Wrong number format";
        for (unsigned int i = 0; i < s.length(); i++) {
            if (s[i] < 48 || (s[i] > 57 && s[i] < 97) ||
                s[i] > 102)
                throw "Wrong number format";
        }
    }
    return s;
}

bool NumConverterApplication::ParseArgs(int argc, const char** argv,
    Argument* arg) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 3) {
        mess_ = "Error: Should be 2 arguments.\n";
        Help(argv[0]);
        return false;
    }
    if (strcmp(argv[1], "bin") == 0) {
        arg->numsys = bin;
    } else if (strcmp(argv[1], "oct") == 0) {
        arg->numsys = oct;
    } else if (strcmp(argv[1], "dec") == 0) {
        arg->numsys = dec;
    } else if (strcmp(argv[1], "hex") == 0) {
        arg->numsys = hex;
    } else {
        mess_ = "Error: Wrong name for a number system.\n";
        return false;
    }
    try {
        arg->number = ParseNumber(argv[2], arg->numsys);
    }
    catch(...) {
        mess_ = "Error: Wrong number format.\n";
        return false;
    }
    return true;
}

std::string NumConverterApplication::operator()(int argc, const char** argv) {
    Argument arg;
    bool returnCode = ParseArgs(argc, argv, &arg);
    if (!returnCode)
        return mess_;
    NumConverter a(arg.number, arg.numsys);
    std::ostringstream stream;
    stream << "";
    switch (arg.numsys) {
        case bin: {
            stream << a.GetValue() << "in bin.\n";
            stream << "Is" << a.ToHex() << "in hex.\n";
            stream << "Is" << a.ToOctal() << "in oct.\n";
            stream << "Is" << a.ToDecimal() << "in dec.\n";
            break;
        }
        case oct: {
            stream << a.GetValue() << "in oct.\n";
            stream << "Is" << a.ToHex() << "in hex.\n";
            stream << "Is" << a.ToDecimal() << "in dec.\n";
            stream << "Is" << a.ToBinary() << "in bin.\n";
            break;
        }
        case dec: {
            stream << a.GetValue() << "in dec.\n";
            stream << "Is" << a.ToHex() << "in hex.\n";
            stream << "Is" << a.ToOctal() << "in oct.\n";
            stream << "Is" << a.ToBinary() << "in bin.\n";
            break;
        }
        case hex: {
            stream << a.GetValue() << "in hex.\n";
            stream << "Is" << a.ToOctal() << "in oct.\n";
            stream << "Is" << a.ToDecimal() << "in dec.\n";
            stream << "Is" << a.ToBinary() << "in bin.\n";
            break;
        }
    }

    mess_ = stream.str();

    return mess_;
}
