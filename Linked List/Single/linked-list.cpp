#include <bits/stdc++.h>
using namespace std;

// struct Node{

// 	int data;
// 	int right;

// 	Node(int val){
// 		data = val;
// 		right = nullptr;
// 	}

// };

class Node{
public:

	int data;
	Node* right;
    
    public:
	Node(int val){
		data = val;
		right = nullptr;
	}

};

int main(){

	#ifndef ONLIE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int nums[n];
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}
    
    Node* y = new Node(nums[2]);
    // cout << *y; -> Here Pointer Won't Work ( Operator<< Is Not Overloaded For Node Objects )
    cout << y->data;
}

// INPUT : 

// 4
// 2 3 4 5

// OUTPUT : 2