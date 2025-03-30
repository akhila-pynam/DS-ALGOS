#include<bits/stdc++.h>
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
Node* binarytree() {

    int value;
    cin >> value;

    if (value == -1) return nullptr;

    Node* node = new Node(value);
    node->left = binarytree();
    node->right = binarytree();
    return node;
}

void inorder(Node* root){

    if(root == nullptr) return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root = binarytree();
    inorder(root);
    

}