#include <bits/stdc++.h>

using namespace std;

int main()
{
    queue<int> server;
    int tasks, minutes, num;
    cin >> tasks >> minutes;

    while (tasks--) {
        cin >> num;
        server.push(num);
    }
    int counter = 0;
    int curr = 0;
    while (!server.empty() && curr + server.front() <= minutes) {
        counter++;
        curr += server.front();
        server.pop();
    }
    cout << counter << endl;

    return 0;
}
