#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q, num, query, counter = 0;

    while (cin >> n >> q) {
        if (n == 0 && q == 0) break;
        counter++;
        vector<int> arr;
        vector<int>::iterator low, up;  // for binary search

        while (n--) {
            cin >> num;
            arr.push_back(num);
        }
        sort(arr.begin(), arr.end());

        cout << "CASE# " << counter << ":" << endl;
        while (q--) {
            cin >> query;
            low = lower_bound(arr.begin(), arr.end(), query);   // binary search first occurence
            up = upper_bound(arr.begin(), arr.end(), query);    // binary search last occurence

            if (low == up)   // if point same, then not found
                cout << query << " not found" << endl;
            else
                cout << query << " found at " << low-arr.begin()+1 << endl;
        }
    }

    return 0;
}
