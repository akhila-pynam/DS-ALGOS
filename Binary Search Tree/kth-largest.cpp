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

Node* kthLargestelement(Node* root, int k, int& count) {
	
    if (root == nullptr) return nullptr;

    Node* result = kthLargestelement(root->right, k, count);
    count++;
    if (count == k) return root;

    if (result) return result;

    return kthLargestelement(root->left, k, count);
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	Node* root = binarySearchtree();

	int count = 0;

    int k;
    cin >> k;

	Node* result = kthLargestelement(root, k, count);

    if (result) {
        cout << "Kth Largest element: " << result->data << endl;
    } 
    else {
        cout << "-1" << endl;
    }

}