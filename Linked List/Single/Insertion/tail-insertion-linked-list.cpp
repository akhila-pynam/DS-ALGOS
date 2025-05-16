#include <bits/stdc++.h>
using namespace std;

// TC -> O(n^2)
// SC -> O(n)

// How : 

// insert : O(n^2) ( Why : Eachh time We Are Iterating The List Again And Again Untill While Loops Fails )
// insertHead : O(1)
// dispaly : O(n)
// Total TC -> O(n^2)

// For Now the Tc & Sc Is O(n^2) Later I will Optimize It In O(n) Soon In Future ! 

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

void insertTail(int nodeVal){
     
   Node* temp = head;
   while(temp->right != nullptr){
      temp = temp->right;
   }
   temp->right = new Node(nodeVal);
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
    
    int nodeVal;
    cin >> nodeVal;

    insertTail(nodeVal);

	display();

    return 0;

}

// INPUT : 

// 8
// 4 5 6 2 3 8 9 1 
// 100

// OUTPUT : 4 5 6 2 3 8 9 1 100 