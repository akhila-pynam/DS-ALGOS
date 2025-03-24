#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> Rank;

void disjointSet(int n) {
    
    parent.resize(n + 1);
    Rank.resize(n + 1, 0);

    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
    }
}

int findParent(int node) {
    if (node == parent[node]) return node;
    return parent[node] = findParent(parent[node]);  
}

void unionRank(int u, int v){

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

int kruskalAlgo(int n, vector<pair<int, pair<int, int>>>& adjList) {

    sort(adjList.begin(), adjList.end());  

    int mstW = 0;
    disjointSet(n); 

    for (auto& neighbor : adjList) {
       
        int w = neighbor.first;
        int u = neighbor.second.first;
        int v = neighbor.second.second;

        if (findParent(u) != findParent(v)) {
            unionRank(u, v);
            mstW = mstW + w; 
        }
    }

    return mstW;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m; 

    vector<pair<int, pair<int, int>>> adjList;

    for (int i = 0; i < m; ++i) {
        
        int u, v, w;
        cin >> u >> v >> w;

        adjList.push_back({w, {u, v}});

    }

    int mstW = kruskalAlgo(n, adjList);

    cout << mstW << endl; 

    return 0;
}
