#include <bits/stdc++.h>
using namespace std;

long long distance(long long x, long long y, long long a, long long b){

    
// Manhattan-Distance 

    // int hDis = abs(x-a);
    // int vDis = abs(y-b);
    
    // int tDis = hDis + vDis;

    // return tDis;


 // Euclidean Distance 

    // return sqrt((x-a)*(x-a) + (y-b)*(y-b));

// Sqrd Euclidean Distance - DSA 
   
    return ((x-a)*(x-a) + (y-b)*(y-b));
    
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	long long x, y;
	cin >> x >> y;

	long long a, p;
	cin >> a >> p;

	long long out = distance(x, y, a, p);

    cout << out;
    
	return 0;

}

INPUT : 

2 3
2 9

OUTPUT : 36

INPUT : 

1 1
4 5

OUTPUT : 25