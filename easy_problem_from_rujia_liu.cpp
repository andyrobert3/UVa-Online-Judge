#include <iostream>
#include <vector>

using namespace std;

int main() {
	int numElements, queries, num, k, v;
	vector<vector<int> > output;
	
	while (cin >> numElements >> queries) {
		output.assign(1000001, vector<int>());
	
		// input
		for (int i = 1; i <= numElements; i++) {
			cin >> num;
			output[num].push_back(i);	// stores position of num
		}
	
		while (queries--) {
			// kth occurence of v
			cin >> k >> v;
			
			if (output[v].size() < k)	cout << 0 << endl;	// get kth occurence
			else								cout << output[v][k-1] << endl;	
		}
	}
	
	return 0;
}  
