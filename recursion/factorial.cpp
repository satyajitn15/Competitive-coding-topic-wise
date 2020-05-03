#include <iostream>

using namespace std;

int factorial(int n) {
	return n==0 ? 1 : n*factorial(n-1);
} 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout << "factorial " << factorial(5) << "\n";
	return 0;
}
