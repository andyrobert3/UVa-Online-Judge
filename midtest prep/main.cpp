#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num, cs;
    cin >> num >> cs;
    vector<int> soldiers;

    // insertion
    for (int i = 0; i < num; i++)
        soldiers.push_back(i);

    int start, endTroops;

    while (cs--) {
        cin >> start >> endTroops;

        vector<int>::iterator it1, it2;

        // search for the soldiers
        it1 = lower_bound(soldiers.begin(), soldiers.end(), start);
        it2 = lower_bound(soldiers.begin(), soldiers.end(), endTroops);

        // at the beginning
        if (it1 - soldiers.begin() == 0)
            cout << -1 << " ";
        else
            cout << *(it1-1) << " ";

        // at the end
        if (soldiers.end() - it2 == 1)
            cout << -1 << endl;
        else
            cout << *(it2+1) << endl;

        // remove soldiers
        soldiers.erase(it1, it2+1);
    }

    return 0;
}
