#include <iostream>
#include <vector>

using namespace std;

vector<string> graph;
vector<vector<bool>> used;

int width, height, count;

int iDir[4] = {0, 0, -1, 1};
int jDir[4] = {1, -1, 0, 0};

void dfs(int i, int j) {
	if (i < 0 || i >= height || j < 0 || j >= width)	return;
	if (graph[i][j] == '#' || used[i][j]) 				return;
	
	if (graph[i][j] == 'G')	count++;
	
	
	used[i][j] = true;
	
	// check neighbours for traps, if found go back
	for (int k = 0; k < 4; k++) {
		if (graph[i+iDir[k]][j+jDir[k]] == 'T') {
			return;
		}
	}
	
	// recrusively search other areas
	for (int k = 0; k < 4; k++)
		dfs(i+iDir[k], j+jDir[k]);
}


int main() {
	
	while (cin >> width >> height) {
		count = 0;
		graph.clear();	// reset grid
		cin.get();	// remove new line
		
		// reset the 'used' 2D array
		used.assign(height, vector<bool>());
		for (auto &it: used)
			it.assign(width, false);
		
		// input the map
		string line;
		for (int i = 0; i < height; i++) {
			getline(cin, line);	
			graph.push_back(line);							
		}
		
		// find player starting point
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (graph[i][j] == 'P') {
					dfs(i, j);
					break;
				}
			}
		}
		
		cout << count << endl;
	}
			
	
	return 0;
}
