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

Node* reverseNodesInGroups(Node* head, int k) {

    if(head == nullptr) return nullptr;

    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    int count = 0;

    while (current != nullptr && count < k){

        next = current->right;
        current->right = prev;
        prev = current;
        current = next;
        count++;

    }

    if (next != nullptr) {
        head->right = reverseNodesInGroups(next, k);
    }

    return prev;
}

void reverseNodes(int k) {
    head = reverseNodesInGroups(head, k);
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

	reverseNodes(k);

	display();

	return 0;

}


// INPUT : 

// 7
// 1 2 3 5 4 6 7
// 3

// OUTPUT : 3 2 1 6 4 5 7