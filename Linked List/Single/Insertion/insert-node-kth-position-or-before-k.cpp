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

void kthPosition(int k, int nodeVal){

	if (k == 0) {
		Node* temp = new Node(nodeVal);
		temp->right = head;
		head = temp;
		return;
	}

	Node* temp = head;
	int count = 0;

	if (temp == nullptr) {
		return;
	}

	while (temp->right != nullptr && count < k-2) {
		temp = temp->right;
		count++;
	}

	Node* newNode = new Node(nodeVal);
	newNode->right = temp->right;
	temp->right = newNode;
    
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

    int k;
    cin >> k;

    int nodeVal;
    cin >> nodeVal;

    kthPosition(k, nodeVal);

	display();
    
    return 0;

}

// INPUT : 

// 8
// 4 5 6 2 3 8 9 1 
// 3
// 10

// OUTPUT : 4 5 10 6 2 3 8 9 1 