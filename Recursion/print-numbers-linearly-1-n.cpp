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

	if(i > n) return;
  
	cout << i << endl;
	i++;

    printNums(i, n);

}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
    
    int n;
    cin >> n;

    int i=1;

	printNums(i, n);

	return 0;

}

// INPUT : 2 
// OUTPUT : 1 2 

// INPUT : 5
// OUTPUT : 1 2 3 4 5
