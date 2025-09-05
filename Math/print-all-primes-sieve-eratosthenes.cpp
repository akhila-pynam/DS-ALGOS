#include <bits/stdc++.h>
using namespace std;

void sieveEra(int n, vector<int>& visited, vector<int>& output){

// 0 & 1's Are Not Primes. So That's Why We Started From 2.

	for(int i=2; i<n; i++){


		if(visited[i] == 1){
			output.push_back(i);
		}
        
        if(visited[i] == 1){
        	
        	for(int j = i*i; j<n; j = j+i){
                visited[j] = 0;
        	}

        }

	}
    
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	vector<int> visited(n, 1);
    vector<int> output;

	sieveEra(n, visited, output);

	for(auto it : output){
		cout << it << " ";
	}

    return 0;

}