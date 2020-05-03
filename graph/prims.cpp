#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
#include <dos.h>
using namespace std;

struct Edge {
	int w = INT_MAX, to =-1;
	bool operator <(Edge const& other) const {
		return make_pair(w, to) < make_pair (other.w, other.to);
	}
};

int n;
vector<vector <Edge> > adj;

void prim() {
	int total_weight = 0;
	vector<Edge> min_e(n);
	min_e[0].w	= 0;
	set<Edge> s;
	q.insert({0,0});
	vector<bool> selected(n, false);
	for(int i=0; i<n; ++i) {
		if(s.empty()) {
			cout << "NO MST! \n";
			exit(0);
		}
	}
	int v = s.begin()->to;
	selected[v] = true;
	total_weight += s.begin()->w;
	s.erase(s.begin());

	if(min_e[v].to != -1) 
		cout << v << min_e[v].to << "\n";
	
	for (Edge e : adj[v]) {
            if (!selected[e.to] && e.w < min_e[e.to].w) {
                s.erase({min_e[e.to].w, e.to});
                min_e[e.to] = {e.w, v};
                s.insert({e.w, e.to});
            }
        }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}