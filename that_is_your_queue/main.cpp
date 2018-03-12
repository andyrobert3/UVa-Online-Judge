#include <bits/stdc++.h>

using namespace std;

int main(void) {
    long population;
    int commands, testCase = 0;

    while (cin >> population >> commands) {
        if (population == 0 && commands == 0)   break;

        // insert population
        deque<int> q;
        for (int i = 1; i <= min((int)population, 2000); i++) { // idk why, but 2000 is works
            q.push_back(i);
        }

        cout << "Case " << ++testCase << ":" << endl;

        // execute commands
        while (commands--) {
            char command;
            cin >> command;

            // move from front to back
            if (command == 'N') {
                q.push_back(q.front());
                cout << q.front() << endl;  // citizen to be processed next
                q.pop_front();
            } else {
                // emergency
                int citizen;
                cin >> citizen;
                deque<int>::iterator it;

                // search for citizen
                for (it = q.begin(); it != q.end(); it++) {
                    if (*it == citizen) {
                        q.erase(it);
                        break;
                    }
                }

                q.push_front(citizen);  // to front of queue
            }
        }
    }


    return 0;
}
