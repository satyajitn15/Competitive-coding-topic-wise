//input
/*
6 10
A E 2
A B 4
B C 1
B D 2
D F 2
D C 1
C F 5
E C 3
E F 2
F D 1
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
#include <set>
#include <algorithm>
using namespace std;

unordered_map<char, vector<pair<char, int>> > adjList;

void dijikstra(char src) {
	unordered_map<char, int> dist;
	for(auto j: adjList)
		dist[j.first] = INT_MAX;

	set<pair<int, char> > s;
	dist[src] = 0;
	s.insert({0, src});

	while(!s.empty()) {
		auto p = *(s.begin());
		char node = p.second;
		int nodeDist = p.first;
		s.erase(s.begin());

		for(auto childPair: adjList[node]) {
			if( nodeDist + childPair.second < dist[childPair.first]) {
				char dest = childPair.first;
				auto f = s.find({dist[dest], dest});
				if(f != s.end()) s.erase(f);

				dist[dest] = nodeDist + childPair.second;
				s.insert({dist[dest], dest});	
			}
		}
	}

	for(auto d: dist) {
		cout << d.first << "  located at distance of " << d.second << " from " << src << "\n";
 	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	char u, v;
	int d;
	for(int i=0; i<m;++i) {
		cin >> u >> v >> d;
		adjList[u].push_back({v, d});
	}

	// for(auto v: adjList) {
	// 	cout << v.first << "-> ";
	// 	for(auto u: v.second) {
	// 		cout << "(" << u.first << ", " << u.second <<")" ; 
	// 	}cout << "\n";
	// }

	dijikstra('A');
	return 0;
