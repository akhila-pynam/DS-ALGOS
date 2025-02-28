#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildTreeHelper(vector<int>& postorder, int postStart, int postEnd,
                      vector<int>& inorder, int inStart, int inEnd, 
                      map<int, int>& inMap) {

    if (postStart > postEnd || inStart > inEnd) return nullptr;

    Node* root = new Node(postorder[postEnd]);

    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;

    root->right = buildTreeHelper(postorder, postStart + numsLeft, postEnd - 1,
                                  inorder, inRoot + 1, inEnd, inMap);

    root->left = buildTreeHelper(postorder, postStart, postStart + numsLeft - 1,
                                 inorder, inStart, inRoot - 1, inMap);

    return root;
}

Node* buildTree(vector<int>& postorder, vector<int>& inorder) {

    map<int, int> inMap;

    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    return buildTreeHelper(postorder, 0, postorder.size() - 1,
                           inorder, 0, inorder.size() - 1, inMap);
}

void printInorder(Node* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printPostorder(Node* root) {
    if (root == nullptr) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

void printLevelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();

            if (node) {
                cout << node->val << " ";

                q.push(node->left);
                q.push(node->right);
            }
        }
    }
    cout << endl;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    int n;
    cin >> n;

    vector<int> postorder(n), inorder(n);

    for (int i = 0; i < n; i++) cin >> postorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];

    Node* root = buildTree(postorder, inorder);
    
    cout << "Level Order Traversal : ";
    printLevelOrder(root);

    return 0;
}
