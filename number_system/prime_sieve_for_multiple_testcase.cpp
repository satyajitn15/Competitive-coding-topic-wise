#include <iostream>
using namespace std;
#define ll long long
void prime_sieve(int *p) {
	for(int i=3; i<=1000000; i+=2) {
		p[i] = 1;
	}

	for(ll i=3; i<=1000000; i+=2) {
		if(p[i] == 1) {
			for(ll j=i*i; j<=1000000; j = j+i){
				p[j] = 0;
			}
		}
	}
	p[2] = 1;
	p[1] =p[0] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int p[1000005] = {0};
	prime_sieve(p);

	int cumsum[1000005] = {0};

	for(int i=1; i<=1000000; ++i) {
		cumsum[i] = cumsum[i-1] + p[i];
	}

	int q;
	cin >> q;
	while(q--) {
		int a, b;
		cin	>> a >> b;

		cout << cumsum[b] - cumsum[a-1] << "\n";
	}
	return 0;
}
