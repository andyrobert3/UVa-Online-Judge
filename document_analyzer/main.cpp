#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <sstream>

using namespace std;

int main() {
    int TC, _case = 1;
    cin >> TC;

    while (TC--) {
        string line;

        map<int, string> wordSequence; // stores the order of words
        unordered_set<string> checkWords;   // check if words are there
        int order = 0;

        while (getline(cin, line), line != "END") {
            // remove non-alpha characters and replacing them with spaces (for istringstream)
            for (char &c : line)
                if (!isalpha(c))
                    c = ' ';

            // separate them by spaces
            istringstream iss(line);
            string s;
            while (iss >> s) {
                wordSequence[order++] = s;
                checkWords.insert(s);
            }
        }


        unordered_map<string, int> occurences;    // counts frequency of word
        int currP = 0, currQ = (int)wordSequence.size();
        for (int p = 0, q = 0; p < (int)wordSequence.size() && q < (int)wordSequence.size(); q++) {
            occurences[wordSequence[q]]++;  // count occurences
            checkWords.erase(wordSequence[q]);  // once empty, means we've passed through the solution (p and q)
            // checkWords.erase() is flag for found

            // if empty (contains all words p to q), we find other smaller cases that increment p
            for (;checkWords.empty() && p < (int)wordSequence.size(); p++) {
                // get smallest difference (<) would ensure that smallest p gets selected
                if (q - p < currQ - currP) {
                    currQ = q;
                    currP = p;
                }

                occurences[wordSequence[p]]--;  // take note of frequency of elements within a range, once reaches 0 then recalculate q

                if (occurences[wordSequence[p]] == 0)   checkWords.insert(wordSequence[p]); // find smaller subsets that still span all elements
                // inserting at checkWords breaks the loop, thus incrementing q again
            }
        }

        cout << "Document " << _case++ << ": " << currP+1 << " " << currQ+1 << endl;

    }

    return 0;
}
