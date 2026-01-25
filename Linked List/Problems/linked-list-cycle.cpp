#include <bits/stdc++.h>
using namespace std;

int pos = -1;

struct Node{

    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
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

int cnt = 0;

bool LLcycle(){

    map<Node*, int> mp;
    Node* temp = head;
    while(temp != null){
        mp[temp] = 1;
        temp = temp->next;

        if(mp[temp] > 1) return true;
    }

    return false;

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

    bool cycle = LLcycle();
    if(cycle){
        cout << "true";
    }

    else cout << "false";
    
    return 0;

}