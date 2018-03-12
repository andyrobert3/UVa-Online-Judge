#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long int n, m, val, pos, key;
    cin >> n >> m;

    vector<unsigned long int> arr;
    vector<unsigned long int>::iterator it;

    while (n--) {
        cin >> val;
        arr.push_back(val);
    }

    //sort(arr.begin(), arr.end());

    while (m--) {
        cin >> pos >> key;
        it = find(arr.begin(), arr.end(), key);
        advance(it, pos-1);

        if (*it == key)
            cout << (it - arr.begin()) << endl;
        else
            cout << '0' << endl;
    }

    return 0;
}
