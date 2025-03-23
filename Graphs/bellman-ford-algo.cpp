#include <bits/stdc++.h>
using namespace std;

int bellmanFord(vector<vector<pair<int, int>>>& adjList, vector<int>& distance, int source, int n){
    
    distance[source] = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {

            for(auto neighbor : adjList[j]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if(distance[j] != INT_MAX && distance[j] + weight < distance[v]) {
                    distance[v] = distance[j] + weight;
                }
            }
        }
    }

    for(int j=0; j<n; j++) {

        for(auto neighbor : adjList[j]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if(distance[j] != INT_MAX && distance[j] + weight < distance[v]) {
                return -1;
            }
        }
    }
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif 

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adjList(n);

	for(int i = 0; i < m; i++) {
		
		int u, v, w; 
		cin >> u >> v >> w;
		
		adjList[u].push_back({v, w});

	}

	for(int i = 0; i < n; i++) {
  
        for(auto& neighbor : adjList[i]) {
            cout << "(" << neighbor.first << " " << neighbor.second << ")";
        }

        cout << endl;

    }

	vector<int> distance(n, INT_MAX);
	int source = 0;

	bellmanFord(adjList, distance, source, n);

    cout << "BellManFord : ";
	for(int i = 0; i < n; i++) {
	    if(distance[i] != INT_MAX) {
	    	cout << distance[i] << " ";
	    } 
	}

	return 0;
}
