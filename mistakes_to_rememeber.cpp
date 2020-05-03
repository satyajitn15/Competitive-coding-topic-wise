#include <iostream>

#define mod 1000000007
using namespace std;

int main() {

	//fast input and output
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//long long are  64 bit integer 
	// long long x, y;
	// cin>>x>>y;
	// cout<<x*y<<"\n";

	//while left shifiting (if leftshifting more than 30 use  : number << 1ll)
	// cout<<(1ll<<40)<<"\n" ;

	//But what if we don’t know how many lines of input are going to be there? We can use this then
	// string s; 
 //    while (getline(cin, s)) { 
 //        if (s.empty()) 
 //            break; 
 //        // cout << s << endl; 
 //    } 
  
  	// int n, i;
  	// cin>>n;
  	// while(n--) {
  	// 	cin>>i;
  	// }


  	//A problem when taking remainders: In a lot of problems, you have to print your solution modulo some large prime (for example 10^9 + 7).
  	long long x , y, z;
  	cin>> x >> y ;
  	// z = (z + x* y) % mod;
  	z = ((z%mod) + ((x%mod)*(y%mod))%mod) % mod; 
  	cout<<z<<"\n" ;
	return 0;
}