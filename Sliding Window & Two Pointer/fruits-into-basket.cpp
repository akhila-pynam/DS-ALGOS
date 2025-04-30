#include <bits/stdc++.h>
using namespace std;

int fruitsBaskets(int n, int* fruits){
   
// Naive Solution 

    // map<int, int> f;
    // int maxLen = 0;


    // for(int i=0; i<n; i++){

    // 	for(int j=i; j<n; j++){

    // 		f[fruits[j]]++;

	//     	if(f.size() > 2){
    //             break;
	//     	}

	//     	if(f.size() <= 2){
	//     		int length = j-i+1;
	//     		maxLen = max(maxLen, length);
	//     	}

	//     }
	//     f.clear();
    // }
    // return maxLen;


// Optimal Solution

    int left = 0;
    int right = 0;
    int maxLen = 0;
    map<int, int> f;

    while(right < n){
      
      f[fruits[right]]++;

      if(f.size() > 2){
        
        while(f.size() > 2){
        	
        	f[fruits[left]]--;
        	
        	if(f[fruits[left]] == 0){
                f.erase(fruits[left]);
            }

        	left++;
        }

      }

      if(f.size() <= 2){
      	int length = right - left + 1;
      	maxLen = max(maxLen, length);
      }
      
      right++;

    }
    return maxLen;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int fruits[n];
	for(int i=0; i<n; i++){
		cin >> fruits[i];
	}

	int result = fruitsBaskets(n, fruits);
	cout << result;

	return 0;

}

// INPUT :

// 5 
// 1 2 3 2 2 

// OUTPUT : 4

// INPUT : 

// 3 
// 1 2 1 

// OUTPUT : 3 
