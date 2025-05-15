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
     
     if(head == NULL){
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

void deleteNode(int k){

if (head == nullptr) return;  
    
    if (head->data == k) {
        Node* temp = head;
        head = head->right;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->right != nullptr && temp->right->data != k) {
        temp = temp->right;
    }

    if (temp->right == nullptr) return;

    Node* del = temp->right;
    temp->right = temp->right->right;
    delete del;

}

void display(){
     
     Node* temp = head;
     while(temp->right != nullptr){
     	cout << temp->data <<  " ";
     	temp = temp->right;
     }
     cout << temp->data << " ";

}

int main(){

	#ifndef ONLIE_JUDGE
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

	deleteNode(k);
	display();

	return 0;

}

// INPUT : 

// 7
// 5 2 3 6 4 7 8 
// 7

// OUTPUT : 5 2 3 6 4 8 


// INPUT : 

// 7
// 5 2 3 6 4 7 8 
// 6

// OUTPUT : 5 2 3 4 7 8 