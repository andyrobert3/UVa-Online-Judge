#include <queue>
#include <stack>
#include <iostream>

using namespace std;

int main()
{
    long num, val;
    int action;

    while (cin >> num, num != 0) {
        stack<long> st;
        queue<long> q;
        priority_queue<long> pq;
        bool is_stack = true, is_queue = true, is_pq = true;

        for (int i = 0; i < num; i++) {
            //int outSt, outQue, outPQ;
            cin >> action >> val;

            switch (action) {
                case 1:
                    if (is_stack)   st.push(val);
                    if (is_queue)   q.push(val);
                    if (is_pq)      pq.push(val);

                    break;

                case 2:
                    // stack
                    if (is_stack) {
                        if (st.empty() || st.top() != val)    is_stack = false; // check for runtime error with empty()
                        else  st.pop();
                    }

                    // queue
                    if (is_queue) {
                        if (q.empty() || q.front() != val)   is_queue = false; // check for runtime error with empty()
                        else    q.pop();
                    }

                    // priority queue
                     if (is_pq) {
                        if (pq.empty() || pq.top() != val)    is_pq = false;    // check for runtime error with empty()
                        else    pq.pop();
                    }


                    break;
            }
        }
        if (!is_stack)
            cout << "impossible" << endl;
        else
            cout << "stack" << endl;

        /*
        if (!is_stack && !is_queue)
            cout << "impossible" << endl;
        else if (is_stack && !is_queue)
            cout << "stack" << endl;
        else if (!is_stack && is_queue)
            cout << "queue" << endl;
        else
            cout << "not sure" << endl;

        if (!is_stack && !is_queue && !is_pq)
            cout << "impossible" << endl;
        else if (is_stack && !is_queue && !is_pq)
            cout << "stack" << endl;
        else if (!is_stack && is_queue && !is_pq)
            cout << "queue" << endl;
        else if (!is_stack && !is_queue && is_pq)
            cout << "priority queue" << endl;
        else
            cout << "not sure" << endl;
            */
    }

    return 0;
}
