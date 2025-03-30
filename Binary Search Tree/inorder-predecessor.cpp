#include <bits/stdc++.h>
using namespace std;

struct Node{

	int data;
	Node* left;
	Node* right;

	Node(int value){
		data = value;
		right = nullptr;
		left = nullptr;
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

Node* inorderPredeccessor(Node* root, int val){

	Node* Predeccessor = nullptr;
	if(root == nullptr) return root;

	while(root){
	    if(val <= root->data){
			root = root->left;
		}
		else{
			Predeccessor = root;
			root = root->right;
		}

	}
	
   return Predeccessor;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	Node* root = binarySearchtree();

    int val;
    cin >> val;

	Node* Predeccessor = inorderPredeccessor(root, val);

	if(Predeccessor){
		cout << Predeccessor->data;
	}
	else{
		cout << "not found";
	}

}