#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string text;
	getline(cin,text);
	// reverse(text.begin(), text.end());
	cout << text << "\n";

	text.insert(text.end(),' ');
	int j=0;

	for(int i=0; i<text.size(); ++i) {
		if(text[i] == ' ') {
			reverse(text.begin()+j,text.begin()+i);
			j = i+1;
		}
	}

	text.pop_back();
	cout << text << "\n";
	return 0;
}
