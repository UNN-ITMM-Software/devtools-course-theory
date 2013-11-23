// Copyright 2013 Michail Kupriyanov

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

#include "../include/mathquancalc.h"
// #include "mathquancalc.h"

static void Help(char* appName) {
    printf("This is a math quantities calculator application.\n\n");
    printf("Please provide arguments in the following format:\n\n");
    printf("  $ %s <value_1> <probability_1> <value_2> <probability2_>"
        " ... \n\n", appName);
    printf("Where both arguments are double numbers.\n");
}

static void PrintSample(std::vector<MathQuanCalc::Event> sample) {
    printf("\n%s", "Values:    ");
    for (unsigned int i = 0; i < sample.size(); i++) {
        printf("%5.2f ", sample[i].value);
    }
    printf("\n%s", "Probabilitys: ");
    for (unsigned int i = 0; i < sample.size(); i++) {
        printf("%5.2f ", sample[i].probability);
    }
}

static void MakeCalc(MathQuanCalc* mqCalc,
    const std::vector<MathQuanCalc::Event>& sample) {
    try {
        mqCalc->PutSample(sample);
        double expVal = 0.;
        try {
            expVal = mqCalc->GetExpectedValue();
            printf("\n%s %5.2f", "Expected value:", expVal);
        }
        catch(const std::string& str) {
            printf("\n%s\n", str.c_str());
        }
        double dispersion = 0.;
        try {
            dispersion = mqCalc->GetDispersion();
            printf("\n%s %5.2f\n", "Dispersion:", dispersion);
        }
        catch(const std::string& str) {
            printf("\n%s\n", str.c_str());
        }
    }
    catch(const std::string& str) {
            printf("\n%s\n", str.c_str());
    }
}

static double ParseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (!end[0]) {
        printf("%s is valid\n", arg);
    } else {
        printf("%s is invalid\n", arg);
        throw std::string("ERROR: wrong number format");
    }

    return value;
}

int main(int argc, char** argv) {
    MathQuanCalc mqCalc;
    MathQuanCalc::Event event;
    std::vector<MathQuanCalc::Event> sample;

    if (argc == 1) {
        Help(argv[0]);
        exit(0);
    }
    if ((argc % 2) == 0) {
        printf("ERROR: wrong arguments format.\n\n");
        Help(argv[0]);
        exit(1);
    }

    for (int i = 1; i < argc; i += 2) {
        try {
            event.value = ParseDouble(argv[i]);
            event.probability = ParseDouble(argv[i + 1]);
        }
        catch(const std::string& str) {
            printf("\n%s\n", str.c_str());
            exit(0);
        }
        sample.push_back(event);
    }

    PrintSample(sample);
    MakeCalc(&mqCalc, sample);
    return 0;
}
