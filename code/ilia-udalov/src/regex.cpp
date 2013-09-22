#include "regex.h"

int Regex:: isOk() {
    size_t r = 0;
    size_t t = 0;
    if ((reg.size() > 0) && (reg[r] == '^')) {
        return Matchhere(r + 1, t);
    }
    do {
        if (Matchhere(r, t))
            return 1;
    } while (t++ != text.size());
    return 0;

int Regex::Matchhere(size_t r, size_t t) {
    if (r == reg.size())
        return 1;
    if (reg[r + 1] == '*')
        return Matchstar(reg[r], r + 2, t);
    if (reg[r] == '$' && reg.size() == r)
        return t == text.size();
    if (t != text.size() && (reg[r] == '.' || reg[r] == text[t]))
        return Matchhere(r + 1, t + 1);
    return 0;
}

int Regex::Matchstar(int c, size_t r, size_t t) {
    do {
        if (Matchhere(r, t))
            return 1;
    } while (t != text.size() && (text[t++] == c || c == '.'));
    return 0;
}
