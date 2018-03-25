#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, string> slogans;
    int N, Q;
    string line1, line2;
    cin >> N;
    cin.get();  // remove endline character

    while (N--) {
        getline(cin, line1);
        getline(cin, line2);

        slogans[line1] = line2;
    }

    cin >> Q;
    cin.get(); // cin doesn't remove endline character, done manually

    while (Q--) {
        getline(cin, line1);
        cout << slogans[line1] << endl;
    }

    return 0;
}
