#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int value) {
        data = value;
        right = nullptr;
        left = nullptr;
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

void preorder(Node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void iteratorBST(Node* root) {
    stack<Node*> S;
    Node* current = root;

    while (current != nullptr || !S.empty()) {
        while (current != nullptr) {
            S.push(current);
            current = current->left;
        }

        current = S.top();
        S.pop();
        cout << current->data << " ";

        current = current->right;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root = binarySearchtree();

    preorder(root);
    cout << endl;

    iteratorBST(root);
    cout << endl;

    return 0;
}
