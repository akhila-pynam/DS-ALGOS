#include <bits/stdc++.h>
using namespace std;

struct Node{
	
	int data;
	Node* left;
	Node* right;

	Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
	}

};

Node* binarySearchtree(){

	int value;
	cin >> value;

	if(value == -1) return nullptr;

	Node* node = new Node(value);
	node->left = binarySearchtree();
	node->right = binarySearchtree();
	return node;

}

Node* inorderSuccessor(Node* root, int val){

	Node* Successor = nullptr;

    while(root){
	    if(val >= root->data){
	       root = root->right;
		}
		else{
          Successor = root;
		  root = root->left;
		}
    }
	return Successor;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	Node* root = binarySearchtree();

	int val;
	cin >> val;

    Node* Successor = inorderSuccessor(root, val);

    if(Successor){
    	cout << Successor->data;
    }
    else{
    	cout << "No Successor";
    }
}