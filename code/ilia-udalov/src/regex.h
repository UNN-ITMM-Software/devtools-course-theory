#include <string>

using namespace std;

#ifndef REGEX_H
#define REGEX_H

class Regex {

private:
    string reg;
    string text;

public:
    Regex(const char* _reg, const char* _text)
        : reg(_reg), text(_text) {
    }
    Regex(const string& _reg, const string& _text)
        : reg(_reg), text(_text) {
    }
    int setRegex(const char* _reg) {
        reg = _reg;
        return 0;
    }
    int setRegex(const string& _reg) {
        reg = _reg;
        return 0;
    }
    int setText(const char* _text) {
        text = _text;
        return 0;
    }
    int setText(const string& _text) {
        text = _text;
        return 0;
    }

    string getRegex() {
        return reg;
    }
    string getText() {
        return text;
    }

    int isOk();
private:
    int Matchhere(size_t r, size_t t);
    int Matchstar(int c, size_t r, size_t t);
};

#endif
