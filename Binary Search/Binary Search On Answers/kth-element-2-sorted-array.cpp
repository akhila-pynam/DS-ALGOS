#include <bits/stdc++.h>
using namespace std;

int findKth(int n1, int n2, int* arr1, int* arr2, int e){
    
// BRUTAL SOLUTION

	// int arrLen = n1 + n2;
    // int arr[arrLen];
    // int i = 0, j = 0, k = 0;

    // while(i < n1 && j < n2){

    //     if(arr1[i] < arr2[j]){
    //         arr[k] = arr1[i];
    //         i++;
    //         k++;
    //     } 
    //     else {
    //         arr[k] = arr2[j];
    //         j++;
    //         k++;
    //     }

    // }

    // while(i < n1){
    //     arr[k] = arr1[i];
    //     i++;
    //     k++;
    // }
    // while(j < n2){
    //     arr[k] = arr2[j];
    //     j++;
    //     k++;
    // }

    // for(int m=1; m<=arrLen; m++){
    //    if(arr[m] == e){
    //    	return m;
    //    }
    // }
    
    // return -1;


// OPTIMAL APPROACH USING BINARY SEARCH

	if (n1 > n2) return findKth(n2, n1, arr2, arr1, e);

	int left = 0;
	int right = n1;
	int arrLen = n1+n2;

	int ans = -1;

	while(left <= right){

		int m1 = (left + right)/ 2;
		int m2 = (arrLen + 1)/ 2 - 1;
        
        int left1 = (m1 == 0) ? INT_MIN : arr1[m1 - 1];
        int left2 = (m2 == 0) ? INT_MIN : arr2[m2 - 1];

        int right1 = (m1 == n1) ? INT_MAX : arr1[m1];
        int right2 = (m2 == n2) ? INT_MAX : arr2[m2];
        
        if(left1 <= right2 && left2 <= right1){
            return max(left1, left2);
        }
        else if(left1 > right2){
            right = m1 - 1;
        } 
        else{
            left = m1 + 1;
        }

    }
    return -1;
        
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
	for(int i=1; i<=n1; i++){
		cin >> arr1[i];
	}

	int arr2[n2];
	for(int i=1; i<=n2; i++){
		cin >> arr2[i];
	}

	int e;
	cin >> e;

	int result = findKth(n1, n2, arr1, arr2, e);
	cout << result;

	return 0;

}