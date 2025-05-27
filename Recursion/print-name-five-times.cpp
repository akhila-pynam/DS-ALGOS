#include <bits/stdc++.h>
using namespace std;

int name = 0;
void printName(){

	if(name == 5) return;
  
	cout << "Akhila Pynam" << endl;
	name++;

    printName();

}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	

	printName();

	return 0;

}

// OUTPUT :

// Akhila Pynam
// Akhila Pynam
// Akhila Pynam
// Akhila Pynam
// Akhila Pynam