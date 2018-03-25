#include <iostream>
#include <unordered_map>
#include <stdio.h>

using namespace std;

int main()
{
    int TC, N, M;
    cin >> TC;
    while (TC--) {
        int num;
        cin >> N >> M;
        unordered_map<int, int> list1;

        while (N--) {
            cin >> num;
            list1[num]++;
        }

        while (M--) {
            cin >> num;
            list1[num]--;
        }
        // list[num] will contain the diff for each element

        int count = 0;
        for (auto &it: list1) {
            count += abs(it.second);    // take abs so can find min elements to remove
        }

        cout << count << endl;
    }

    return 0;
}
