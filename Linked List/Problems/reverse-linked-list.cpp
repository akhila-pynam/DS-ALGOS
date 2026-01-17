#include <bits/stdc++.h>
using namespace std;

struct Node{
   
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }

};

Node* head = NULL;

void linkedList(int value){
     
    if(head == NULL){
       head = new Node(value);
       return;
    }

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = new Node(value);

}

void reverseLL(){

    if(head == NULL){
       return;
    }
    
    Node* temp = head;
    stack<int> st;

    while(temp != nullptr){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

}

void display(){

    Node* temp = head;
    while(temp->next != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
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

        linkedList(value);

    }

    reverseLL();
    display();

    return 0;

}

// INPUT :  

// 7
// 1 2 5 6 8 9 4 

// OUTPUT : 4 9 8 6 5 2 1 