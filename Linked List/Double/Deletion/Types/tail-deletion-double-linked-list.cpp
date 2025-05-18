#include <bits/stdc++.h>
using namespace std;

struct Node{

	int data;
	Node* left;
	Node* right;

	Node(int val){
		data = val;
		left = nullptr;
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
		temp->right->left = temp;

	}
}

void deleteTail(){
    
    if(head == NULL || head->right == nullptr){
       delete(head);
    }
    
    Node* temp = head;
    while(temp->right->right != nullptr){
    	temp = temp->right;
    }

    delete(temp->right);
    temp->right = nullptr;

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
	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		int value;
		cin >> value;

		insert(value);

	}

    deleteTail();

	display();

	return 0;
}

// INPUT :

// 7
// 18 2 3 6 1 4 2

// OUTPUT : 18 2 3 6 1 4 