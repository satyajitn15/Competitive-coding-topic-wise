#include <iostream>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k;	
	cin >> n >> k;
	int dp[n]; 
	dp[0] = 1;
	for(int step=1; step<=n;++step) {
		dp[step] = 0;
		for(int j=1; j<=k; ++j) {
			if(step-j >= 0) dp[step] += dp[step-j];
		}
	}

	cout << dp[n] << "\n";
	return 0;
}
