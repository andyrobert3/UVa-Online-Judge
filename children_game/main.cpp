#include <bits/stdc++.h>

using namespace std;

bool cmp(string s1, string s2) {
    // compares 50 and 900
    // 50900 or 90050 is greater?
    return (s1 + s2) > (s2 + s1);   // compare lexicographically
}

int main()
{
    size_t n;
    while (cin >> n, n) {
        vector<string> numbers(n);

        // size_t is generic type, if undefined
        for (size_t i = 0; i < n; i++) {
             cin >> numbers[i];
        }

        sort(numbers.begin(), numbers.end(), cmp);

        for (size_t i = 0; i < n; i++) {
            cout << numbers[i];
        }
        cout << endl;
    }
    return 0;
}
