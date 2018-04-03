#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
int i, V, u, v, pos_u, pos_v, ans;
int p[9];

vector<ii> EL;	// edge list

int main() {
	V = 9;	// 9 vertices and 9 edges

	EL.emplace_back(0,1); EL.emplace_back(0,5);
	EL.emplace_back(1,4);
	EL.emplace_back(2,0); EL.emplace_back(2,1); EL.emplace_back(2,4);
	EL.emplace_back(5,3);
	EL.emplace_back(6,7); EL.emplace_back(6,8);
	
	for (i = 0; i < V; i++) p[i] = i;	// stores the vertices
	
	ans = 0;
	do {
		bool valid = true;
		
		for (i = 0; i < (int)EL.size(); i++) {
			u = EL[i].first;
			v = EL[i].second;
	
			for (pos_u = 0; pos_u < V; pos_u++) if (p[pos_u] == u) break;
			for (pos_v = 0; pos_v < V; pos_v++) if (p[pos_v] == v) break;
			if (pos_u > pos_v) valid = false;
		}
			
		if (valid) ans++;		
	
	} while (next_permutation(p, p+9));
	
	printf("There are %d valid topological orderings\n", ans);
		
	return 0;
}
	
	
	
