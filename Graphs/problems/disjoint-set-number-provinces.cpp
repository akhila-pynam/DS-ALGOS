#include <bits/stdc++.h>
using namespace std;

int findParent(int node) {

    if (node == parent[node]) {
        return node;
    }
    else{
        parent[node] = findParent(parent[node]);
        return parent[node];
    }

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

vector<int> parent;
vector<int> Rank;

int disjointSet(vector<vector<int>>& Matrix) {
    
    int n = Matrix.size();
    parent.resize(n);
    Rank.resize(n, 0);

    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (Matrix[i][j] == 1 && i != j) {
                unionRank(i, j);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (findParent(i) == i) {
            count++;
        }
    }

    return count;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    int n, m;
    cin >> n >> m;

    vector<vector<int>> Matrix(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> Matrix[i][j];
        }
    }

    cout << disjointSet(Matrix) << endl;

    return 0;
}
