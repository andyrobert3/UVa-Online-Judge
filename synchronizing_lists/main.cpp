#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TC;
    while (cin >> TC, TC) {
        vector<int> list1, sortedList, list2;
        map<int, int> mapping;
        int num;

        for (int i = 0; i < TC; i++) {
            cin >> num;
            list1.push_back(num);
        }

        sortedList = list1;
        sort(sortedList.begin(), sortedList.end());

        for (int i = 0; i < TC; i++) {
            cin >> num;
            list2.push_back(num);
        }

        sort(list2.begin(), list2.end());

        // now see list1 sorted and list2
        for (int i = 0; i < TC; i++) {
            mapping[sortedList[i]] = list2[i];
        }

        for (int i = 0; i < TC; i++) {
            cout << mapping[list1[i]] << endl;
        }

    }
    return 0;
}
