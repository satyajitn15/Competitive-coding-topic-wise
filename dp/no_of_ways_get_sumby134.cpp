#include <iostream>

using namespace std;

/*
	Problem: given n, ﬁnd the number of diﬀerent ways to write n as the sum of 1, 3, 4 
	◮ Example: for n = 5, the answer is 6
	5 = 1 + 1 + 1 + 1 + 1 = 1 + 1 + 3 = 1 + 3 + 1 = 3 + 1 + 1 = 1 + 4 = 4 + 1

*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long D[10];
	D[0] = D[1] =D[2] = 1;
	D[3] = 2;
	for(int i=4; i<10; ++i)
		D[i] = D[i-1] + D[i-3] +D[i-4];

	for(int i=0;i<10;++i)
		cout<<"D["<<i<<"] :" <<D[i] << "\n";
	
	return 0;
}