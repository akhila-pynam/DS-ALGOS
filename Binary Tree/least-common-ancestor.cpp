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

Node* binarytree(){
	int value;
	cin >> value;

	if(value == -1) return nullptr;

	Node* node = new Node(value);
	node->left  = binarytree();
	node->right = binarytree();
	return node;
}

Node* lcA(Node* root, int p, int q){
     
    if(root == nullptr) return nullptr;
    
    if(root->data == p || root->data == q){
    	return root;
    }

    Node* left = lcA(root->left, p, q);
    Node* right = lcA(root->right, p, q);

    if(left != nullptr and right != nullptr){
    	return root;
    }

    return left ? left : right;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	Node* root = binarytree();

	int p, q;
    cin >> p >> q;

    Node* lcaNode = lcA(root, p, q);

    if(lcaNode != nullptr){
        cout << lcaNode->data << endl;
    }

    return 0;
}