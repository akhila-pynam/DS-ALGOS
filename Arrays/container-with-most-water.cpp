#include <bits/stdc++.h>
using namespace std;

int containerMostwater(int n, vector<int>& height, priority_queue<int>& pq){

    int left = 0;
    int right = n-1;
    int ans = 0;

    while(left <= right){
         
        ans = max(min(height[left], height[right])*(right-left), ans);

        if(height[left] < height[right]) left++;
        else right--;


    }
    
    return ans;

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector<int> height(n);
    for(int i=0; i<n; i++){
        cin >> height[i];
    }

    priority_queue<int> pq;

    return containerMostwater(n, height, pq);

    return 0;

}

// INPUT : 

// 9
// 1 8 6 2 5 4 8 3 7

// OUTPUT : 49

// INPUT : 
// 2 
// 1 1 

// OUTPUT : 1