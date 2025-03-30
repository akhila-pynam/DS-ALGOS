#include <bits/stdc++.h>
using namespace std;

struct Node {
    
    int data;
    Node* left;
    Node* right;

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

void zigzagTraversal(Node* root) {

    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel(levelSize);

        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();
            
            int index = leftToRight ? i : (levelSize - 1 - i);
            currentLevel[index] = current->data;

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        for (int val : currentLevel) {
            cout << val << " ";
        }
        cout << endl;

        if (leftToRight) {
           leftToRight = false;
        } else {
           leftToRight = true;
        }

    }
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root = binarytree();
    zigzagTraversal(root);
    return 0;
}