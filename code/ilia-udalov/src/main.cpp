#include <iostream>
#include <fstream>

#include "regex.h"

using namespace std;

int main (int argc, char* argv[]) {

    ifstream f;
    string buf;
    Regex r(".*", "Hello, regular expression!");

    if (argc == 1) {
        cout << "Input error" << endl;
        return 0;
    }
    f.open(argv[1], ios::in);
    while (!f.eof()) {
        getline(f, buf);
        cout << "Regex: " << buf << endl;
        r.setRegex(buf);
        if (f.eof())
        {
            cout << "error: missing text!" << endl;
            return 0;
        }
        getline(f, buf);
        cout << "Text: " << buf << endl;
        r.setText(buf);
        cout << "Result: " << r.isOk() << endl;
    }
    f.close();
    return 0;
}
