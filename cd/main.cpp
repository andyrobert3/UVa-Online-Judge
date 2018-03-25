#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    long N, M;   // N-> Jack, M-> Jill
    long cd, count;

    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;
        unordered_set<long> jack;
        count = 0;

        while (N--) {
            cin >> cd;
            jack.insert(cd);
        }

        while (M--) {
            cin >> cd;
            // found (duplicate)
            if (jack.count(cd) > 0) count++;
        }

        cout << count << endl;
    }


    return 0;
}
