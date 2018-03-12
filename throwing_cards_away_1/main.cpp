#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num;
    while (cin >> num, num) {
        queue<int> cards;
        vector<int> discardedCards;

        for (int i = 0; i < num; i++)
            cards.push(i+1);

        while (cards.size() >= 2 && num--) {
            discardedCards.push_back(cards.front());
            cards.pop();

            cards.push(cards.front());
            cards.pop();
        }

        cout << "Discarded cards:";
        for (int i = 0; i < (int)discardedCards.size(); i++) {
            if (i < (int)discardedCards.size() - 1)   {
                cout << " " << discardedCards.at(i) << ",";
            } else {
                cout << " " << discardedCards.at(i);
            }
        }

        cout << "\nRemaining card: ";
        cout << cards.front() << endl;
        cards.pop();
    }

    return 0;
}
