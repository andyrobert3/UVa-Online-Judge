#include <bits/stdc++.h>

using namespace std;

bool cmp(tuple<string, int, int, int> p1,
         tuple<string, int, int, int> p2) {

    // same year
    if (get<3>(p1) == get<3>(p2)) {
        // same month
        if (get<2>(p1) == get<2>(p2)) {
            return get<1>(p1) < get<1>(p2);
        } else {
            return get<2>(p1) < get<2>(p2);
        }
    } else {
        return get<3>(p1) < get<3>(p2);
    }

}

int main()
{
    int TC, date, month, year;
    string name;
    cin >> TC;

    vector< tuple<string, int, int, int> > classStudents;

    while (TC--) {
        cin >> name >> date >> month >> year;
        classStudents.push_back(make_tuple(name, date, month, year));
    }

    sort(classStudents.begin(), classStudents.end(), cmp);

    cout << get<0>(classStudents[classStudents.size()-1]) << endl; // youngest
    cout << get<0>(classStudents.at(0)) << endl;   // oldest

    return 0;
}
