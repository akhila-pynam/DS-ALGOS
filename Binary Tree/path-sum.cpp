#include <bits/stdc++.h>
using namespace std;

struct Node{

	int data;
	Node* left;
	Node* right;

	Node(int val){

		data = val;
		left = nullptr;
		right = nullptr;

	}

};

Node* binarytree(){

	int value;
	cin >> value;

	if(value == -1) return nullptr;

	Node* newNode = new Node(value);
	newNode->left = binarytree();
	newNode->right = binarytree();
	return newNode;

}

bool pathSum(Node* root, int tS, int cS){

	if(root == nullptr) return false;

	cS = root->data + cS;

  if(root->left == nullptr && root->right == nullptr){
  	if(cS == tS) return true;
  	else return false;
  }
  
  bool lSum = pathSum(root->left, tS, cS);
  bool rSum = pathSum(root->right, tS, cS);

  // if(lSum || rSum) return true;
  // else return false;
  
  // Another Way To Write

  return (lSum || rSum);

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int tS;
	cin >> tS;

	Node* root = binarytree();
	int cS = 0;

    bool out = pathSum(root, tS, cS);
    
    if(out) {
      cout << "true";
    } 
    else{
      cout << "false";
    }


    return 0;

}