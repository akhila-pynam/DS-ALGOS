#include<bits/stdc++.h>
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

Node* binarytree() {
    int value;
    cin >> value;

    if (value == -1) {
        return nullptr;
    }

    Node* node = new Node(value);
    node->left = binarytree();
    node->right = binarytree();
    return node;
}

int diameter = 0;

int height(Node* root) {
    if (root == nullptr) return 0;

    int left = height(root->left);
    int right = height(root->right);

    diameter = max(diameter, left + right);
    return 1 + max(left, right);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root = binarytree();
    height(root);
    cout << diameter << endl;
    return 0;
}
