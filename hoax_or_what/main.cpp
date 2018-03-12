#include <bits/stdc++.h>

using namespace std;

int main()
{
    int days;

    while (cin >> days, days) {
        multiset<int> promotions;   // can store multiple values of same element
        int bills;
        long long sum = 0;

        for (int i = 0; i < days; i++) {
            cin >> bills;

            while(bills--) {
                int num;
                cin >> num;
                promotions.insert(num);
            }
            auto it = promotions.end();
            it--;

            int top = *(it);
            int low = *(promotions.begin());

            sum += (top-low);

            promotions.erase(promotions.begin());
            promotions.erase(it);

        }

        cout << sum << endl;
    }

    return 0;
}
