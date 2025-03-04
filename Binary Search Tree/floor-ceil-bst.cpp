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

pair<int, int> result(Node* root, int val){

	int floor = -1;
	int ceil = -1;

	if(root == nullptr) return {};

	while(root){
		if(root->data == val){
			floor = root->data;
			ceil = root->data;
			break;
		}

		if(val > root->data){
			floor = root->data;
			root = root->right;
		}
		else{
			ceil = root->data;
			root = root->left;
		}
	}
	return {floor, ceil};
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	Node* root = binarySearchtree();

    int val;
    cin >> val;

    pair<int, int> floorAndceil= result(root, val);

    cout << "Floor: " << floorAndceil.first << endl;
    cout << "Ceil : " << floorAndceil.second << endl;

}