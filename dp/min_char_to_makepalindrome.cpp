#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str1, str2;

	getline(cin, str1);
	str2 = str1;
	reverse(str2.begin(), str2.end());

	// cout<< str1 << "\n" <<str2 << "\n";
	int m, n;
	m = n = str1.size();
	int D[m][n];
	for(int i=0; i<=n;++i) {
		D[i][0] = 1;
		D[0][i] = 1;
	}

	for(int i=1; i<=n; ++i) {
		for(int j=1; j<= m; ++j) {
			if(str1[i] == str2[j]) 
				D[i][j] = D[i-1][j-1] + 1;
			else
				D[i][j] = max(D[i-1][j], D[i][j-1]);
		}
	}

	cout<<"minimum charcter added to make it palindrome :" << m - D[m][n] << "\n" ;
	return 0;
}