#include <bits/stdc++.h>

using namespace std;

int main()
{
    // can use deque

    string s;
    list<char> text;
    list<char>::iterator it;

    // not EOF
    while (getline(cin, s)) {
        text.clear();
        it = text.begin();

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[')    // now move iterator forward
                it = text.begin();
            else if (s[i] == ']')  // move iterator back at end
                it = text.end();
            else
                text.insert(it, s[i]);  // insert char at iterator pos (back or front)
        }

        // print out modified word
        for (it = text.begin(); it != text.end(); it++) {
            cout << *it;    // reference the character
        }
        cout << endl;
    }

    /*

    */


    return 0;
}
