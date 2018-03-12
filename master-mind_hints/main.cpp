#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TC;
    string country, woman;
    map<string, int> countries; // sorted lexicographically
    map<string, int>::iterator it;

    cin >> TC;
    while (TC--) {
        cin >> country;
        getline(cin, woman);    // remove the woman

        countries[country]++;   // if can find, increment else create new
    }

    // printing out
    for (it = countries.begin(); it != countries.end(); it++) {
        cout << (it->first) << " " << (it->second) << endl;
    }
    // it->first gets the key
    // it->second gets the value (because iterators dereference a pair

    return 0;
}
