#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> Rank;

int findParent(int node) {

    if (node == parent[node]) return node;
    return parent[node] = findParent(parent[node]);

}

void unionSets(int u, int v) {

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

    parent.resize(n + 1);
    Rank.resize(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    int u, v;
    cin >> u >> v;
    unionSets(u, v);

    for(int i=1; i<=n; i++){
        cout << parent[i] << " ";
    }
    cout << endl;

    for(int i=1; i<=n; i++){
    cout << Rank[i] << " ";
    }

    return 0;
}
