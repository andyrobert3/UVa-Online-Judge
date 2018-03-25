#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const pair<string,int> &p1, const pair<string,int> &p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second > p2.second;
}

int main() {
    string line;

    while (getline(cin, line), (line[0]-'0') != 0) {
        map<string, set<string>> projects;
        map<string, int> counter;
        vector< pair<string,int> > ans;

        string projectName;

        // taking input
        while (line[0] - '0' != 1) {
            // project name
            if (isupper(line[0])) {
                projects[line] = set<string>();
                projectName = line;
            } else {
                // usernames
                projects[projectName].insert(line); // prevent duplicates
            }
            getline(cin, line);
        }

        // iterate through sets to calcualte frequency of usernames
        for (auto it1 = projects.begin(); it1 != projects.end(); it1++) {
            // iterate through names in each set
            for (auto it2 = (it1->second).begin(); it2 != (it1->second).end(); it2++) {
                counter[*it2]++;
            }
        }

        // calculate the number of non-duplicate usernames
        for (auto it1= projects.begin(); it1 != projects.end(); it1++) {
            int numStudentsSigned = 0;
            for (auto it2 = (it1->second).begin(); it2 != (it1->second).end(); it2++) {
                if (counter[*it2] > 1)  //signed up more than once
                    continue;   // invalid

                numStudentsSigned++;
            }
            ans.push_back(make_pair(it1->first, numStudentsSigned));
        }

        sort(ans.begin(), ans.end(), cmp);

        for (auto &pr : ans) {
            cout << pr.first << " " << pr.second << endl;
        }
    }


    return 0;
}
