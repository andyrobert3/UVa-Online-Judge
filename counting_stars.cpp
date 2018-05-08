#include <iostream>
#include <vector>

using namespace std;
	
vector<string> sky;
int numR, numC;
int asterisks;

int iDir[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int jDir[8] = {1, -1, 0, 1, -1, 0, 1, -1};

void floodfill(int i, int j, char prevC, char newC) {
	if (i < 0 || i >= numR || j < 0 || j >= numC) 	return;
	if (sky[i][j] != prevC)							return;
	
	sky[i][j] = newC;
	asterisks++;
	
	for (int k = 0; k < 8; k++) {
		floodfill(i+iDir[k], j+jDir[k], prevC, newC);	
	}
}	


int main() {
	string line;
	
	while (cin >> numR >> numC) {
		if (numR == 0 && numC == 0)	break;
		sky.clear();
		
		for (int i = 0; i < numR; i++) {
			cin >> line;
			sky.push_back(line);
		}
		
		int ans = 0;
		for (int i = 0; i < numR; i++) {
			for (int j = 0; j < numC; j++) {
				if (sky[i][j] == '*') {
					asterisks = 0;
					
					floodfill(i, j, '*', '@');
					
					if (asterisks == 1)	
						ans++;
				}
			}
		}
		
		cout << ans << endl;
	}
}
