// Copyright 2013 K.Nikolaev

#ifndef CODE_KIRILL_NIKOLAEV_LIBRARY_NUMCONVERTER_APPLICATION_H_
#define CODE_KIRILL_NIKOLAEV_LIBRARY_NUMCONVERTER_APPLICATION_H_

#include <string>
#include "./NumConverter.h"

#pragma pack(push, 1)
typedef struct {
    NumSystem numsys = bin;
    std::string number = "";
} Argument;
#pragma pack(pop)

class NumConverterApplication {
 public:
    NumConverterApplication();

    std::string operator()(int argc, const char** argv);

 private:
    std::string mess_;

    void Help(const char* appname);
    bool ParseArgs(int argc, const char** argv, Argument* arg);
};

#endif  // CODE_KIRILL_NIKOLAEV_LIBRARY_NUMCONVERTER_APPLICATION_H_
