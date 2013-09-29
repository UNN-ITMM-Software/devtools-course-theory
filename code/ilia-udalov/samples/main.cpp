#include <iostream>
#include <fstream>

#include "../include/regex.hpp"

using namespace std;

int main (int argc, char* argv[]) {

    ifstream f;
    string buf;
    Regex r;

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
        cout << "Result: " << r.match() << endl;
    }
    f.close();
    return 0;
}
