#include <bits/stdc++.h>

using namespace std;

int M;

bool cmp(int num1, int num2) {
    if (num1 % M  == num2 % M) {
        if (num1 % 2 == 0 && num2 % 2 == 0) {
            return num1 < num2; // both even, choose smaller
        } else if (num1 % 2 != 0 && b % 2 != 0) {
            return num1 > num2; // both odd, choose greater
        } else if (num1 % 2 == 0 && num2 % 2 != 0) {
            return false;   // choose odd
        } else if (num1 % 2 != 0 && num2 % 2 == 0) {
            return true;    // choose even
        }
    }


    return num1%M < num2%M;
}

int main()
{
    int N, num;

    while(cin >> N >> M) {
        if (N == 0 && M == 0)   break;
        vector<int> numbers;

        for (int i = 0; i < N; i++) {
            cin >> num;
            numbers.push_back(num);
        }

        sort(numbers.begin(), numbers.end(), cmp);

        cout << N << " " << M << endl;

        vector<int>::iterator it;
        for (it = numbers.begin(); it != numbers.end(); it++)
            cout << *it << endl;
    }
    cout << 0 << " " << 0 << endl;


    return 0;
}
