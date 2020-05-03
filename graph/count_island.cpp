#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//input
/*
5 5
1 0 1 1 1
0 0 1 1 0 
1 0 0 1 0 
1 0 0 0 0
1 0 0 1 1
*/

int numIslands(vector<vector<char>>& grid) {
	if(grid.empty() || grid[0].empty()) {
		return 0;
	}
	int H = grid.size();
	int W = grid[0].size();
	int answer = 0;
	auto inside = [&](int row, int col) {
		return row>=0 && row<H && col>=0 && col<W;
	};
	vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
	vector<vector<bool>> visited(H, vector<bool>(W));
	for(int row=0; row<H; ++row) {
		for(int col=0; col<W; ++col) {
			if(!visited[row][col] && grid[row][col] == '1') {
				answer++;
				//bfs()
				queue<pair<int,int>> q;
				q.push({row,col});
				visited[row][col] = true;
				while(!q.empty()) {
					pair<int,int> p = q.front();
					q.pop();
					for(pair<int,int> dir: directions) {
						int new_row = p.first + dir.first;
						int new_col = p.second+ dir.second;

						if(inside(new_row,new_col) && !visited[new_row][new_col] && grid[new_row][new_col] == '1') {
							q.push({new_row,new_col});
							visited[new_row][new_col] = true;
						}
					}
					
				}
			}
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//Take vector inpput
	int row, col;
	cin >> row >> col;

	vector<vector<char>> grid(row);
	int i;
	for(int i=0; i<row; ++i) {
		grid[i].resize(row);
		for(int j=0; j<col; ++j) {
			cin >> grid[i][j];
		}
	}
	cout << "No of numIslands :" << numIslands(grid) << "\n";
	return 0;
}
