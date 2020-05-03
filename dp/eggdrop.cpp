#include <iostream>
#include <limits.h>
using namespace std;

int eggDrop(int n, int m) {
	int trial[n+1][m+1];
	for(int i=1; i<=m; ++i) {
		trial[0][i] = 0;
		trial[1][i] = 1;
	}
	for(int i=1; i<=n; ++i) trial[i][1] = i;
	int result;
	for(int i=2;i <=n; ++i) {
		for(int j=2; j<=m; ++j) {
			trial[i][j] = INT_MAX;
			for(int k=1; k<=j; ++k) {
				result = 1 + max(trial[i-1][j-1], trial[i-1][j]);
				if(result < trial[i][j])
					trial[i][j] = result;
			}
		}
	}
	return trial[n][m];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	cout << "Min trial :" << eggDrop(n, m) << "\n";
	return 0;
}