#include <iostream>
#include <vector>
using namespace std;
#define ll long long
vector<ll> v1, v2;
//finding subsequences using bitmasking
void subsets(vector<ll> v) {
	vector<ll> ans;
	int n = v.size();

	for(int i=0; i<(1<<n); ++i) {
		//Extract the bits of the current number
		int j=0;
		for(int no=i; no>0; no = no>>1) {
			if(no&1){
				ans.emplace_back(v[j]);
			}
			j++;
		}
		for(auto x: ans) cout << x;
		cout << "\n";
		ans.clear();
	}
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<ll> nos = {1,2,3,4,5};
	subsets(nos);
	return 0;
}
