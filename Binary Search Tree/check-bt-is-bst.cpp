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

bool checkBst(Node* root, int min, int max){

	if(root == nullptr) return true;

	if(root->data <= min || root->data >= max){
		return false;
	}

	return checkBst(root->left, min, root->data) && checkBst(root->right, root->data, max);

}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    Node* root = binarySearchtree();

    int min = INT_MIN;
    int max = INT_MAX;
    checkBst(root, min, max);

    if (checkBst(root, min, max)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

}