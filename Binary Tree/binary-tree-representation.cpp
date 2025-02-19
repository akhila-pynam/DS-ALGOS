#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right = nullptr;
    Node* left = nullptr;

    Node(int value) {
        data = value;
        right = nullptr;
        left = nullptr;
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

void Preorder(Node* root) {

    if (root == nullptr) return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
    
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root = binarytree();
    Preorder(root);
    cout << endl;

    return 0;
}
