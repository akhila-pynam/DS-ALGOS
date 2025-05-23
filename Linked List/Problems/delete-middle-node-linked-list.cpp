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

void deleteMiddle(){
     
    if (head == nullptr || head->right == nullptr) {
		delete head;
		head = nullptr;
		return;
	}

	Node* slow = head;
	Node* fast = head;
	Node* prev = nullptr;

	while (fast != nullptr && fast->right != nullptr) {
		fast = fast->right->right;
		prev = slow;
		slow = slow->right;
	}

	prev->right = slow->right;
	delete slow;

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
    
    deleteMiddle();

	display();

	return 0;

}

// INPUT : 

// 5
// 1 0 2 0 1 

// OUTPUT : 1 0 0 1 