// Copyright 2013 Michail Kupriyanov

#include "library/calc_application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>

#include "library/mathquancalc.h"

MathQuanCalcApplication::MathQuanCalcApplication() : message_("") {}

void MathQuanCalcApplication::help(const char* appname) {
    message_ += std::string("This is a math quantities ")
        + "calculator application.\n\n"
        + "Please provide arguments in the following format:\n\n"
        + "  $ %s <value_1> <probability_1> <value_2> <probability2_>"
        + " ... \n\n" + appname
        + "Where both arguments are double numbers.\n";
}

static double ParseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("ERROR: wrong number format");
    }

    return value;
}

bool MathQuanCalcApplication::parseArguments(int argc, const char** argv,
                           std::vector<MathQuanCalc::Event>* sample) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if ((argc % 2) == 0) {
        message_ = "ERROR: wrong arguments format.\n\n";
        help(argv[0]);
        return false;
    }

    MathQuanCalc::Event event;
    for (int i = 1; i < argc; i += 2) {
        try {
            event.value = ParseDouble(argv[i]);
            event.probability = ParseDouble(argv[i + 1]);
        }
        catch(const std::string& str) {
            message_ = str;
            return false;
        }
        sample->push_back(event);
    }

    return true;
}
static void MakeCalc(MathQuanCalc* mqCalc,
    std::vector<MathQuanCalc::Event>* sample,
    std::ostringstream* stream) {
    try {
        mqCalc->PutSample(*sample);
        double expVal = 0.;
        try {
            expVal = mqCalc->GetExpectedValue();
            (*stream) << "\nExpected value:  " << expVal << "\n";
        }
        catch(const std::string& str) {
            (*stream) << "\n" << str.c_str() << "\n";
        }
        double dispersion = 0.;
        try {
            dispersion = mqCalc->GetDispersion();
            (*stream) << "\n" << "Dispersion:  " << dispersion << "\n";
        }
        catch(const std::string& str) {
            (*stream) << "\n" << str.c_str() << "\n";
        }
    }
    catch(const std::string& str) {
            (*stream) << "\n" << str.c_str() << "\n";
    }
}

std::string MathQuanCalcApplication::operator()(int argc, const char** argv) {
    std::vector<MathQuanCalc::Event> sample;

    bool returnCode = parseArguments(argc, argv, &sample);
    if (returnCode != true)
        return message_;

    MathQuanCalc calc;

    std::ostringstream stream;
    stream << "Result = ";

    MakeCalc(&calc, &sample, &stream);

    message_ = stream.str();

    return message_;
}
