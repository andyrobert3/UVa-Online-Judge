#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;

int main() {
	int TC, neighbour;
	string line;
	
	while (cin >> TC) {
		
		while(TC--) {
			int P, rows;
			cin >> P;
			cin.get();
		
			vector<int> output;
			
			graph.assign(P, vector<int>());
			
			for (int i = 0; i < P; i++) {
				getline(cin, line);
				istringstream iss(line);
				
				// zero based index
				while(iss >> neighbour) {
					graph[i].push_back(neighbour-1);
				}				
			}
			
			int _min = 1001;	// max neighbours
			for (auto &row: graph) {
				if (row.size() < _min) {
					_min = row.size();
				}
			}
			
			for (int j = 0; j < P; j++) {
				if (_min == (int)graph[j].size())
					output.push_back(j+1);
			}
			
			sort(output.begin(), output.end());
		
			for (int k = 0; k < (int)output.size(); k++) {
				cout << output[k];
				if (k != (int)output.size()-1)
					cout << " ";
			}
			cout << endl;
					
		}	
	}
	
}
