#include <bits/stdc++.h>
using namespace std;

struct Node{

	int data;
	Node* left;
	Node* right;

	Node(int val){
		data = val;
		left  = nullptr;
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
		temp->right->left = temp->right;
	}
};

void deleteNode(int nodeVal){

    if(head->data == nodeVal){
    	
    	Node* temp = head;
    	delete(temp);
    	head = temp->right;
    	return;

    }

    Node* temp = head;
    while(temp->right != nullptr && temp->right->data != nodeVal){
    	temp = temp->right;
    }
    delete(temp->right);
    temp->right = temp->right->right;

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
    
    int nodeVal;
    cin >> nodeVal;

    deleteNode(nodeVal);

    display();

    return 0;

}

// INPUT : 

// 7
// 18 2 3 6 1 4 2
// 18

// OUTPUT : 2 3 6 1 4 2 

// INPUT : 

// 7
// 18 2 3 6 1 4 2
// 1

// OUTPUT : 18 2 3 6 4 2 