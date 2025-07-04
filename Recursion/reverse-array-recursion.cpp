// #include <bits/stdc++.h>
// using namespace std;

// void swap(int &left, int &right){
    
//     int temp = left;
//     left = right;
//     right = temp;

// }

// void func(int left, int right, int array[]){
   
//     if(left >= right) return;
//     swap(array[left], array[right]);
//     func(left+1, right-1, array);

// }

// int main(){

// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// 	#endif

//     int n;
//     cin >> n;

// 	int left = 0;
// 	int right = n-1;

// 	int array[n];
// 	for(int i=0; i<n; i++){
// 		cin >> array[i];
// 	}

// 	func(left, right, array);

//     for(int i=0; i<n; i++){
//     	cout << array[i] << " ";
//     }

// 	return 0; 	

// }


// Simple Method 

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){

	int temp = a;
	a = b;
	b = temp;

}

void func(int i, int n, int array[]){

	if(i > n/2) return;
	swap(array[i], array[n-i-1]);
	func(i+1, n, array);

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int array[n];
	for(int i=0; i<n; i++){
		cin >> array[i];
	}

	func(0, n, array);

	for(int i=0; i<n; i++){
		cout << array[i] << " ";
	}

	return 0;

}

// INPUT :

// 5 
// 2 3 6 5 4

// OUTPUT : 4 5 6 3 2 