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
    	while(temp->right != nullptr){
    		temp = temp->right;
    	}
    	temp->right = new Node(value);
    }

}

void sortList(){

    Node* temp = head;
    priority_queue<int, vector<int>, greater<int>> pq;

    while(temp != nullptr){
       pq.push(temp->data);
       temp = temp->right;
    }

    temp = head;

    while (pq.size() != 0){

        temp->data = pq.top();
        pq.pop();
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

    sortList();

	display();

	return 0;

}

// INPUT : 

// 5
// 5 6 1 2 1 

// OUTPUT : 1 1 2 5 6 