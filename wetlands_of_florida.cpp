#include <iostream>
#include <vector>
#include <sstream>
#include <ctype.h>

using namespace std;

vector<string> area;
int numR, numC;

// calculate area of floodill
int floodfill(int i, int j, char prevC, char newC) {
	if (i < 0 || i >= numR || j < 0 || j >= numC)	return 0;
	if (area[i][j] != prevC)	return 0;
	
	area[i][j] = newC;
	
	int indivSize = 1;
	return (indivSize + floodfill(i, j+1, prevC, newC) + floodfill(i, j-1, prevC, newC)
	+ floodfill(i+1, j-1, prevC, newC) + floodfill(i+1, j, prevC, newC) + floodfill(i+1, j+1, prevC, newC)
	+ floodfill(i-1, j-1, prevC, newC) + floodfill(i-1, j, prevC, newC) + floodfill(i-1, j+1, prevC, newC));
	
}

// std::ws is from sstream, it extracts as much whitespace as possible
int main() {
	int TC;
	
	cin >> TC >> ws;
	
	string line;
	string sep = "";
	int baseVal = 'X' + 'W';
	
	while(TC--) {
		cout << sep;
		sep = "\n";
		
		area.clear();
		
		// check to confirm it is graph
		while(isalpha(cin.peek())) {
			cin >> line >> ws;
			area.push_back(line);
		}
		
		numR = (int)area.size();
		numC = area[0].length();

		int i, j;
		
		// confirm it is query
		while (isdigit(cin.peek())) {
			cin >> i >> j >> ws;
			
			char prevC = area[--i][--j];
			char newC = baseVal - prevC;	// works idk?
			
			// newC = 'X' not working
			cout << floodfill(i, j, prevC, newC) << endl;
		}
		
		cin >> ws;	// eat further whitespace
	}	
	
	return 0;
}
