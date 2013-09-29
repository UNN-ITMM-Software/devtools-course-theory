#ifndef REGEX_H
#define REGEX_H

#include <string>

class Regex {

public:
    Regex(const std::string& _regex = "", const std::string& _text = "")
        : regex(_regex), text(_text) {
    }
    int setRegex(const std::string& _regex);
    int setText(const std::string& _text);

    std::string getRegex();
    std::string getText();

    int match();

private:
    std::string regex;
    std::string text;

private:
    int matchHere(size_t r, size_t t);
    int matchStar(int c, size_t r, size_t t);
};

#endif
