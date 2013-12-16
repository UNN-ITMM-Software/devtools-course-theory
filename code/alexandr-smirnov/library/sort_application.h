/* Copyright 2013 Alexandr Smirnov */

#ifndef CODE_ALEXANDR_SMIRNOV_LIBRARY_SORT_APPLICATION_H_
#define CODE_ALEXANDR_SMIRNOV_LIBRARY_SORT_APPLICATION_H_

#include <string>

class SorterApplication {
 public:
    SorterApplication();

    std::string operator()(int argc, const char** argv);

 private:
    std::string message_;

    void help(const char* appname);
    bool parseArguments(int argc, const char** argv);
};

#endif  // CODE_ALEXANDR_SMIRNOV_LIBRARY_SORT_APPLICATION_H_
