#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> output;

// classic DFS
void DFS(int v) {
	visited[v] = true;
	
	for (auto &neighbour: adj[v])
		if (!visited[neighbour])
			DFS(neighbour);
			
	output.push_back(v);
}

int main() {
	int n, m;
	
	
	while (cin >> n >> m) {
		if (n == 0 && m == 0)	break;
		output.clear();

		adj.assign(n+1, vector<int>());
		visited.assign(n+1, false);
				
		int i, j;
		
		while (m--) {
			cin >> i >> j;
			adj[i].push_back(j);	// directed
		}
		
		// topological sort 
		for (int i = 1; i <= n; i++) {
			if (!visited[i])
				DFS(i);
		}
		
		// needed 
		reverse(output.begin(), output.end());
		
		for (auto &it : output)
			cout << it << " ";
			
		cout << endl;
	}
	
	return 0;
}
