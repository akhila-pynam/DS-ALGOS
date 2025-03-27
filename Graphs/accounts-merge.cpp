#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> Rank;
vector<int> size;
unordered_map<string, int> mapMailNode;
vector<vector<string>> accounts;

int findParent(int node) {
    if (node == parent[node]) return node;
    return parent[node] = findParent(parent[node]);
}

void unionBySize(int u, int v) {
   
    int ulp_u = findParent(u);
    int ulp_v = findParent(v);

    if(ulp_u == ulp_v) return;

    if(size[ulp_u] < size[ulp_v]) {
        parent[ulp_u] = ulp_v;
        size[ulp_v] = size[ulp_v] + size[ulp_u];
    } 
    else{
        parent[ulp_v] = ulp_u;
        size[ulp_u] = size[ulp_u] + size[ulp_v];
    }
}

int disjointSet(int n){

    parent.resize(n);
    Rank.resize(n, 0);
    size.resize(n, 1);

    for(int i=0; i<n; ++i){
        parent[i] = i;
    }

    for(int i=0; i<n; i++){

        string name;
        int m;
        cin >> name >> m;

        vector<string> account;

        account.push_back(name);

        for(int j=0; j<m; j++){

            string mail;
            cin >> mail;

            account.push_back(mail);

            if(mapMailNode.find(mail) == mapMailNode.end()){
                mapMailNode[mail] = i;
            } 
            else{
                unionBySize(i, mapMailNode[mail]);
            }
        }

        accounts.push_back(account);
    }

    return n;
}

vector<vector<string>> accountMerge() {
    vector<string> mergedMail[accounts.size()];

    for(auto it : mapMailNode){

        string mail = it.first;
        int node = findParent(it.second);
        mergedMail[node].push_back(mail);

    }

    vector<vector<string>> ans;

    for(int i=0; i<accounts.size(); i++) {

        if (mergedMail[i].size() == 0) continue;

        sort(mergedMail[i].begin(), mergedMail[i].end());

        vector<string> temp;

        temp.push_back(accounts[i][0]);

        for(auto it : mergedMail[i]) {
            temp.push_back(it);
        }
        ans.push_back(temp);
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    disjointSet(n);

    vector<vector<string>> result = accountMerge();

    for (auto& group : result) {
        for (int i=0; i<group.size(); i++) {
            
            if (i) cout << " ";

            cout << group[i];
        }
        cout << endl;
    }

    return 0;
}
