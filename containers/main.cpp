#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string input;
    int case_num = 0;

    while(cin >> input, input != "end") {

        vector< stack<char> > containers;   // create new every line
        case_num++;
        // traverse through input
        for (int i = 0; i < (int)input.size(); i++) {
            char c = input[i];
            bool found = false;

            // check containers
            for (int j = 0; j < (int)containers.size(); j++) {
                if (c <= containers[j].top()) {
                    containers[j].push(c);
                    found = true;
                    break;
                }
            }

            if (!found) {
                stack<char> newStack;
                newStack.push(c);
                containers.push_back(newStack);
            }
        }

        /*
        for (int k = 0; k < (int)containers.size(); k++) {
                cout << "Stack " << k+1 << ": ";
                stack<char> temp;
                while (!containers[k].empty()) {
                    cout << containers[k].top() << " ";
                    temp.push(containers[k].top());
                    containers[k].pop();
                }

                // put back
                while (!temp.empty()) {
                    containers[k].push(temp.top());
                    temp.pop();
                }
                cout << endl;
        }   // debugging
        */

        cout << "Case " << case_num << ": " << (int)containers.size() << endl;
    }

    return 0;
}
