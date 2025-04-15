#include <bits/stdc++.h>
using namespace std;

int kthMiss(int n, int* arr, int k){
    
        int left = 0;
        int right = n - 1;
        int ans = -1;

        while(left <= right){

            int mid = (left + right)/2;
            int missing = arr[mid] - (mid + 1);

            if(missing >= k){
                ans = mid;
                right = mid - 1;
            } 
            else{
                left = mid + 1;
            }
        }

        ans = left + k;
        return ans;
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

	int k;
	cin >> k;
 
    int result = kthMiss(n, arr, k);
    cout << result;

	return 0;

}