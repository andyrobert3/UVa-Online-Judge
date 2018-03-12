#include <bits/stdc++.h>

using namespace std;

int memberTeamOf[1000001];  // to mark an element is part of which team
queue<int> queueTeams[1001];    // separate teams queuing (array of queues)

int main()
{
    int numTeams, numElements, element, team;
    int num = 1;

    while (cin >> numTeams, numTeams) {
        // input of elements
        for (team = 0; team < numTeams; team++) {
            while (!queueTeams[team].empty())   // housework to clean from previous example
                queueTeams[team].pop();

            cin >> numElements;

            for (int i = 0; i < numElements; i++) {
                cin >> element;
                memberTeamOf[element] = team;   // set mark element is a part of which team
            }
        }

        // input of commands
        string command;
        queue<int> combinedQueue;   // refresh combinedQueue everytime(don't place out of while loop)

        cout << "Scenario #" << num++ << endl;

        while (cin >> command, command != "STOP") {
            if (command == "ENQUEUE") {
                cin >> element;
                int team = memberTeamOf[element];   // find team that the element is part of

                // if no one from team has queued, then add their team queue (queue from the back)
                if (queueTeams[team].empty())
                    combinedQueue.push(team);   // create a new team queue

                queueTeams[team].push(element); // add the element to the team queue
            } else {
                if (combinedQueue.empty())  continue;

                int team = combinedQueue.front();   // find front team

                if (queueTeams[team].empty())   continue;

                cout << queueTeams[team].front() << endl;   // print the front of the front queue
                queueTeams[team].pop(); // remove front person

                if (queueTeams[team].empty())   // team no longer in queue
                    combinedQueue.pop();
            }
        }
        cout << endl;
    }
    return 0;
}
