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

    if (!(cin >> value)) {   
        return nullptr;
    }
     
    Node* node = new Node(value);
    node->left = binarytree();
    node->right = binarytree();
    return node;
}

int balancedTree(Node* root){

    if(root == nullptr) return 0;

    int left = balancedTree(root->left);
    int right = balancedTree(root->right);

    int balanced = abs(left-right);
    if(balanced > 1 || left == -1 || right == -1){
        return -1;
    }

    return 1+max(left, right);

}

bool isBalanced(Node* root){
    if(root == nullptr) return true;

    return balancedTree(root) != -1;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root = binarytree();
    balancedTree(root);


    if (isBalanced(root)) {
        cout << "Balanced";
    } 
    else {
        cout << "Not Balanced";
    }
}