#include <iostream>
#include <vector>

using namespace std;
	
vector<vector<char>> sky;
int numR, numC;

/*
bool checkStar(int i, int j) {
	
	bool isStar = true;
	
	// top of sky
	if (i == 0) {
		// upper left
		if (j == 0) {
			
			if (sky[i][j+1] == '*')	isStar = false;
			if (sky[i+1][j+1] == '*') isStar = false;
			if (sky[i+1][j] == '*')	isStar = false;
			
			if (isStar)	return true;		
		} else if (j == numC-1) {
			// upper right
			
			if (sky[i][j-1] == '*')	isStar = false;
			if (sky[i+1][j-1] == '*') isStar = false;
			if (sky[i+1][j] == '*')	isStar = false;
			
			if (isStar)	return true;
			
		} else {
			if (sky[i][j-1] == '*')	isStar = false;
			if (sky[i][j+1] == '*') isStar = false;
			if (sky[i+1][j] == '*')	isStar = false;
			if (sky[i+1][j+1] == '*')	isStar = false;
			if (sky[i+1][j-1] == '*')	isStar = false;
		
			if (isStar) return true;
		}
	} else if (i == numR - 1) {
		// bottom left
		if (j == 0) {
			if (sky[i][j+1] == '*')	isStar = false;
			if (sky[i-1][j+1] == '*') isStar = false;
			if (sky[i-1][j] == '*')	isStar = false;
			
			if (isStar) return true;

		} else if (j == numC-1) {
			// bottom right
			if (sky[i][j-1] == '*')	isStar = false;
			if (sky[i-1][j-1] == '*') isStar = false;
			if (sky[i-1][j] == '*')	isStar = false;
			
			if (isStar) return true;

		} else {
			// bottom
			if (sky[i][j-1] == '*')	isStar = false;
			if (sky[i][j+1] == '*') isStar = false;
			if (sky[i-1][j] == '*')	isStar = false;
			if (sky[i-1][j+1] == '*')	isStar = false;
			if (sky[i-1][j-1] == '*')	isStar = false;
		
			if (isStar) return true;
		}
	} else {
		// left
		if (j == 0) {
			if (sky[i][j+1] == '*')	isStar = false;
			if (sky[i+1][j+1] == '*') isStar = false;
			if (sky[i+1][j] == '*')	isStar = false;
			if (sky[i-1][j] == '*')	isStar = false;
			if (sky[i-1][j+1] == '*')	isStar = false;
		
			if (isStar) return true;
		} else if (j == numC-1) {
			// right
			if (sky[i][j-1] == '*')	isStar = false;
			if (sky[i-1][j] == '*') isStar = false;
			if (sky[i-1][j-1] == '*')	isStar = false;
			if (sky[i+1][j] == '*')	isStar = false;
			if (sky[i+1][j-1] == '*')	isStar = false;
		
			if (isStar) return true;
		} else {
			// all 8 parts check
			if (sky[i][j-1] == '*')	isStar = false;
			if (sky[i][j+1] == '*')	isStar = false;
			if (sky[i+1][j] == '*')	isStar = false;
			if (sky[i+1][j-1] == '*')	isStar = false;
			if (sky[i+1][j+1] == '*')	isStar = false;
			if (sky[i-1][j] == '*')	isStar = false;
			if (sky[i-1][j-1] == '*')	isStar = false;
			if (sky[i-1][j+1] == '*')	isStar = false;
			
			if (isStar)	return true;			
		}
	}
	
	return isStar;
}
*/

// returns size of connected components
int floodfill (int i, int j, int prevC, int newC) {
	if (i < 0 || i >= numR || j < 0 || j >= numC)	return 0;
	if (sky[i][j] != prevC)							return 0;	
	
	sky[i][j] = newC;
	
	int ans = 1;	// one star is found
	return (ans + floodfill(i, j+1, prevC, newC) + floodfill(i, j-1, prevC, newC)
			+ floodfill(i+1, j+1, prevC, newC) + floodfill(i+1, j-1, prevC, newC)
			+ floodfill(i+1, j, prevC, newC) + floodfill(i-1, j+1, prevC, newC)
			+ floodfill(i-1, j, prevC, newC) + floodfill(i-1, j-1, prevC, newC));
	
}

int main() {
	
	while (cin >> numR >> numC) {
		if (numR == 0 && numC == 0)	break;
		//cin.get();
		
		sky.assign(numR, vector<char>());
		for (auto &it: sky) {
			it.assign(numC, '.');
		}
		
		for (int i = 0; i < numR; i++) {
			for (int j = 0; j < numC; j++) {
				cin >> sky[i][j];
			}
		}
		
		int CC = 0;
		for (int i = 0; i < numR; i++) {
			for (int j = 0; j < numC; j++) {
				if (sky[i][j] == '*')
					if (floodfill(i, j, '*', '@') == 1) 
						CC++;
					
			}
		}
		
		cout << CC << endl;
	}
}
