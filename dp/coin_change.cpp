#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n_coins, coin, amount;
	cin >> amount;
	cin >> n_coins;
	vector<int> coins(n_coins);
	for(int i=0; i<n_coins; ++i) {
		cin >> coins[i];
	} 

	int no_of_ways[amount+1][n_coins];

	for(int i=0; i<n_coins; ++i) no_of_ways[0][i] = 1;
	

	for(int i=1; i<= amount; ++i) {
		for(int j=0; j<n_coins; ++j) {
			int x = (i >= coins[j]) ? no_of_ways[i-coins[j]][j] : 0;
			int y = (j>=1) ? no_of_ways[i][j-1] : 0;
			no_of_ways[i][j] = x + y;
		}
	}

	cout << "No of ways getting coin exchange is : " << no_of_ways[amount][n_coins-1] << "\n" ;

	return 0;
}