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

Node* binarytree(){
	int value;
	cin >> value;

	if(value == -1) return nullptr;

	Node* node = new Node(value);
	node->left = binarytree();
	node->right = binarytree();
	return node;
}

void leftBoundary(Node* root, vector<int>& result){
	if(root == nullptr) return;

	if(root->left != nullptr){
		result.push_back(root->data);
		leftBoundary(root->left, result);
	}
	else if(root->right != nullptr){
        result.push_back(root->data);
        leftBoundary(root->right, result);
	}
}

void leafnodesBoundary(Node* root, vector<int>& result){
    if(root == nullptr) return;
    
    leafnodesBoundary(root->left, result);
    leafnodesBoundary(root->right, result);
    if(root->left == nullptr && root->right == nullptr){
    	result.push_back(root->data);
    }
}

void rightBoundary(Node* root, vector<int>& result){

	if(root == nullptr) return;

	if(root->right != nullptr){
		rightBoundary(root->right, result);
		result.push_back(root->data);
	}
	else if(root->left != nullptr){
		rightBoundary(root->right, result);
		result.push_back(root->data);
	}
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	Node* root = binarytree();

	if(root == nullptr) return 0;
	vector<int> result;
	result.push_back(root->data);

	if(root->right == nullptr && root->left == nullptr) {

         for (int value : result) {
            cout << value << " ";
         }
	}

    leftBoundary(root->left, result);
    leafnodesBoundary(root, result);
    rightBoundary(root->right, result);

    for (int value : result) {
        cout << value << " ";
    }
    
    return 0
}