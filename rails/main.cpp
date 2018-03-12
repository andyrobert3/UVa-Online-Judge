#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TC, numJobs, jobPos, temp, highestPriority, currPriority;
    int time;
    cin >> TC;

    while (TC--) {
        time = 0;
        priority_queue<int> pq;
        queue<int> q;

        cin >> numJobs >> jobPos;

        // insert the jobs
        for (int i = 0; i < numJobs; i++) {
            cin >> temp;
            q.push(temp);
            pq.push(temp);
        }

        bool printFinished = false;
        while (!printFinished) {
            // get highest priority to print
            highestPriority = pq.top();
            pq.pop();

            // shuffle through the queue until max priority
            while (true) {
                currPriority = q.front();
                q.pop();

                if (highestPriority > currPriority) {
                    q.push(currPriority);
                } else if (highestPriority == currPriority) {
                    time++; // now able to print

                    if (jobPos == 0)
                        printFinished = true;   // can exit;
                    else
                        jobPos--;

                    break;  // find next max priority
                }

                // account for job moved to end of queue
                jobPos--;

                if (jobPos < 0)
                    jobPos = (int)q.size() - 1;
            }
        }

        cout << time << endl;
    }

    return 0;
}
