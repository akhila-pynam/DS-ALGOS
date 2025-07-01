// Parameterized Method

#include <bits/stdc++.h>
using namespace std;

void summation(int i, int sum){

    if(i < 1) {
	    cout << sum;
	    return;
    }
    
    summation(i-1, sum + i);

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int sum = 0;

	summation(n, sum);

	return 0;

}


// INPUT : 3
// OUTPUT : 6

// INPUT : 2
// OUTPUT : 3

// INPUT : 5 
// OUTPUT : 15


// Functional Method 

#include <bits/stdc++.h>
using namespace std;

int functional(int n){
     
    if(n == 0) return 0;

    return n + functional(n-1);

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int output = functional(n);

	if(output){
		cout << output << endl;
	}
	else{
		cout << n << endl;
	}

	return 0;

}


// INPUT : 5
// OUTPUT : 15

// INPUT : 4 
// OUTPUT : 10

// INPUT : 3 
// OUTPUT : 6


