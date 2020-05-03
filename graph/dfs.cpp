#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adjList;
vector<bool> visited;

void dfs(int v) {
	visited[v] = true;
	cout<< v <<" ";
	for(auto u: adjList[v]) {
		if(!visited[u])
			dfs(u);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, u, v;
	cin>> n >> m;
	adjList.resize(n+1);
	visited.resize(n+1);
	visited.assign(n, false);

	for(int i=0; i<m; ++i) {
		cin>> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}


	for(int i=0;i < n; ++i)  {
		visited.assign(n, false);
		cout<<"\nDFS of "<<i<<" :";
		dfs(i);
	}
	return 0;
}