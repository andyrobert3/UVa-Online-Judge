#include <iostream>
#include <map>
#include <stack>

using namespace std;

int main()
{
    int TC, currCase = 1;
    cin >> TC;
    while (TC--) {
        stack<char> st;
        map<char, int> _map;
        string movement;
        cin >> movement;

        for (int i = 0; i < (int)movement.size(); i++) {

            if (st.empty() || st.top() != movement[i]) {
                st.push(movement[i]);
                _map[movement[i]]++;    // enter confirm got path
            } else {
                st.pop();

                // number of times traversed
                // non-empty stack, means that st.top() is being traversed
                if (!st.empty()) _map[st.top()]++;  // magic_line
            }
        }
        _map[movement[0]]--;    // additional movement that was double counted in beginning

        cout << "Case " << currCase++ << "\n";
        for (auto &it: _map) {
            cout << it.first << " = " << it.second << "\n";
        }
    }


    return 0;
}
