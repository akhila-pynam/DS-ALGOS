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

Node* binarytree() {
    int value;
    if (!(cin >> value)) {   // Added to prevent hang if input.txt is missing or empty
        return nullptr;
    }
     
    // if (value == -1) return nullptr;

    Node* node = new Node(value);
    node->left = binarytree();
    node->right = binarytree();
    return node;
}

int Height(Node* root) {
    if (root == nullptr) return 0;

    int left = Height(root->left);
    int right = Height(root->right);

    int balancedFactor = abs(left - right);

    if (balancedFactor > 1 || left == 1 || right == -1) {
        return -1;
    }

    return 1 + max(left, right);
}

bool balancedBinarytree(Node* root) {
    if (root == nullptr) return true;
    return Height(root) != -1;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root = binarytree();

    if (balancedBinarytree(root)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0; 
}