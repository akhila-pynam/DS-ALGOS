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
    cin >> value;

    if (value == -1) return nullptr;

    Node* node = new Node(value);
    node->left = binarytree();
    node->right = binarytree();
    return node;
}

bool helper(Node* p, Node* q) {

    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;

    if (p->data != q->data) {
        return false;
    }
    return helper(p->left, q->right) && helper(p->right, q->left);
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root = binarytree();
    
    bool isMirror = helper(root->left, root->right);

    if (isMirror) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
