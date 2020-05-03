#include <iostream>
#include <vector>
using namespace std;

int lcs(vector<int> arr) {
	int size = arr.size();
	vector<int> lis(size, 1);

	for(int i=1; i<size; ++i) {
		for(int j=0; j < i; ++j) {
			if(arr[i] > arr[j] && lis[i] < lis[j]+1)
				lis[i] = lis[j]+1;
		}
	}
	int max = lis[0];
	for(int i=0; i<size; ++i){
		if(lis[i]>max)	max = lis[i];
	}

	return max;
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i;
	cin >> n;
	vector<int> arr;
	while(n--) {
		cin >> i;
		arr.push_back(i);
	}

	cout << "LCS :" << lcs(arr) << "\n";
	return 0;
}