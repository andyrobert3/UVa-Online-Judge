#include <bits/stdc++.h>

using namespace std;

int main()
{

    int num;

    unordered_map<int, int> pairs;
    vector<int> orderedInputs;

    while (cin >> num) {
        // not found
        if (pairs.find(num) == pairs.end()) {
            orderedInputs.push_back(num);   // unique
            pairs[num] = 1;
        } else {
            pairs[num]++;
        }
    }

    for (auto &number : orderedInputs) {
        cout << number << " " << pairs[number] << endl;
    }

    return 0;
}
