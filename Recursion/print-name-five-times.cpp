// #include <bits/stdc++.h>
// using namespace std;

// int name = 0;
// void printName(){

// 	if(name == 5) return;
  
// 	cout << "Akhila Pynam" << endl;
// 	name++;

//     printName();

// }

// void printName(int i, int n){

// 	if(i > 5) return;
  
// 	cout << "Akhila Pynam" << endl;
// 	i++;

//     printName(i, n);

// }

// int main(){

// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// 	#endif	

//     int 
// 	printName();

// 	return 0;

// }

#include <bits/stdc++.h>
using namespace std;

void printName(int i, int n){

	if(i > 5) return;
  
	cout << "Akhila Pynam" << endl;
	i++;

    printName(i, n);

}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
    
    int n;
    cin >> n;

    int i=1;

	printName(i, n);

	return 0;

}


// OUTPUT :

// Akhila Pynam
// Akhila Pynam
// Akhila Pynam
// Akhila Pynam
// Akhila Pynam