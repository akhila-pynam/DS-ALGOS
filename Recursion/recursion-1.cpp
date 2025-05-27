#include <bits/stdc++.h>
using namespace std;

void printOne(){
     
    cout << 1 << endl;
    printOne();
    
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


    printOne();

    return 0;

}