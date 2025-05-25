#include <bits/stdc++.h>
using namespace std;

struct Node{

	int data;
	Node* right;
	Node* random;

	Node(int val){

		data = val;
		right = nullptr;
		random = nullptr;

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

void clone(){

	Node* temp = head;
	map<Node*, Node*> mp;

	while(temp != nullptr){
		Node* newNode = new Node(temp->data);
		mp[temp] = newNode;
		temp = temp->right;
	}

	temp = head;
	while(temp != nullptr){
		
		Node* copyNode = mp[temp];
		copyNode->right = mp[temp->right];
		copyNode->random = mp[temp->random];
		temp = temp->right;

	}
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

    clone();

    display();

    return 0;

}


// INPUT : 

// 7
// 1 2 3 5 4 6 7

// OUTPUT : 1 2 3 5 4 6 7