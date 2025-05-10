#include <bits/stdc++.h>
using namespace std;

vector<int> topkFreq(int n, int* nums, int k){
   
    map<int, int> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i=0; i<n; i++){
       m[nums[i]]++;
    }   

    for(auto& it : m){

        pq.push({it.second, it.first});

        if(pq.size() > k){
            pq.pop();
        }
    }

    vector<int> result;

    while(!pq.empty()){
        result.push_back(pq.top().second);
        pq.pop();
    }  

    sort(result.begin(), result.end());
    return result;
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

    int k;
    cin >> k;

    vector<int> topK = topkFreq(n, nums, k);

    for(int i=0; i<(int)topK.size(); i++){
        cout << topK[i] << " ";
    }

    return 0;
}

// INPUT :

// 6
// 1 1 1 2 2 3
// 2

// OUTPUT : 1 2