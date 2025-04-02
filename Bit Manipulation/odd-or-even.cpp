#include <bits/stdc++.h>
using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

	int number;
	cin >> number;

	// Return Even = True
	//         Odd = False

	// if(number % 2 == 0){
	// 	cout << "True";
	// }
	// else{
	// 	cout << "False";
	// }

	if(number & 1){
		cout << "True";    // odd
	}
	else{
		cout << "False";   // even
	}
}