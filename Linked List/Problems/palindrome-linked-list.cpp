#include <bits/stdc++.h>
using namespace std;

struct  Node{

	int data;
	Node* right;

	Node(int val){
		data = val;
		right = nullptr;
	}
};

Node* head = NULL;
void insert(int value){

	if(head == nullptr){
		head = new Node(value);
	}
	else{

		Node* temp = head;
		while(temp->right != nullptr){
			temp = temp->right;
		}
		temp->right = new Node(value);
	}
}

bool palindromeLinkedlist(){

	stack<int> st;
	Node* temp = head;

	while(temp != nullptr){
		st.push(temp->data);
		temp = temp->right;
	}

	temp = head;

	while(temp != nullptr && temp->data == st.top()){
		
        st.top();
        st.pop();

        temp = temp->right;
	}

	if(st.size() == 0){
	   return true;
	}
	else{
       return false;
	}
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		int value;
		cin >> value;

		insert(value);
	}

	if(palindromeLinkedlist()){
		cout << "true";
	}
	else{
		cout << "false";
	}

	return 0;

}

// INPUT : 

// 3
// 1 2 1 

// OUTPUT : true 


// INPUT : 

// 4
// 1 5 6 9 

// OUPTUT : false