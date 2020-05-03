#include <iostream>
#include <limits.h>
using namespace std;

int minCoins(int N, int coins[], int T) {
	// N-amount //T-no of different coins
	int dp[100] = {0};

	for(int i=1; i<=N; ++i) {
		dp[i] = INT_MAX;
		for(int j=0; j<T; ++j) {
			if(i-coins[j] >= 0) {
				dp[i] = min(dp[i], dp[i-coins[j]]+1);
			}
		}
	}
	return dp[N];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int coins[] = {1,7,10};
	int N = 15;
	int dp[100] = {0};
	cout << minCoins(N, coins, sizeof(coins)/sizeof(coins[0]));

	return 0;
}