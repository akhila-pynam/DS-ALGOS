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

Node* binarySearchtree(){
    
    int value;
    cin >> value;

    if(value == -1) return nullptr;

    Node* node = new Node(value);
    node->left = binarySearchtree();
    node->right = binarySearchtree();
    return node;

}

void inorder(Node* root, vector<int>& elements){
    
    if(root == nullptr) return;

    inorder(root->left, elements);
    elements.push_back(root->data);
    inorder(root->right, elements);

}

bool twoSum(Node* root, int target){

    vector<int> elements;
    inorder(root, elements);

    int i = 0;
    int j = elements.size() - 1;

    while(i<j){

        int sum = elements[i] + elements[j];

        if(sum == target) return true;

        else if(sum < target){
            i++;
        }
        else{
            j--;
        }
    }

    return false;

}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    Node* root = binarySearchtree();

    int target;
    cin >> target;

    if(twoSum(root , target)){
        cout << "true";
    }
    else{
        cout << "false";
    }

}