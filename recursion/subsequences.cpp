#include <iostream>

using namespace std;
//Easy to implement but give TLE on sequence length > 26
void subsequence(char in[], char out[], int i, int j) {
	if(in[i]=='\0') {
		out[j] = '\0';
		cout << out << ", ";
		return;
	}
	//Including
	out[j] = in[i];
	subsequence(in,out,i+1,j+1);

	//Excluding
	subsequence(in,out,i+1,j);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	char in[100] = "abc";
	char out[100];
	subsequence(in,out,0,0);
	return 0;
}
