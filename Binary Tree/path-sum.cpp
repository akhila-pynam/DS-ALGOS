#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* binarytree() {
    int value;
    cin >> value;
    if (value == -1) return nullptr;
    Node* newNode = new Node(value);
    newNode->left = binarytree();
    newNode->right = binarytree();
    return newNode;
}

bool pathSum(int n, Node* root, int targetSum) {
    if (root == nullptr) {
        return 0;
    }
    int lSum = pathSum(n, root->left, targetSum);
    int rSum = pathSum(n, root->right, targetSum);
    int maxSum = max(lSum, rSum) + root->data;
    return maxSum;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    Node* root = binarytree();

    int targetSum;
    cin >> targetSum;

    bool out = pathSum(n, root, targetSum);

    if (out) {
        cout << "true";
    } 
    else{
        cout << "false";
    }

    return 0;
}
