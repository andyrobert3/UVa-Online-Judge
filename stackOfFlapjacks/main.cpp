#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> V) {
    for (int i = 0; i < (int)V.size(); i++) {
        if (i > 0) cout << " ";
        cout << V.at(i);
    }
    cout << endl;
}

bool isSorted(vector<int> V) {
    for (int i = 0; i < (int)V.size(); i++)
        if (V[i-1] > V[i])  return false;
    return true;
}

int main(void)
{
    string s;
    int num;

    // read line till EOF
    while(getline(cin, s)) {
        istringstream iss(s);
        vector<int> pancakes;
        vector<int> outputText;

        // take every number on the line
        while (iss >> num)
            pancakes.push_back(num);

        int size = pancakes.size();

        //printVector(pancakes);

        int temp = 0;   // to do house work for deletion and printing

        while (temp != size && !isSorted(pancakes)) {
            int max = pancakes[0];
            int maxPos = 0;

            // find max and pos
            for (int i = 0; i < size-temp; i++) {
                if (pancakes[i] > max) {
                    max = pancakes[i];
                    maxPos = i;
                }
            }

            // maxPos already at desired position
            if (maxPos == size - 1 - temp) {
                temp++;
                continue;
            }

            // when max value is not on top, find max value then put it on top
            if (maxPos != 0) {
                outputText.push_back(size- maxPos);
                reverse(pancakes.begin(), pancakes.begin() + maxPos + 1);
            }

            // flip stack because max is on top already
            outputText.push_back(temp + 1);
            reverse(pancakes.begin(), pancakes.begin() + size - temp);
            temp++;
        }

        cout << s << endl;  // error submitting because of this fucker

        outputText.push_back(0);
        printVector(outputText);
    }

    return 0;
}
