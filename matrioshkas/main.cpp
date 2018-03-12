#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int val;

    while (getline(cin, s)) {
        stack<int> bracketCheck;    // check balanced or not
        stack<int> valCheck;    // check sizes of Matrioshkas

        istringstream iss(s);
        bool flag = true;

        while (iss >> val) {
            if (flag) {
                // if negative value
                if (val < 0) {
                    val = abs(val); // find positive
                    bracketCheck.push(val);

                    // values check
                    if (valCheck.empty()) {
                        valCheck.push(val);
                    } else {
                        int pastTop = valCheck.top();
                        valCheck.pop();

                        pastTop -= val; // stores value difference from two different brackets
                        if (pastTop <= 0) {
                            flag = false;
                            break;
                        }

                        // put them back in
                        valCheck.push(pastTop);
                        valCheck.push(val);
                    }
                } else {
                    // normal bracket checking
                    if (bracketCheck.empty() || bracketCheck.top() != val) {
                        flag = false;
                        break;
                    }

                    bracketCheck.pop();
                    valCheck.pop();
                }
            }
        }

        if (!bracketCheck.empty())  flag = false;   // unbalanced

        if (flag)   cout << ":-) Matrioshka!" << endl;
        else        cout << ":-( Try again." << endl;

    }
    return 0;
}
