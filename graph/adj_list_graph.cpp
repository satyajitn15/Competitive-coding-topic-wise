/*
9
D B 40
D C 40
C A 10
C D 40
B A 0
B D 40
A B 20
A C 10
A D 50
*/
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

unordered_map<string, list<pair<string, int>> > adjList;

void addEdge(string u, string v, int dist) {
	adjList[u].push_back({v, dist});
}

void print() {
	for(auto v: adjList) {
		cout << v.first << "-> ";
		for(auto u: adjList[v.first]) {
			cout << "(" << u.first << "," << u.second << ")"; 
		}cout << "\n";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string u , v;
	int m, d;
	cin >> m;
	for(int i=0; i<m; ++i) {
		cin >> u >> v >> d;
		addEdge(u,v,d);
	}

	print();
	return 0;	
}