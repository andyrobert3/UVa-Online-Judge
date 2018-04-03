#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// stores weight too!
vector<vector<pair<int, int>>> graph;

int maxUnits;
int lastVertex;

// special DFS to find largest path
void DFS(int u) {
	
	int maxWeight = -1;
	int maxNeighbour = 0;	// default
	
	for (auto &neighbour: graph[u]) {
		if (neighbour.second > maxWeight) {
			maxWeight = neighbour.second;
			maxNeighbour = neighbour.first;
		}
	}
	
	if (maxWeight != -1) {
		maxUnits += maxWeight;
		lastVertex = maxNeighbour;
		DFS(maxNeighbour);
	} 
	
}

int main() {
	int TC, numNodes, numEdges, _case = 1;
	cin >> TC >> ws;
	
	while (TC--) {
		cin >> numNodes >> numEdges;
		vector<int> nodes(numNodes);
		int weight;
		maxUnits = 0;
		lastVertex = 0;
		
		graph.assign(numNodes, vector<pair<int,int>>());
		
		// maps nodeID with weight
		for (int nodeID = 0; nodeID < numNodes; nodeID++) {
			cin >> nodes[nodeID];
		}
		
		int n1, n2;
		
		while (numEdges--) {
			cin >> n1 >> n2;
			// add connection, with weight
			graph[n1].emplace_back(n2, nodes[n2]);
		}
		
		// process data
		DFS(0);
		
		cout << "Case " << _case++ << ": " << maxUnits << " " << lastVertex << endl;
	}
 	
	return 0;
}
