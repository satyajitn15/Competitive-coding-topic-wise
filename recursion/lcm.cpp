#include <iostream>

using namespace std;
int gcd(int a, int b) {
	if (b==0) return a;
	else return gcd(b, a%b);
}
int lcm(int a, int b){
	return a*b/gcd(a,b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout << lcm(10,15) << "\n";
	return 0;
}
