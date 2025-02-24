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

void rightView(Node* root){
	if(root == nullptr) return;

	queue<Node*> q;
	q.push(root);

	while(!q.empty()){

		int levelsize = q.size();
		int rightMostValue;

		for(int i=0; i<levelsize; i++){
			Node* element = q.front();
			q.pop();

			rightMostValue = element->data;

			if(element->left != nullptr){
				q.push(element->left);
			}
			if(element->right != nullptr){
				q.push(element->right);
			}
		}
        cout << rightMostValue << " ";
	}
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
     
	Node* root = binarytree();
	rightView(root);

	return 0;
}