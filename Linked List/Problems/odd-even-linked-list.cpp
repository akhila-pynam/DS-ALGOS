#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;

    Node(int val) {
        data = val;
        right = nullptr;
    }
};

Node* head = NULL;

void insert(int value) {
    if (head == nullptr) {
        head = new Node(value);
    } else {
        Node* temp = head;
        while (temp->right != nullptr) {
            temp = temp->right;
        }
        temp->right = new Node(value);
    }
}

void oddEven(int n) {
   
// Works, But Only For Integers

    // stack<int> odd;
    // stack<int> even;
    // stack<int> oe;
    // Node* temp = head;

    // int index = 1;

    // while (temp != nullptr) {
    //     if (index % 2 != 0) {
    //         odd.push(temp->data);
    //     } else {
    //         even.push(temp->data);
    //     }

    //     temp = temp->right;
    //     index++;
    // }

    // while (!even.empty()) {
    //     oe.push(even.top());
    //     even.pop();
    // }

    // while (!odd.empty()) {
    //     oe.push(odd.top());
    //     odd.pop();
    // }

    // while (!oe.empty()) {
    //     cout << oe.top() << " ";
    //     oe.pop();
    // }


// Optimal O(n) Solution 

    if(head == nullptr && head->right == nullptr) return;

    Node* odd = head;
    Node* even = head->right;
    Node* attachEven = even;

    while(even != nullptr && even->right != nullptr){

        odd->right = even->right;
        odd = odd->right;

        even->right = odd->right;
        even = even->right;

    }

    odd->right = attachEven;

}

void display(){

    Node* temp = head;
    while(temp->right != nullptr){
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << temp->data << " ";

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int value;
        cin >> value;

        insert(value);
    }

    oddEven(n);

    display();

    return 0;
}

// INPUT :

// 7
// 2 1 3 5 6 4 7 

// OUTPUT : 2 3 6 7 1 5 4 

// INPUT : 

// 5 
// 1 2 3 4 5 

// OUTPUT : 1 3 5 2 4 