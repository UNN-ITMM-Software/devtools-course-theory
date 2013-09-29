#include "../include/regex.hpp"

int Regex::match() {
    size_t r = 0;
    size_t t = 0;
    if ((regex.size() > 0) && (regex[r] == '^')) {
        return matchHere(r + 1, t);
    }
    do {
        if (matchHere(r, t))
            return 1;
    } while (t++ != text.size());
    return 0;
}

int Regex::matchHere(size_t r, size_t t) {
    if (r == regex.size())
        return 1;
    if (regex[r + 1] == '*')
        return matchStar(regex[r], r + 2, t);
    if (regex[r] == '$' && regex.size() == r)
        return t == text.size();
    if (t != text.size() && (regex[r] == '.' || regex[r] == text[t]))
        return matchHere(r + 1, t + 1);
    return 0;
}

int Regex::matchStar(int c, size_t r, size_t t) {
    do {
        if (matchHere(r, t))
            return 1;
    } while (t != text.size() && (text[t++] == c || c == '.'));
    return 0;
}

int Regex::setRegex(const std::string& _regex) {
    regex = _regex;
    return 0;
}

int Regex::setText(const std::string& _text) {
    text = _text;
    return 0;
}

std::string Regex::getRegex() {
    return regex;
}

std::string Regex::getText() {
    return text;
}
