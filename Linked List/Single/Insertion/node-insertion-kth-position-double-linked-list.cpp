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

void insertNode(int nodeVal, int k){
     
    Node* temp = head; 
    int cnt = 1;

    while(temp->right != nullptr && cnt < k-1){
    	temp = temp->right;
    	cnt++;
    }

    Node* newNode = new Node(nodeVal);
    newNode->right = temp->right; 
    newNode->left = temp;
    temp->right = newNode;
    newNode->right->left = newNode;

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

    insertNode(nodeVal, k);
    display();

    return 0;
}

// INPUT : 

// 7
// 1 2 6 5 4 8 2 
// 3
// 7

// OUTPUT : 1 2 7 6 5 4 8 2 