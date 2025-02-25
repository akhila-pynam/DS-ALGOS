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
	node->left = binarytree();
	node->right = binarytree();
	return node;
}

void countAllnodes(Node* root, int& count){

	if (root == nullptr) return;

    // here used preorder , we can use any-order
   
    count++;
	countAllnodes(root->left, count);
	countAllnodes(root->right, count);


}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	Node* root = binarytree();

	int count = 0;
	countAllnodes(root, count);

	cout << count;
}