#include <iostream>

using namespace std;

void sternBrocot(string path) {
	unsigned long long leftU = 0, midU = 1, rightU = 1;
	unsigned long long leftL = 1, midL = 1, rightL = 0;
	
	for (int i = 0; i < path.length(); i++) {
		if (path[i] == 'R') 	leftU = midU, leftL = midL;	// shift left values to mid
		else 					rightU = midU, rightL = midL; // shift right values to mid
		
		midU = leftU + rightU;
		midL = leftL + rightL;
	}
	
	cout << midU << "/" << midL << endl;
	
}

int main() {
	int N;
	cin >> N;
	string path;
	
	while (N--) {
		cin >> path;
		sternBrocot(path);
	}
	
	return 0;
}
