#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<char>> pic;

// I LOVE FLOODFILL
void floodFill(int i, int j, char prevC, char newC) {
	if (i < 0 || i >= N || j < 0 || j >= N)	return;
	
	// color isn't same as previous, don't touch it
	if (pic[i][j] != prevC)	return;
	
	// replace color
	pic[i][j] = newC;
	
	// recur in all directions
	floodFill(i+1, j+1, prevC, newC);
	floodFill(i+1, j, prevC, newC);
	floodFill(i+1, j-1, prevC, newC);
	
	floodFill(i, j+1, prevC, newC);
	floodFill(i, j-1, prevC, newC);
	
	floodFill(i-1, j-1, prevC, newC);
	floodFill(i-1, j, prevC, newC);
	floodFill(i-1, j+1, prevC, newC);
}

int main() {
	int _case = 1;
	
	while(cin >> N) {
		//cin.get();
		
		pic.assign(N, vector<char>());
		for (auto &it: pic) {
			it.assign(N, '0');
		}
		
		// taking input in per character
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> pic[i][j];
				
		int CC = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (pic[i][j] == '1') {
					CC++;	// calculate connected components
					floodFill(i, j, '1', '2');	// flood fill every connected components	
				}
			}
		}
		
		cout << "Image number " << _case++ << " contains " << CC << " war eagles.\n";
	}
	
	
	
}
