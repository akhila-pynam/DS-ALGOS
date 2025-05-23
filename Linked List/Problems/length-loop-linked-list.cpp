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

void lenghtOfloop(int pos){
     
    if(pos == -1) return;

    Node* temp = head;
    Node* cycleNode =  nullptr;
    int index = 0;

    while(temp->right != nullptr){

    	if(index == pos){
    		cycleNode = temp;
    	}

    	temp = temp->right;
    	index++;

    }

    if(cycleNode != nullptr){
    	temp->right = cycleNode;
    }

}

int output(){
          
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->right != nullptr){
    	
    	slow = slow->right;
    	fast = fast->right->right;

    	if (slow == fast) {

            int length = 1;
            fast = fast->right;

            while (slow != fast) {
                fast = fast->right;
                length++;
            }

            return length;

        }
    }
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

    int pos;
    cin >> pos;

    lenghtOfloop(pos);

    cout << output();

    return 0;

}

// INPUT : 

// 5
// 1 0 2 0 1 
// 1

// OUTPUT : 4


// INPUT : 

// 5
// 1 2 3 4 5 
// 1

// OUTPUT : 4