// #include <bits/stdc++.h>
// using namespace std;

// int n = 10;
// int cnt = 0;
// void printLinearly(){
 
//     if(cnt == 11) return;

//     cout << cnt << endl;
//     cnt++;
    
//     printLinearly();

// }

// int main(){

// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// 	#endif	

// 	printLinearly();

// 	return 0;

// }

#include <bits/stdc++.h>
using namespace std;

void printNums(int i, int n){

	if(i == n) return;

	i++;
	printNums(i, n);
    cout << i << endl;


}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);;
	#endif

	int n;
	cin >> n;

	int i = 0;

	printNums(i, n);

	return 0;

}

// INPUT : 5 
// OUTPUT : 5 4 3 2 1 

// INPUT : 3 
// OUTPUT : 3 2 1