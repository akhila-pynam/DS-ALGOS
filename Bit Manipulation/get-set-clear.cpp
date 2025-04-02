#include <bits/stdc++.h>
using namespace std;

int bitManipulation(int num, int postion){
        
        int get = (num >> (postion-1)) & 1 ;
        int set = (1 << (postion-1)) | num ;
        int clear =  (~(1 << postion-1)) & num;

        cout << get << " " << set << " " << clear << endl;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int num;
	int position;

	cin >> num >> position;

	bitManipulation(num, position);	

    return 0;

}

// INPUT : 70 3
// OUTPUT : 1 70 66


// INPUT : 8 1 
// OUPUT : 0 9 8 