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

Node* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                      vector<int>& inorder, int inStart, int inEnd, 
                      map<int, int>& inMap){

    if (preStart > preEnd || inStart > inEnd) return nullptr;

    Node* root = new Node(preorder[preStart]);

    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;

    root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
                                 inorder, inStart, inRoot - 1, inMap);

    root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
                                  inorder, inRoot + 1, inEnd, inMap);

    return root;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder) {

    map<int, int> inMap;

    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    Node* root = buildTreeHelper(preorder, 0, preorder.size() - 1,
                                 inorder, 0, inorder.size() - 1, inMap);

    return root;
}

void printInorder(Node* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printPreorder(Node* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
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
            } else {
                cout << "null ";
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

    vector<int> preorder(n), inorder(n);

    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];

    Node* root = buildTree(preorder, inorder);
    
    cout << "Level Order Traversal : ";
    printLevelOrder(root);

    return 0;
}
