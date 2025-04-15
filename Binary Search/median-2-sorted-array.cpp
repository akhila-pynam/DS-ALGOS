#include <bits/stdc++.h>
using namespace std;

double findMedian(int n1, int n2, int* arr1, int* arr2){
  
    int arr[n1 + n2];
    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2){

        if(arr1[i] < arr2[j]){
            arr[k] = arr1[i];
            i++;
            k++;
        } 
        else {
            arr[k] = arr2[j];
            j++;
            k++;
        }

    }

    while(i < n1){
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = arr2[j];
        j++;
        k++;
    }

    int arrLen = n1 + n2;
    if(arrLen % 2 == 0){
        return (arr[arrLen/2 - 1] + arr[arrLen/2]) / 2.0;
    } 
    else{
        return arr[arrLen/2];
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n1;
    cin >> n1;

    int n2;
    cin >> n2;

    int arr1[n1];
    for(int i = 0; i < n1; i++){
        cin >> arr1[i];
    }

    int arr2[n2];
    for(int i = 0; i < n2; i++){
        cin >> arr2[i];
    }

    double result = findMedian(n1, n2, arr1, arr2);
    cout << result;

    return 0;
}

// INPUT :

// 3 2
// 2 4 6
// 1 3

// OUTPUT : 3

// INPUT : 

// 2 2 
// 1 2 
// 3 4 

// OUTPUT : 2.5
