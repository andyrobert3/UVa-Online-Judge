#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int TC;
    while (cin >> TC, TC) {
        cin.get();  // remove endline
        map<vector<int>, int> courses;

        for (int j = 0; j < TC; j++) {
            string line;
            int s;
            vector<int> combination;

            for (int i = 0; i < 5; i++) {
                cin >> s;
                combination.push_back(s);
            }

            sort(combination.begin(), combination.end());   // get unique combo

            courses[combination]++;
        }

        int max = 0, count = 0;

        // find max
        for (auto &students : courses) {
            if (students.second > max)
                max = students.second;
        }

        // find number of students who join max courses
        for (auto &students : courses) {
            if (students.second == max)
                count += max;
        }

        cout << count << endl;
    }

    return 0;
}
