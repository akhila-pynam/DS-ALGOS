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

void bottomView(Node* root, vector<int>& result){

    
	if(root == nullptr) return;

	map<int, int> Map;
	queue<pair<Node*, int>> q;
	q.push({root,0});

	while(!q.empty()){
		pair<Node*, int> currentElement = q.front();
		q.pop();

		Node* node = currentElement.first;
		int distance = currentElement.second;

		Map[distance] = node->data;

		if(node->left != nullptr){
			q.push({node->left, distance-1});
		}
		if(node->right != nullptr){
			q.push({node->right, distance+1});
		}

	} 

	for(auto& currentElement : Map){
        result.push_back(currentElement.second);
    }
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	Node* root = binarytree();
	vector<int> result;
	bottomView(root, result);

	for(auto& value : result){
		cout << value << " ";
	}
}