#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, key;
	cin >> n;
	int a[1000];

	for(int i=0; i<n; ++i) {
		cin >> a[i];
	}

	//sort an array using sort() function
	// sort(a, a+n); //

	//to sort in descending order pass an lamda function to sort() as third argument
	//We can write our own customize comparator function
	sort(a, a+n, [](int x, int y) -> bool{
		return x > y;
	});
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}cout << "\n";
	return 0;
}