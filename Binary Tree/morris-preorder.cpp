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

void morrisPreorder(Node* root){
    Node* current = root;

    while(current != nullptr){
    	if(current->left == nullptr){
    		cout << current->data << " ";
    		current = current->right;
    	}

        else{
          Node* predecessor = current->left;
          while(predecessor->right != nullptr && predecessor->right != current){
          	predecessor = predecessor->right;
          }
        
            if(predecessor->right == NULL){
                    predecessor->right = current;
                    cout << current->data << " ";
                    current = current->left;
                } 

            else{
                    predecessor->right = NULL;
                    current = current->right;
                }
        }

    }
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	Node* root = binarytree();
	morrisPreorder(root);
}