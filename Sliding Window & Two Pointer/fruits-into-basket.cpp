#include <bits/stdc++.h>
using namespace std;

int fruitsBasket(int n, int* fruits){

// Brutal Solution

    // int maxLen = 0;
    // int length = 0;
    
    // for(int i=0; i<n; i++){
        
    //     set<int> basket;

    //     for(int j=i; j<n; j++){

    //         basket.insert(fruits[j]);

    //         if(basket.size() > 2){
    //             break;
    //         }

    //         if(basket.size() <= 2){
    //             length = j - i + 1;
    //             maxLen = max(length, maxLen);
    //         }    
    //     }
    // }
    // return maxLen;

// Optimal Solution

    int left = 0;
    int right = 0;
    int maxLen = 0;
    int length = 0;
    int k = 2;
    map<int, int> basket;

    while(right < n){

        basket[fruits[right]]++;

        if(basket.size() > k){

            while(basket.size() > k){
                
                basket[fruits[left]]--;

                if(basket[fruits[left]] == 0){
                    basket.erase(fruits[left]);
                }
                left++;
            }
        }
        if(basket.size() <= k){
            length = right - left + 1;
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

    int result = fruitsBasket(n, fruits);
    cout << result;

    return 0;

}

// INPUT :

// 3
// 1 2 1

// OUTPUT : 3


// INPUT :

// 5
// 1 2 3 2 2 

// OUTPUT : 4