#include <bits/stdc++.h>

#define INF 100000

using namespace std;

vector<vector<int> > adj;
int d[1005][1005];
int TC;
vector<int> x, y;

bool visited[1005];

// distance from coordinate i to coordinate j
int dist(int i, int j) {
	return (pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2));
}

bool compareEqual(int i, int j) {
	if (x[i] < x[j]) {	// more west
		return true;
	} else {
		if (x[i]== x[j] && y[i] < y[j])	// more south
		   return true;
	}
	
	return false;
}

// find the two minimum distances from vertex u, then connect them in the adjacency list
void build_graph() {
	if (TC == 1)	return;
	for (int i = 0; i < TC; i++) {
		adj[i].clear();
		int min = INF;
		int u, v;
		
		// take closest first point
		for (int j = 0; j < TC; j++) {
			if (d[i][j] < min) {
			   min = d[i][j];
			   u = j;	// mark the coordinate with minimum distance
   		 	}
		}
		
		// in equal case
		for (int j = u+1; j < TC; j++) {
			if (d[i][j] == min)
			   if (compareEqual(j,u) == true)
			   	  u = j;
		}
		
		adj[i].push_back(u);	// take note of coordinate
		
		// take second closest station, if exists
		if (TC >= 3) {
     	   min = INF;
		   for (int j = 0; j < TC; j++) {
		   	    if (j != u && d[i][j] < min) {
		   	   	  min = d[i][j];
				  v = j;	// mark coodinate with min distance
			    }
		   }
		   
		   // equal case
		   for (int j = v + 1; j < TC; j++) {
		   	    if (d[i][j] == min && j != u) {
		   	   	   if (compareEqual(j,v))
		   	   	   	  v = j;
			    }
		   }
		   
		   adj[i].push_back(v);	// take note of coordinate
  		}
	
	}
}

void DFS(int u) {
	visited[u] = true;
	
	for (auto &neighbour: adj[u])
		if (!visited[neighbour])
		   DFS(neighbour);

}

// is the whole graph connected
bool isConnected() {
	DFS(0);

	for (int i = 0; i < TC; i++)
		if (!visited[i])	
		   return false;
		   
	return true;
}


int main() {

	int xPos, yPos;
	
	while (cin >> TC, TC) {
		adj.assign(TC, vector<int>());
		x.clear();
		y.clear();
				
		for (int i = 0; i < TC; i++) {
			cin >> xPos >> yPos;
			
			// stores the each station's coordinates
   			x.push_back(xPos);
   			y.push_back(yPos);
			
			// distance[i][j] represents the distance between point i and j, calculate for all points
			for (int j = 0 ; j < i; j++)
				d[i][j] = d[j][i] = dist(i,j);
				
			d[i][i] = INF;	// dont count for self loops
			visited[i] = false;
		}
		build_graph();
		
		if (isConnected())
		   cout << "All stations are reachable." << endl;
		else
			cout << "There are stations that are unreachable." << endl;
		
	}
	
	return 0;
}
