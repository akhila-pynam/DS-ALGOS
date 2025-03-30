#include <bits/stdc++.h>
using namespace std;

struct Node{
	
	int data;
	Node* right;
	Node* left;

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

Node* lcaBst(Node* root, int val1, int val2){

	if(root == nullptr) return root;

	if(root->data == val1 || root->data == val2){
		return root;
	}

	Node* left = lcaBst(root->left, val1, val2);
	Node* right = lcaBst(root->right, val1, val2);

	if(left != nullptr && right != nullptr){
		return root;
	}

	if(left){
		return left;
	}
	else{
		return right;
	}


}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	Node* root = binarySearchtree();

    int val1, val2;
    cin >> val1 >> val2;

	Node* lca =  lcaBst(root, val1, val2);

	if (lca) {
        cout << lca->data;
    } else {
        cout << "Not Found";
    }

}