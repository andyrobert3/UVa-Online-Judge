#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int height, width;
int iDir[4] = {0, 0, -1, 1};
int jDir[4] = {1, -1, 0 , 0};

vector<string> grid;

// regular floodfill
void floodfill(int i, int j, char prevC, char newC) {
	if (i < 0 || i >= height || j < 0 || j >= width)	return;
	if (grid[i][j] != prevC)							return;	// different language
	
	grid[i][j] = newC;
	
	for (int k = 0; k < 4; k++) {
		floodfill(i + iDir[k], j + jDir[k], prevC, newC);
	}	
}

// pair.second ->occurences, pair.first -> language char
bool cmp(const pair<char,int> &p1, const pair<char,int> &p2) {
	if (p1.second == p2.second)	return p1.first < p2.first;
	return p1.second > p2.second;
}


int main() {
	int TC, _case = 1;
	string line;
	cin >> TC;
	
	while (TC--) {
		unordered_map<char, int> languages;
		vector<pair<char,int>> output;
		
		// getting the input
		cin >> height >> width;
		cin.get();	// remove new line for getline read
		grid.clear();
		
		for (int i = 0; i < height; i++) {
			getline(cin, line);
			grid.push_back(line);
		}	
		
		
		// processing input	
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (grid[i][j] != '@') {
					languages[grid[i][j]]++;
					floodfill(i, j, grid[i][j], '@');	
				}
			}
		}
		
		// output
		for (auto &it: languages) {
			output.emplace_back(it.first, it.second);
		}
		
		sort(output.begin(), output.end(), cmp);
		
		// printing out
		cout << "World #" << _case++ << endl;
		for (auto &p: output) {
			cout << p.first << ": " << p.second << endl;
		}
		
	}
	
	return 0;
}
