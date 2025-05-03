#include <bits/stdc++.h>
using namespace std;


void swap(int index, int parent, int* nums){

    int temp = nums[index];
    nums[index] = nums[parent];
    nums[parent] = temp;

}

void heapify_down(int index, int* nums, int n){
    
    int leftIndex = 2*index+1; 
    int rightIndex = 2*index+2;
    int parent = (index - 1)/2;
    int smallest = index;

    if(smallest < n && nums[leftIndex] > nums[parent]){
    	smallest = leftIndex;
    }
    else{
    	smallest = rightIndex;
    }

    if(smallest != index){
    	swap(index, smallest, nums);
        heapify_down(smallest, nums, n);
    }
}

void heapify_up(int index, int* nums, int n){

	while(index > 0){

        int parent = (index - 1) / 2;

        if(nums[index] < nums[parent]){
            swap(index, parent, nums);
            index = parent;
        } 
        else{
            break;
        }

    }

}

void minHeapify(int n, int* nums, int index, int val){
     
    if(nums[index] > val){
    	nums[index] = val;
    	heapify_up(index, nums, n);
    }
    else{
    	nums[index] = val;
    	heapify_down(index, nums, n);
    }
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int nums[n];
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}

	int index;
	cin >> index;

	int val;
	cin >> val;

	minHeapify(n, nums, index, val);

	for(int i=0; i<n; i++){
		cout << nums[i] << " ";
	}

	return 0;

}

// INPUT :

// 6
// 1 4 5 5 7 6
// 5 
// 2

// OUTPUT : 1 4 2 5 7 5 
