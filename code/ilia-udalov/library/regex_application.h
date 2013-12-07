// Copyright 2013 Ilia Udalov

#ifndef CODE_ILIA_UDALOV_LIBRARY_REGEX_APPLICATION_H_
#define CODE_ILIA_UDALOV_LIBRARY_REGEX_APPLICATION_H_

#include <string>

#include "./regex.h"

class RegexApplication {
 public:
    RegexApplication();

    std::string operator()(int argc, const char** argv);

 private:
    std::string message_;

    void help(const char* appname);
    bool parseArguments(int argc, const char** argv);
};

#endif  // CODE_ILIA_UDALOV_LIBRARY_REGEX_APPLICATION_H_
