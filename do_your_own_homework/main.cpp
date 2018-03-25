#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int T, N, D, days, daysRequired;
    int TC = 1;
    string subject;

    cin >> T;
    while (T--) {
        // input
        cin >> N;
        unordered_map<string, int> sparrow;

        // input
        while (N--) {
            cin >> subject >> days;
            sparrow[subject] = days;
        }
        cin >> D;
        cin >> subject;


        cout << "Case " << TC++ << ": ";
        // processing
        if (sparrow.find(subject) == sparrow.end()) {
            cout << "Do your own homework!" << endl;
        } else {
            daysRequired = sparrow[subject];
            if (daysRequired <= D)
                cout << "Yesss" << endl;
            else if (daysRequired <= D + 5)
                cout << "Late" << endl;
            else
                cout << "Do your own homework!" << endl;
        }


    }

    return 0;
}
