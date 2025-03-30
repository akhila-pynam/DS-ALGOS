#include <bits/stdc++.h>
using namespace std;

struct Node {

    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
    
};

Node* binarySearchtree() {

    int value;
    cin >> value;

    if (value == -1) return nullptr;

    Node* node = new Node(value);
    node->left = binarySearchtree();
    node->right = binarySearchtree();
    return node;

}

Node* FindMin(Node* root) {

    while (root && root->left != nullptr) {
        root = root->left;
    }

    return root;
}

Node* deleteNode(Node* root, int val) {

    if (root == nullptr) return root;

    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } 
    else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } 


    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;

        } else if (root->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;

        } else if (root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
            
        } else {
            Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

void inorder(Node* root) {

    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}


int main() {

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root = binarySearchtree();

    int val;
    cin >> val;

    Node* result = deleteNode(root, val);
    inorder(result);

    return 0;
}
