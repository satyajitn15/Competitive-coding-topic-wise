#include <iostream>
#include <vector>
using namespace std;
#define inf 99999
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> sheight(n+1);

	for(int i=1; i<=n; ++i) cin >> sheight[i];
	
	vector<int> dp(n+1);
	dp[1] = 0;
	for(int i=2; i<=n; ++i) {
		int min = inf;
		for(int j=1; j<=k;++j) {
			if(i-j >= 1 && (min > abs(sheight[i] - sheight[i-j]) + dp[i-j])) {
				min = abs(sheight[i] - sheight[i-j]) + dp[i-j];
			}
		}
		dp[i] = min;
	}

	cout << "min cost :" << dp[n] << "\n";
	return 0;
}
