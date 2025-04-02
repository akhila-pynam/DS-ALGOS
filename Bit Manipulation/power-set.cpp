#include <bits/stdc++.h>
using namespace std;

void powerSet(int n, int nums[], list<list<int>>& listSubsets) {
    
    int totalSubsets = 1 << n;

    for (int i=0; i<totalSubsets; i++) {
        
        list<int> output;

        for (int j=0; j<n; j++) {
            
            if(i & (1 << j)) {
                output.push_back(nums[j]);
            }

        }

        listSubsets.push_back(output);
        
    }
}

int main() {
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    list<list<int>> listSubsets;

    powerSet(n, nums, listSubsets);

    for (const auto& subset : listSubsets) {
   
        for (const auto& elem : subset) {
            cout << elem << " ";
        }
       cout << endl;
    }

    return 0;
}
