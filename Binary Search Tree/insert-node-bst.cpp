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

Node* insertNode(Node* root, int val){

	if(root == nullptr) return new Node(val);
	Node* current = root;

	while(current){

		if(current->data <= val){

           if(current->right != nullptr){
              current = current->right;
           }

           else{
              current->right = new Node(val);
              break;
           }
         
	    }

	    else{
	    	if(current->left != nullptr){
	    		current = current->left;
	    	}
	    	else{
	    		current->left = new Node(val);
	    		break;
	    	}
	    }
    }
    return root;
}

void preorder(Node* root) {

	if (root == nullptr) return;

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	Node* root = binarySearchtree();

	int val;
	cin >> val;

    Node* result = insertNode(root, val);

    preorder(result);
}