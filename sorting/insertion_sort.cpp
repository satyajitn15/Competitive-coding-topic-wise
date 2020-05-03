#include <iostream>

using namespace std;
/* input
10 
2 5 8 0 2 9 8 5 2 52 
*/
void insertionSort(int arr[], int n) {

	for(int i=1; i<n-1; ++i) {
		int e =arr[i];
		//place the currrent elemnt at right positoin in sorted partint
		int j = i-1;
		while(j>=0 && arr[j] > e) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j + 1] = e;
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

	insertionSort(a, n);

	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}cout << "\n";
	return 0;
}