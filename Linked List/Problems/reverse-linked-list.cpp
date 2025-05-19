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

Node* head = NULL;
void insert(int value){
    
    if(head == nullptr){
        head = new Node(value);
    }
    else{
        
        Node* temp = head;
        while(temp->right !=  nullptr){
            temp = temp->right;
        }
        temp->right = new Node(value);
    }
     
}

void reverseLinkedlist(){
    
    stack<int> st;
    Node* temp = head;
    
    while(temp != nullptr){
        st.push(temp->data);
        temp = temp->right;
    }
    
    temp = head;
    while(temp != nullptr){
        temp->data = st.top();
        st.pop();

        temp = temp->right;
    }


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

    for(int i=0; i<n; i++){
        int value;
        cin >> value;

        insert(value);
    }

    reverseLinkedlist();

    display();

    return 0;

}

// INPUT :  

// 7
// 1 2 5 6 8 9 4 

// OUTPUT : 4 9 8 6 5 2 1 