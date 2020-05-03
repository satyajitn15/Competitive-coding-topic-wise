#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*3
satyajit
1702040018
sagar
1702560588
sujit
1702040035
*/
typedef struct Student {
	string name;
	int id;
}Student;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	Student *s = new Student[n];
	for(int i=0; i<n; ++i) {
		getline(cin,s[i].name);
		getline(cin,s[i].name);
		cin >> s[i].id;
	}

	sort(s,s+n,[](Student s1, Student s2) {
		return s1.id < s2.id;
	});

	for(int i=0; i<n; ++i) {
		cout << s[i].name << " : " << s[i].id << "\n" ;
	}
	return 0;
}
