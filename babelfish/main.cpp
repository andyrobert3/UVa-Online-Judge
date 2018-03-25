#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

int main() {
    string line, english, foreign;
    unordered_map<string, string> translator;

    // !line.empty() checks for blank line
    while (getline(cin, line), !line.empty()) {
        istringstream iss(line);
        iss >> english >> foreign;

        translator[foreign] = english;
    }

    while (cin >> foreign) {
        if (translator.find(foreign) == translator.end())
            cout << "eh" << endl;
        else
            cout << translator[foreign] << endl;
    }

    return 0;
}

