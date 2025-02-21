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

Node* newNode(int value) {
    return new Node(value);
}

Node* binarytree() {
    int value;
    cin >> value;

    if (value == -1) return nullptr;
    Node* node = new Node(value);
    node->left = binarytree();
    node->right = binarytree();
    return node;
}

bool isSameTree(Node* p, Node* q) {

    if (p == nullptr && q == nullptr) {     // both conditions true
        return true;
    }
    if (p == nullptr || q == nullptr) {    // atleast 1 condition true
        return false;
    }

    if (p->data == q->data) return true;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    Node* tree1 = binarytree();
    Node* tree2 = binarytree();

    bool result = isSameTree(tree1, tree2);
    
    if (result) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
} 