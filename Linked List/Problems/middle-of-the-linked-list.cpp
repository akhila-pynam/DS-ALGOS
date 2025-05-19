#include <bits/stdc++.h>
using namespace std;

struct Node{

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

void middleLinkedlist(){

	Node* slow = head;
	Node* fast = head;

	while(fast != nullptr && fast->right != nullptr){
		slow = slow->right;
		fast = fast->right->right;
	}
    
    head = slow;
}

void display(){
    
    Node* temp = head;
    while(temp->right != nullptr){
    	cout << temp->data << " ";
    	temp = temp->right;
    }
    cout << temp->data << " ";

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
 
    middleLinkedlist();
	display();

	return 0;

}

// INPUT : 

// 6
// 1 2 3 4 5 4

// OUTPUT : 4 5 4 


// INPUT :

// 5
// 1 2 3 4 5 

// OUTPUT : 3 4 5 