#include <bits/stdc++.h>

using namespace std;

int totalASCII(string s) {
    int sum = 0;
    for (int i = 0; i < (int)s.size(); i++)
        sum += (int)s[i];
    return sum;
}

bool cmpFunc(string s1, string s2) {
    int sum1 = totalASCII(s1), sum2 = totalASCII(s2);
    return (sum1 < sum2);
}

void printVector(vector<string> v) {
    for (int i = 0; i < (int) v.size(); i++)
        cout << v.at(i) << endl;
}

int main()
{
    int numFiles, cols, rows;
    string f;
    while (cin >> numFiles) {
        int longestLength = 0;

        // input
        vector<string> files;
        for (int i = 0; i < numFiles; i++) {
            cin >> f;
            files.push_back(f);

            if (f.length() > longestLength)
                longestLength = f.length();
        }

        sort (files.begin(), files.end());

        cols = 60/longestLength;
        // find additional columns, remove them to fit
        while (cols*longestLength + 2*(cols-1) > 60) cols--;

        // now count rows
        rows = 0;
        while (cols*rows < numFiles)   rows++;

        for (int i = 0; i  < 60; i++)
            cout << "-";
        cout << endl;

        for (int i = 0; i < rows; i++) {
                // (i + j*rows < numFiles) to guard against extra spaces
            for (int j = 0; j < cols && i + j*rows < numFiles; j++) {
                cout << files[i + j*rows];

                // deal with extra space
                for (int k = 0; k < longestLength - files[i + j*rows].length(); k++) {
                    cout << " ";
                }

                // extra 2 spaces before last column
                if (j < cols - 1)
                    cout << "  ";
            }
            cout << endl;
        }

        //printVector(files);
    }
    return 0;
}
