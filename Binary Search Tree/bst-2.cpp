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

Node* binarySearch(Node* root, int val){
	while (root != nullptr && root->data != val) {
 
            root = (root->data > val) ? root->left : root->right;
        }
       
        return root; 
    }

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif

    Node* root = binarytree();

    int val;
    cin >> val;

    Node* result = binarySearch(root, val);
    
    if(result){
    	cout << result->data;
    }
    else{
    	cout << "not found";
    }
}