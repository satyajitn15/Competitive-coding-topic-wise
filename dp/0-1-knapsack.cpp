#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int wts[] = {2,7,3,4};
	int prices[] = {5,20,20,10};
	int N = 4;
	int W = 11;

	int dp[100][100];

	for(int i=0; i<=N; ++i) {
		for(int w=0; w<=W; ++w) {
			if(i==0 || w==0) {
				dp[i][w] = 0;
			}
			else {
				int inc=0, exc=0;
				if(wts[i-1] <= w) {
					inc = prices[i-1] + dp[i-1][w - wts[i-1]];
				}
				else {
					exc = dp[i-1][w];
				}
				dp[i][w] = max(inc, exc);
			}
		}
	}

	cout << "Max profit :" << dp[N][W] << "\n";

	return 0;
}
