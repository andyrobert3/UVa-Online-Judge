#include <bits/stdc++.h>

using namespace std;

// comparator function
class cmpFunc {
public:
    bool operator() (pair<int,int> &p1, pair<int,int> &p2) {
        if (p1.second == p2.second)
            return p1.first > p2.first;
        else
            return p1.second > p2.second;
    }
};


int main()
{
    string text;
    int q_num, period, k;

    priority_queue <pair<int, int>, vector<pair<int, int> >, cmpFunc> argus;
    map<int,int> queries;

    // input
    while (cin >> text, text != "#") {
        cin >> q_num >> period;
        queries[q_num] = period;    // to map for later
        argus.push(make_pair(q_num, period));
    }

    // calculations
    cin >> k;
    while (k--) {
        pair<int, int> temp = argus.top();  // next to be printed
        argus.pop();

        cout << temp.first << endl;

        // put back in of multiple of period
        temp.second += queries[temp.first];
        argus.push(temp);
    }

    return 0;
}
