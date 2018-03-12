#include <bits/stdc++.h>

using namespace std;

string toLowerWord(string word) {
    string lowerWord = word;

    for (int i = 0; i < (int) word.size(); i++)
        lowerWord[i] = tolower(word[i]);

    return lowerWord;
}


void printArray(vector< pair<string, string> > input) {

    for (int i = 0; i < (int) input.size(); i++) {
        cout << input[i].first << endl;
    }
}

bool cmp(pair<string,string> sentence1,
         pair<string,string> sentence2 ) {

    if (sentence1.second < sentence2.second) {
        return true;
    } else if (sentence1.second == sentence2.second) {
        if (sentence1.second < sentence2.second) {
            return true;
        }
    }
}


int main()
{
    string wordsToIgnore;
    vector <string> ignoreWords;

    // input
    while (getline(cin, wordsToIgnore)) {
        if (wordsToIgnore == "::")  break;
        ignoreWords.push_back(wordsToIgnore);
    }

    vector< pair<string, string> > output;
    string titles;

    // calculations
    while (getline(cin, titles)) {
        if (titles == "!") break;   // debug

        istringstream iss(titles);
        string searchWord;

        while (iss >> searchWord) {
            // search for word
            vector<string>::iterator it;

            string lowerSearchWord = toLowerWord(searchWord);
            it = find (ignoreWords.begin(), ignoreWords.end(), lowerSearchWord);

            // if not found
            if (it == ignoreWords.end()) {
                string tempSentence = titles;

                // find position of word
                size_t found = titles.find(searchWord);

                // lower case before word
                for (int i = 0; i < (int)found; i++)
                    tempSentence[i] = tolower(titles[i]);

                // upper case for search word
                for (int i = found; i < (int)(found + searchWord.size()); i++)
                    tempSentence[i] = toupper(titles[i]);

                // lower case for rest
                for (int i = found + (int)searchWord.size(); i < (int)titles.size(); i++)
                    tempSentence[i] = tolower(titles[i]);

                output.push_back(pair<string, string> (tempSentence, searchWord));
            }
        }
    }

    sort(output.begin(), output.end(), cmp);
    printArray(output);

    return 0;
}
