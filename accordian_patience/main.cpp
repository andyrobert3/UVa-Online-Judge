#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<char, int> mapping;
    mapping['2'] = 2;
    mapping['3'] = 3;
    mapping['4'] = 4;
    mapping['5'] = 5;
    mapping['6'] = 6;
    mapping['7'] = 7;
    mapping['8'] = 8;
    mapping['9'] = 9;
    mapping['T'] = 10;
    mapping['J'] = 11;
    mapping['Q'] = 12;
    mapping['K'] = 13;
    mapping['A'] = 14;
    mapping['D'] = 20;
    mapping['C'] = 30;
    mapping['H'] = 40;
    mapping['S'] = 50;

    string input;

    while (cin >> input, input != "#") {
        int currPos = 0;
        stack< pair<int,int> > pileCards[52];
        vector< pair<int, int> > cards;

        cards.push_back(pair<int,int>(mapping[input[0]], mapping[input[1]]));  // first occurence
        for (int i = 1; i < 52; i++) {
            cin >> input;
            cards.push_back(pair<int, int>(mapping[input[0]], mapping[input[1]]));
        }

        // put cards from deck to stack of cards
        while (!cards.empty()) {
            pileCards[currPos++].push(cards[0]);    // get from top of deck
            cards.erase(cards.begin());

            bool madeMove;
            do {
                madeMove = false;

                // match with neigbours
                for (int i = 0; i < currPos; i++) {
                    // check third card left
                    if (i - 3 >= 0) {
                        if (pileCards[i].top().first == pileCards[i-3].top().first
                            || pileCards[i].top().second == pileCards[i-3].top().second) {

                            pileCards[i-3].push(pileCards[i].top());
                            pileCards[i].pop();
                            madeMove = true;
                            break;
                        }
                    }

                    // check first card left
                    if (i - 1 >= 0) {
                        if (pileCards[i].top().first == pileCards[i-1].top().first
                            || pileCards[i].top().second == pileCards[i-1].top().second) {

                            pileCards[i-1].push(pileCards[i].top());
                            pileCards[i].pop();
                            madeMove = true;
                            break;
                        }
                    }
                }

                // check for gaps and remove them
                for (int i = 0; i < currPos; i++) {
                    if (pileCards[i].empty()) {

                        for (int j = i; j < currPos - 1; j++) {
                            swap(pileCards[j], pileCards[j+1]);
                        }
                        currPos--;  // reduced size
                        break;
                    }
                }
            } while (madeMove);
        }

        cout << currPos << " ";
        if (currPos == 1)
            cout << "pile remaining:";
        else
            cout << "piles remaining:";

        for (int i = 0; i < currPos; i++) {
            cout << " " << pileCards[i].size();
        }

        cout << endl;
    }

    return 0;
}
