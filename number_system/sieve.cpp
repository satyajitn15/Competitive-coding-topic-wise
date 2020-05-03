#include <iostream>
using namespace std;

// T(n) = O(N*loglogN)
void prime_sieve(int *p) {
	//mark all odd no as prime
	for(int i=3; i<=1000000; i+=2) p[i] = 1;

	for(long long i=3; i<=1000000; i+=2) {
		//if current no is not marked (it is prime)
		if(p[i] == 1) {
			//mark all multiples of i as not prime
			for(long long j = i*i; j <= 1000000; j+=i) {
				p[j] = 0;
			}
		}
	}
	//special case
	p[2] = 1;
	p[1] = p[0] = 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int p[1000005] = {0};
	//prime sieve (fastest way to calcualte if a oumber is prime or not)
	int n;
	cin >> n;
	prime_sieve(p);
	for(int i=0;i <=n; ++i) {
		if(p[i] == 1) {
			cout << i << " ";
		}
	}
	return 0;
};