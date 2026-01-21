// #include <bits/stdc++.h>
// using namespace std;

// struct Node{

//     int data;
//     Node* next;

//     Node(int val){
//         data = val;
//         next = nullptr;
//     }

// };

// Node* head = NULL;
// void linkedList(int value){

//     if(head == NULL){
//         head = new Node(value);
//         return;
//     }

//     Node* temp = head;
//     while(temp->next != nullptr){
//         temp = temp->next;
//     }

//     temp->next = new Node(value);

// }

// Node* middleofLL(){

//     Node* temp = head;
//     int cnt = 0;
//     stack<int> st;

//     while(temp != nullptr){
//         cnt++;
//         st.push(temp->data);
//         temp = temp->next;
//     }

//     temp = head;
//     int midNode = (cnt/2) + 1;

//     while(midNode > 1){
//         midNode--;
//         temp = temp->next;
//     }

//     return temp;

// }

// void display(){

//     Node* temp = head;
//     while(temp->next != nullptr){
//         cout << temp->data << " ";
//         temp = temp->next;
//     }

//     cout << temp->data << " ";

// }

// int main(){

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif

//     int n;
//     cin >> n;

//     for(int i=0; i<n; i++){
       

//         int value;
//         cin >> value;

//         linkedList(value);

//     }

//     head = middleofLL();
//     display();

//     return 0;

// }

// TC - O(n^2);

#include <bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node* next;

    Node(int val){
        data = val;
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

void middleofLL(){
     
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    head = slow;

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

    middleofLL();
    display();

    return 0;

}

// INPUT : 

// 5
// 2 4 6 3 1 

// OUTPUT : 6 3 1 


// INPUT :

// 6
// 6 1 2 3 4 5 6

// OUTPUT : 3 4 5 6 