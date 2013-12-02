/* Copyright 2013 Ksenya Kochanova */
#ifndef CODE_KSENYA_KOCHANOVA_LIBRARY_TEMPCONV_APPLICATION_H_
#define CODE_KSENYA_KOCHANOVA_LIBRARY_TEMPCONV_APPLICATION_H_

#include <string>

#pragma pack(push, 1)
 typedef struct {

   double value;
   TemperatureUnit unit;
   } Expression;

#pragma pack(pop)

class TempConv {

  public:

    TempConv();
    std::string operator()(int argc, const char** argv);

  private:

    std::string message_;
    void help(const char* appname);
    bool parseArguments(int argc, const char** argv, Expression* expr);
};

 #endif  //CODE_KSENYA_KOCHANOVA_LIBRARY_TEMPCONV_APPLICATION_H_
