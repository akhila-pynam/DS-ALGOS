#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> WordSize;

int findParent(int node) {
    
    if (node == parent[node]) return node;
    return parent[node] = findParent(parent[node]); 

}

void unionSize(int u, int v) {
   
    int ulp_u = findParent(u); 
    int ulp_v = findParent(v);

    if (ulp_u == ulp_v) return; 

    if (WordSize[ulp_u] < WordSize[ulp_v]) {
        
        parent[ulp_u] = ulp_v;
        WordSize[ulp_v] = WordSize[ulp_v] + WordSize[ulp_u];

    }
    else if (WordSize[ulp_u] > WordSize[ulp_v]) {

        parent[ulp_v] = ulp_u;
        WordSize[ulp_u] = WordSize[ulp_u] + WordSize[ulp_v];

    } 
    else { 

        parent[ulp_v] = ulp_u;
        WordSize[ulp_u]++;

    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n; 
    cin >> n;

    for(int i=0; i<n; i++){
       
        int ele1, ele2;
        cin >> ele1 >> ele2;

    }


    parent.resize(n + 1);
    WordSize.resize(n + 1, 1);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        WordSize[i] = 1; 
    }


    unionSize(3, 7);

    if (findParent(3) == findParent(7)) {
        cout << "Same\n";
    } 
    else{
        cout << "Not same\n";
    }


    if (findParent(6) == findParent(5)) {
        cout << "Same\n";
    } 
    else {
        cout << "Not same\n";
    }

    return 0;
}

// INPUT :

// 7
// 1 2
// 2 3
// 4 5
// 6 7
// 3 4
// 5 6
// 1 3
// 3 7


// OUTPUT :
 
// Same
// Not same

