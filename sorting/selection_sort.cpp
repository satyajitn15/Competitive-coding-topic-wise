#include <iostream>

using namespace std;
/* input
10 
2 5 8 0 2 9 8 5 2 52 
*/
void selectionSort(int arr[], int n) {

	for(int i=0; i<n-1; ++i) {
		//find the smallest element inde xin ub=nsorted part
		int min_index = i;
		for(int j=i; j<n-1; ++j) {
			if(arr[j] < arr[min_index]) min_index =j;
		} 
		//after loop swap
		swap(arr[i], arr[min_index]);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, key;
	cin >> n;
	int a[1000];

	for(int i=0; i<n; ++i) {
		cin >> a[i];
	}

	selectionSort(a, n);

	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}cout << "\n";
	return 0;
}