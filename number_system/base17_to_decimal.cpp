#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//'a' - 97  'A' - 65  0 - 48
	char hex[17];
	long long decimal=0, place=1;
	int val=0;
	cin >> hex;

	int len = strlen(hex);
	for(int i=0; hex[i] != '\0'; ++i) {
		if(hex[i]>='0' && hex[i]<='9') {
			val = hex[i] - '0';
		}
		else if(hex[i] >='a' && hex[i] <= 'g') {
			val = hex[i] - 97 + 10;
		}
		else if(hex[i]>='A' && hex[i]<='G') {
			val = hex[i] - 65 + 10;
		}
		decimal += val * pow(17,--len);
	}

	cout << decimal << "\n";
	return 0;
}