/* Copyright 2013 Aleksey Kostrov */

#ifndef CODE_ALEKSEY_KOSTROV_LIBRARY_DICHOTOMY_SEARCH_APPLICATION_H_
#define CODE_ALEKSEY_KOSTROV_LIBRARY_DICHOTOMY_SEARCH_APPLICATION_H_

#include <string.h>
#include <string>

#pragma pack(push, 1)
typedef struct {
    int size;
    int element;
} Expression;
#pragma pack(pop)

class DichotomySearchApplication {
 public:
    DichotomySearchApplication();

    std::string operator()(int argc, const char** argv);

 private:
    std::string message;

    void help(const char* appname);
    int parseInteger(const char *arg);
    bool parseArguments(int argc, const char** argv, Expression* expr);
};

#endif  // CODE_ALEKSEY_KOSTROV_LIBRARY_DICHOTOMY_SEARCH_APPLICATION_H_
