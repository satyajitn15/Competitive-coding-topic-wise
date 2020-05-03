#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
    string A, B;
    cin >> A >> B;
    // cout << A << " " << B << "\n";
    int LCS[A.size()+1][B.size()+1];
    for(int i=0; i<=A.size(); ++i) {
    	for(int j=0; j<=B.size(); ++j) {
    		if(i==0 || j==0) 
    			LCS[i][j] = 0;
    		else if(A[i-1] == B[j-1]) 
    			LCS[i][j] = LCS[i-1][j-1] + 1;
    		else
    			LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
    	}
    }

    cout << "LCS :" << LCS[A.size()][B.size()] << "\n";
	return 0;
}
