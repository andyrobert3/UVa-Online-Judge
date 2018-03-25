#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int numWords, numJobs;
    cin >> numWords >> numJobs;
    unordered_map<string, int> wordsToJob;

    string job;
    int dollarVal;

    while (numWords--) {
        cin >> job >> dollarVal;
        wordsToJob[job] = dollarVal;
    }

    while (numJobs--) {
        string word;
        int total = 0;
        while (cin >> word, word != ".") {
            if (wordsToJob.count(word))
                total += wordsToJob[word];
        }
        cout << total << endl;
    }


    return 0;
}
