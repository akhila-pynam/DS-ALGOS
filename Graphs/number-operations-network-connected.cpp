#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> Rank;

void disjointSet(int n) {
   
    parent.resize(n);
    Rank.resize(n, 0);
    
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

}

int findParent(int node) {
    if (node == parent[node]) return node;
    return parent[node] = findParent(parent[node]);
}

void unionNode(int u, int v) {
   
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

int ConnectNetwork(int n, vector<vector<int>>& connections) {
   
    int cs = connections.size();

    if (cs < n-1) return -1;

    disjointSet(n);  

    for (auto& neighbor : connections) {
      
        int u = neighbor[0];
        int v = neighbor[1];
        unionNode(u, v);

    }

    unordered_set<int> components;
    
    for (int i = 0; i < n; ++i) {
        components.insert(findParent(i));
    }

    return components.size() - 1;
}

int main() {
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<vector<int>> connections(m);
    
    for (int i = 0; i < m; i++) {
        
        int u, v;
        cin >> u >> v;
        connections[i] = {u, v};

    }

    int result = ConnectNetwork(n, connections);
    cout << result << endl;

    return 0;
}
