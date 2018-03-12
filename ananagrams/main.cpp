#include<bits/stdc++.h>
using namespace std;

bool stringCmp(pair<string,string> a, pair<string,string> b) {
    return a.second < b.second;
}

int main (void) {
    string input, word;
    vector< pair<string,string> > words;
    vector<string> result;

    // take care of input
    while (getline(cin, input)) {
        if (input == "#") break;

        istringstream iss(input);

        while (iss >> word) {
            string lowerCase = word;

            // convert everything to lower case
            for (int i = 0; i < (int)lowerCase.size(); i++)
                lowerCase[i] = tolower(lowerCase[i]);

            sort (lowerCase.begin(), lowerCase.end());  // sort the lowerCase word for unique comparison
            words.push_back(pair<string,string>(word, lowerCase));  // first is the original, second is for comparison
        }
    }

    sort (words.begin(), words.end(), stringCmp);  // sort the whole list to simplify searching for duplicates


    bool found = false;
    for (int i = 0; i < words.size() - 1; i++) {
        if (words[i].second != words[i+1].second) {
            if (found) {
                found = false;
            } else {
                result.push_back(words[i].first);
            }
        } else {
            found = true;
        }
    }

    /*
    // O(N), check for non-duplicates
    for (int i = 1; i < (int)words.size()-1; i++) {
        if (i == 1) {
            if (words[i-1].second != words[i].second)
                result.push_back(words[i-1].first);
        } else if (i == (int)words.size()-2) {
            if (words[i].second != words[i+1].second)
                result.push_back(words[i+1].first);
        } else {
            if (words[i-1].second != words[i].second && words[i].second != words[i+1].second)
                result.push_back(words[i].first);
        }
    }
    */
    if (!found) result.push_back(words[words.size()-1].first);

    sort (result.begin(), result.end());    // for output printing

    for (int i = 0; i < (int)result.size(); i++)
      cout << result[i] << endl;

    return 0;
}
