#include <iostream>
#include <string.h>
using namespace std;
void swap(char *x, char* y) {
	char tmp = *x;
	*x = *y;
	*y = tmp;
}
void permute(char* str, int l, int r) {
	if(l == r) cout << str << "\n";
	else {
		for(int i=l; i <=r; ++i) {
			swap((str+l), (str+i));
			permute(str, l+1, r);
			swap((str+l), (str+i));
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	char str[100];	cin >> str;
	permute(str, 0, strlen(str) - 1);
	return 0;
}