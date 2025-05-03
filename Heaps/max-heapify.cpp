#include <bits/stdc++.h>
using namespace std;

void swap(int index, int parent, int* arr) {
  
    int temp = arr[index];
    arr[index] = arr[parent];
    arr[parent] = temp;

}

void heapify_up(int index, int* arr){
   
    while(index > 0){

        int parent = (index - 1) / 2;

        if(arr[index] > arr[parent]){
            swap(index, parent, arr);
            index = parent;
        } 
        else{
            break;
        }

    }
}

void heapify_down(int index, int n, int* arr) {

    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;
    int largest = index;

    if (leftIndex < n && arr[leftIndex] > arr[largest]) {
        largest = leftIndex;
    }

    if (rightIndex < n && arr[rightIndex] > arr[largest]) {
        largest = rightIndex;
    }

    if (largest != index) {
        swap(index, largest, arr);
        heapify_down(largest, n, arr);  
    }

}


void maxHeapify(int n, int* arr, int index, int val){

    if(arr[index] < val){

    	arr[index] = val;
        heapify_up(index, arr);

    } 
    else{
    	arr[index] = val;
        heapify_down(index, n, arr);
    }

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int index;
    cin >> index;

    int val;
    cin >> val;

    maxHeapify(n, arr, index, val);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}

// INPUT : 

// 6
// 10 9 8 7 6 5 
// 0
// 2

// OUTPUT : 9 7 8 2 6 5 
