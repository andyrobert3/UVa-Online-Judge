#include <iostream>
#include <vector>

using namespace std;

int main() {
	int rows, cols, enterCol;
	
	while(cin >> rows >> cols >> enterCol) {
		if (rows == 0 && cols == 0 && enterCol == 0) break;
		
		vector<pair<int, int>> pastCoordinates;
		vector<vector<char>> instructionGrid(rows, vector<char>());
		vector<vector<bool>> hasVisited(rows, vector<bool>());
		
		for (auto &sub_arr: instructionGrid) {
			sub_arr.assign(cols, ' ');		
		}
		
		for (auto &sub: hasVisited) {
			sub.assign(cols, false);
		}
		
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cin >> instructionGrid[i][j];
			}
		}
		
		pair<int, int> pos (0, enterCol-1);
		hasVisited[0][enterCol-1] = true;
		
		int steps = 0, loopSteps;
		bool hasLoop = false;
		
		while ((pos.first >= 0 && pos.first < rows) && (pos.second >= 0 && pos.second < cols)) {
			char inst = instructionGrid[pos.first][pos.second];
			pastCoordinates.emplace_back(pos.first, pos.second);
			
			if (inst == 'W') {
				pos.second--;
			} else if (inst == 'E') {
				pos.second++;
			} else if (inst == 'N') {
				pos.first--;
			} else if (inst == 'S') {
				pos.first++;
			}
			
			steps++;
			
			if ((pos.first >= 0 && pos.first < rows) && (pos.second >= 0 && pos.second < cols)) {
				// loop
				if (hasVisited[pos.first][pos.second]) {
					
					for (int i = 0; i < (int)pastCoordinates.size(); i++) {
						if (pastCoordinates[i] == pos) {
							loopSteps = (int)pastCoordinates.size() - i;
							break;
						}
					}

					hasLoop = true;
					break;

				} else {
					hasVisited[pos.first][pos.second] = true;
				}
			}
		}
		
		
		if (hasLoop)		cout << steps-loopSteps << " step(s) before a loop of " << loopSteps << " step(s)\n";
		else				cout << steps << " step(s) to exit\n";
	}
	
	return 0;
}
