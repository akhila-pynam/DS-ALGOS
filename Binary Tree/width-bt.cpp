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

Node* binarytree(){
    int value;
    cin >> value;

    if(value == -1) return nullptr;

    Node* node = new Node(value);
    node->left = binarytree();
    node->right = binarytree();
    return node;
}

int widthOfbt(Node* root) {
    if (!root) return 0;
    
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int ans = 0;
    
    while (!q.empty()) {
        int n = q.size();
        int start = q.front().second;
        int end = q.back().second;
        ans = max(ans, end - start + 1);
        
        for (int i = 0; i < n; i++) {
            pair<Node*, int> p = q.front();
            Node* node = p.first;
            int idx = p.second;
            q.pop();
            
            if (node->left) q.push({node->left, 2 * idx + 1});
            if (node->right) q.push({node->right, 2 * idx + 2});
        }
    }
    
    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root = binarytree();
    int ans = widthOfbt(root);

    cout << ans;
    return 0;
}
