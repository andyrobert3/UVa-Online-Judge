#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int iMove[8] = {2, 2, 1, -1, -2, -2, 1, -1};
int jMove[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

bool isWithin(int i, int j)	{
	return (i >= 0 && i < 8 && j >= 0 && j < 8);
}

bool cmp(const string &s1, const string &s2) {
	if (s1[1] != s2[1])		return s1[1] > s2[1];
	return s1[0] < s2[0];	
}

int main() {
	int TC;
	cin >> TC;
	
	vector<vector<int>> jumps;	// stores jumps required
	string s;
	
	while (TC--) {
		int x, y;
		vector<string> output;
		
		jumps.assign(8, vector<int>());
		for (auto &i: jumps)
			i.assign(8, -1);	// -1 means not traversed yet
			
		// take input
		cin >> s;
		int _maxJumps = 0;
		int c = 20;	// WHY??
		
		// proces input
		x = s[0] - 'a';
		y = 7 - (s[1] - '1');	// flip axis
		jumps[y][x] = 0;	// initial 
		
		
		// check often for the upper parts too
		while (c--) {
		
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {		
					// if jumped here before
					if (jumps[i][j] != -1) {
					
						// look for other jumps
						for (int k = 0; k < 8; k++) {
							int _i = i + iMove[k];
							int _j = j + jMove[k];
			
							if (isWithin(_i, _j)) {
								// standardize distances (jumps)
								if (jumps[_i][_j] == -1 || jumps[_i][_j] > jumps[i][j] + 1)
									jumps[_i][_j] = jumps[i][j] + 1;
							}							
						}
					}
				}
			}
		}
		
		// find max jumps
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (jumps[i][j] > _maxJumps)
					_maxJumps = jumps[i][j];
			}
		}
		
		cout << _maxJumps;
		
		
		// prepping output
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (jumps[i][j] == _maxJumps) {
					string tmp;
					tmp += (char) (j + 'a');	
					tmp += (char) ('8' - i);
					output.push_back(tmp);
				}
			}
		}
		
		sort(output.begin(), output.end(), cmp);
		
		for (auto &it: output) {
			cout << " " << it;
		}
		
		cout << endl;
	}
	
	return 0;
}
