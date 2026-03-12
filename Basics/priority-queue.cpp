#include <bits/stdc++.h>
using namespace std;

// To Access Small Element 

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    priority_queue<int> q ;

    for(int i=0; i<n; i++){
    
       int val;
       cin >> val;

       q.push(val);

    }

    while(q.size() != 1){    
        q.pop();
    }

    cout << q.top();


}

// INPUT :

// 4
// 4 5 8 6 

// OUTPUT : 4