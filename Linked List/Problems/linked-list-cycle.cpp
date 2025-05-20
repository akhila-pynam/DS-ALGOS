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

void cycleLinkedlist(int pos){

	if(pos == -1) return;

	Node* temp =  head;
	Node* cycleNode = nullptr;
	int index = 0;

	while(temp->right != nullptr){

		if(index == pos){
			cycleNode = temp;
		}

		temp = temp->right;
		index++;

	}

	if(cycleNode != nullptr){
		temp->right = cycleNode;
	}

}

bool detectCycle(){

    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->right != nullptr){
    	slow = slow->right;
    	fast = fast->right->right;

    	if(slow == fast){
    		return true;
    	}

    }
    return false;
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

	int pos;
	cin >> pos;
    
    cycleLinkedlist(pos);

    if(detectCycle()){
    	cout << "true";
    }
    else{
    	cout << "false";
    }

	return 0;

}

// INPUT : 

// 4
// 3 2 0 -4
// 1

// OUTPUT :  true

// INPUT : 

// 1 
// 1 
// -1

// OUTPUT : false