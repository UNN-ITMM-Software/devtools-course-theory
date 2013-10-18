#include <iostream>
#include <fstream>

#include "../include/regex.hpp"

using namespace std;

int main (int argc, char* argv[]) {

    ifstream f;
    string regex, substr, text;

    if (argc == 1) {
        cout << "Input error" << endl;
        return 0;
    }
    f.open(argv[1], ios::in);
    if (f == 0) {
        cout << "Wrong path!" << endl;
        return 0;
    }

    while (!f.eof()) {
        getline(f, regex);
        if (f.eof()) {
            cout << "error: missing text!" << endl;
            return 0;
        }
        getline(f, substr);
        getline(f, text);

        cout << "Text: " << text << endl;
        cout << "Regex: " << regex << "; is match: " << match(regex, text) << endl;
        cout << "Find:  " << substr << "; Substring position: " << find(substr, text) << endl;
        cout << endl;
    }

    f.close();
    return 0;
}
