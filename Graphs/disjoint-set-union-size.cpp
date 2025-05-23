#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> Rank;
vector<int> WordSize;

int disjointSet(int n) {

    parent.resize(n + 1);
    Rank.resize(n + 1, 0);
    WordSize.resize(n + 1, 1); 
    
    for (int i = 1; i <= n; ++i) {  
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {  
        int ele1, ele2;
        cin >> ele1 >> ele2; 
    }

    return n;
}

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
        WordSize[ulp_v] += WordSize[ulp_u];

    }

    else if (WordSize[ulp_u] > WordSize[ulp_v]) {
       
        parent[ulp_v] = ulp_u;
        WordSize[ulp_u] += WordSize[ulp_v];

    } 

    else {
       
        parent[ulp_v] = ulp_u;
        WordSize[ulp_u]++;

    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n; 

    disjointSet(n);

    if (findParent(1) == findParent(3)) {
        cout << "Same\n";
    } 
    else {
        cout << "Not same\n";
    }

    unionSize(1, 3);

    if (findParent(1) == findParent(3)) {
        cout << "Same\n";
    } 
    else {
        cout << "Not same\n";
    }

    return 0;
}

// INPUT : 

// 5
// 1 2
// 2 3
// 3 4
// 4 5


// OUTPUT :

// Not Same 
// Same 
