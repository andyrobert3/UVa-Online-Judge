#include <bits/stdc++.h>

using namespace std;

int main()
{
    int elements;
    queue <long> permutation;
    vector <long> output;
    long num;

    cin >> elements;

    // input
    while (elements--) {
        cin >> num;
        permutation.push(num);
    }

    long max_val = 0;

    while (!permutation.empty()) {
        if (permutation.front() > max_val) {
            output.push_back(permutation.front());
            max_val = permutation.front();
            permutation.pop();
        } else {
            permutation.pop();
        }
    }

    cout << output.size() << endl;
    for (int i = 0; i < output.size(); i++) {
        cout << output.at(i) << " ";
    }
    cout << endl;



    return 0;
}
