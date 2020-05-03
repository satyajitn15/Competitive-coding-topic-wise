#include <iostream>
#include <limits.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int dp[100] = {0};

	dp[1] = 0;
	for(int i=2; i<=n; ++i) {
		int op1, op2, op3;
		op1 = op2 = op3 = INT_MAX;
		if(n%3 == 0) {
			op1 = dp[i/3];
		}
		if(n%2 == 0) {
			op2 = dp[i/2];
		}
		op3 = dp[i-1];

		dp[i] = min(min(op1, op2), op3) + 1;
	}

	cout << dp[n] << "\n";
	return 0;
}