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
    int smallest = i;

    if(leftIndex < n && nums[leftIndex] > nums[smallest]){
        smallest = leftIndex;
    }

    if(rightIndex < n && nums[rightIndex] > nums[smallest]){
        smallest = rightIndex;
    }

    if(smallest != i){
        swap(i, smallest, nums);
        heapify_down(n, nums, smallest);
    }

}

void buildMinHeap(int n, int* nums){
    
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify_down(n, nums, i);
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
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    buildMinHeap(n, nums);

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
