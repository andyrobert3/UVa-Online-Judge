#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int main()
{
    int TC;
    cin >> TC;
    cin.get();  // remove '\n'
    while (TC--) {
        bool isKey = true;
        string line, s, key;
        getline(cin, line);
        // make sure in order
        map<string, string> dictionaryOld;
        map<string, string> dictionaryNew;

        // change to spaces for isstringstream
        for (auto &c : line)
            if (!isalnum(c))    c = ' ';

        istringstream iss(line);

        while (iss >> s) {
            if (isKey) key = s;
            else       dictionaryOld[key] = s;

            isKey = !isKey;
        }

        // input for new dictionary
        isKey = true;
        getline(cin, line);

        // change to spaces for isstringstream
        for (auto &c : line)
            if (!isalnum(c))    c = ' ';

        istringstream iss1(line);

        while (iss1 >> s) {
            if (isKey) key = s;
            else       dictionaryNew[key] = s;

            isKey = !isKey;
        }

        /* OUTPUT:
        / if key dict1 found, but not in dict2, added
        / if cannot find key in dict1 inside dict2, removed
        / if found but diff value, changed */

        bool newKeys = false;
        string outputNew = "";

        for (auto &entry : dictionaryNew) {
            // not found
            if (!dictionaryOld.count(entry.first)) {
                if (!newKeys)   {
                    outputNew += "+";
                    newKeys = true;
                } else {
                    outputNew += ",";
                }
                outputNew += entry.first;
            }
        }

        // removed || modified
        string outputRemoved = "", outputModified = "";
        bool removedKeys = false;
        bool modifiedKeys = false;

        for (auto &entry : dictionaryOld) {
            // not found
            if (!dictionaryNew.count(entry.first)) {
                if (!removedKeys) {
                    outputRemoved += "-";
                    removedKeys = true;
                } else {
                    outputRemoved += ",";
                }
                 outputRemoved += entry.first;
            } else if (dictionaryNew.count(entry.first) && entry.second != (*dictionaryNew.find(entry.first)).second){
                if (!modifiedKeys) {
                    outputModified += "*";
                    modifiedKeys = true;
                } else {
                    outputModified += ",";
                }
                outputModified += entry.first;
            }
        }

        // new, removed, modified
        if (!modifiedKeys && !removedKeys && !newKeys)
            cout << "No changes" << endl;
        else  {
            if (newKeys)
                cout << outputNew << endl;
            if (removedKeys)
                cout << outputRemoved << endl;
            if (modifiedKeys)
                cout << outputModified << endl;
        }

        cout << endl;
    }

    return 0;
}
