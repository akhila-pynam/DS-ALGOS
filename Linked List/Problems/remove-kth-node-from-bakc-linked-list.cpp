
#include <bits/stdc++.h>
using namespace std;

struct Node{
 
    int data;
    Node* right;

    Node(int val){
        data = val;
        right = nullptr;
    }
};

Node* head = nullptr;

void insert(int value){
    
    if(head == nullptr){
        head = new Node(value);
    } 
    else{

        Node* temp = head;
        while(temp->right != nullptr){
            temp = temp->right;
        }
        temp->right = new Node(value);

    }
}

void removeBack(int k, int n){
    
    if(head == nullptr) return;

    Node* slow = head;
    Node* fast = head;

    for(int i = 0; i < k; i++){
       
        if(fast != nullptr){
            fast = fast->right;
        }

    }

    if(fast == nullptr && k == n){
        
        Node* temp = head;
        head = head->right;
        delete temp;
        return;

    }

    while(fast != nullptr && fast->right != nullptr){
        slow = slow->right;
        fast = fast->right;
    }

    Node* temp = slow->right;
    slow->right = slow->right->right;
    delete temp;

}

void display(){
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->right;
    }
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

    int k;
    cin >> k;
    
    removeBack(k, n);

    display();

    return 0;

}

// INPUT :

// 5
// 1 2 3 4 5 
// 1 

// OUTPUT : 1 2 3 4


// INPUT :

// 7
// 45 1 8 7 18 56 12
// 3

// OUTPUT : 45 1 8 7 56 12