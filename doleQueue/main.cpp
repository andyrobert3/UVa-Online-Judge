#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> arr) {
    for (auto v: arr)
        cout << v << " ";
    cout << endl;
}


int main()
{
    int n, k, m;
    bool applicants[20];

    while (cin >> n >> k >> m) {
        if (n == 0 && k == 0 && m == 0) break;

        for (int i = 0; i < 20; i++)    applicants[i] = false;
        for (int i = 0; i < n; i++)     applicants[i] = true;

        int anticlockwisePtr = n-1, clockwisePtr = 0;   // so extra one move in the beginning
        int j, counter = 0;
        int sentoff = 0;

        // until everyone has been sentoff
        while (sentoff < n) {
            counter = 0;

            // decreases pointer
            j = clockwisePtr;
            while (counter < m) {   // move m valid times
                if (j == 0) j = n-1;
                else    j--;

                if (applicants[j])  counter++;
            }

            clockwisePtr = j;   // save again

            // increasing pointer
            counter = 0;
            j = anticlockwisePtr;
            while (counter < k) {   // move k valid times
                if (j == n-1) j = 0;
                else    j++;

                if (applicants[j])  counter++;
            }
            anticlockwisePtr = j;

            if (sentoff > 0)    cout << ",";    // besides first time
            if (anticlockwisePtr == clockwisePtr) {
                cout << setw(3) << anticlockwisePtr + 1;
                sentoff++;
            } else {
                cout << setw(3) << anticlockwisePtr + 1 << setw(3) << clockwisePtr + 1;
                sentoff += 2;
            }

            applicants[anticlockwisePtr] = false;   // remove
            applicants[clockwisePtr] = false;   // remove
        }
        cout << endl;
    }

    return 0;
}
