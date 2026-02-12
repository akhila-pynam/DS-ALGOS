#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> Rank;

int disjointSet(int n) {

    parent.resize(n + 1);
    Rank.resize(n + 1, 0);

    for (int i=0; i<n; ++i) {
        parent[i] = i;
    }

    for (int i=0; i<n; i++) {
        int ele1, ele2;
        cin >> ele1 >> ele2;
    }

    return n;
}

int findParent(int node) {
    if (node == parent[node]) return node;
    return parent[node] = findParent(parent[node]);
}

void unionRank(int u, int v) {
    
    int ulp_u = findParent(u);
    int ulp_v = findParent(v);

    if (ulp_u == ulp_v) return;

    if (Rank[ulp_u] < Rank[ulp_v]) {
        parent[ulp_u] = ulp_v;
    }
    else if (Rank[ulp_u] > Rank[ulp_v]) {
        parent[ulp_v] = ulp_u;
    }
    else {
        parent[ulp_v] = ulp_u;
        Rank[ulp_u]++;
    }
}

int main() {

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

    unionRank(1, 3);

    if (findParent(1) == findParent(3)) {
        cout << "Same\n";
    } 
    else {
        cout << "Not same\n";
    }

    return 0;
}


// INPUT : 

// 6
// 1 2
// 2 3
// 4 5
// 6 7
// 5 6
// 3 7 

// OUTPUT :

// Same
// Not same

