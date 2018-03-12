#include <bits/stdc++.h>

using namespace std;

struct coordinate{
    int x, y ,z;
};

bool cmp(coordinate c1, coordinate c2) {
    return c1.x < c2.x;
}

// casted to int
int getDistance(coordinate c1, coordinate c2) {
    return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2) + pow(c1.z - c2.z, 2));
}

void printVector(vector<coordinate> v) {
    for (auto val : v)
        cout << val.x << " " << val.y << " " << val.z << endl;
}

int main()
{
    int x, y, z;
    coordinate c;
    vector<coordinate> coordinates;
    int histogram[10] = {0};

    // input
    while (cin >> x >> y >> z) {
        if (x == 0 && y == 0 && z == 0) break;
        c.x = x;
        c.y = y;
        c.z = z;

        coordinates.push_back(c);
    }

    //sort(coordinates.begin(), coordinates.end(), cmp);
    //printVector(coordinates);

    // coordinates vector
    for (int i = 0; i <(int)coordinates.size(); i++) {
        int dist, min = 10; // min is used to find closest distance within 10, so fills up histogram
        // from 0, 1, 2, .. position and so on

        for (int j = 0; j < (int)coordinates.size(); j++) {
            if (i == j) continue;   // same element
            dist = getDistance(coordinates.at(i), coordinates.at(j));

            if (dist < min)
                min = dist;
        }

        // within distance
        if (min <= 9)
            histogram[min]++;
    }

    // print out
    for (int i = 0; i < 10; i++)
        cout << setw(4) << histogram[i];

    cout << endl;

    return 0;
}
