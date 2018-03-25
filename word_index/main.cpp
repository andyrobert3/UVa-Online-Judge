#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<string,int> dictionary;

bool isAscending(string s) {
    for (int i = 0; i < (int)s.size()-1; i++)
        if (s[i] >= s[i+1])
            return false;

    return true;
}

// starts mapping strings to integers
void set_up() {
    queue<string> q;    // can use queue

    // first push for character
    for (char c = 'a'; c <= 'z'; c++) {
        q.push(string(1,c));    // pushing character into queue
    }

    string s;
    int val = 1;
    while (!q.empty()) {
        s = q.front();
        q.pop();

        dictionary[s] = val++;  // mapping string to int

        if (s.size() < 5) {
            // add the string variables (a -> ab, ... , az)
            // OR (ab -> abc, abd, ... , abz)
            for (char c = s[s.size()-1] + 1; c <= 'z'; c++) {
                q.push(s+c);
            }
        }
    }
}

int main() {
    string word;

    set_up();

    while (cin >> word) {
        if (!isAscending(word)) cout << 0 << endl;
        else    cout << dictionary[word] << endl;
    }

    return 0;
}
