#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TC, currLength, temp, swaps;
    bool swapped = false;
    cin >> TC;

    while (TC--) {
        cin >> currLength;
        int trains[currLength];
        swaps = 0;

        for (int i = 0; i < currLength; i++) {
            cin >> temp;
            trains[i] = temp;
        }

        // optimised bubble sort
        do {
            swapped = false;
            for (int i = 1; i < currLength; i++) {
                if (trains[i-1] > trains[i]) {
                    int temp = trains[i-1];
                    trains[i-1] = trains[i];
                    trains[i] = temp;
                    swapped = true;

                    swaps++;
                }
            }
            currLength--;
        } while (swapped);

        cout << "Optimal train swapping takes " << swaps << " swaps.\n";
    }

    return 0;
}
