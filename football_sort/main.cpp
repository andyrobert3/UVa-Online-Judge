#include <bits/stdc++.h>
// 10698
using namespace std;

struct team {
    string name;
    int points, gamesPlayed, scored, suffered, diff;
};

// non case sensitive comparator
bool nameComparator(string &name1, string &name2) {
    int i = 0;
    // check size
    while (i < (int)name1.size() && i < (int)name2.size()) {
        if (toupper(name1[i]) != toupper(name2[i])) {
            return toupper(name1[i]) < toupper(name2[i]);
        }
        i++;
    }

    return name1.size() < name2.size();
}

bool cmp(team t1, team t2) {
    if (t1.gamesPlayed == 0 && t2.gamesPlayed == 0) return nameComparator(t1.name, t2.name);

    if (t1.points != t2.points) return t1.points > t2.points;
    if (t1.diff != t2.diff) return t1.diff > t2.diff;
    if (t1.scored != t2.scored) return t1.scored > t2.scored;

    return nameComparator(t1.name, t2.name);
}

// add the various data for each team
void add_statistics(vector<team> &teams, string currTeam, int scored, int suffered) {

    int teamIndex = -1;
    // search for team
    for (int i = 0; i < (int)teams.size(); i++) {
        if (teams[i].name == currTeam) {
            teamIndex = i;
            break;
        }
    }

    // points
    if (scored > suffered)  teams[teamIndex].points += 3;
    else if (scored == suffered)    (teams[teamIndex].points)++;

    // games played
    (teams[teamIndex].gamesPlayed)++;

    // scored
    teams[teamIndex].scored += scored;
    teams[teamIndex].suffered += suffered;
    teams[teamIndex].diff += (scored-suffered);
}

int main()
{
    int T, G;
    string teamName;

    bool first = true;

    while (cin >> T >> G) {
        if (T == 0 && G == 0)   break;
        cin.ignore(100, '\n');  // 100 max numbers to extract

        // take care of spacing between fixtures
        if (first) first = false;
        else cout << endl;

        vector<team> teams;

        // every team input
        while (T--) {
            cin >> teamName;
            team t;
            t.name = teamName;
            t.points = t.gamesPlayed = t.scored = t.suffered = t.diff = 0;
            teams.push_back(t);
        }

        string homeTeam, awayTeam;
        char dash;  // useless
        int homeGoals, awayGoals;

        while (G--) {
            cin >> homeTeam >> homeGoals;
            cin >> dash;
            cin >> awayGoals >> awayTeam;

            // home team
            add_statistics(teams, homeTeam, homeGoals, awayGoals);
            // away team
            add_statistics(teams, awayTeam, awayGoals, homeGoals);
        }

        sort(teams.begin(), teams.end(), cmp);

        int currRank = 0;

        // represent output, tedious AF
        for (int i = 0; i < (int)teams.size(); i++) {
            if (i == 0 || teams[i].points != teams[i-1].points || teams[i].diff != teams[i-1].diff || teams[i].scored != teams[i-1].scored) {
                currRank = i + 1;
                printf("%2d. ", currRank);  // print current Rank
            } else {
                printf("    ");
            }

            cout << setw(15) << teams[i].name << setw(3) << teams[i].points;
            cout << setw(3) << teams[i].gamesPlayed << setw(3) << teams[i].scored;
            cout << setw(3) << teams[i].suffered << setw(3) << teams[i].diff;


            // set 15 spaces for string, then 3 spaces for each integer
            // %3d means use at least 3 spaces to display, padding as needed
            //printf("%15s %3d %3d %3d %3d %3d ", teams[i].name.c_str(), teams[i].points, teams[i].gamesPlayed, teams[i].scored, teams[i].suffered, teams[i].diff);


            if (teams[i].gamesPlayed == 0)  cout << " " << setw(6) << "N/A" << endl;    // printf("%6s\n", "N/A");
            else  printf(" %6.2f\n", (teams[i].points*100)/(float)(teams[i].gamesPlayed*3.0));
        }
    }


    return 0;
}
