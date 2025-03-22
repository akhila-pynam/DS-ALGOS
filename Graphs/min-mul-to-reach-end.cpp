#include <bits/stdc++.h>
using namespace std;

int minMulreachend(int n, int array[], vector<int>& visited, int start, int end){
   
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = 1;

    while(!q.empty()){

        auto qPair = q.front();
        int x = qPair.first;
        int distance = qPair.second;
        q.pop();

        for(int i = 0; i < n; i++){

            int newNode = (array[i] * x) % 100000;
            if(newNode == end) return distance + 1;

            if(!visited[newNode]){

                q.push({newNode, distance + 1});
                visited[newNode] = 1;
                
            }

        }
    }
    return -1;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    int array[n];
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }

    vector<int> visited(100000, 0);
    int start = 3; 
    int end = 30;  

    int result = minMulreachend(n, array, visited, start, end);

    cout << result;
    return 0;
}
