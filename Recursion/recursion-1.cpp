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


// OUTPUT : 1 1 1 1 1 1 1 1 1 1 1 1 1 ... Uptill Infinite 
// In Online Compiler We Get Stack Overflow Or Sengmantation Fault 