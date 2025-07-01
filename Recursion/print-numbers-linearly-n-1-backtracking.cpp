// #include <bits/stdc++.h>
// using namespace std;

// void func(int n, int cnt){
     
//     if(cnt == 0) return;
//     cout << cnt << " ";
//     cnt--;
//     func(n, cnt);

// }

// int main(){

// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// 	#endif

// 	int n;
// 	cin >> n;

// 	func(n, 100);

// 	return 0;

// }



// Back - Tracking Method

#include <bits/stdc++.h>
using namespace std;

void printNums(int i, int n){

	if(i == n) return;

	i++;
	printNums(i, n);
    cout << i << endl;


}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);;
	#endif

	int n;
	cin >> n;

	int i = 0;

	printNums(i, n);

	return 0;

}

// INPUT : 7
// OUPTUT : 7 6 5 4 3 2 1 