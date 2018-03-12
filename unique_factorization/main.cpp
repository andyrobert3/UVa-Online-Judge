#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n;
    while (cin >> n, n) {
        stack<int> factors;
        int waysFactorize, factor = 2;

        while (n/factor > 0) {
            if (n%factor != 0)
                factor++;
            else {
                factors.push(factor);
                n /= factor;
            }
        }

        cout << factors.size() << endl;

        while (!factors.empty()) {
            cout << factors.top() << " ";
            factors.pop();
        }
    }
    return 0;
}
