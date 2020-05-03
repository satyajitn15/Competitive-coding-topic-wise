#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<int, vector<int> > adjList;
vector<bool> visited;
unordered_map<int, int> dist;
void dfs(int s) {
	visited[s] = true;
	cout << s << " ";
	for(auto u: adjList[s]) {
		if(!visited[u]) 
			dfs(u);
	}
}

void bfs(int s) {
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	visited[s] = true;

	while(!q.empty()) {
		int s =q.front(); q.pop();
		cout << s << ", ";
		for(auto u: adjList[s]) {
			if(!visited[u]) {
				visited[u] = true;
				dist[u] = dist[s]+1;
				q.push(u);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m; cin >> n >> m;
	visited.assign(n, false);
	int u, v;
	for(int i=0;i <m; ++i) {
		cin >> u >> v;
		adjList[u].emplace_back(v);
		adjList[v].emplace_back(u);
	}

	// for(auto node:adjList) {
	// 	cout << node.first << " -> ";
	// 	for(auto adj: adjList[node.first]) {
	// 		cout << adj << ", ";
	// 	}cout << "\n";
	// }
	// dfs(1);
	bfs(1);
	cout << "\n";
	for(auto x: dist) {
		cout << "Distance of node " << x.first << "from node 1 is : " << x.second << "\n";
	}
	return 0;
}
