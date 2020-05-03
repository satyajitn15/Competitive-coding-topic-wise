#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
//take input from input.txt

vector<vector<int>> adjList;
vector<bool> visited;
vector<int> parent;
vector<int> dist;

void bfs(int s) {
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	cout<<s<<" ";
	while(!q.empty()) {
		int v = q.front();
		q.pop();

		for(auto u : adjList[v]) {
			if(!visited[u]) {
				visited[u] = true;
				cout<<u<<" ";
				q.push(u);
				dist[u] = dist[v] + 1; 
				parent[u] = v;
			}
		}
	}
}

void shortestPathFromSource(int u) {
	if(!visited[u])
		cout<<"No path!\n";
	else {
		vector<int> path;
		for(int v = u; v != -1; v = parent[v] ) 
			path.push_back(v);
		reverse(path.begin(), path.end());
		cout<<"Path :";
		for(auto v: path)
			cout<<v<<"-> ";
	}cout<<"\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int n, m, a,b;
	cin>>n>>m;
	//n no of nodes
	//m no of edges
	adjList.resize(n+1);
	visited.resize(n+1);
	parent.resize(n+1);
	dist.resize(n+1);

	while(m--) {
		cin>>a>>b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	for(int i=0;i< n; ++i)  {
		cout<<i<<"-> ";
		for(auto adj: adjList[i]) {
			cout<<adj<<", ";
		}cout<<"\n";
	}

	bfs(0);

	shortestPathFromSource(6);	
	shortestPathFromSource(7);	

	cout<<"Distance of Node"<<3<<"from "<<0<<"is :"<<dist[3];
	return 0;
}
