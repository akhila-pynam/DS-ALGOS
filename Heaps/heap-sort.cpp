#include <bits/stdc++.h>
using namespace std;

void swap(int i, int parent, int* nums){
    
    int temp = nums[i];
    nums[i] = nums[parent];
    nums[parent] = temp;

}

void heapify_down(int n, int* nums, int i){
   
    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;
    int largest = i;

    if(leftIndex < n && nums[leftIndex] > nums[largest]){
        largest = leftIndex;
    }

    if(rightIndex < n && nums[rightIndex] > nums[largest]){
        largest = rightIndex;
    }

    if(largest != i){
        swap(i, largest, nums);
        heapify_down(n, nums, largest);
    }
}

void buildMaxheap(int n, int* nums){

    for(int i=(n-1)/2; i>=0; i--){
        heapify_down(n, nums, i);
    }

}

void heapSort(int* nums, int n){

    buildMaxheap(n, nums);
    int last = n - 1; 

    while(last > 0){

        swap(0, last, nums); 
        last--; 
        heapify_down(last + 1, nums, 0); 

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
    for (int i=0; i<n; i++){
        cin >> nums[i];
    }

    heapSort(nums, n);

    for (int i=0; i<n; i++){
        cout << nums[i] << " ";
    }

    return 0;
}

// INPUT : 

// 5
// 7 4 1 5 3 

// OUTPUT : 1 3 4 5 7 
