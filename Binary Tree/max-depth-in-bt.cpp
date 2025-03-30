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

	if (value == -1) return nullptr;

    Node* node = new Node(value);

    node->left = binarytree();
    node->right = binarytree();
    return node;
}

int maxDepth(Node* root){

    if(root == nullptr) return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + max(left, right);

}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    Node* root = binarytree();
    cout << maxDepth(root) << endl;
    return 0;


}