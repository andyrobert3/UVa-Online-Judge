#include <bits/stdc++.h>

using namespace std;

bool isParenthesesBalance(string expression) {
    stack<char> st;

    for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == '(' || expression[i] == '[') {
                st.push(expression[i]);
            } else if (expression[i] == ')') {
                if (st.empty() || st.top() != '(')  return false;   // not followed by )
                st.pop();
            } else if (expression[i] == ']') {
                if (st.empty() || st.top() != '[')  return false;   // not followed by ]
                st.pop();
            }
    }

    if (st.empty()) return true;
    else            return false;
}

int main()
{
    int n;
    string s;   // char s[140]; // faster
    cin >> n;
    // scanf("%d\n", &n); // faster
    cin.ignore();   // ignores new line character to prep for getline(cin, s)

    while (n--) {
        // gets(s); // faster
        getline(cin, s);    // gets the whole line (so also takes care of spaces)
        printf("%s\n", isParenthesesBalance(s) ? "Yes" : "No");
    }

    return 0;
}
