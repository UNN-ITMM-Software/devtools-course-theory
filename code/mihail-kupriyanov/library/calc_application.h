// Copyright 2013 Michail Kupriyanov

#ifndef CODE_MIHAIL_KUPRIYANOV_LIBRARY_CALC_APPLICATION_H_
#define CODE_MIHAIL_KUPRIYANOV_LIBRARY_CALC_APPLICATION_H_

#include <string>
#include <vector>

#include "./mathquancalc.h"

class MathQuanCalcApplication {
 public:
    MathQuanCalcApplication();

    std::string operator()(int argc, const char** argv);

 private:
    std::string message_;

    void help(const char* appname);
    bool parseArguments(int argc, const char** argv,
        std::vector<MathQuanCalc::Event>* sample);
};


#endif  // CODE_MIHAIL_KUPRIYANOV_LIBRARY_CALC_APPLICATION_H_
