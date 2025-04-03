#include <bits/stdc++.h>
using namespace std;

int powerExpo(double x, int n){
    
    if(n == 0) return 1.0;
    if(x == 0) return 0.0;
    if(x == 1) return 1.0;
    if(x == -1 && n%2 == 0) return 1.0;

    long binaryForm = n;
    double ans = 1;

    if(n < 0){
    	x = 1/x;
    	binaryForm = -binaryForm;
    }

    while(binaryForm > 0){
       
        if(binaryForm % 2 == 1){
        	ans = ans * x;
        }

        x = x*x;
        binaryForm = binaryForm/2;
    }

    return ans;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	double x;
	int n;
	cin >> x >> n;

	double ans = powerExpo(x, n);
	cout << ans;
}