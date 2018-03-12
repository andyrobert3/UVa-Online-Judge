#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TC, length, cars;
    int carLength;
    string bank;

    cin >> TC;

    while (TC--) {
        queue<int> left, right;
        int currCapacity = 0;   // to model as ferry
        bool isLeft = true; // determine position on bank
        int counter = 0;

        cin >> length >> cars;
        length *= 100;    // in cm

        for (int i = 0; i < cars; i++) {
            cin >> carLength >> bank;
            if (bank == "left") left.push(carLength);
            else if (bank == "right") right.push(carLength);
        }

        // check till when both stops crossing
        while (!left.empty() || !right.empty()) {
            currCapacity = 0;   // crossed river

            if (isLeft) {
                    // check whether to continue taking cars on left side
                while (!left.empty() && currCapacity + left.front() <= length) {
                    currCapacity += left.front();
                    left.pop();
                }
            } else {
                    // check whether to continue taking cars on left side
                while (!right.empty() && currCapacity + right.front() <= length) {
                    currCapacity += right.front();
                    right.pop();
                }
            }
            counter++;
            isLeft = !isLeft;   // change sides of bank
        }
        cout << counter << endl;
    }

    return 0;
}
